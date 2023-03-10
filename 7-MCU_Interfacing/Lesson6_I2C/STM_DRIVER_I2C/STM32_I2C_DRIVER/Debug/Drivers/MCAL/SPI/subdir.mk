################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/MCAL/SPI/STM32F103_SPI.c 

OBJS += \
./Drivers/MCAL/SPI/STM32F103_SPI.o 

C_DEPS += \
./Drivers/MCAL/SPI/STM32F103_SPI.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/MCAL/SPI/%.o Drivers/MCAL/SPI/%.su: ../Drivers/MCAL/SPI/%.c Drivers/MCAL/SPI/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -c -I"D:/0-EMBEDDED_SYSTEMS/1-Keroles_Diploma_Online/my_codes/MCU_Interfacing/Lesson4_SPI/STM_Driver_SPI/STM32_SPI_DRIVER/Drivers/HAL/KeyPad/Inc" -I"D:/0-EMBEDDED_SYSTEMS/1-Keroles_Diploma_Online/my_codes/MCU_Interfacing/Lesson4_SPI/STM_Driver_SPI/STM32_SPI_DRIVER/Drivers/MCAL/RCC/Includes" -I"D:/0-EMBEDDED_SYSTEMS/1-Keroles_Diploma_Online/my_codes/MCU_Interfacing/Lesson4_SPI/STM_Driver_SPI/STM32_SPI_DRIVER/Drivers/MCAL/UART/Includes" -I"D:/0-EMBEDDED_SYSTEMS/1-Keroles_Diploma_Online/my_codes/MCU_Interfacing/Lesson4_SPI/STM_Driver_SPI/STM32_SPI_DRIVER/Drivers/HAL/LCD/Inc" -I"D:/0-EMBEDDED_SYSTEMS/1-Keroles_Diploma_Online/my_codes/MCU_Interfacing/Lesson4_SPI/STM_Driver_SPI/STM32_SPI_DRIVER/Drivers/MCAL/GPIO/Includes" -I"D:/0-EMBEDDED_SYSTEMS/1-Keroles_Diploma_Online/my_codes/MCU_Interfacing/Lesson4_SPI/STM_Driver_SPI/STM32_SPI_DRIVER/Drivers/MCAL/EXTI/Includes" -I"/STM32_SPI_DRIVER/Drivers/MCAL/UART/Includes" -I"D:/0-EMBEDDED_SYSTEMS/1-Keroles_Diploma_Online/my_codes/MCU_Interfacing/Lesson4_SPI/STM_Driver_SPI/STM32_SPI_DRIVER/Drivers" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-MCAL-2f-SPI

clean-Drivers-2f-MCAL-2f-SPI:
	-$(RM) ./Drivers/MCAL/SPI/STM32F103_SPI.d ./Drivers/MCAL/SPI/STM32F103_SPI.o ./Drivers/MCAL/SPI/STM32F103_SPI.su

.PHONY: clean-Drivers-2f-MCAL-2f-SPI

