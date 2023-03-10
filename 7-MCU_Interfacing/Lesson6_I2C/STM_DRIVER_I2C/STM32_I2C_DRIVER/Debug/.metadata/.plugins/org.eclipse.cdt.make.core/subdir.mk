################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../.metadata/.plugins/org.eclipse.cdt.make.core/specs.c 

OBJS += \
./.metadata/.plugins/org.eclipse.cdt.make.core/specs.o 

C_DEPS += \
./.metadata/.plugins/org.eclipse.cdt.make.core/specs.d 


# Each subdirectory must supply rules for building sources it contributes
.metadata/.plugins/org.eclipse.cdt.make.core/%.o .metadata/.plugins/org.eclipse.cdt.make.core/%.su: ../.metadata/.plugins/org.eclipse.cdt.make.core/%.c .metadata/.plugins/org.eclipse.cdt.make.core/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -c -I"C:/Users/MAshr/OneDrive/Desktop/STM_DRIVER_I2C/STM32_I2C_DRIVER/Drivers/HAL/KeyPad/Inc" -I"C:/Users/MAshr/OneDrive/Desktop/STM_DRIVER_I2C/STM32_I2C_DRIVER/Drivers/MCAL/RCC/Includes" -I"C:/Users/MAshr/OneDrive/Desktop/STM_DRIVER_I2C/STM32_I2C_DRIVER/Drivers/MCAL/UART/Includes" -I"C:/Users/MAshr/OneDrive/Desktop/STM_DRIVER_I2C/STM32_I2C_DRIVER/Drivers/HAL/LCD/Inc" -I"C:/Users/MAshr/OneDrive/Desktop/STM_DRIVER_I2C/STM32_I2C_DRIVER/Drivers/MCAL/GPIO/Includes" -I"C:/Users/MAshr/OneDrive/Desktop/STM_DRIVER_I2C/STM32_I2C_DRIVER/Drivers/MCAL/EXTI/Includes" -I"C:/Users/MAshr/OneDrive/Desktop/STM_DRIVER_I2C/STM32_I2C_DRIVER/Drivers" -I"C:/Users/MAshr/OneDrive/Desktop/STM_DRIVER_I2C/STM32_I2C_DRIVER/Drivers/MCAL/SPI/Includes" -I"C:/Users/MAshr/OneDrive/Desktop/STM_DRIVER_I2C/STM32_I2C_DRIVER/Drivers/MCAL/I2C/Includes" -I"C:/Users/MAshr/OneDrive/Desktop/STM_DRIVER_I2C/STM32_I2C_DRIVER/Drivers/HAL/EEPROM/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean--2e-metadata-2f--2e-plugins-2f-org-2e-eclipse-2e-cdt-2e-make-2e-core

clean--2e-metadata-2f--2e-plugins-2f-org-2e-eclipse-2e-cdt-2e-make-2e-core:
	-$(RM) ./.metadata/.plugins/org.eclipse.cdt.make.core/specs.d ./.metadata/.plugins/org.eclipse.cdt.make.core/specs.o ./.metadata/.plugins/org.eclipse.cdt.make.core/specs.su

.PHONY: clean--2e-metadata-2f--2e-plugins-2f-org-2e-eclipse-2e-cdt-2e-make-2e-core

