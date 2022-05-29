################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32L5xx_HAL_Driver/subdir.mk
-include Drivers/CMSIS/subdir.mk
-include Application/User/subdir.mk
-include Application/Startup/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := GTZC_TZSC_MPCBB_TrustZone_Secure
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
GTZC_TZSC_MPCBB_TrustZone_Secure.elf \

MAP_FILES += \
GTZC_TZSC_MPCBB_TrustZone_Secure.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
GTZC_TZSC_MPCBB_TrustZone_Secure.list \


# All Target
all: main-build

# Main-build Target
main-build: GTZC_TZSC_MPCBB_TrustZone_Secure.elf secondary-outputs

# Tool invocations
GTZC_TZSC_MPCBB_TrustZone_Secure.elf GTZC_TZSC_MPCBB_TrustZone_Secure.map: $(OBJS) $(USER_OBJS) C:\Users\lotfi\Desktop\PROJET\ M1\ TrustZone\GTZC_TZSC_MPCBB_TrustZone\STM32CubeIDE\Secure\STM32L552ZETXQ_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "GTZC_TZSC_MPCBB_TrustZone_Secure.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m33 -T"C:\Users\lotfi\Desktop\PROJET M1 TrustZone\GTZC_TZSC_MPCBB_TrustZone\STM32CubeIDE\Secure\STM32L552ZETXQ_FLASH.ld" --specs=nosys.specs -Wl,-Map="GTZC_TZSC_MPCBB_TrustZone_Secure.map" -Wl,--gc-sections -static -Wl,--cmse-implib -Wl,--out-implib=./secure_nsclib.o --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -u _printf_float -u _scanf_float -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

GTZC_TZSC_MPCBB_TrustZone_Secure.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "GTZC_TZSC_MPCBB_TrustZone_Secure.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) GTZC_TZSC_MPCBB_TrustZone_Secure.elf GTZC_TZSC_MPCBB_TrustZone_Secure.list GTZC_TZSC_MPCBB_TrustZone_Secure.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
