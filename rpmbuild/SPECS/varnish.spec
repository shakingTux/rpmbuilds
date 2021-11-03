Name:           varnish
Version:        6.5.2
Release:        1%{?dist}
Summary:	High-performance HTTP accelerator

License:        BSD
URL:            http://www.varnish-cache.org/
Source0:        %{name}-%{version}.tgz

Requires:	gcc
Requires:	logrotate
Requires:	ncurses
Requires:	pcre
Requires:	jemallock

BuildRequires:	python3-docutils
Packager:	Filip Snarski <snarskifilip@gmail.com>

%description
This is Varnish Cache, a high-performance HTTP accelerator.
Documentation wiki and additional information about Varnish is
available on the folowing web site: http://www.varnish-cache.org/

%prep
%setup -q -n %{name}-%{version}


%build
make clean
make TARGET=linux-glibc USE_PCRE=1 USE_PCRE_JIT=1 USE_THREAD=1 \
USE_GETADDRINFO=1 USE_OPENSSL=1 USE_LUA=1 USE_ZLIB=1 USE_PROMEX=1 USE_SYSTEMD=1 \



%install

%pre
getent group varnish >/dev/null || groupadd -r varnish
getent passwd varnish >/dev/null || useradd -r -g varnish -s /sbin/nologin \
	-c "Varnish user" -m -d %{buildroot}/%{_localstatedir}/lib/varnish varnish

%files
%dir /etc/varnish/
%dir %{_localstatedir}/lib/varnish
%config(noreplace) /etc/varnish/default.vcl
%{_unitdir}/%{name}.service
%{_sbindir}/%{name}
%{_mandir}/man1/*


%changelog
