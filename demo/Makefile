TOP=..

include $(TOP)/configure/CONFIG

#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#USR_CFLAGS += 

PROD    = cexpDemo
# <name>.dbd will be created from <name>Include.dbd
DBD		= cexpDemo.dbd
# Install demo script only if
INSTALL_DEMO_SCRIPT_YES = cexpDemo.cmd
SCRIPTS_IOC += $(INSTALL_DEMO_SCRIPT_$(BUILD_CEXP))

cexpDemo_DBD = base.dbd $(CEXP_DBDS)

cexpDemo_SRCS         += cexpDemo_registerRecordDeviceDriver.cpp
cexpDemo_SRCS_DEFAULT += cexpDemoMain.c
cexpDemo_SRCS_RTEMS    = -nil-
cexpDemo_SRCS_vxWorks  = -nil-
cexpDemo_LIBS          = $(EPICS_BASE_IOC_LIBS) $(CEXP_LIBS)

#===========================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE
$(PROD): $(wildcard *,$(CEXP_DIR))
