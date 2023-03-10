################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/src/EEPROM.c \
../drivers/src/KeyPad.c \
../drivers/src/LCD.c \
../drivers/src/RCC.c \
../drivers/src/STM32F103_EXTI.c \
../drivers/src/STM32F103_GPIO.c \
../drivers/src/STM32F103_I2C.c \
../drivers/src/STM32F103_SPI.c \
../drivers/src/UART.c 

OBJS += \
./drivers/src/EEPROM.o \
./drivers/src/KeyPad.o \
./drivers/src/LCD.o \
./drivers/src/RCC.o \
./drivers/src/STM32F103_EXTI.o \
./drivers/src/STM32F103_GPIO.o \
./drivers/src/STM32F103_I2C.o \
./drivers/src/STM32F103_SPI.o \
./drivers/src/UART.o 

C_DEPS += \
./drivers/src/EEPROM.d \
./drivers/src/KeyPad.d \
./drivers/src/LCD.d \
./drivers/src/RCC.d \
./drivers/src/STM32F103_EXTI.d \
./drivers/src/STM32F103_GPIO.d \
./drivers/src/STM32F103_I2C.d \
./drivers/src/STM32F103_SPI.d \
./drivers/src/UART.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/src/%.o drivers/src/%.su: ../drivers/src/%.c drivers/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"D:/0-EMBEDDED_SYSTEMS/1-Keroles_Diploma_Online/my_codes/ARM/LABs/LAB1/drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-drivers-2f-src

clean-drivers-2f-src:
	-$(RM) ./drivers/src/EEPROM.d ./drivers/src/EEPROM.o ./drivers/src/EEPROM.su ./drivers/src/KeyPad.d ./drivers/src/KeyPad.o ./drivers/src/KeyPad.su ./drivers/src/LCD.d ./drivers/src/LCD.o ./drivers/src/LCD.su ./drivers/src/RCC.d ./drivers/src/RCC.o ./drivers/src/RCC.su ./drivers/src/STM32F103_EXTI.d ./drivers/src/STM32F103_EXTI.o ./drivers/src/STM32F103_EXTI.su ./drivers/src/STM32F103_GPIO.d ./drivers/src/STM32F103_GPIO.o ./drivers/src/STM32F103_GPIO.su ./drivers/src/STM32F103_I2C.d ./drivers/src/STM32F103_I2C.o ./drivers/src/STM32F103_I2C.su ./drivers/src/STM32F103_SPI.d ./drivers/src/STM32F103_SPI.o ./drivers/src/STM32F103_SPI.su ./drivers/src/UART.d ./drivers/src/UART.o ./drivers/src/UART.su

.PHONY: clean-drivers-2f-src

