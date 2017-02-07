TOP = .
include $(TOP)/configure/CONFIG

DIRS += configure
DIRS += src
DIRS += demo

include $(TOP)/configure/RULES_TOP
