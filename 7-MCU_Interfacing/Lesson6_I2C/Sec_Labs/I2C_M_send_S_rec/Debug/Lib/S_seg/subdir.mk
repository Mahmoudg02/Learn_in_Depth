################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Lib/S_seg/S_seg.c 

OBJS += \
./Lib/S_seg/S_seg.o 

C_DEPS += \
./Lib/S_seg/S_seg.d 


# Each subdirectory must supply rules for building sources it contributes
Lib/S_seg/%.o: ../Lib/S_seg/%.c Lib/S_seg/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gdwarf-2 -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


