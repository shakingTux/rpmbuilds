..
.. NB:  This file is machine generated, DO NOT EDIT!
..
.. Edit ./vmod_proxy.vcc and run make instead
..

.. role:: ref(emphasis)


==========
vmod_proxy
==========

-----------------------------------------------------
Varnish Module to extract TLV attributes from PROXYv2
-----------------------------------------------------

:Manual section: 3

SYNOPSIS
========

.. parsed-literal::

  import proxy [as name] [from "path"]
  
  STRING alpn()
  
  STRING authority()
  
  BOOL is_ssl()
  
  BOOL client_has_cert_sess()
  
  BOOL client_has_cert_conn()
  
  INT ssl_verify_result()
  
  STRING ssl_version()
  
  STRING client_cert_cn()
  
  STRING ssl_cipher()
  
  STRING cert_sign()
  
  STRING cert_key()
  
DESCRIPTION
===========

*vmod_proxy* contains functions to extract proxy-protocol-v2 TLV
attributes as described in
https://www.haproxy.org/download/1.8/doc/proxy-protocol.txt.

.. _proxy.alpn():

STRING alpn()
-------------

Extract ALPN attribute.

Example::

	set req.http.alpn = proxy.alpn();

.. _proxy.authority():

STRING authority()
------------------

Extract authority attribute. This corresponds to SNI from a TLS
connection.

Example::

	set req.http.authority = proxy.authority();

.. _proxy.is_ssl():

BOOL is_ssl()
-------------

Report if proxy-protocol-v2 has SSL TLV.

Example::

	if (proxy.is_ssl()) {
		set req.http.ssl-version = proxy.ssl_version();
	}

.. _proxy.client_has_cert_sess():

BOOL client_has_cert_sess()
---------------------------

Report if the client provided a certificate at least once over the TLS
session this connection belongs to.

.. _proxy.client_has_cert_conn():

BOOL client_has_cert_conn()
---------------------------

Report if the client provided a certificate over the current
connection.

.. _proxy.ssl_verify_result():

INT ssl_verify_result()
-----------------------

Report the SSL_get_verify_result from a TLS session. It only matters
if client_has_cert_sess() is true. Per default, value is set to 0
(X509_V_OK).

Example::

	if (proxy.client_has_cert_sess() && proxy.ssl_verify_result() == 0) {
		set req.http.ssl-verify = "ok";
	}

.. _proxy.ssl_version():

STRING ssl_version()
--------------------

Extract SSL version attribute.

Example::

	set req.http.ssl-version = proxy.ssl_version();

.. _proxy.client_cert_cn():

STRING client_cert_cn()
-----------------------

Extract the common name attribute of the client certificate's.

Example::
	set req.http.cert-cn = proxy.client_cert_cn();

.. _proxy.ssl_cipher():

STRING ssl_cipher()
-------------------

Extract the SSL cipher attribute.

Example::

	set req.http.ssl-cipher = proxy.ssl_cipher();

.. _proxy.cert_sign():

STRING cert_sign()
------------------

Extract the certificate signature algorithm attribute.

Example::

	set req.http.cert-sign = proxy.cert_sign();

.. _proxy.cert_key():

STRING cert_key()
-----------------

Extract the certificate key algorithm attribute.

Example::

	set req.http.cert-key = proxy.cert_key();

SEE ALSO
========

* :ref:`varnishd(1)`
* :ref:`vsl(7)`

COPYRIGHT
=========

::

  Copyright (c) 2018 GANDI SAS
  All rights reserved.
 
  Author: Emmanuel Hocdet <manu@gandi.net>
 
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
