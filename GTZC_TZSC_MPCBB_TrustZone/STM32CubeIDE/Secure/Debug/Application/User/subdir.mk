################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/lotfi/Desktop/PROJET\ M1\ TrustZone/GTZC_TZSC_MPCBB_TrustZone/Secure/Src/gpio.c \
C:/Users/lotfi/Desktop/PROJET\ M1\ TrustZone/GTZC_TZSC_MPCBB_TrustZone/Secure/Src/gtzc.c \
C:/Users/lotfi/Desktop/PROJET\ M1\ TrustZone/GTZC_TZSC_MPCBB_TrustZone/Secure/Src/main.c \
C:/Users/lotfi/Desktop/PROJET\ M1\ TrustZone/GTZC_TZSC_MPCBB_TrustZone/Secure/Src/secure_nsc.c \
C:/Users/lotfi/Desktop/PROJET\ M1\ TrustZone/GTZC_TZSC_MPCBB_TrustZone/Secure/Src/stm32l5xx_hal_msp.c \
C:/Users/lotfi/Desktop/PROJET\ M1\ TrustZone/GTZC_TZSC_MPCBB_TrustZone/Secure/Src/stm32l5xx_it.c \
../Application/User/syscalls.c \
../Application/User/sysmem.c \
C:/Users/lotfi/Desktop/PROJET\ M1\ TrustZone/GTZC_TZSC_MPCBB_TrustZone/Secure/Src/usart.c 

OBJS += \
./Application/User/gpio.o \
./Application/User/gtzc.o \
./Application/User/main.o \
./Application/User/secure_nsc.o \
./Application/User/stm32l5xx_hal_msp.o \
./Application/User/stm32l5xx_it.o \
./Application/User/syscalls.o \
./Application/User/sysmem.o \
./Application/User/usart.o 

C_DEPS += \
./Application/User/gpio.d \
./Application/User/gtzc.d \
./Application/User/main.d \
./Application/User/secure_nsc.d \
./Application/User/stm32l5xx_hal_msp.d \
./Application/User/stm32l5xx_it.d \
./Application/User/syscalls.d \
./Application/User/sysmem.d \
./Application/User/usart.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/gpio.o: C:/Users/lotfi/Desktop/PROJET\ M1\ TrustZone/GTZC_TZSC_MPCBB_TrustZone/Secure/Src/gpio.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L552xx -DDEBUG -c -I../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../Secure_nsclib -I../../../Secure/Inc -I../../../Drivers/STM32L5xx_HAL_Driver/Inc/Legacy -I../../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -mcmse -MMD -MP -MF"Application/User/gpio.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/gtzc.o: C:/Users/lotfi/Desktop/PROJET\ M1\ TrustZone/GTZC_TZSC_MPCBB_TrustZone/Secure/Src/gtzc.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L552xx -DDEBUG -c -I../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../Secure_nsclib -I../../../Secure/Inc -I../../../Drivers/STM32L5xx_HAL_Driver/Inc/Legacy -I../../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -mcmse -MMD -MP -MF"Application/User/gtzc.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/main.o: C:/Users/lotfi/Desktop/PROJET\ M1\ TrustZone/GTZC_TZSC_MPCBB_TrustZone/Secure/Src/main.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L552xx -DDEBUG -c -I../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../Secure_nsclib -I../../../Secure/Inc -I../../../Drivers/STM32L5xx_HAL_Driver/Inc/Legacy -I../../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -mcmse -MMD -MP -MF"Application/User/main.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/secure_nsc.o: C:/Users/lotfi/Desktop/PROJET\ M1\ TrustZone/GTZC_TZSC_MPCBB_TrustZone/Secure/Src/secure_nsc.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L552xx -DDEBUG -c -I../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../Secure_nsclib -I../../../Secure/Inc -I../../../Drivers/STM32L5xx_HAL_Driver/Inc/Legacy -I../../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -mcmse -MMD -MP -MF"Application/User/secure_nsc.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/stm32l5xx_hal_msp.o: C:/Users/lotfi/Desktop/PROJET\ M1\ TrustZone/GTZC_TZSC_MPCBB_TrustZone/Secure/Src/stm32l5xx_hal_msp.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L552xx -DDEBUG -c -I../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../Secure_nsclib -I../../../Secure/Inc -I../../../Drivers/STM32L5xx_HAL_Driver/Inc/Legacy -I../../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -mcmse -MMD -MP -MF"Application/User/stm32l5xx_hal_msp.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/stm32l5xx_it.o: C:/Users/lotfi/Desktop/PROJET\ M1\ TrustZone/GTZC_TZSC_MPCBB_TrustZone/Secure/Src/stm32l5xx_it.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L552xx -DDEBUG -c -I../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../Secure_nsclib -I../../../Secure/Inc -I../../../Drivers/STM32L5xx_HAL_Driver/Inc/Legacy -I../../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -mcmse -MMD -MP -MF"Application/User/stm32l5xx_it.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/%.o Application/User/%.su: ../Application/User/%.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L552xx -DDEBUG -c -I../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../Secure_nsclib -I../../../Secure/Inc -I../../../Drivers/STM32L5xx_HAL_Driver/Inc/Legacy -I../../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -mcmse -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/usart.o: C:/Users/lotfi/Desktop/PROJET\ M1\ TrustZone/GTZC_TZSC_MPCBB_TrustZone/Secure/Src/usart.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L552xx -DDEBUG -c -I../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../Secure_nsclib -I../../../Secure/Inc -I../../../Drivers/STM32L5xx_HAL_Driver/Inc/Legacy -I../../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -mcmse -MMD -MP -MF"Application/User/usart.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-User

clean-Application-2f-User:
	-$(RM) ./Application/User/gpio.d ./Application/User/gpio.o ./Application/User/gpio.su ./Application/User/gtzc.d ./Application/User/gtzc.o ./Application/User/gtzc.su ./Application/User/main.d ./Application/User/main.o ./Application/User/main.su ./Application/User/secure_nsc.d ./Application/User/secure_nsc.o ./Application/User/secure_nsc.su ./Application/User/stm32l5xx_hal_msp.d ./Application/User/stm32l5xx_hal_msp.o ./Application/User/stm32l5xx_hal_msp.su ./Application/User/stm32l5xx_it.d ./Application/User/stm32l5xx_it.o ./Application/User/stm32l5xx_it.su ./Application/User/syscalls.d ./Application/User/syscalls.o ./Application/User/syscalls.su ./Application/User/sysmem.d ./Application/User/sysmem.o ./Application/User/sysmem.su ./Application/User/usart.d ./Application/User/usart.o ./Application/User/usart.su

.PHONY: clean-Application-2f-User

