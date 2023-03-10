################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/MCAL/GPIO/Src/STM32F103_GPIO.c 

OBJS += \
./Drivers/MCAL/GPIO/Src/STM32F103_GPIO.o 

C_DEPS += \
./Drivers/MCAL/GPIO/Src/STM32F103_GPIO.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/MCAL/GPIO/Src/%.o Drivers/MCAL/GPIO/Src/%.su: ../Drivers/MCAL/GPIO/Src/%.c Drivers/MCAL/GPIO/Src/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -c -I"D:/0-EMBEDDED_SYSTEMS/1-Keroles_Diploma_Online/my_codes/MCU_Interfacing/Lesson6_I2C/STM_DRIVER_I2C/STM32_I2C_DRIVER/Drivers/HAL/KeyPad/Inc" -I"D:/0-EMBEDDED_SYSTEMS/1-Keroles_Diploma_Online/my_codes/MCU_Interfacing/Lesson6_I2C/STM_DRIVER_I2C/STM32_I2C_DRIVER/Drivers/MCAL/RCC/Includes" -I"D:/0-EMBEDDED_SYSTEMS/1-Keroles_Diploma_Online/my_codes/MCU_Interfacing/Lesson6_I2C/STM_DRIVER_I2C/STM32_I2C_DRIVER/Drivers/MCAL/UART/Includes" -I"D:/0-EMBEDDED_SYSTEMS/1-Keroles_Diploma_Online/my_codes/MCU_Interfacing/Lesson6_I2C/STM_DRIVER_I2C/STM32_I2C_DRIVER/Drivers/HAL/LCD/Inc" -I"D:/0-EMBEDDED_SYSTEMS/1-Keroles_Diploma_Online/my_codes/MCU_Interfacing/Lesson6_I2C/STM_DRIVER_I2C/STM32_I2C_DRIVER/Drivers/MCAL/GPIO/Includes" -I"D:/0-EMBEDDED_SYSTEMS/1-Keroles_Diploma_Online/my_codes/MCU_Interfacing/Lesson6_I2C/STM_DRIVER_I2C/STM32_I2C_DRIVER/Drivers/MCAL/EXTI/Includes" -I"D:/0-EMBEDDED_SYSTEMS/1-Keroles_Diploma_Online/my_codes/MCU_Interfacing/Lesson6_I2C/STM_DRIVER_I2C/STM32_I2C_DRIVER/Drivers" -I"D:/0-EMBEDDED_SYSTEMS/1-Keroles_Diploma_Online/my_codes/MCU_Interfacing/Lesson6_I2C/STM_DRIVER_I2C/STM32_I2C_DRIVER/Drivers/MCAL/SPI/Includes" -I"D:/0-EMBEDDED_SYSTEMS/1-Keroles_Diploma_Online/my_codes/MCU_Interfacing/Lesson6_I2C/STM_DRIVER_I2C/STM32_I2C_DRIVER/Drivers/MCAL/I2C/Includes" -I"D:/0-EMBEDDED_SYSTEMS/1-Keroles_Diploma_Online/my_codes/MCU_Interfacing/Lesson6_I2C/STM_DRIVER_I2C/STM32_I2C_DRIVER/Drivers/HAL/EEPROM/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-MCAL-2f-GPIO-2f-Src

clean-Drivers-2f-MCAL-2f-GPIO-2f-Src:
	-$(RM) ./Drivers/MCAL/GPIO/Src/STM32F103_GPIO.d ./Drivers/MCAL/GPIO/Src/STM32F103_GPIO.o ./Drivers/MCAL/GPIO/Src/STM32F103_GPIO.su

.PHONY: clean-Drivers-2f-MCAL-2f-GPIO-2f-Src

