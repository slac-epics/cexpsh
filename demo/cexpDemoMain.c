#define _GNU_SOURCE
#include <stdlib.h>
#include <iocsh.h>
#include <epicsThread.h>
#include <epicsExit.h>

#ifdef HAVE_CEXP
#include <cexp.h>
#endif

/* User can call cexpsh from iocsh; define USE_CEXP_MAIN
 * if you want the app to start out in cexpsh (you may call
 * iocsh from cexpsh, too).
 */
#undef USE_CEXP_MAIN

int
main(int argc, char **argv)
{

#if defined(HAVE_CEXP) && defined(USE_CEXP_MAIN)
	cexp_main(argc, argv); 
#else
	if ( argc >= 2 ) {
		iocsh( argv[1] );
		epicsThreadSleep( 0.2 );
	}
	iocsh( 0 );
#endif
	epicsExit( 0 );
	return 0;
}
