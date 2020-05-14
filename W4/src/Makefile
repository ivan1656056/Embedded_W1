#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <This makefile allows the make function to build this project>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = $(shell platform)

# Architectures Specific Flags
CPU = cortex-m4
ARCH = thumb
SPECS = nosys.specs

# Compiler Commands, Flags and Defines Depending the Platform Selected
#Compiler Collection
ifeq ($(PLATFORM),HOST)
CC = gcc -DHOST -ffreestanding -flto
else
CC = arm-none-eabi-gcc -DMSP432
endif
#Linkage Editor
ifeq ($(PLATFORM),HOST)
LD = -ld
else
LD = arm-none-eabi-ld
endif
#Linkage Editor Flags - 
LDFLAGS =  -Wl,-Map=Output.map -Lplatform.h -Lmemory.h -Lmsp432p401r.h -Lmisc.h -lc -lm -lnosys -lgcc -flto -ffreestanding -nostdlib -T $(LINKER_FILE)
#Compiler FLags
ifeq ($(PLATFORM),HOST)
CFLAGS = -std=c99
else
CFLAGS = -std=c99 -mcpu=$(CPU) -m$(ARCH) -specs=$(SPECS) -march=armv7e-m -mfloat-abi=softfp -mfpu=fpv4-sp-d16 -Wall
endif
#Compiler PreProcessor Flags
CPPFLAGS = -g

#Selects Source Files and Future Objects to Be Made Depending on Platform

ifeq ($(PLATFORM),HOST)
OBJS = main.o math.o data.o stats.o course1.o memory.o
else
OBJS = $(SOURCES:.c=.o)
endif

#Sets the Name of the Final Executable
TARGET = Executable

#Creates Preprocessed File for Any .c File in the src Folder
%.i : %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -I$(INCLUDE_CMSIS) -I$(INCLUDE_COMMON) -I$(INCLUDE_MSP432) -E $< -o $@

#Creates Assembly File for Any .c File in the src Folder
%.asm : %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -I$(INCLUDE_CMSIS) -I$(INCLUDE_COMMON) -I$(INCLUDE_MSP432) -S $<

#Creates Object File for Any .c File in the src Folder
%.o : %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -I$(INCLUDE_CMSIS) -I$(INCLUDE_COMMON) -I$(INCLUDE_MSP432) -c $<

#Creates a Clean Command to Delete all non Executable Files
.PHONY: clean
clean:
	rm -f *.i *.s *.o *.map $(TARGET)

#Creates a Compile-All Command to Compile All Source Files (From .c to .o)
.PHONY: compile-all
compile-all: $(OBJS)
	@:

#Tells the Build Phony What to Do Based on Platform
ifeq ($(PLATFORM),HOST)
FORMULE = $(CC) $(CFLAGS) $(CPPFLAGS) -I$(INCLUDE_CMSIS) -I$(INCLUDE_COMMON) -I$(INCLUDE_MSP432) $(OBJS) -o
else
FORMULE = $(CC) $(CFLAGS) $(CPPFLAGS) $(OBJS) $(LDFLAGS) -o
endif

#Creates a Build Command to Compile all Object files and Link Into a Final Executable.
.PHONY: build
build: all
.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJS)
	$(FORMULE) $@
	
	


