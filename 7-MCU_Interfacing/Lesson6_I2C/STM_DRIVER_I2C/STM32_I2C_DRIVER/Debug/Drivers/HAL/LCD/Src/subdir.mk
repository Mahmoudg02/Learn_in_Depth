################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/HAL/LCD/Src/LCD.c 

OBJS += \
./Drivers/HAL/LCD/Src/LCD.o 

C_DEPS += \
./Drivers/HAL/LCD/Src/LCD.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/HAL/LCD/Src/%.o Drivers/HAL/LCD/Src/%.su: ../Drivers/HAL/LCD/Src/%.c Drivers/HAL/LCD/Src/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -c -I"D:/0-EMBEDDED_SYSTEMS/1-Keroles_Diploma_Online/my_codes/MCU_Interfacing/Lesson6_I2C/STM_DRIVER_I2C/STM32_I2C_DRIVER/Drivers/HAL/KeyPad/Inc" -I"D:/0-EMBEDDED_SYSTEMS/1-Keroles_Diploma_Online/my_codes/MCU_Interfacing/Lesson6_I2C/STM_DRIVER_I2C/STM32_I2C_DRIVER/Drivers/MCAL/RCC/Includes" -I"D:/0-EMBEDDED_SYSTEMS/1-Keroles_Diploma_Online/my_codes/MCU_Interfacing/Lesson6_I2C/STM_DRIVER_I2C/STM32_I2C_DRIVER/Drivers/MCAL/UART/Includes" -I"D:/0-EMBEDDED_SYSTEMS/1-Keroles_Diploma_Online/my_codes/MCU_Interfacing/Lesson6_I2C/STM_DRIVER_I2C/STM32_I2C_DRIVER/Drivers/HAL/LCD/Inc" -I"D:/0-EMBEDDED_SYSTEMS/1-Keroles_Diploma_Online/my_codes/MCU_Interfacing/Lesson6_I2C/STM_DRIVER_I2C/STM32_I2C_DRIVER/Drivers/MCAL/GPIO/Includes" -I"D:/0-EMBEDDED_SYSTEMS/1-Keroles_Diploma_Online/my_codes/MCU_Interfacing/Lesson6_I2C/STM_DRIVER_I2C/STM32_I2C_DRIVER/Drivers/MCAL/EXTI/Includes" -I"D:/0-EMBEDDED_SYSTEMS/1-Keroles_Diploma_Online/my_codes/MCU_Interfacing/Lesson6_I2C/STM_DRIVER_I2C/STM32_I2C_DRIVER/Drivers" -I"D:/0-EMBEDDED_SYSTEMS/1-Keroles_Diploma_Online/my_codes/MCU_Interfacing/Lesson6_I2C/STM_DRIVER_I2C/STM32_I2C_DRIVER/Drivers/MCAL/SPI/Includes" -I"D:/0-EMBEDDED_SYSTEMS/1-Keroles_Diploma_Online/my_codes/MCU_Interfacing/Lesson6_I2C/STM_DRIVER_I2C/STM32_I2C_DRIVER/Drivers/MCAL/I2C/Includes" -I"D:/0-EMBEDDED_SYSTEMS/1-Keroles_Diploma_Online/my_codes/MCU_Interfacing/Lesson6_I2C/STM_DRIVER_I2C/STM32_I2C_DRIVER/Drivers/HAL/EEPROM/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-HAL-2f-LCD-2f-Src

clean-Drivers-2f-HAL-2f-LCD-2f-Src:
	-$(RM) ./Drivers/HAL/LCD/Src/LCD.d ./Drivers/HAL/LCD/Src/LCD.o ./Drivers/HAL/LCD/Src/LCD.su

.PHONY: clean-Drivers-2f-HAL-2f-LCD-2f-Src

