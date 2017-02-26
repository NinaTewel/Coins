export CC      := gcc
export CFLAGS  := -Wall

LS                     := $(shell ls)
EXCLUDED               := Makefile obj SRC_makefile_template.mk
SRC_CODE_TARGETS       := $(filter-out $(EXCLUDED),$(LS))
SRC_CODE_TARGETS_CLEAN := $(SRC_CODE_TARGETS:=_CLEAN)

NEW_MAKEFILE_CONTENT   := include ../SRC_makefile_template.mk

define SRC_CODE_TARGETS_template
.PHONY: $(1)
$(1):
# Working with GNU make 4.0 or newer, automatic common makefiles generation.
# Should be disable if folder specific makefiles are needed.
	$(file > $(1)/Makefile,$(NEW_MAKEFILE_CONTENT))
	$(MAKE) $(CFLAGS) -C $(1)
	-cp -t obj $(1)/*.o
endef

define SRC_CODE_TARGETS_CLEAN_template
.PHONY: $(1)_CLEAN
$(1)_CLEAN:
	-rm $(1)/*.o
	-rm $(1)/*.d
	-rm $(1)/*.d.*
	-rm $(1)/Makefile
endef

.PHONY: makeSources
makeSources: $(SRC_CODE_TARGETS)

.PHONY: clean
clean: $(SRC_CODE_TARGETS_CLEAN)

$(foreach target,\
          $(SRC_CODE_TARGETS),\
          $(eval $(call SRC_CODE_TARGETS_template,$(target))))

$(foreach target,\
          $(SRC_CODE_TARGETS),\
          $(eval $(call SRC_CODE_TARGETS_CLEAN_template,$(target))))

