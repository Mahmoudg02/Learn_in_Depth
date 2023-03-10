################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Lib/PushButton/PushButton.c 

OBJS += \
./Lib/PushButton/PushButton.o 

C_DEPS += \
./Lib/PushButton/PushButton.d 


# Each subdirectory must supply rules for building sources it contributes
Lib/PushButton/%.o: ../Lib/PushButton/%.c Lib/PushButton/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gdwarf-2 -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


