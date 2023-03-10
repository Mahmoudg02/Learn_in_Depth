################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include Drivers/MCAL/UART/Src/subdir.mk
-include Drivers/MCAL/SPI/Src/subdir.mk
-include Drivers/MCAL/RCC/Src/subdir.mk
-include Drivers/MCAL/I2C/Src/subdir.mk
-include Drivers/MCAL/GPIO/Src/subdir.mk
-include Drivers/MCAL/EXTI/Src/subdir.mk
-include Drivers/HAL/LCD/Src/subdir.mk
-include Drivers/HAL/KeyPad/Src/subdir.mk
-include Drivers/HAL/EEPROM/Src/subdir.mk
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


BUILD_ARTIFACT_NAME := STM32_I2C_DRIVER
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
STM32_I2C_DRIVER.elf \

MAP_FILES += \
STM32_I2C_DRIVER.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
STM32_I2C_DRIVER.list \


# All Target
all: main-build

# Main-build Target
main-build: STM32_I2C_DRIVER.elf secondary-outputs

# Tool invocations
STM32_I2C_DRIVER.elf STM32_I2C_DRIVER.map: $(OBJS) $(USER_OBJS) D:\0-EMBEDDED_SYSTEMS\1-Keroles_Diploma_Online\my_codes\MCU_Interfacing\Lesson6_I2C\STM_DRIVER_I2C\STM32_I2C_DRIVER\STM32F103C6TX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -gdwarf-2 -o "STM32_I2C_DRIVER.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"D:\0-EMBEDDED_SYSTEMS\1-Keroles_Diploma_Online\my_codes\MCU_Interfacing\Lesson6_I2C\STM_DRIVER_I2C\STM32_I2C_DRIVER\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="STM32_I2C_DRIVER.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

STM32_I2C_DRIVER.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "STM32_I2C_DRIVER.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) STM32_I2C_DRIVER.elf STM32_I2C_DRIVER.list STM32_I2C_DRIVER.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
