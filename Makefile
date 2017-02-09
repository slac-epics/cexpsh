TOP = .
include $(TOP)/configure/CONFIG

DIRS += configure
DIRS += cexpSupApp
DIRS += cexpDemoApp

cexpDemoApp_DEPEND_DIRS = cexpSupApp

include $(TOP)/configure/RULES_TOP
