################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/cnn.c \
../src/perceptron.c 

OBJS += \
./src/cnn.o \
./src/perceptron.o 

C_DEPS += \
./src/cnn.d \
./src/perceptron.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: SDSCC Compiler'
	sdscc -Wall -O3 -I"../src" -c -fmessage-length=0 -MT"$@" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<" -sds-sys-config linux -sds-proc a9_0 -sds-pf "zed"
	@echo 'Finished building: $<'
	@echo ' '


