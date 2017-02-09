TOP=../..

include $(TOP)/configure/CONFIG

#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

# EXTERNAL NON EPICS PACKAGES: USER INCLUDES AND LIBRARIES
#=========================================================
USR_INCLUDES += -I$(CEXP_INCLUDE)



# PATH TO THE EXTERNAL LIBRARIES
# #===============================
cexp_DIR += $(CEXP_LIB)
pmbfd_DIR += $(CEXP_LIB)
pmelf_DIR += $(CEXP_LIB)
tecla_r_DIR += $(CEXP_LIB)
spencer_regexp_DIR += $(CEXP_LIB)
cexpSup_DIR += $(TOP)/lib


# LINK EXTERNAL LIBRARIES STATICALLY
#===================================
ifeq ($(HAS_CEXP), YES)
    USR_LIBS_Linux += cexp pmbfd pmelf tecla_r spencer_regexp
    USR_CPPFLAGS_Linux += -DHAVE_CEXP
endif



# ================================================
# Build the IOC application
# ================================================
# This will attempt to build an IOC application 
# for every target including the host computer.
# ================================================

PROD_IOC += cexpDemo

# <name>.dbd will be created from <name>Include.dbd
DBD	+= cexpDemo.dbd

cexpDemo_DBD += base.dbd

# cexpsh
cexpDemo_DBD += cexpSup.dbd

cexpDemo_SRCS         += cexpDemo_registerRecordDeviceDriver.cpp
cexpDemo_SRCS_DEFAULT += cexpDemoMain.c
cexpDemo_SRCS_RTEMS    = -nil-
cexpDemo_SRCS_vxWorks  = -nil-

cexpDemo_LIBS += cexpSup

cexpDemo_LIBS += $(EPICS_BASE_IOC_LIBS) 


# Install demo script only if
INSTALL_DEMO_SCRIPT_YES = cexpDemo.cmd
SCRIPTS_IOC += $(INSTALL_DEMO_SCRIPT_YES)

#===========================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

