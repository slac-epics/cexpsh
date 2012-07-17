#define _GNU_SOURCE
#include <cexp.h>
#include <dlfcn.h>
#include <stdlib.h>

int frce(void *a)
{
	return
		a == dlsym
	||  a == dladdr
	||  a == dlopen
	||  a == dlclose
	||  a == malloc
	;
}

int
main(int argc, char **argv)
{
	return cexp_main(argc, argv);
}
