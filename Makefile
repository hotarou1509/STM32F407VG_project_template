# Project's Directories
PROJ_DIR			:= ~/workspace/mcu/demo/simple_uart

DEVICE_NAME			:= STM32F407VG

PROJ_NAME			:= $(DEVICE_NAME)_simple_uart

DEVICE_DIR			:= $(PROJ_DIR)/Device/$(DEVICE_NAME)

DRIVER_DIR			:= $(PROJ_DIR)/drivers/$(DEVICE_NAME)

# ARM Compiler Lib Directory
LIBDIR_1			:= /usr/lib/arm-none-eabi/lib/thumb
LIBDIR_2			:= /usr/lib/gcc/arm-none-eabi/9.2.1/thumb

# Output building folder
BUILD_DIR			:= $(PROJ_DIR)/output

# Folder list contains C files
CC_DIRS				+= $(PROJ_DIR)/src
CC_DIRS				+= $(DEVICE_DIR)/src
CC_DIRS				+= $(DRIVER_DIR)/src

# Folder list contains ASM files
ASM_DIRS			+= $(DEVICE_DIR)/src

# Include folders:
INC_DIRS			+= $(PROJ_DIR)/Core/Include
INC_DIRS			+= $(DEVICE_DIR)/inc
INC_DIRS			+= $(PROJ_DIR)/drivers/$(DEVICE_NAME)/inc

# Linker script:
LINKER_SCRIPT		+= $(DEVICE_DIR)/linker/$(DEVICE_NAME).ld
LD_LIBS				+= -lc -lm -lnosys

# Device MCU's specific architechture:
include $(DEVICE_DIR)/device.mk
# MCU
MCU = $(CPU) -c -g -mthumb $(FPU) $(FLOAT-ABI)

# Setting compiler option
CC_OPT				= $(MCU) $(INC_DIR) -DCLI_STAND_ALONE
ASM_OPT				= $(MCU)
LD_OPT				= -T $(LINKER_SCRIPT) -Map $(BUILD_DIR)/$(PROJ_NAME).map $(OBJECT_FILE) -L $(LIBDIR_1)/$(ARCH_DIR) $(LD_LIBS) -L $(LIBDIR_2)/$(ARCH_DIR) -lgcc

# Using common target rule
include $(PROJ_DIR)/common.mk
