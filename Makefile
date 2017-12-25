CPUS=$(shell cat /proc/cpuinfo | grep "processor" | wc -l)

define shcmd-make
	cd output && make -j$(CPUS)
endef

define shcmd-makeclean
	cd output && make clean
endef

define shcmd-makerm
	rm -rf output
endef

.PHONY: all clean rm
all: 
	$(call shcmd-make)

clean:
	$(call shcmd-makeclean)

rm:
	$(call shcmd-makerm)
