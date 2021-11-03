.. _install-src:

Compiling Varnish from source
=============================

If there are no binary packages available for your system, or if you
want to compile Varnish from source for other reasons, follow these
steps:

Getting hold of the source
--------------------------

Download the appropriate release tarball, which you can find on
https://varnish-cache.org/releases/ .

Alternatively, if you want to hack on Varnish, you should clone our
git repository by doing.

      ``git clone https://github.com/varnishcache/varnish-cache``

Build dependencies on FreeBSD
-----------------------------

To get the dependencies required to build varnish from source
you can either::

	pkg install automake pkgconf py36-sphinx py36-docutils pcre libtool

.. XXX does cpio need to be installed on FreeBSD?

And optionally, to be able to run all the testcases::

	pkg install haproxy nghttp2 vttest

Or if you want the built from sources::

	cd /usr/ports/www/varnish6
	make depends clean

Then continue `Compiling Varnish`_

Build dependencies on Debian / Ubuntu
--------------------------------------

..  grep-dctrl -n -sBuild-Depends -r ^ ../../../../varnish-cache-debian/control | tr -d '\n' | awk -F,\  '{ for (i = 0; ++i <= NF;) { sub (/ .*/, "", $i); print "* `" $i "`"; }}' | egrep -v '(debhelper)'

In order to build Varnish from source you need a number of packages
installed. On a Debian or Ubuntu system, use this command to install
them (replace ``sudo apt-get install`` if needed)::

    sudo apt-get install \
	make \
	automake \
	autotools-dev \
	libedit-dev \
	libjemalloc-dev \
	libncurses-dev \
	libpcre3-dev \
	libtool \
	pkg-config \
	python3-docutils \
	python3-sphinx \
	cpio

Optionally, to rebuild the svg files::

    sudo apt-get install graphviz

Recommended, in particular if you plan on building custom vmods::

    sudo apt-get install autoconf-archive

Optionally, to pull from a repository::

    sudo apt-get install git

Then continue `Compiling Varnish`_

Build dependencies on Red Hat / CentOS
--------------------------------------

.. gawk '/^BuildRequires/ {print "* `" $2 "`"}' ../../../redhat/varnish.spec | sort | uniq | egrep -v '(systemd)'

in the following shell commands, replace ``sudo yum install`` if needed.

Install sphinx

* On Red Hat / CentOS 8, sphinx is not included in the default
  repositories, so execute these steps to include it from the
  PowerTools repository::

    sudo dnf install -y 'dnf-command(config-manager)'
    sudo yum config-manager --set-enabled PowerTools
    sudo yum install -y diffutils python3-sphinx

* On Red Hat / CentOS <= 7, install sphinx::

    sudo yum install -y python-sphinx

The following step should conclude installation of the required
packages::

  yum install -y \
	make \
	autoconf \
	automake \
	jemalloc-devel \
	libedit-devel \
	libtool \
	libunwind-devel \
	ncurses-devel \
	pcre-devel \
	pkgconfig \
	python3-docutils \
	cpio

Optionally, to rebuild the svg files::

    yum install graphviz

Optionally, to pull from a repository::

    yum install git

.. XXX autoconf-archive ? is this any helpful on the notoriously
   outdated Redhats?

Then continue `Compiling Varnish`_

Build dependencies on MacOS
---------------------------

To compile varnish on MacOS, these steps should install the required
dependencies:

* Install ``xcode`` via the App Store

* Install dependencies via `brew`::

    brew install \
	autoconf \
	automake \
	pkg-config \
	libtool \
	docutils \
	sphinx-doc

* Add sphinx to PATH as advised by the installer::

    PATH="/usr/local/opt/sphinx-doc/bin:$PATH"

Then continue `Compiling Varnish`_

Build dependencies on a SmartOS Zone
------------------------------------

As of SmartOS pkgsrc 2017Q1, install the following packages::

	pkgin in autoconf automake libedit libtool ncurses \
		 pcre py27-sphinx python27 gmake gcc49 pkg-config

Optionally, to rebuild the svg files::

	pkgin in graphviz

Optionally, to pull from a repository::

	pkgin in git

Building on Solaris and other Solaris-ish OSes
----------------------------------------------

Building with gcc should be straight forward, as long as the above
requirements are installed.

By convention, consider installing Varnish under `/opt/local` using::

	./configure \
	        --prefix=/opt/local \
	        --mandir=/opt/local/man

Alternatively, building with Solaris Studio 12.4 should work
considering the following recommendations:

* have GNU `nm` in `$PATH` before Solaris `nm`
* Provide compiler flags for `configure` to include paths under which
  dependencies are installed. Example for `/opt/local`::

	./configure \
	        --prefix=/opt/local \
	        --mandir=/opt/local/man \
	        CPPFLAGS="-I/opt/local/include" \
	        CFLAGS="-m64" \
	        LDFLAGS="-L/opt/local/lib -R/opt/local/lib"

Compiling Varnish
-----------------

The configuration will need the dependencies above satisfied. Once that is
taken care of::

	cd varnish-cache
	sh autogen.sh
	sh configure
	make

The `configure` script takes some arguments, but more likely than not you can
forget about that for now, almost everything in Varnish can be tweaked with run
time parameters.

Before you install, you may want to run the test suite, make a cup of
tea while it runs, it usually takes a couple of minutes::

	make check

Don't worry if one or two tests fail. Some of the tests are a
bit too timing sensitive (Please tell us which so we can fix them).
However, if a lot of them fail, and in particular if the `b00000.vtc` test
fails, something is horribly wrong. You will get nowhere without
figuring this one out.

Installing
----------

And finally, the true test of a brave heart: ``sudo make install``

Varnish will now be installed in ``/usr/local``. The ``varnishd`` binary is in
`/usr/local/sbin/varnishd`. To make sure that the necessary links and caches
of the most recent shared libraries are found, run ``sudo ldconfig``.
