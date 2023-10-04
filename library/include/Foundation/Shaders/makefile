#
# Copyright 2011-2023 Branimir Karadzic. All rights reserved.
# License: https://github.com/bkaradzic/bgfx/blob/master/LICENSE
#

THISDIR:=$(dir $(lastword $(MAKEFILE_LIST)))
BGFXDIR:=$(THISDIR)/../../../extern/bgfx.cmake/bgfx
include $(BGFXDIR)/scripts/tools.mk

SHADER_TMP = $(THISDIR)/tmp

BIN = vs_common.bin.h \
	  fs_mask.bin.h \

.PHONY: all
all: $(BIN)

define shader-embedded
	@echo [$(<)]
	 $(SILENT) $(SHADERC) --type $(1) --platform linux   -p 120        -f $(<) -o "$(SHADER_TMP)" --bin2c $(basename $(<))_glsl -i "$(BGFXDIR)/src"
	 @cat "$(SHADER_TMP)" > $(@)
	-$(SILENT) $(SHADERC) --type $(1) --platform android               -f $(<) -o "$(SHADER_TMP)" --bin2c $(basename $(<))_essl -i "$(BGFXDIR)/src"
	-@cat "$(SHADER_TMP)" >> $(@)	 
	-$(SILENT) $(SHADERC) --type $(1) --platform linux   -p spirv      -f $(<) -o "$(SHADER_TMP)" --bin2c $(basename $(<))_spv -i "$(BGFXDIR)/src"
	-@cat "$(SHADER_TMP)" >> $(@)
	-$(SILENT) $(SHADERC) --type $(1) --platform windows -p $(2)  -O 3 -f $(<) -o "$(SHADER_TMP)" --bin2c $(basename $(<))_dx9 -i "$(BGFXDIR)/src"
	-@cat "$(SHADER_TMP)" >> $(@)
	-$(SILENT) $(SHADERC) --type $(1) --platform windows -p $(3)  -O 3 -f $(<) -o "$(SHADER_TMP)" --bin2c $(basename $(<))_dx11 -i "$(BGFXDIR)/src"
	-@cat "$(SHADER_TMP)" >> $(@)
	-$(SILENT) $(SHADERC) --type $(1) --platform ios     -p metal -O 3 -f $(<) -o "$(SHADER_TMP)" --bin2c $(basename $(<))_mtl -i "$(BGFXDIR)/src"
	-@cat "$(SHADER_TMP)" >> $(@)
	-@printf "extern const uint8_t* $(basename $(<))_pssl;\n" | tr -d '\015' >> $(@)
	-@printf "extern const uint32_t $(basename $(<))_pssl_size;\n" | tr -d '\015' >> $(@)
endef

vs_common.bin.h : vs_common.sc
	$(call shader-embedded, v, vs_3_0, vs_4_0)

fs_mask.bin.h : fs_mask.sc
	$(call shader-embedded, f, ps_3_0, ps_4_0)

.PHONY: clean
clean:
	@echo Cleaning...
	@-rm -vf $(BIN)

.PHONY: rebuild
rebuild: clean all
