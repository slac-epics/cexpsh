TOP=..

include $(TOP)/configure/CONFIG

#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

LIBNAM=$(LIB_PREFIX)cexp$(LIB_SUFFIX)
LIBTGT=lib/$(LIBNAM)

LIBRARY+=cexpSup

LIB_INSTALLS_YES+=$(LIBTGT)
LIB_INSTALLS_YES+=$(addprefix lib/$(LIB_PREFIX),$(addsuffix $(LIB_SUFFIX),$(CEXP_DEPLIBS)))

LIB_INSTALLS=$(LIB_INSTALLS_$(BUILD_CEXP))

INC_YES+=cexp.h
INC_YES+=cexpsyms.h
INC_YES+=ctyps.h
INC=$(INC_$(BUILD_CEXP))

DBD+=cexpSup.dbd

cexpSup_SRCS+=cexpSup.c

#==================================================
# Build an IOC support library

include $(TOP)/configure/RULES


ifdef CEXP_INCLUDE
	cexpSup_INCLUDES += -I$(CEXP_INCLUDE)
endif

