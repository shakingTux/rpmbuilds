Name:           haproxy
Version:        2.4.6
Release:        1%{?dist}
Summary:        TCP/HTTP proxy and load balancer for high availability environments

License:        GPLv2+
URL:            http://www.haproxy.org/
Source0:        %{name}-%{version}.tar.gz
Source1:	haproxy.service
Source2:	haproxy.cfg
Source3:	haproxy.logrotate

BuildRequires:  lua53-devel
BuildRequires:	systemd-devel
BuildRequires:	pcre-devel
BuildRequires:	openssl-devel
BuildRequires:	gcc
BuildRequires:	make
BuildRequires:	zlib-devel

Provides:	haproxy-2.4.6
Packager:	Filip Snarski <snarskifilip@gmail.com>

%description
HAProxy is a TCP/HTTP reverse proxy which is particularly suited for high
availability environments. Indeed, it can:
 - route HTTP requests depending on statically assigned cookies
 - spread load among several servers while assuring server persistence
   through the use of HTTP cookies
 - switch to backup servers in the event a main server fails
 - accept connections to special ports dedicated to service monitoring
 - stop accepting connections without breaking existing ones
 - add, modify, and delete HTTP headers in both directions
 - block requests matching particular patterns
 - report detailed status to authenticated users from a URI
   intercepted by the application

%prep
%setup -q -n %{name}-2.4.6


%build
make clean
make TARGET=linux-glibc USE_PCRE=1 USE_PCRE_JIT=1 USE_THREAD=1 \
USE_GETADDRINFO=1 USE_OPENSSL=1 USE_LUA=1 USE_ZLIB=1 USE_PROMEX=1 USE_SYSTEMD=1 \



%install
#rm -rf $RPM_BUILD_ROOT
%{__make} install-bin DESTDIR=%{buildroot} PREFIX=%{_prefix}
%{__make} install-man DESTDIR=%{buildroot} PREFIX=%{_prefix}

%{__install} -p -D -m 0644 %{SOURCE1} %{buildroot}%{_unitdir}/%{name}.service
%{__install} -p -D -m 0644 %{SOURCE2} %{buildroot}%{_sysconfdir}/haproxy/%{name}.cfg
%{__install} -p -D -m 0644 %{SOURCE3} %{buildroot}%{_sysconfdir}/logrotate.d/%{name}

%{__install} -d -m 0755 %{buildroot}%{_localstatedir}/lib/haproxy

%pre
getent group haproxy >/dev/null || groupadd -r haproxy
getent passwd haproxy >/dev/null || useradd -r -g haproxy -s /sbin/nologin \
	-c "Haproxy user" -m -d %{buildroot}/%{_localstatedir}/lib/haproxy haproxy

%files
%dir /etc/haproxy/
%dir %{_localstatedir}/lib/haproxy
%config(noreplace) /etc/haproxy/%{name}.cfg
%config(noreplace) %{_sysconfdir}/logrotate.d/%{name}
%{_unitdir}/%{name}.service
%{_sbindir}/%{name}
%{_mandir}/man1/*


%changelog
