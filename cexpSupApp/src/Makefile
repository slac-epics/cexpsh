TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================


# EXTERNAL NON EPICS PACKAGES: USER INCLUDES AND LIBRARIES
#=========================================================
USR_INCLUDES += -I$(CEXP_INCLUDE)



# PATH TO THE EXTERNAL LIBRARIES
#===============================
cexp_DIR += $(CEXP_LIB)
pmbfd_DIR += $(CEXP_LIB)
pmelf_DIR += $(CEXP_LIB)
tecla_r_DIR += $(CEXP_LIB)
spencer_regexp_DIR += $(CEXP_LIB)



# LINK EXTERNAL LIBRARIES STATICALLY
#===================================
ifeq ($(HAS_CEXP), YES)
    USR_LIBS_Linux += cexp pmbfd pmelf tecla_r spencer_regexp
    USR_CPPFLAGS_Linux += -DHAVE_CEXP
endif



#==================================================
# Build an IOC support library
#==================================================
# This will attempt to build an IOC support library
# for every target including the host computer.
#==================================================
LIBRARY+=cexpSup

# cexpSup.dbd will be created and installed
DBD+=cexpSup.dbd

cexpSup_SRCS += cexpSup.c

cexpSup_LIBS += $(EPICS_BASE_IOC_LIBS)


#==================================================

include $(TOP)/configure/RULES

