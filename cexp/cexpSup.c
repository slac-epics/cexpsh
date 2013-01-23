#include <epicsExport.h>

#ifdef HAVE_CEXP
#include <iocsh.h>
#include <cexp.h>
#include <stdio.h>
#ifdef __linux__
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#endif
#endif

#ifdef HAVE_CEXP

static void
wrap_cexp_help_call(const iocshArgBuf *args)
{
	cexpsh("-h",0);
	cexpsh("-ic","cexpsh.help()",0);
}

static void
wrap_cexp_call(const iocshArgBuf *args)
{
char *new_args[args->aval.ac+1];
int  i;

	/* copy argument list (moved one up)) */
	for ( i=0; i<args->aval.ac; i++ )
		new_args[i+1] = args->aval.av[i];

	i=0;
	if ( args->aval.ac > 0 ) {
		new_args[0]=new_args[1];
		i++;
	}
	/* add '-i' argument so that this interpreter does not become interactive */
	new_args[i]="-i";

	cexp_main(args->aval.ac+1, new_args);
}

static const iocshArg cexp_argv = {
	"args",
	iocshArgArgv
};

static const iocshArg *cexp_argv_bloat[] = {
	&cexp_argv
};

static iocshFuncDef cexp_call_def = {
	"cexpsh",
	sizeof(cexp_argv_bloat)/sizeof(cexp_argv_bloat[0]),
	cexp_argv_bloat
};

static iocshFuncDef cexp_help_call_def = {
	"cexpsh.help",
	0,
	0
};
#endif

static void
cexpRegistrar()
{
#ifdef HAVE_CEXP

char *symfile = 0, *strbuf = 0;

	if ( ! cexpSystemModule ) {

		/* let cexp load the symbol table. This can fall-back to argv[0] but
		 * argv[0] is just 'cexpsh' in our case (see above).
		 * Unfortunately there is no easy way to find the current executable
		 * path in an OSI way:
		 *

		 mark4o's answer here helps:

http://stackoverflow.com/questions/1023306/finding-current-executables-path-without-proc-self-exe

Some OS-specific interfaces:

Mac OS X: _NSGetExecutablePath() (man 3 dyld)
Linux: readlink /proc/self/exe
Solaris: getexecname()
FreeBSD: sysctl CTL_KERN KERN_PROC KERN_PROC_PATHNAME -1
BSD with procfs: readlink /proc/curproc/file
Windows: GetModuleFileName() with hModule = NULL

Some shells, including bash and ksh, set the environment
variable "_" to the full path of the executable

		 */

#ifdef __linux__
		{
		struct stat sb;
		int         got;

			if ( lstat("/proc/self/exe",&sb) ) {
				perror("lstat(/proc/self/exe) failed");
			} else {
				/* some linux is buggy... */
				if ( 0 == sb.st_size )
					sb.st_size = PATH_MAX;
				if ( ! (strbuf = malloc(sb.st_size + 1)) ) {
					perror("no memory for symbol file path");
				} else {
					if ( (got = readlink("/proc/self/exe", strbuf, sb.st_size)) < 0 ) {
						perror("readlink(/proc/self/exe failed)");
					} else {
						symfile      = strbuf;
						symfile[got] = 0;
					}
				}
			}
		}
#endif

		if ( ! symfile ) {
			symfile = getenv("_");
		}

		if ( symfile ) {
			cexpInit( 0 );
			if ( ! cexpModuleLoad( symfile, "SYSTEM" ) ) {
				fprintf(stderr,"cexpsh: Unable to load symbol table from executable - try to use '-s' argument\n");
			}
		}
	}

	free(strbuf);

	iocshRegister( &cexp_call_def,      wrap_cexp_call      );
	iocshRegister( &cexp_help_call_def, wrap_cexp_help_call );
#endif
}

epicsExportRegistrar(cexpRegistrar);
