################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Src/STM32F103_GPIO.c 

OBJS += \
./Drivers/Src/STM32F103_GPIO.o 

C_DEPS += \
./Drivers/Src/STM32F103_GPIO.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Src/%.o Drivers/Src/%.su: ../Drivers/Src/%.c Drivers/Src/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"D:/0-KEROLES MATERIALS/1-Keroles_Diploma_Online/my_codes/Micro_controller_Peripherals/Unit7_Lesson3_SEC/STM_LCD_KEYPAD_HAL_DRIVER/Drivers/Includes" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-Src

clean-Drivers-2f-Src:
	-$(RM) ./Drivers/Src/STM32F103_GPIO.d ./Drivers/Src/STM32F103_GPIO.o ./Drivers/Src/STM32F103_GPIO.su

.PHONY: clean-Drivers-2f-Src

