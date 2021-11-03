-1

	Instead of presenting a continuously updated display, print the statistics to stdout.

-f <glob>

	Legacy field filtering glob. Use backslash to escape characters. If the argument starts with '^' it is used as an exclusive glob. Multiple -f arguments may be given. Legacy filtering globs are run along with inclusion globs (-I arguments) and exclusion globs (-X arguments) in order on a first-match basis.

-h

	Print program usage and exit

-I <glob>

	Field inclusion glob. Use backslash to escape characters. Multiple -I  arguments may be given. Exclusion globs are run in order along with exclusion globs (-X arguments) and legacy filtering globs (-f arguments) on a first-match basis.

-j

	Print statistics to stdout as JSON.

-l

	Lists the available fields to use with the -f option.

-n <dir>

	Specify the varnishd working directory (also known as instance name) to get logs from. If -n is not specified, the host name is used.

-t <seconds|off>

	Timeout before returning error on initial VSM connection. If set the VSM connection is retried every 0.5 seconds for this many seconds. If zero the connection is attempted only once and will fail immediately if unsuccessful. If set to "off", the connection will not fail, allowing the utility to start and wait indefinetely for the Varnish instance to appear.  Defaults to 5 seconds.

-V

	Print version information and exit.

-X <glob>

	Field exclusion glob. Use backslash to escape characters. Multiple -X  arguments may be given. Exclusion globs are run in order along with inclusion globs (-I arguments) and legacy filtering globs (-f arguments) on a first-match basis.

-x

	Print statistics to stdout as XML.

--optstring
	Print the optstring parameter to ``getopt(3)`` to help writing wrapper scripts.

