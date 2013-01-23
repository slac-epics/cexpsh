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

TARGETS_IOC_YES=build/Makefile $(LIBTGT)
TARGETS_IOC=$(TARGETS_IOC_$(BUILD_CEXP))

CEXP_CONFIG_ARGS_CROSS=--host=$(GNU_TARGET)
CEXP_CONFIG_ARGS_Linux+=--enable-pthreads

CEXP_CONFIG_ARGS= $(CEXP_CONFIG_ARGS_$(BUILD_CLASS)) CC=$(CC)
CEXP_CONFIG_ARGS+= --prefix=`pwd`/../
# We don't want to mess with curses/terminfo etc.
CEXP_CONFIG_ARGS+= --enable-ansiterm
# let cexp fall into interactive mode after processing a script
CEXP_CONFIG_ARGS+= --enable-interactive-default
CEXP_CONFIG_ARGS+= --disable-loader
# binutils (for disassembler) do not compile cleanly as of 2.21 :-(
CEXP_CONFIG_ARGS+= --disable-werror
CEXP_CONFIG_ARGS+=$(CEXP_CONFIG_ARGS_$(OS_CLASS))

#==================================================
# Build an IOC support library

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE
#
$(CEXP_SRCDIR)/cexp.h:
	$(error "CEXP sources not found; install 'cexp' sources in '$(subst ../,,$(CEXP_SRCDIR))' dir")

build/Makefile: $(CEXP_SRCDIR)/cexp.h
	if ! [ -d build ] ; then mkdir build ; fi
	cd build ; export PATH=$(GNU_DIR)/bin:$$PATH; ../$(CEXP_SRCDIR)/configure $(CEXP_CONFIG_ARGS)

$(LIBTGT): build/Makefile buildcexp

.PHONY : buildcexp

buildcexp:
	export PATH=$(GNU_DIR)/bin:$$PATH; $(MAKE) -C build install

../O.Common/%.h: $(CEXP_SRCDIR)/%.h
	ln -s $^ $@

dump-vars:
	echo $(OS_CLASS)
	echo $(BUILD_CEXP)
	echo $(LIBTGT)
	echo $(INC)
	echo $(LIBRARY)
	echo $(CEXP_CONFIG_ARGS)
