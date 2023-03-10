################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/MCAL/RCC/RCC.c 

OBJS += \
./Drivers/MCAL/RCC/RCC.o 

C_DEPS += \
./Drivers/MCAL/RCC/RCC.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/MCAL/RCC/%.o Drivers/MCAL/RCC/%.su: ../Drivers/MCAL/RCC/%.c Drivers/MCAL/RCC/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -c -I"D:/0-EMBEDDED_SYSTEMS/1-Keroles_Diploma_Online/my_codes/MCU_Interfacing/Lesson3_Uart/STM32_UART_DRIVER/Drivers/HAL/KeyPad/Inc" -I"D:/0-EMBEDDED_SYSTEMS/1-Keroles_Diploma_Online/my_codes/MCU_Interfacing/Lesson3_Uart/STM32_UART_DRIVER/Drivers/MCAL/UART/Includes" -I"D:/0-EMBEDDED_SYSTEMS/1-Keroles_Diploma_Online/my_codes/MCU_Interfacing/Lesson3_Uart/STM32_UART_DRIVER/Drivers/HAL/LCD/Inc" -I"D:/0-EMBEDDED_SYSTEMS/1-Keroles_Diploma_Online/my_codes/MCU_Interfacing/Lesson3_Uart/STM32_UART_DRIVER/Drivers/MCAL/GPIO/Includes" -I"D:/0-EMBEDDED_SYSTEMS/1-Keroles_Diploma_Online/my_codes/MCU_Interfacing/Lesson3_Uart/STM32_UART_DRIVER/Drivers/MCAL/EXTI/Includes" -I"/STM32_UART_DRIVER/Drivers/MCAL/UART/Includes" -I"D:/0-EMBEDDED_SYSTEMS/1-Keroles_Diploma_Online/my_codes/MCU_Interfacing/Lesson3_Uart/STM32_UART_DRIVER/Drivers" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-MCAL-2f-RCC

clean-Drivers-2f-MCAL-2f-RCC:
	-$(RM) ./Drivers/MCAL/RCC/RCC.d ./Drivers/MCAL/RCC/RCC.o ./Drivers/MCAL/RCC/RCC.su

.PHONY: clean-Drivers-2f-MCAL-2f-RCC

