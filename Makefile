############################### DIRECTORIES ################################
PROJ_DIR			:= ~/workspace/mcu/demo/blink_led

DEVICE_NAME			:= STM32F407VG

PROJ_NAME			:= $(DEVICE_NAME)_blink_led
DEVICE_DIR			:= $(PROJ_DIR)/Device/$(DEVICE_NAME)

# ARM Compiler Lib
LIBDIR_1			:= /usr/lib/arm-none-eabi/lib/thumb/v7e-m+fp/hard
LIBDIR_2			:= /usr/lib/gcc/arm-none-eabi/9.2.1/thumb/v7e-m+fp/hard

# output building folder
BUILD_DIR			:= $(PROJ_DIR)/output

# list folder contains C files
CC_DIRS				+= $(PROJ_DIR)/src
CC_DIRS				+= $(DEVICE_DIR)/src

# list folder contains ASM files
ASM_DIRS			+= $(DEVICE_DIR)/src

# include folders:
INC_DIRS			+= $(PROJ_DIR)/Core/Include
INC_DIRS			+= $(DEVICE_DIR)/inc

# linker file:
LINKER_SCRIPT		+= $(DEVICE_DIR)/linker/$(DEVICE_NAME).ld

################################## CFLAGS ##################################
# cpu
CPU					= -mcpu=cortex-m4
# fpu
FPU					= -mfpu=fpv4-sp-d16
# float-abi
FLOAT-ABI			= -mfloat-abi=hard
# mcu
MCU = $(CPU) -c -g -mthumb $(FPU) $(FLOAT-ABI)

################################### LDFLAGS ################################
LIBS				= -lc -lm -lnosys

# setting compiler option
CC_OPT				= $(MCU) $(INC_DIR) -DCLI_STAND_ALONE
ASM_OPT				= $(MCU)
LD_OPT				= -T $(LINKER_SCRIPT) -Map $(BUILD_DIR)/$(PROJ_NAME).map $(OBJECT_FILE) -L $(LIBDIR_1) $(LIBS) -L $(LIBDIR_2) -lgcc

# using common target rule
include $(PROJ_DIR)/common.mk
