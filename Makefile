CPUS=$(shell cat /proc/cpuinfo | grep "processor" | wc -l)

define shcmd-make
	cd output && make -j$(CPUS)
endef

define shcmd-makeclean
	cd output && make clean
endef

.PHONY: all clean
all: 
	$(call shcmd-make)

clean:
	$(call shcmd-makeclean)
