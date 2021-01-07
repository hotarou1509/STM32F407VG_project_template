# list of C files:
CC_FILES			+= $(foreach __dir,$(CC_DIRS),$(wildcard $(__dir)/*.c))

# list of ASM files:
ASM_FILES			+= $(foreach __dir,$(ASM_DIRS),$(wildcard $(__dir)/*.s))
ASM_FILES			+= $(foreach __dir,$(ASM_DIRS),$(wildcard $(__dir)/*.S))

# include folder
INC_DIR				+= $(foreach __dir,$(INC_DIRS),$(addprefix -I , $(__dir)))

# Compiler
PREFIX_GCC_COMPILER	:= arm-none-eabi
CC					:= $(PREFIX_GCC_COMPILER)-gcc
ASM					:= $(PREFIX_GCC_COMPILER)-as
LD					:= $(PREFIX_GCC_COMPILER)-ld
SIZE				:= $(PREFIX_GCC_COMPILER)-size
OBJCPY				:= $(PREFIX_GCC_COMPILER)-objcopy
NM					:= $(PREFIX_GCC_COMPILER)-nm

# Building
BUILD_FILE			= $(CC_FILES) $(ASM_FILES)
OBJECT_FILE			= $(addprefix $(BUILD_DIR)/,$(addsuffix .o,$(basename $(notdir $(BUILD_FILE)))))
DEPS				= $(OBJECT_FILE:.o=.d)

.PHONY:	all

all: clean build hex size

# generate object file of c file:
ifndef generate_c_rule
define generate_c_rule
$(addprefix $(BUILD_DIR)/,$(addsuffix .o,$(basename $(notdir $(1))))): $(1)
		@echo Processing $$<
		$(CC) $(CC_OPT) $$< -o $$@
endef
endif #generate_c_rule

#generate object file of c file:
ifndef generate_asm_rule
define generate_asm_rule
$(addprefix $(BUILD_DIR)/,$(addsuffix .o,$(basename $(notdir $(1))))): $(1)
		@echo Processing $$<
		$(ASM) $(ASM_OPT) $$< -o $$@
endef
endif #generate_asm_rule

# generate all c and asm file of project
$(foreach file,$(CC_FILES),$(eval $(call generate_c_rule,$(file))))
$(foreach file,$(ASM_FILES),$(eval $(call generate_asm_rule,$(file))))

size: $(BUILD_DIR)/$(PROJ_NAME).elf
		@echo "Size area memories in binary image $(BUILD_DIR)/$(PROJ_NAME).elf"
		$(SIZE) $(BUILD_DIR)/$(PROJ_NAME).elf

d_size: $(BUILD_DIR)/$(PROJ_NAME).elf
		$(NM) --demangle --print-size --size-sort --reverse-sort -S $(BUILD_DIR)/$(PROJ_NAME).elf

show_flag:
	@echo "\r\nCC_DIRS :"
	@echo $(CC_DIRS)
	@echo "\r\nCC_FILES :"
	@echo $(CC_FILES)
	@echo "\r\nASM_DIRS :"
	@echo $(ASM_DIRS)
	@echo "\r\nASM_FILES :"
	@echo $(ASM_FILES)
	@echo "\r\nINC_DIR :"
	@echo $(INC_DIR)
	@echo "\r\nOBJECT_FILE :"
	@echo $(OBJECT_FILE)
	@echo "\r\nCC_OPT :"
	@echo $(CC_OPT)
	@echo "\r\nASM_OPT :"
	@echo $(ASM_OPT)
	@echo "\r\nLD_OPT :"
	@echo $(LD_OPT)
	@echo "\r\nBUILD_DIR :"
	@echo $(BUILD_DIR)
	@echo "\r\n"

# building commands
hex: $(BUILD_DIR)/$(PROJ_NAME).elf
		$(OBJCPY) -O ihex $(BUILD_DIR)/$(PROJ_NAME).elf $(BUILD_DIR)/$(PROJ_NAME).hex

bin: $(BUILD_DIR)/$(PROJ_NAME).elf
		$(OBJCPY) -O binary -S $(BUILD_DIR)/$(PROJ_NAME).elf $(BUILD_DIR)/$(PROJ_NAME).bin

build: $(OBJECT_FILE) 
		@echo "Linking object files to create new binary image $(BUILD_DIR)/$(PROJ_NAME).elf"
		$(LD) $(LD_OPT) -o $(BUILD_DIR)/$(PROJ_NAME).elf

clean: 
	@rm -rf $(BUILD_DIR)
	@mkdir -p $(BUILD_DIR)

-include $(DEPS)
