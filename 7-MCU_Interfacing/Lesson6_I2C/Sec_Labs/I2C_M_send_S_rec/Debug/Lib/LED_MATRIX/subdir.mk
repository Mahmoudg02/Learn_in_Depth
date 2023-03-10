################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Lib/LED_MATRIX/LED_MATRIX.c 

OBJS += \
./Lib/LED_MATRIX/LED_MATRIX.o 

C_DEPS += \
./Lib/LED_MATRIX/LED_MATRIX.d 


# Each subdirectory must supply rules for building sources it contributes
Lib/LED_MATRIX/%.o: ../Lib/LED_MATRIX/%.c Lib/LED_MATRIX/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gdwarf-2 -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


