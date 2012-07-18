# Makefile

TOP=..

include $(TOP)/configure/CONFIG

# Set the following to NO to disable consistency checking of
# the support applications defined in $(TOP)/configure/RELEASE
CHECK_RELEASE = YES

CFG=CONFIG_CEXP

TARGETS = $(CONFIG_TARGETS)
CONFIGS += $(subst ../,,$(wildcard $(CONFIG_INSTALLS)))


include $(TOP)/configure/RULES

$(INSTALL_CFG)/CONFIG_CEXP:$(INSTALL_CFG) $(TOP)/configure/CONFIG_CEXP.in
	$(RM) $@; \
	if [ -e $(TOP)/cexp/$(CEXP_VERS)/binutils ] ; then \
		sed -e 's/@OPCODES@/opcodes/' $(TOP)/configure/CONFIG_CEXP.in > $@ ; \
	else \
		sed -e 's/@OPCODES@//' $(TOP)/configure/CONFIG_CEXP.in > $@ ; \
	fi
