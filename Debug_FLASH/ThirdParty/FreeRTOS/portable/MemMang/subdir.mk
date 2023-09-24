################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ThirdParty/FreeRTOS/portable/MemMang/heap_4.c 

OBJS += \
./ThirdParty/FreeRTOS/portable/MemMang/heap_4.o 

C_DEPS += \
./ThirdParty/FreeRTOS/portable/MemMang/heap_4.d 


# Each subdirectory must supply rules for building sources it contributes
ThirdParty/FreeRTOS/portable/MemMang/%.o: ../ThirdParty/FreeRTOS/portable/MemMang/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@ThirdParty/FreeRTOS/portable/MemMang/heap_4.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


