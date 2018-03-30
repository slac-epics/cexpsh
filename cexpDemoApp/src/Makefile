TOP=../..

include $(TOP)/configure/CONFIG

#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

# ================================================
# Build the IOC application
# ================================================
# This will attempt to build an IOC application 
# for every target including the host computer.
# ================================================

PROD_IOC += cexpDemo

# <name>.dbd will be created from <name>Include.dbd
DBD	+= cexpDemo.dbd

cexpDemo_DBD += base.dbd $(CEXP_DBDS)

cexpDemo_SRCS         += cexpDemo_registerRecordDeviceDriver.cpp
cexpDemo_SRCS_DEFAULT += cexpDemoMain.c
cexpDemo_SRCS_RTEMS    = -nil-
cexpDemo_SRCS_vxWorks  = -nil-

cexpDemo_LIBS     += $(CEXP_LIBS)
cexpDemo_SYS_LIBS += $(CEXP_SYS_LIBS)

cexpDemo_LIBS     += $(EPICS_BASE_IOC_LIBS)


# Install demo script only if
INSTALL_DEMO_SCRIPT_YES = cexpDemo.cmd
SCRIPTS_IOC += $(INSTALL_DEMO_SCRIPT_YES)

#===========================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

