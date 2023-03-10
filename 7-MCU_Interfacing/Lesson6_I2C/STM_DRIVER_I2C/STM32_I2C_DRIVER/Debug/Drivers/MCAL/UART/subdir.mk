################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/MCAL/UART/UART.c 

OBJS += \
./Drivers/MCAL/UART/UART.o 

C_DEPS += \
./Drivers/MCAL/UART/UART.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/MCAL/UART/%.o Drivers/MCAL/UART/%.su: ../Drivers/MCAL/UART/%.c Drivers/MCAL/UART/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -c -I"D:/0-EMBEDDED_SYSTEMS/1-Keroles_Diploma_Online/my_codes/Micro_controller_Peripherals/Unit7_Lesson3_SEC/STM_LCD_KEYPAD_HAL_DRIVER/Drivers/HAL/KeyPad/Inc" -I"D:/0-EMBEDDED_SYSTEMS/1-Keroles_Diploma_Online/my_codes/Micro_controller_Peripherals/Unit7_Lesson3_SEC/STM_LCD_KEYPAD_HAL_DRIVER/Drivers/MCAL/GPIO/Includes" -I"D:/0-EMBEDDED_SYSTEMS/1-Keroles_Diploma_Online/my_codes/Micro_controller_Peripherals/Unit7_Lesson3_SEC/STM_LCD_KEYPAD_HAL_DRIVER/Drivers/HAL/LCD/Inc" -I"D:/0-EMBEDDED_SYSTEMS/1-Keroles_Diploma_Online/my_codes/Micro_controller_Peripherals/Unit7_Lesson3_SEC/STM_LCD_KEYPAD_HAL_DRIVER/Drivers" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-MCAL-2f-UART

clean-Drivers-2f-MCAL-2f-UART:
	-$(RM) ./Drivers/MCAL/UART/UART.d ./Drivers/MCAL/UART/UART.o ./Drivers/MCAL/UART/UART.su

.PHONY: clean-Drivers-2f-MCAL-2f-UART

