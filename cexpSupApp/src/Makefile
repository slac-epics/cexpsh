TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================


# EXTERNAL NON EPICS PACKAGES: USER INCLUDES AND LIBRARIES
#=========================================================


#==================================================
# Build an IOC support library
#==================================================
# This will attempt to build an IOC support library
# for every target including the host computer.
#==================================================
LIBRARY+=cexpSup

# LINK EXTERNAL LIBRARIES
#===================================
ifeq ($(HAS_CEXP), YES)
    cexpSup_LIBS_Linux     += $(filter-out cexpSup,$(CEXP_LIBS))
    cexpSup_SYS_LIBS_Linux += $(CEXP_SYS_LIBS)
endif

# cexpSup.dbd will be created and installed
DBD+=cexpSup.dbd

cexpSup_SRCS += cexpSup.c

cexpSup_LIBS += $(EPICS_BASE_IOC_LIBS)


#==================================================

include $(TOP)/configure/RULES

