..
.. NB:  This file is machine generated, DO NOT EDIT!
..
.. Edit ./vmod_std.vcc and run make instead
..


:tocdepth: 1


.. _vmod_std(3):

==================================
VMOD std - Varnish Standard Module
==================================

SYNOPSIS
========

.. parsed-literal::

  import std [as name] [from "path"]
  
  :ref:`std.random()`
   
  :ref:`std.round()`
   
  :ref:`std.collect()`
   
  :ref:`std.querysort()`
   
  :ref:`std.toupper()`
   
  :ref:`std.tolower()`
   
  :ref:`std.strstr()`
   
  :ref:`std.fnmatch()`
   
  :ref:`std.fileread()`
   
  :ref:`std.blobread()`
   
  :ref:`std.file_exists()`
   
  :ref:`std.healthy()`
   
  :ref:`std.port()`
   
  :ref:`std.duration()`
   
  :ref:`std.bytes()`
   
  :ref:`std.integer()`
   
  :ref:`std.ip()`
   
  :ref:`std.real()`
   
  :ref:`std.time()`
   
  :ref:`std.log()`
   
  :ref:`std.syslog()`
   
  :ref:`std.timestamp()`
   
  :ref:`std.syntax()`
   
  :ref:`std.getenv()`
   
  :ref:`std.cache_req_body()`
   
  :ref:`std.late_100_continue()`
   
  :ref:`std.set_ip_tos()`
   
  :ref:`std.rollback()`
   
  :ref:`std.real2integer()`
   
  :ref:`std.real2time()`
   
  :ref:`std.time2integer()`
   
  :ref:`std.time2real()`
   
DESCRIPTION
===========

.. note: not using :ref:`vmod_std(3)` because it expands to "VMOD
   std - Varnish Standard Module" and here just the plan vmod name
   makes more sense.

*vmod_std* contains basic functions which are part and parcel of
Varnish, but which for reasons of architecture fit better in a VMOD.

Numeric functions
=================

.. _std.random():

REAL random(REAL lo, REAL hi)
-----------------------------

Returns a random real number between *lo* and *hi*.

This function uses the "testable" random generator in varnishd which
enables determinstic tests to be run (See ``m00002.vtc``).  This
function should not be used for cryptographic applications.

Example::

	set beresp.http.random-number = std.random(1, 100);

.. _std.round():

REAL round(REAL r)
------------------

Rounds the real *r* to the nearest integer, but round halfway cases
away from zero (see `round(3)`).


String functions
================

.. _std.collect():

VOID collect(HEADER hdr, STRING sep=", ")
-----------------------------------------

Collapses multiple *hdr* headers into one long header. The default
separator *sep* is the standard comma separator to use when collapsing
headers, with an additional whitespace for pretty printing.

Care should be taken when collapsing headers. In particular collapsing
``Set-Cookie`` will lead to unexpected results on the browser side.

Examples::

	std.collect(req.http.accept);
	std.collect(req.http.cookie, "; ");

.. _std.querysort():

STRING querysort(STRING)
------------------------

Sorts the query string for cache normalization purposes.

Example::

	set req.url = std.querysort(req.url);

.. _std.toupper():

STRING toupper(STRING s)
------------------------

Converts the string *s* to uppercase.

Example::

	set beresp.http.scream = std.toupper("yes!");

.. _std.tolower():

STRING tolower(STRING s)
------------------------

Converts the string *s* to lowercase.

Example::

	set beresp.http.nice = std.tolower("VerY");

.. _std.strstr():

STRING strstr(STRING s1, STRING s2)
-----------------------------------

Returns a string beginning at the first occurrence of the string *s2*
in the string *s1*, or an empty string if *s2* is not found.

Note that the comparison is case sensitive.

Example::

	if (std.strstr(req.url, req.http.restrict)) {
		...
	}

This will check if the content of ``req.http.restrict`` occurs
anywhere in ``req.url``.

.. _std.fnmatch():

BOOL fnmatch(STRING pattern, STRING subject, BOOL pathname, BOOL noescape, BOOL period)
---------------------------------------------------------------------------------------

::

   BOOL fnmatch(
      STRING pattern,
      STRING subject,
      BOOL pathname=1,
      BOOL noescape=0,
      BOOL period=0
   )

Shell-style pattern matching; returns ``true`` if *subject* matches
*pattern*, where *pattern* may contain wildcard characters such as ``*``
or ``?``.

The match is executed by the implementation of `fnmatch(3)` on your
system. The rules for pattern matching on most systems include the
following:

* ``*`` matches any sequence of characters

* ``?`` matches a single character

* a bracket expression such as ``[abc]`` or ``[!0-9]`` is interpreted
  as a character class according to the rules of basic regular
  expressions (*not* `pcre(3)` regexen), except that ``!`` is used for
  character class negation instead of ``^``.

If *pathname* is ``true``, then the forward slash character ``/`` is
only matched literally, and never matches ``*``, ``?`` or a bracket
expression. Otherwise, ``/`` may match one of those patterns.  By
default, *pathname* is ``true``.

If *noescape* is ``true``, then the backslash character ``\`` is
matched as an ordinary character. Otherwise, ``\`` is an escape
character, and matches the character that follows it in the
*pattern*. For example, ``\\`` matches ``\`` when *noescape* is
``true``, and ``\\`` when ``false``. By default, *noescape* is
``false``.

If *period* is ``true``, then a leading period character ``.`` only
matches literally, and never matches ``*``, ``?`` or a bracket
expression. A period is leading if it is the first character in
*subject*; if *pathname* is also ``true``, then a period that
immediately follows a ``/`` is also leading (as in ``/.``).  By
default, *period* is ``false``.

`std.fnmatch()`_ invokes VCL failure and returns ``false`` if
either of *pattern* or *subject* is ``NULL`` -- for example, if an
unset header is specified.

Examples::

	# Matches URLs such as /foo/bar and /foo/baz
	if (std.fnmatch("/foo/\*", req.url)) { ... }

	# Matches URLs such as /foo/bar/baz and /foo/baz/quux
	if (std.fnmatch("/foo/\*/\*", bereq.url)) { ... }

	# Matches /foo/bar/quux, but not /foo/bar/baz/quux
	if (std.fnmatch("/foo/\*/quux", req.url)) { ... }

	# Matches /foo/bar/quux and /foo/bar/baz/quux
	if (std.fnmatch("/foo/\*/quux", req.url, pathname=false)) { ... }

	# Matches /foo/bar, /foo/car and /foo/far
	if (std.fnmatch("/foo/?ar", req.url)) { ... }

	# Matches /foo/ followed by a non-digit
	if (std.fnmatch("/foo/[!0-9]", req.url)) { ... }


File(system) functions
======================

.. _std.fileread():

STRING fileread(STRING)
-----------------------

Reads a text file and returns a string with the content.

The entire file is cached on the first call, and subsequent calls
will return this cached contents, even if the file has changed in
the meantime.

For binary files, use std.blobread() instead.

Example::

	synthetic("Response was served by " + std.fileread("/etc/hostname"));

Consider that the entire contents of the file appear in the string
that is returned, including newlines that may result in invalid
headers if `std.fileread()`_ is used to form a header. In that
case, you may need to modify the string, for example with
``regsub()`` (see :ref:`vcl(7)`)::

  set beresp.http.served-by = regsub(std.fileread("/etc/hostname"), "\R$", "");

.. _std.blobread():

BLOB blobread(STRING)
---------------------

Reads any file and returns a blob with the content.

The entire file is cached on the first call, and subsequent calls
will return this cached contents, even if the file has changed in
the meantime.

.. _std.file_exists():

BOOL file_exists(STRING path)
-----------------------------

Returns ``true`` if path or the file pointed to by path exists,
``false`` otherwise.

Example::

	if (std.file_exists("/etc/return_503")) {
		return (synth(503, "Varnish is in maintenance"));
	}


Type Inspection functions
=========================

.. _std.healthy():

BOOL healthy(BACKEND be)
------------------------

Returns ``true`` if the backend *be* is healthy.

.. _std.port():

INT port(IP ip)
---------------

Returns the port number of the IP address *ip*. Always returns ``0``
for a ``*.ip`` variable when the address is a Unix domain socket.

Type Conversion functions
=========================

These functions all have the same form::

	TYPE type([arguments], [fallback TYPE])

Precisely one of the *arguments* must be provided (besides the
optional *fallback*), and it will be converted to *TYPE*.

If conversion fails, *fallback* will be returned and if no
fallback was specified, the VCL will be failed.

.. _std.duration():

DURATION duration([STRING s], [DURATION fallback], [REAL real], [INT integer])
------------------------------------------------------------------------------

::

   DURATION duration(
      [STRING s],
      [DURATION fallback],
      [REAL real],
      [INT integer]
   )

Returns a DURATION from a STRING, REAL or INT argument.

For a STRING *s* argument, *s* must be quantified by ``ms``
(milliseconds), ``s`` (seconds), ``m`` (minutes), ``h`` (hours),``d``
(days), ``w`` (weeks) or ``y`` (years) units.

*real* and *integer* arguments are taken as seconds.

If the conversion of an *s* argument fails, *fallback* will be
returned if provided, or a VCL failure will be triggered.

Conversions from *real* and *integer* arguments never fail.

Only one of the *s*, *real* or *integer* arguments may be given or a VCL
failure will be triggered.

Examples::
	set beresp.ttl = std.duration("1w", 3600s);
	set beresp.ttl = std.duration(real=1.5);
	set beresp.ttl = std.duration(integer=10);

.. _std.bytes():

BYTES bytes([STRING s], [BYTES fallback], [REAL real], [INT integer])
---------------------------------------------------------------------

::

   BYTES bytes(
      [STRING s],
      [BYTES fallback],
      [REAL real],
      [INT integer]
   )

Returns BYTES from a STRING, REAL or INT argument.

A STRING *s* argument can be quantified with a multiplier (``k``
(kilo), ``m`` (mega), ``g`` (giga), ``t`` (tera) or ``p`` (peta)).

*real* and *integer* arguments are taken as bytes.

If the conversion of an *s* argument fails, *fallback* will be
returned if provided, or a VCL failure will be triggered.

Other conversions may fail if the argument can not be represented,
because it is negative, too small or too large. Again, *fallback* will
be returned if provided, or a VCL failure will be triggered.

*real* arguments will be rounded down.

Only one of the *s*, *real* or *integer* arguments may be given or a VCL
failure will be triggered.

Example::
	std.cache_req_body(std.bytes(something.somewhere, 10K));
	std.cache_req_body(std.bytes(integer=10*1024));
	std.cache_req_body(std.bytes(real=10.0*1024));

.. _std.integer():

INT integer([STRING s], [INT fallback], [BOOL bool], [BYTES bytes], [DURATION duration], [REAL real], [TIME time])
------------------------------------------------------------------------------------------------------------------

::

   INT integer(
      [STRING s],
      [INT fallback],
      [BOOL bool],
      [BYTES bytes],
      [DURATION duration],
      [REAL real],
      [TIME time]
   )

Returns an INT from a STRING, BOOL or other quantity.

If the conversion of an *s* argument fails, *fallback* will be
returned if provided, or a VCL failure will be triggered.

A *bool* argument will be returned as 0 for ``false`` and 1 for
``true``. This conversion will never fail.

For a *bytes* argument, the number of bytes will be returned.  This
conversion will never fail.

A *duration* argument will be rounded down to the number of seconds
and returned.

A *real* argument will be rounded down and returned.

For a *time* argument, the number of seconds since the UNIX epoch
(1970-01-01 00:00:00 UTC) will be returned.

*duration*, *real* and *time* conversions may fail if the argument can
not be represented because it is too small or too large. If so,
*fallback* will be returned if provided, or a VCL failure will be
triggered.

Only one of the *s*, *bool*, *bytes*, *duration*, *real* or *time*
arguments may be given or a VCL failure will be triggered.

Examples::

	if (std.integer(req.http.foo, 0) > 5) {
		...
	}

	set resp.http.answer = std.integer(real=126.42/3);

.. _std.ip():

IP ip(STRING s, [IP fallback], BOOL resolve=1, [STRING p])
----------------------------------------------------------

Converts the string *s* to the first IP number returned by the system
library function `getaddrinfo(3)`. If conversion fails, *fallback* will
be returned or VCL failure will happen.

The IP address includes a port number that can be found with ``std.port()``
that defaults to 80. The default port can be set to a different value with
the *p* argument. It will be overriden if *s* contains both an IP address
and a port number or service name.

When *s* contains both, the syntax is either ``address:port`` or
``address port``. If the address is a numerical IPv6 address it must be
enclosed between brackets, for example ``[::1] 80`` or ``[::1]:http``.
The *fallback* may also contain both an address and a port, but its default
port is always 80.

If *resolve* is false, `getaddrinfo(3)` is called using ``AI_NUMERICHOST``
and ``AI_NUMERICSERV`` to avoid network lookups depending on the system's
`getaddrinfo(3)` or nsswitch configuration. This makes "numerical" IP
strings and services cheaper to convert.

Example::

	if (std.ip(req.http.X-forwarded-for, "0.0.0.0") ~ my_acl) {
		...
	}

.. _std.real():

REAL real([STRING s], [REAL fallback], [INT integer], [BOOL bool], [BYTES bytes], [DURATION duration], [TIME time])
-------------------------------------------------------------------------------------------------------------------

::

   REAL real(
      [STRING s],
      [REAL fallback],
      [INT integer],
      [BOOL bool],
      [BYTES bytes],
      [DURATION duration],
      [TIME time]
   )

Returns a REAL from a STRING, BOOL or other quantity.

If the conversion of an *s* argument fails, *fallback* will be
returned if provided, or a VCL failure will be triggered.

A *bool* argument will be returned as 0.0 for ``false`` and 1.0 for
``true``.

For a *bytes* argument, the number of bytes will be returned.

For a *duration* argument, the number of seconds will be returned.

An *integer* argument will be returned as a REAL.

For a *time* argument, the number of seconds since the UNIX epoch
(1970-01-01 00:00:00 UTC) will be returned.

None of these conversions other than *s* will fail.

Only one of the *s*, *integer*, *bool*, *bytes*, *duration* or *time*
arguments may be given or a VCL failure will be triggered.

Example::

	if (std.real(req.http.foo, 0.0) > 5.5) {
		...
	}

.. _std.time():

TIME time([STRING s], [TIME fallback], [REAL real], [INT integer])
------------------------------------------------------------------

::

   TIME time([STRING s], [TIME fallback], [REAL real], [INT integer])

Returns a TIME from a STRING, REAL or INT argument.

For a STRING *s* argument, the following formats are supported::

	"Sun, 06 Nov 1994 08:49:37 GMT"
	"Sunday, 06-Nov-94 08:49:37 GMT"
	"Sun Nov  6 08:49:37 1994"
	"1994-11-06T08:49:37"
	"784111777.00"
	"784111777"

*real* and *integer* arguments are taken as seconds since the epoch.

If the conversion of an *s* argument fails or a negative *real* or
*integer* argument is given, *fallback* will be returned if provided,
or a VCL failure will be triggered.

Examples::

	if (std.time(resp.http.last-modified, now) < now - 1w) {
		...
	}

	if (std.time(int=2147483647) < now - 1w) {
		...
	}

LOGGING functions
=================

.. _std.log():

VOID log(STRING s)
------------------

Logs the string *s* to the shared memory log, using :ref:`vsl(7)` tag
``SLT_VCL_Log``.

Example::

	std.log("Something fishy is going on with the vhost " + req.http.host);

.. _std.syslog():

VOID syslog(INT priority, STRING s)
-----------------------------------

Logs the string *s* to syslog tagged with *priority*. *priority* is
formed by ORing the facility and level values. See your system's
``syslog.h`` file for possible values.

Notice: Unlike VCL and other functions in the std vmod, this function
will not fail VCL processing for workspace overflows: For an out of
workspace condition, the `std.syslog()`_ function has no effect.

Example::

	std.syslog(9, "Something is wrong");

This will send a message to syslog using ``LOG_USER | LOG_ALERT``.

.. _std.timestamp():

VOID timestamp(STRING s)
------------------------

Introduces a timestamp in the log with the current time, using the
string *s* as the label. This is useful to time the execution of lengthy
VCL subroutines, and makes the timestamps inserted automatically by
Varnish more accurate.

Example::

	std.timestamp("curl-request");


CONTROL and INFORMATION functions
=================================

.. _std.syntax():

BOOL syntax(REAL)
-----------------

Returns ``true`` if VCL version is at least *REAL*.

.. _std.getenv():

STRING getenv(STRING name)
--------------------------

Return environment variable *name* or the empty string. See `getenv(3)`.

Example::

	set req.http.My-Env = std.getenv("MY_ENV");

.. _std.cache_req_body():

BOOL cache_req_body(BYTES size)
-------------------------------

Caches the request body if it is smaller than *size*.  Returns
``true`` if the body was cached, ``false`` otherwise.

Normally the request body can only be sent once. Caching it enables
retrying backend requests with a request body, as usually the case
with ``POST`` and ``PUT``.

Example::

	if (std.cache_req_body(1KB)) {
		...
	}

.. _std.late_100_continue():

VOID late_100_continue(BOOL late)
---------------------------------

Controls when varnish reacts to an ``Expect: 100-continue`` client
request header.

Varnish always generates a ``100 Continue`` response if requested by
the client trough the ``Expect: 100-continue`` header when waiting for
request body data.

But, by default, the ``100 Continue`` response is already generated
immediately after ``vcl_recv`` returns to reduce latencies under the
assumption that the request body will be read eventually.

Calling ``std.late_100_continue(true)`` in ``vcl_recv`` will cause the
``100 Continue`` response to only be sent when needed. This may cause
additional latencies for processing request bodies, but is the correct
behavior by strict interpretation of RFC7231.

This function has no effect outside ``vcl_recv`` and after calling
``std.cache_req_body()`` or any other function consuming the request
body.

Example::

	vcl_recv {
		std.late_100_continue(true);

		if (req.method == "POST") {
			std.late_100_continue(false);
			return (pass);
		}
		...
	 }

.. _std.set_ip_tos():

VOID set_ip_tos(INT tos)
------------------------

Sets the IP type-of-service (TOS) field for the current session to
*tos*. Silently ignored if the listen address is a Unix domain socket.

Please note that the TOS field is not removed by the end of the
request so probably want to set it on every request should you utilize
it.

Example::

	if (req.url ~ "^/slow/") {
		std.set_ip_tos(0);
	}

.. _std.rollback():

VOID rollback(HTTP h)
---------------------

Restores the *h* HTTP headers to their original state.

Example::

	std.rollback(bereq);


DEPRECATED functions
====================

.. _std.real2integer():

INT real2integer(REAL r, INT fallback)
--------------------------------------

**DEPRECATED**: This function will be removed in a future version of
varnish, use `std.integer()`_ with a *real* argument and the
`std.round()`_ function instead, for example::

	std.integer(real=std.round(...), fallback=...)

Rounds the real *r* to the nearest integer, but round halfway cases
away from zero (see `round(3)`). If conversion fails, *fallback* will
be returned.

Examples::

	set req.http.integer = std.real2integer(1140618699.00, 0);
	set req.http.posone = real2integer( 0.5, 0);	# =  1.0
	set req.http.negone = real2integer(-0.5, 0);	# = -1.0

.. _std.real2time():

TIME real2time(REAL r, TIME fallback)
-------------------------------------

**DEPRECATED**: This function will be removed in a future version of
varnish, use `std.time()`_ with a *real* argument and the
`std.round()`_ function instead, for example::

	std.time(real=std.round(...), fallback=...)

Rounds the real *r* to the nearest integer (see
`std.real2integer()`_) and returns the corresponding time when
interpreted as a unix epoch. If conversion fails, *fallback* will be
returned.

Example::

	set req.http.time = std.real2time(1140618699.00, now);

.. _std.time2integer():

INT time2integer(TIME t, INT fallback)
--------------------------------------

**DEPRECATED**: This function will be removed in a future version of
varnish, use `std.integer()`_ with a *time* argument instead, for
example::

	std.integer(time=..., fallback=...)

Converts the time *t* to a integer. If conversion fails,
*fallback* will be returned.

Example::

	set req.http.int = std.time2integer(now, 0);

.. _std.time2real():

REAL time2real(TIME t, REAL fallback)
-------------------------------------

**DEPRECATED**: This function will be removed in a future version of
varnish, use `std.real()`_ with a *time* argument instead, for
example::

	std.real(time=..., fallback=...)

Converts the time *t* to a real. If conversion fails, *fallback* will
be returned.

Example::

	set req.http.real = std.time2real(now, 1.0);



SEE ALSO
========

* :ref:`varnishd(1)`
* :ref:`vsl(7)`
* `fnmatch(3)`

COPYRIGHT
=========

::

  Copyright (c) 2010-2017 Varnish Software AS
  All rights reserved.
 
  Author: Poul-Henning Kamp <phk@FreeBSD.org>
 
  SPDX-License-Identifier: BSD-2-Clause
 
  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions
  are met:
  1. Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.
  2. Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in the
     documentation and/or other materials provided with the distribution.
 
  THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE
  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
  OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
  HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
  OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
  SUCH DAMAGE.
