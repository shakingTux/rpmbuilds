..
.. NB:  This file is machine generated, DO NOT EDIT!
..
.. Edit ./vmod_debug.vcc and run make instead
..


:tocdepth: 1



.. _vmod_debug(3):

========================================
VMOD debug - Development, test and debug
========================================

SYNOPSIS
========

.. parsed-literal::

  import debug [as name] [from "path"]
  
  :ref:`debug.author()`
   
  :ref:`debug.test_priv_call()`
   
  :ref:`debug.test_priv_vcl()`
   
  :ref:`debug.test_priv_task()`
   
  :ref:`debug.test_priv_top()`
   
  :ref:`debug.obj()`
  
      :ref:`xobj.enum()`
  
      :ref:`xobj.string()`
  
      :ref:`xobj.number()`
  
      :ref:`xobj.foo()`
  
      :ref:`xobj.date()`
  
      :ref:`xobj.test_priv_call()`
  
      :ref:`xobj.test_priv_vcl()`
  
      :ref:`xobj.test_priv_task()`
  
      :ref:`xobj.test_priv_top()`
  
  :ref:`debug.rot52()`
   
  :ref:`debug.argtest()`
   
  :ref:`debug.vre_limit()`
   
  :ref:`debug.register_obj_events()`
   
  :ref:`debug.fail()`
   
  :ref:`debug.fail2()`
   
  :ref:`debug.dyn()`
  
      :ref:`xdyn.backend()`
  
      :ref:`xdyn.refresh()`
  
  :ref:`debug.dyn_uds()`
  
      :ref:`xdyn_uds.backend()`
  
      :ref:`xdyn_uds.refresh()`
  
  :ref:`debug.vcl_discard_delay()`
   
  :ref:`debug.match_acl()`
   
  :ref:`debug.test_probe()`
   
  :ref:`debug.vsc_new()`
   
  :ref:`debug.vsc_count()`
   
  :ref:`debug.vsc_destroy()`
   
  :ref:`debug.concat()`
  
      :ref:`xconcat.get()`
  
  :ref:`debug.concatenate()`
   
  :ref:`debug.collect()`
   
  :ref:`debug.sethdr()`
   
  :ref:`debug.priv_perf()`
   
  :ref:`debug.obj_opt()`
  
      :ref:`xobj_opt.meth_opt()`
  
  :ref:`debug.return_strands()`
   
  :ref:`debug.catflap()`
   
  :ref:`debug.stk()`
   
  :ref:`debug.vcl_prevent_cold()`
   
  :ref:`debug.vcl_allow_cold()`
   
  :ref:`debug.cold_backend()`
   
  :ref:`debug.cooling_backend()`
   
  :ref:`debug.sndbuf()`
   
  :ref:`debug.store_ip()`
   
  :ref:`debug.get_ip()`
   
  :ref:`debug.director()`
  
      :ref:`xdirector.fail()`
  
  :ref:`debug.client_ip()`
   
  :ref:`debug.client_port()`
   
  :ref:`debug.fail_rollback()`
   
  :ref:`debug.ok_rollback()`
   
  :ref:`debug.re_quote()`
   
  :ref:`debug.priv_task_with_option()`
   

DESCRIPTION
===========

This vmod is used to develop, test and debug the various aspects
of VMOD handling in Varnish.

.. _debug.author():

STRING author(ENUM person, ENUM someone)
----------------------------------------

::

   STRING author(
      ENUM {phk, des, kristian, mithrandir} person=phk,
      ENUM {phk, slink, geoff} someone=phk
   )

Test function for ENUM arguments

.. _debug.test_priv_call():

VOID test_priv_call()
---------------------

Test function for call private pointers

.. _debug.test_priv_vcl():

VOID test_priv_vcl()
--------------------

Test function for VCL private pointers

.. _debug.test_priv_task():

STRING test_priv_task(STRING s="")
----------------------------------

Test function for TASK private pointers

.. _debug.test_priv_top():

STRING test_priv_top(STRING)
----------------------------

Test function for TOP private pointers

.. _debug.obj():

new xobj = debug.obj(STRING string, ENUM number)
------------------------------------------------

::

   new xobj = debug.obj(
      STRING string="default",
      ENUM {one, two, three} number=one
   )

Test object

.. NOTE: .enum before .foo as part of test r01332.vtc

.. _xobj.enum():

VOID xobj.enum(ENUM)
--------------------

::

      VOID xobj.enum(ENUM {phk, des, kristian, mithrandir, martin})

Testing that enums work as part of object and that the parser isn't
(too) buggy.

.. _xobj.string():

STRING xobj.string()
--------------------

getter for string

.. _xobj.number():

STRING xobj.number()
--------------------

getter for number

.. _xobj.foo():

STRING xobj.foo(STRING why)
---------------------------

Foo indeed.

.. _xobj.date():

TIME xobj.date()
----------------

You never know when you need a date.

.. _xobj.test_priv_call():

VOID xobj.test_priv_call()
--------------------------

Test method for call private pointers

Objects share the ``PRIV_*`` state with other objects and methods from
the same vmod - IOW the ``PRIV_*`` state is per vmod, not per object.

.. _xobj.test_priv_vcl():

VOID xobj.test_priv_vcl()
-------------------------

Test method for VCL private pointers

Objects share the ``PRIV_*`` state with other objects and methods from
the same vmod - IOW the ``PRIV_*`` state is per vmod, not per object.

.. _xobj.test_priv_task():

STRING xobj.test_priv_task(STRING s="")
---------------------------------------

Test method for TASK private pointers

Objects share the ``PRIV_*`` state with other objects and methods from
the same vmod - IOW the ``PRIV_*`` state is per vmod, not per object.

.. _xobj.test_priv_top():

STRING xobj.test_priv_top(STRING)
---------------------------------



.. _debug.rot52():

VOID rot52(HTTP hdr)
--------------------

Encrypt the HTTP header with quad-ROT13 encryption,
(this is approx 33% better than triple-DES).

.. _debug.argtest():

STRING argtest(STRING one, REAL two, STRING three, STRING comma, INT four, [STRING opt])
----------------------------------------------------------------------------------------

::

   STRING argtest(
      STRING one,
      REAL two=2,
      STRING three="3",
      STRING comma=",",
      INT four=4,
      [STRING opt]
   )



.. _debug.vre_limit():

INT vre_limit()
---------------



.. _debug.register_obj_events():

VOID register_obj_events()
--------------------------

Register the vmod to receive expiry callbacks

.. _debug.fail():

VOID fail()
-----------

Function to fail vcl code.  (See also: RFC748)

.. _debug.fail2():

BOOL fail2()
------------

Function to fail vcl code. Always returns true.

.. _debug.dyn():

new xdyn = debug.dyn(STRING addr, STRING port, PROBE probe)
-----------------------------------------------------------

::

   new xdyn = debug.dyn(STRING addr, STRING port, PROBE probe=0)

Dynamically create a single-backend director, addr and port must not be empty.

.. _xdyn.backend():

BACKEND xdyn.backend()
----------------------

Return the dynamic backend.

.. _xdyn.refresh():

VOID xdyn.refresh(STRING addr, STRING port, PROBE probe=0)
----------------------------------------------------------

Dynamically refresh & (always!) replace the backend by a new one.

.. _debug.dyn_uds():

new xdyn_uds = debug.dyn_uds(STRING path)
-----------------------------------------

Dynamically create a single-backend director listening at a Unix
domain socket, path must not be empty.

.. _xdyn_uds.backend():

BACKEND xdyn_uds.backend()
--------------------------

Return the dynamic UDS backend.

.. _xdyn_uds.refresh():

VOID xdyn_uds.refresh(STRING path)
----------------------------------

Dynamically refresh & (always!) replace the backend by a new UDS backend.

.. _debug.vcl_discard_delay():

VOID vcl_discard_delay(DURATION)
--------------------------------

Hold a reference to the VCL when it goes cold preventing
discard for the given delay.

.. _debug.match_acl():

BOOL match_acl(ACL acl, IP ip)
------------------------------

Perform an IP match against a named ACL.

.. _debug.test_probe():

VOID test_probe(PROBE probe, PROBE same=0)
------------------------------------------

Only here to make sure probe definitions are passed properly.

.. _debug.vsc_new():

VOID vsc_new()
--------------

Add a vsc

.. _debug.vsc_count():

VOID vsc_count(INT val=1)
-------------------------

Update counter

.. _debug.vsc_destroy():

VOID vsc_destroy()
------------------

Remove a vsc

.. _debug.concat():

new xconcat = debug.concat(STRING)
----------------------------------

Create an object that returns the string formed by concatenating the
given strings.

.. _xconcat.get():

STRING xconcat.get()
--------------------

Return the string formed from the concatenation in the constructor.

.. _debug.concatenate():

STRING concatenate(STRING)
--------------------------

Return the string formed by concatenating the given strings.
(Uses ``VRT_StrandsWS()``.)

.. _debug.collect():

STRING collect(STRING)
----------------------

Return the string formed by concatenating the given strings.
(Uses ``VRT_CollectStrands()``.)

.. _debug.sethdr():

VOID sethdr(HEADER, STRING)
---------------------------

Set the given header with the concatenation of the given strings.

.. _debug.priv_perf():

DURATION priv_perf(INT size, INT rounds=10000)
----------------------------------------------

Benchmark ``VRT_priv_task()`` with `size` elements, iterating `rounds`
times.

Returns the average time taken for each call scaled up from
nanoseconds to seconds - iow the value given as seconds is actually
the duration in nanoseconds.

For comparable results, a higher size run should called first and
discarded.

.. _debug.obj_opt():

new xobj_opt = debug.obj_opt([STRING s], [BOOL b])
--------------------------------------------------

Test object constructor with all the fancy stuff.

.. _xobj_opt.meth_opt():

STRING xobj_opt.meth_opt([STRING s], [BOOL b])
----------------------------------------------

Test object method with all the fancy stuff.

.. _debug.return_strands():

STRING return_strands(STRING strand)
------------------------------------



.. _debug.catflap():

VOID catflap(ENUM {miss, first, last} type)
-------------------------------------------

Test the HSH_Lookup catflap

.. _debug.stk():

BYTES stk()
-----------

Return an approximation of the amount of stack used.

This function is by no means guaranteed to work cross platform and
should now only be used for diagnostic purposes.

0B is returned if no sensible value can be determined.

.. _debug.vcl_prevent_cold():

VOID vcl_prevent_cold()
-----------------------

Prevent VCL from going cold.

.. _debug.vcl_allow_cold():

VOID vcl_allow_cold()
---------------------

Allow VCL to go cold.

.. _debug.cold_backend():

VOID cold_backend()
-------------------

Schedule a backend creation attempt when the VCL is COLD, panic guaranteed.

.. _debug.cooling_backend():

VOID cooling_backend()
----------------------

Schedule a backend creation attempt when the VCL is COOLING, failure guaranteed.

.. _debug.sndbuf():

VOID sndbuf(BYTES sndbuf)
-------------------------

Set the client socket' send buffer size to *sndbuf*. The previous, desired
and actual values appear in the logs. Not currently implemented for backend
transactions.

.. _debug.store_ip():

VOID store_ip(IP)
-----------------

Store an IP address to be later found by ``debug.get_ip()`` in the same
transaction.

.. _debug.get_ip():

IP get_ip()
-----------

Get the IP address previously stored by ``debug.store_ip()`` in the same
transaction.

.. _debug.director():

new xdirector = debug.director()
--------------------------------



.. _xdirector.fail():

BACKEND xdirector.fail()
------------------------

Return a backend which fails in director context

.. _debug.client_ip():

STRING client_ip()
------------------

Get the stringified client ip from the session attr

.. _debug.client_port():

STRING client_port()
--------------------

Get the stringified client port from the session attr

.. _debug.fail_rollback():

VOID fail_rollback()
--------------------

fail any rollback before ok_rollback() is called

.. _debug.ok_rollback():

VOID ok_rollback()
------------------

Allow rollbacks. Must be called before the end of the task.

.. _debug.re_quote():

STRING re_quote(STRING)
-----------------------

Quote an input string to be usable for an exact match in a regular expression.

.. _debug.priv_task_with_option():

STRING priv_task_with_option([STRING opt])
------------------------------------------

A function mixing a named PRIV_TASK with optional parameters.

COPYRIGHT
=========

::

  Copyright (c) 2010-2019 Varnish Software AS
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
 
