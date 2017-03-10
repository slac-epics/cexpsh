# Makefile

TOP=..

include $(TOP)/configure/CONFIG


# Set the following to NO to disable consistency checking of
# the support applications defined in $(TOP)/configure/RELEASE
CHECK_RELEASE = YES

CFG=CONFIG_CEXP

TARGETS = $(CONFIG_TARGETS)
CONFIGS += $(subst ../,,$(wildcard $(CONFIG_INSTALLS)))

CEXP_COMPAT:=$(shell grep -rl "CEXP_PACK" $(TOP)/configure/CONFIG_SITE* | rev | cut -d'.' -f1 | rev)

include $(TOP)/configure/RULES


$(INSTALL_CFG)/CONFIG_CEXP:$(INSTALL_CFG) $(TOP)/configure/CONFIG_CEXP.in
	$(RM) $@; \
 	sed -e "s/@VERS@/$(CEXP_VERSION)/" $(TOP)/configure/CONFIG_CEXP.in | sed -e "s/@COMPAT@/$(CEXP_COMPAT)/" > $@ ;
