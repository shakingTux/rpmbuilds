..
.. NB:  This file is machine generated, DO NOT EDIT!
..
.. Edit ./vmod_directors.vcc and run make instead
..

.. role:: ref(emphasis)


==============
vmod_directors
==============

------------------------
Varnish Directors Module
------------------------

:Manual section: 3

SYNOPSIS
========

.. parsed-literal::

  import directors [as name] [from "path"]
  
  new xround_robin = directors.round_robin()
  
      VOID xround_robin.add_backend(BACKEND)
   
      VOID xround_robin.remove_backend(BACKEND)
   
      BACKEND xround_robin.backend()
   
  new xfallback = directors.fallback(BOOL sticky)
  
      VOID xfallback.add_backend(BACKEND)
   
      VOID xfallback.remove_backend(BACKEND)
   
      BACKEND xfallback.backend()
   
  new xrandom = directors.random()
  
      VOID xrandom.add_backend(BACKEND, REAL)
   
      VOID xrandom.remove_backend(BACKEND)
   
      BACKEND xrandom.backend()
   
  new xhash = directors.hash()
  
      VOID xhash.add_backend(BACKEND, REAL)
   
      VOID xhash.remove_backend(BACKEND)
   
      BACKEND xhash.backend(STRING)
   
  new xshard = directors.shard()
  
      VOID xshard.set_warmup(REAL probability)
   
      VOID xshard.set_rampup(DURATION duration)
   
      VOID xshard.associate(BLOB param)
   
      BOOL xshard.add_backend(BACKEND backend, [STRING ident], [DURATION rampup], [REAL weight])
   
      BOOL xshard.remove_backend([BACKEND backend], [STRING ident])
   
      BOOL xshard.clear()
   
      BOOL xshard.reconfigure(INT replicas)
   
      INT xshard.key(STRING)
   
      BACKEND xshard.backend([ENUM by], [INT key], [BLOB key_blob], [INT alt], [REAL warmup], [BOOL rampup], [ENUM healthy], [BLOB param], [ENUM resolve])
   
      VOID xshard.debug(INT)
   
  new xshard_param = directors.shard_param()
  
      VOID xshard_param.clear()
   
      VOID xshard_param.set([ENUM by], [INT key], [BLOB key_blob], [INT alt], [REAL warmup], [BOOL rampup], [ENUM healthy])
   
      STRING xshard_param.get_by()
   
      INT xshard_param.get_key()
   
      INT xshard_param.get_alt()
   
      REAL xshard_param.get_warmup()
   
      BOOL xshard_param.get_rampup()
   
      STRING xshard_param.get_healthy()
   
      BLOB xshard_param.use()
   
  BACKEND lookup(STRING)
  
DESCRIPTION
===========

*vmod_directors* enables backend load balancing in Varnish.

The module implements load balancing techniques, and also serves as an
example on how one could extend the load balancing capabilities of
Varnish.

To enable load balancing you must import this vmod (directors).

Then you define your backends. Once you have the backends declared you
can add them to a director. This happens in executed VCL code. If you
want to emulate the previous behavior of Varnish 3.0 you can just
initialize the directors in ``vcl_init{}``, like this::

    sub vcl_init {
	new vdir = directors.round_robin();
	vdir.add_backend(backend1);
	vdir.add_backend(backend2);
    }

As you can see there is nothing keeping you from manipulating the
directors elsewhere in VCL. So, you could have VCL code that would add
more backends to a director when a certain URL is called.

Note that directors can use other directors as backends.

.. _directors.round_robin():

new xround_robin = directors.round_robin()
------------------------------------------

Create a round robin director.

This director will pick backends in a round robin fashion.

Example::

	new vdir = directors.round_robin();

.. _xround_robin.add_backend():

VOID xround_robin.add_backend(BACKEND)
--------------------------------------

Add a backend to the round-robin director.

Example::

	vdir.add_backend(backend1);

.. _xround_robin.remove_backend():

VOID xround_robin.remove_backend(BACKEND)
-----------------------------------------

Remove a backend from the round-robin director.

Example::

	vdir.remove_backend(backend1);

.. _xround_robin.backend():

BACKEND xround_robin.backend()
------------------------------

Pick a backend from the director.

Example::

	set req.backend_hint = vdir.backend();

.. _directors.fallback():

new xfallback = directors.fallback(BOOL sticky=0)
-------------------------------------------------

Create a fallback director.

A fallback director will try each of the added backends in turn, and
return the first one that is healthy.

If *sticky* is set to ``true``, the director will keep using the
healthy backend, even if a higher-priority backend becomes
available. Once the whole backend list is exhausted, it'll start over
at the beginning.

Example::

	new vdir = directors.fallback();

.. _xfallback.add_backend():

VOID xfallback.add_backend(BACKEND)
-----------------------------------

Add a backend to the director.

Note that the order in which this is done matters for the fallback
director.

Example::

	vdir.add_backend(backend1);

.. _xfallback.remove_backend():

VOID xfallback.remove_backend(BACKEND)
--------------------------------------

Remove a backend from the director.

Example::

	vdir.remove_backend(backend1);

.. _xfallback.backend():

BACKEND xfallback.backend()
---------------------------

Pick a backend from the director.

Example::

	set req.backend_hint = vdir.backend();

.. _directors.random():

new xrandom = directors.random()
--------------------------------

Create a random backend director.

The random director distributes load over the backends using a
weighted random probability distribution.

The "testable" random generator in varnishd is used, which enables
deterministic tests to be run (See: ``d00004.vtc``).

Example::

	new vdir = directors.random();

.. _xrandom.add_backend():

VOID xrandom.add_backend(BACKEND, REAL)
---------------------------------------

Add a backend to the director with a given weight.

Each backend will receive approximately 100 * (weight /
(sum(all_added_weights))) per cent of the traffic sent to this
director.

Example::

	# 2/3 to backend1, 1/3 to backend2.
	vdir.add_backend(backend1, 10.0);
	vdir.add_backend(backend2, 5.0);

.. _xrandom.remove_backend():

VOID xrandom.remove_backend(BACKEND)
------------------------------------

Remove a backend from the director.

Example::

	vdir.remove_backend(backend1);

.. _xrandom.backend():

BACKEND xrandom.backend()
-------------------------

Pick a backend from the director.

Example::

	set req.backend_hint = vdir.backend();

.. _directors.hash():

new xhash = directors.hash()
----------------------------

Create a hashing backend director.

The director chooses the backend server by computing a hash/digest of
the string given to `xhash.backend()`_.

Commonly used with ``client.ip`` or a session cookie to get sticky
sessions.

Example::

	new vdir = directors.hash();

.. _xhash.add_backend():

VOID xhash.add_backend(BACKEND, REAL)
-------------------------------------

Add a backend to the director with a certain weight.

Weight is used as in the random director. Recommended value is 1.0
unless you have special needs.

Example::

	vdir.add_backend(backend1, 1.0);

.. _xhash.remove_backend():

VOID xhash.remove_backend(BACKEND)
----------------------------------

Remove a backend from the director.

Example::
	vdir.remove_backend(backend1);

.. _xhash.backend():

BACKEND xhash.backend(STRING)
-----------------------------

Pick a backend from the backend director.

Use the string or list of strings provided to pick the backend.

Example::
	# pick a backend based on the cookie header from the client
	set req.backend_hint = vdir.backend(req.http.cookie);

.. _directors.shard():

new xshard = directors.shard()
------------------------------

Create a shard director.

Note that the shard director needs to be configured using at least one
`xshard.add_backend()`_ call(s) **followed by a**
`xshard.reconfigure()`_ **call** before it can hand out
backends.

_Note_ that due to various restrictions (documented below), it is
recommended to use the shard director on the backend side.

Introduction
````````````

The shard director selects backends by a key, which can be provided
directly or derived from strings. For the same key, the shard director
will always return the same backend, unless the backend configuration
or health state changes. Conversely, for differing keys, the shard
director will likely choose different backends. In the default
configuration, unhealthy backends are not selected.

The shard director resembles the hash director, but its main advantage
is that, when the backend configuration or health states change, the
association of keys to backends remains as stable as possible.

In addition, the rampup and warmup features can help to further
improve user-perceived response times.

Sharding
````````

This basic technique allows for numerous applications like optimizing
backend server cache efficiency, Varnish clustering or persisting
sessions to servers without keeping any state, and, in particular,
without the need to synchronize state between nodes of a cluster of
Varnish servers:

* Many applications use caches for data objects, so, in a cluster of
  application servers, requesting similar objects from the same server
  may help to optimize efficiency of such caches.

  For example, sharding by URL or some *id* component of the url has
  been shown to drastically improve the efficiency of many content
  management systems.

* As special case of the previous example, in clusters of Varnish
  servers without additional request distribution logic, each cache
  will need store all hot objects, so the effective cache size is
  approximately the smallest cache size of any server in the cluster.

  Sharding allows to segregate objects within the cluster such that
  each object is only cached on one of the servers (or on one primary
  and one backup, on a primary for long and others for short
  etc...). Effectively, this will lead to a cache size in the order of
  the sum of all individual caches, with the potential to drastically
  increase efficiency (scales by the number of servers).

* Another application is to implement persistence of backend requests,
  such that all requests sharing a certain criterion (such as an IP
  address or session ID) get forwarded to the same backend server.

When used with clusters of varnish servers, the shard director will,
if otherwise configured equally, make the same decision on all
servers. In other words, requests sharing a common criterion used as
the shard key will be balanced onto the same backend server(s) no
matter which Varnish server handles the request.

The drawbacks are:

* the distribution of requests depends on the number of requests per
  key and the uniformity of the distribution of key values. In short,
  while this technique may lead to much better efficiency overall, it
  may also lead to less good load balancing for specific cases.

* When a backend server becomes unavailable, every persistence
  technique has to reselect a new backend server, but this technique
  will also switch back to the preferred server once it becomes
  healthy again, so when used for persistence, it is generally less
  stable compared to stateful techniques (which would continue to use
  a selected server for as long as possible (or dictated by a TTL)).

Method
``````

When `xshard.reconfigure()`_ is called, a consistent
hashing circular data structure gets built from the last 32 bits of
SHA256 hash values of *<ident>*\ *<n>* (default *ident* being the
backend name) for each backend and for a running number *n* from 1 to
*replicas*. Hashing creates the seemingly random order for placement
of backends on the consistent hashing ring. When
`xshard.add_backend()`_ was called with a *weight* argument,
*replicas* is scaled by that weight to add proportionally more copies
of the that backend on the ring.

When `xshard.backend()`_ is called, a load balancing key
gets generated unless provided. The smallest hash value in the circle
is looked up that is larger than the key (searching clockwise and
wrapping around as necessary). The backend for this hash value is the
preferred backend for the given key.

If a healthy backend is requested, the search is continued linearly on
the ring as long as backends found are unhealthy or all backends have
been checked. The order of these "alternative backends" on the ring is
likely to differ for different keys. Alternative backends can also be
selected explicitly.

On consistent hashing see:

* http://www8.org/w8-papers/2a-webserver/caching/paper2.html
* http://www.audioscrobbler.net/development/ketama/
* svn://svn.audioscrobbler.net/misc/ketama
* http://en.wikipedia.org/wiki/Consistent_hashing

Error Reporting
```````````````

Failing methods should report errors to VSL with the Error tag, so
when configuring the shard director, you are advised to check::

	varnishlog -I Error:^shard

.. _xshard.set_warmup():

VOID xshard.set_warmup(REAL probability=0.0)
--------------------------------------------

Set the default warmup probability. See the *warmup* parameter of
`xshard.backend()`_. If *probability* is 0.0 (default),
warmup is disabled.

.. _xshard.set_rampup():

VOID xshard.set_rampup(DURATION duration=0)
-------------------------------------------

Set the default rampup duration. See *rampup* parameter of
`xshard.backend()`_. If *duration* is 0 (default), rampup
is disabled.

.. _xshard.associate():

VOID xshard.associate(BLOB param=0)
-----------------------------------

Associate a default `directors.shard_param()`_ object or clear an
association.

The value of the *param* argument must be a call to the
`xshard_param.use()`_ method. No argument clears the
association.

The association can be changed per backend request using the *param*
argument of `xshard.backend()`_.

.. _xshard.add_backend():

BOOL xshard.add_backend(BACKEND backend, [STRING ident], [DURATION rampup], [REAL weight])
------------------------------------------------------------------------------------------

::

      BOOL xshard.add_backend(
            BACKEND backend,
            [STRING ident],
            [DURATION rampup],
            [REAL weight]
      )

Add a backend *backend* to the director.

*ident*: Optionally specify an identification string for this backend,
which will be hashed by `xshard.reconfigure()`_ to
construct the consistent hashing ring. The identification string
defaults to the backend name.

*ident* allows to add multiple instances of the same backend.

*rampup*: Optionally specify a specific rampup time for this
backend. Otherwise, the per-director rampup time is used (see
`xshard.set_rampup()`_).

*weight*: Optionally specify a weight to scale the
`xshard.reconfigure()`_ *replicas* parameter. *weight* is limited to
at least 1. Values above 10 probably do not make much sense. The
effect of *weight* is also capped such that the total number of
replicas does not exceed `UINT32_MAX`.

NOTE: Backend changes need to be finalized with
`xshard.reconfigure()`_ and are only supported on one
shard director at a time.

.. _xshard.remove_backend():

BOOL xshard.remove_backend([BACKEND backend], [STRING ident])
-------------------------------------------------------------

::

      BOOL xshard.remove_backend(
            [BACKEND backend=0],
            [STRING ident=0]
      )

Remove backend(s) from the director. Either *backend* or *ident* must
be specified. *ident* removes a specific instance. If *backend* is
given without *ident*, all instances of this backend are removed.

NOTE: Backend changes need to be finalized with
`xshard.reconfigure()`_ and are only supported on one
shard director at a time.

.. _xshard.clear():

BOOL xshard.clear()
-------------------

Remove all backends from the director.

NOTE: Backend changes need to be finalized with
`xshard.reconfigure()`_ and are only supported on one
shard director at a time.

.. _xshard.reconfigure():

BOOL xshard.reconfigure(INT replicas=67)
----------------------------------------

Reconfigure the consistent hashing ring to reflect backend changes.

This method must be called at least once before the director can be
used.

.. _xshard.key():

INT xshard.key(STRING)
----------------------

Convenience method to generate a sharding key for use with the *key*
argument to the `xshard.backend()`_ method by hashing the
given string with SHA256.

To generate sharding keys using other hashes, use a custom vmod like
`vmod blobdigest`_ with the *key_blob* argument of the
`xshard.backend()`_ method.

.. _vmod blobdigest: https://code.uplex.de/uplex-varnish/libvmod-blobdigest/blob/master/README.rst

.. _xshard.backend():

BACKEND xshard.backend([ENUM by], [INT key], [BLOB key_blob], [INT alt], [REAL warmup], [BOOL rampup], [ENUM healthy], [BLOB param], [ENUM resolve])
----------------------------------------------------------------------------------------------------------------------------------------------------

::

      BACKEND xshard.backend(
            [ENUM {HASH, URL, KEY, BLOB} by=HASH],
            [INT key],
            [BLOB key_blob],
            [INT alt=0],
            [REAL warmup=-1],
            [BOOL rampup=1],
            [ENUM {CHOSEN, IGNORE, ALL} healthy=CHOSEN],
            [BLOB param],
            [ENUM {NOW, LAZY} resolve]
      )

Lookup a backend on the consistent hashing ring.

This documentation uses the notion of an order of backends for a
particular shard key. This order is deterministic but seemingly random
as determined by the consistent hashing algorithm and is likely to
differ for different keys, depending on the number of backends and the
number of replicas. In particular, the backend order referred to here
is _not_ the order given when backends are added.

* *by* how to determine the sharding key

  * ``HASH``:

    * when called in backend context and in ``vcl_pipe {}``: Use the
      varnish hash value as set by ``vcl_hash{}``

    * when called in client context other than ``vcl_pipe {}``: hash
      ``req.url``

  * ``URL``: hash req.url / bereq.url

  * ``KEY``: use the *key* argument

  * ``BLOB``: use the *key_blob* argument

* *key* lookup key with ``by=KEY``

  the `xshard.key()`_ method may come handy to generate a
  sharding key from custom strings.

* *key_blob* lookup key with ``by=BLOB``

  Currently, this uses the first 4 bytes from the given blob in
  network byte order (big endian), left-padded with zeros for blobs
  smaller than 4 bytes.

* *alt* alternative backend selection

  Select the *alt*-th alternative backend for the given *key*.

  This is particularly useful for retries / restarts due to backend
  errors: By setting ``alt=req.restarts`` or ``alt=bereq.retries`` with
  healthy=ALL, another server gets selected.

  The rampup and warmup features are only active for ``alt==0``

* *rampup* slow start for servers which just went healthy

  If ``alt==0`` and the chosen backend is in its rampup period, with a
  probability proportional to the fraction of time since the backup
  became healthy to the rampup period, return the next alternative
  backend, unless this is also in its rampup period.

  The default rampup interval can be set per shard director using the
  `xshard.set_rampup()`_ method or specifically per
  backend with the `xshard.add_backend()`_ method.

* *warmup* probabilistic alternative server selection

  possible values: -1, 0..1

  ``-1``: use the warmup probability from the director definition

  Only used for ``alt==0``: Sets the ratio of requests (0.0 to 1.0)
  that goes to the next alternate backend to warm it up when the
  preferred backend is healthy. Not active if any of the preferred or
  alternative backend are in rampup.

  ``warmup=0.5`` is a convenient way to spread the load for each key
  over two backends under normal operating conditions.

* *healthy*

  * CHOSEN: Return a healthy backend if possible.

    For ``alt==0``, return the first healthy backend or none.

    For ``alt > 0``, ignore the health state of backends skipped for
    alternative backend selection, then return the next healthy
    backend. If this does not exist, return the last healthy backend
    of those skipped or none.

  * IGNORE: Completely ignore backend health state

    Just return the first or *alt*-th alternative backend, ignoring
    health state, *rampup* and *warmup*.

  * ALL: Check health state also for alternative backend selection

    For ``alt > 0``, return the *alt*-th alternative backend of all
    those healthy, the last healthy backend found or none.

* *resolve*

  default: ``LAZY`` in ``vcl_init{}``, ``NOW`` otherwise

  * ``NOW``: look up a backend and return it.

    Can not be used in ``vcl_init{}``.

  * ``LAZY``: return an instance of this director for later backend resolution.

    ``LAZY`` mode is required for referencing shard director instances,
    for example as backends for other directors (director layering).

    In ``vcl_init{}`` and on the client side, ``LAZY`` mode can not be
    used with any other argument.

    On the backend side and in ``vcl_pipe {}``, parameters from
    arguments or an associated parameter set affect the shard director
    instance for the backend request irrespective of where it is
    referenced.

* *param*

  Use or associate a parameter set. The value of the *param* argument
  must be a call to the `xshard_param.use()`_ method.

  default: as set by `xshard.associate()`_ or unset.

  * for ``resolve=NOW`` take parameter defaults from the
    `directors.shard_param()`_ parameter set

  * for ``resolve=LAZY`` associate the `directors.shard_param()`_
    parameter set for this backend request

    Implementation notes for use of parameter sets with
    ``resolve=LAZY``:

    * A *param* argument remains associated and any changes to the
      associated parameter set affect the sharding decision once the
      director resolves to an actual backend.

    * If other parameter arguments are also given, they have
      preference and are kept even if the parameter set given by the
      *param* argument is subsequently changed within the same backend
      request.

    * Each call to `xshard.backend()`_ overrides any
      previous call.

.. _xshard.debug():

VOID xshard.debug(INT)
----------------------

*intentionally undocumented*

.. _directors.shard_param():

new xshard_param = directors.shard_param()
------------------------------------------

Create a shard parameter set.

A parameter set allows for re-use of `xshard.backend()`_
arguments across many shard director instances and simplifies advanced
use cases (e.g. shard director with custom parameters layered below
other directors).

Parameter sets have two scopes:

* per-VCL scope defined in ``vcl_init{}``
* per backend request scope

The per-VCL scope defines defaults for the per backend scope. Any
changes to a parameter set in backend context and in ``vcl_pipe {}``
only affect the respective backend request.

Parameter sets can not be used in client context except for
``vcl_pipe {}``.

The following example is a typical use case: A parameter set is
associated with several directors. Director choice happens on the
client side and parameters are changed on the backend side to
implement retries on alternative backends::

  sub vcl_init {
    new shard_param = directors.shard_param();

    new dir_A = directors.shard();
    dir_A.add_backend(...);
    dir_A.reconfigure(shard_param);
    dir_A.associate(shard_param.use());	# <-- !

    new dir_B = directors.shard();
    dir_B.add_backend(...);
    dir_B.reconfigure(shard_param);
    dir_B.associate(shard_param.use());	# <-- !
  }

  sub vcl_recv {
    if (...) {
      set req.backend_hint = dir_A.backend(resolve=LAZY);
    } else {
      set req.backend_hint = dir_B.backend(resolve=LAZY);
    }
  }

  sub vcl_backend_fetch {
    # changes dir_A and dir_B behaviour
    shard_param.set(alt=bereq.retries);
  }

.. _xshard_param.clear():

VOID xshard_param.clear()
-------------------------

Reset the parameter set to default values as documented for
`xshard.backend()`_.

* in ``vcl_init{}``, resets the parameter set default for this VCL in
* backend context and in ``vcl_pipe {}``, resets the parameter set for
  this backend request to the VCL defaults

This method may not be used in client context other than ``vcl_pipe {}``.

.. _xshard_param.set():

VOID xshard_param.set([ENUM by], [INT key], [BLOB key_blob], [INT alt], [REAL warmup], [BOOL rampup], [ENUM healthy])
---------------------------------------------------------------------------------------------------------------------

::

      VOID xshard_param.set(
            [ENUM {HASH, URL, KEY, BLOB} by],
            [INT key],
            [BLOB key_blob],
            [INT alt],
            [REAL warmup],
            [BOOL rampup],
            [ENUM {CHOSEN, IGNORE, ALL} healthy]
      )

Change the given parameters of a parameter set as documented for
`xshard.backend()`_.

* in ``vcl_init{}``, changes the parameter set default for this VCL

* in backend context and in ``vcl_pipe {}``, changes the parameter set
  for this backend request, keeping the defaults set for this VCL for
  unspecified arguments.

This method may not be used in client context other than ``vcl_pipe {}``.

.. _xshard_param.get_by():

STRING xshard_param.get_by()
----------------------------

Get a string representation of the *by* enum argument which denotes
how a shard director using this parameter object would derive the
shard key. See `xshard.backend()`_.

.. _xshard_param.get_key():

INT xshard_param.get_key()
--------------------------

Get the key which a shard director using this parameter object would
use. See `xshard.backend()`_.

.. _xshard_param.get_alt():

INT xshard_param.get_alt()
--------------------------

Get the *alt* parameter which a shard director using this parameter
object would use. See `xshard.backend()`_.

.. _xshard_param.get_warmup():

REAL xshard_param.get_warmup()
------------------------------

Get the *warmup* parameter which a shard director using this parameter
object would use. See `xshard.backend()`_.

.. _xshard_param.get_rampup():

BOOL xshard_param.get_rampup()
------------------------------

Get the *rampup* parameter which a shard director using this parameter
object would use. See `xshard.backend()`_.

.. _xshard_param.get_healthy():

STRING xshard_param.get_healthy()
---------------------------------

Get a string representation of the *healthy* enum argument which a
shard director using this parameter object would use. See
`xshard.backend()`_.

.. _xshard_param.use():

BLOB xshard_param.use()
-----------------------

This method may only be used in backend context and in ``vcl_pipe {}``.

For use with the *param* argument of `xshard.backend()`_
to associate this shard parameter set with a shard director.

.. _directors.lookup():

BACKEND lookup(STRING)
----------------------

Lookup a backend by its name.

This function can only be used from ``vcl_init{}`` and  ``vcl_fini{}``.

ACKNOWLEDGEMENTS
================

Development of a previous version of the shard director was partly
sponsored by Deutsche Telekom AG - Products & Innovation.

Development of a previous version of the shard director was partly
sponsored by BILD GmbH & Co KG.

COPYRIGHT
=========

::

  This document is licensed under the same licence as Varnish
  itself. See LICENCE for details.
 
  Copyright (c) 2013-2015 Varnish Software AS
  Copyright 2009-2018 UPLEX - Nils Goroll Systemoptimierung
  All rights reserved.
 
  Authors: Poul-Henning Kamp <phk@FreeBSD.org>
 	   Julian Wiesener <jw@uplex.de>
 	   Nils Goroll <slink@uplex.de>
 	   Geoffrey Simmons <geoff@uplex.de>
 
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
