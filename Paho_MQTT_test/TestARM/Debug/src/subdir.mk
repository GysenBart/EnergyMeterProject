################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Base64.c \
../src/Clients.c \
../src/Heap.c \
../src/LinkedList.c \
../src/Log.c \
../src/MQTTClient.c \
../src/MQTTPacket.c \
../src/MQTTPacketOut.c \
../src/MQTTPersistence.c \
../src/MQTTPersistenceDefault.c \
../src/MQTTProperties.c \
../src/MQTTProtocolClient.c \
../src/MQTTProtocolOut.c \
../src/MQTTReasonCodes.c \
../src/MQTTTime.c \
../src/Messages.c \
../src/OsWrapper.c \
../src/Proxy.c \
../src/SHA1.c \
../src/SSLSocket.c \
../src/Socket.c \
../src/SocketBuffer.c \
../src/StackTrace.c \
../src/Thread.c \
../src/Tree.c \
../src/WebSocket.c \
../src/main.c \
../src/utf-8.c 

C_DEPS += \
./src/Base64.d \
./src/Clients.d \
./src/Heap.d \
./src/LinkedList.d \
./src/Log.d \
./src/MQTTClient.d \
./src/MQTTPacket.d \
./src/MQTTPacketOut.d \
./src/MQTTPersistence.d \
./src/MQTTPersistenceDefault.d \
./src/MQTTProperties.d \
./src/MQTTProtocolClient.d \
./src/MQTTProtocolOut.d \
./src/MQTTReasonCodes.d \
./src/MQTTTime.d \
./src/Messages.d \
./src/OsWrapper.d \
./src/Proxy.d \
./src/SHA1.d \
./src/SSLSocket.d \
./src/Socket.d \
./src/SocketBuffer.d \
./src/StackTrace.d \
./src/Thread.d \
./src/Tree.d \
./src/WebSocket.d \
./src/main.d \
./src/utf-8.d 

OBJS += \
./src/Base64.o \
./src/Clients.o \
./src/Heap.o \
./src/LinkedList.o \
./src/Log.o \
./src/MQTTClient.o \
./src/MQTTPacket.o \
./src/MQTTPacketOut.o \
./src/MQTTPersistence.o \
./src/MQTTPersistenceDefault.o \
./src/MQTTProperties.o \
./src/MQTTProtocolClient.o \
./src/MQTTProtocolOut.o \
./src/MQTTReasonCodes.o \
./src/MQTTTime.o \
./src/Messages.o \
./src/OsWrapper.o \
./src/Proxy.o \
./src/SHA1.o \
./src/SSLSocket.o \
./src/Socket.o \
./src/SocketBuffer.o \
./src/StackTrace.o \
./src/Thread.o \
./src/Tree.o \
./src/WebSocket.o \
./src/main.o \
./src/utf-8.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-linux-gnueabihf-gcc -I-dl -I-pthread -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/Base64.d ./src/Base64.o ./src/Clients.d ./src/Clients.o ./src/Heap.d ./src/Heap.o ./src/LinkedList.d ./src/LinkedList.o ./src/Log.d ./src/Log.o ./src/MQTTClient.d ./src/MQTTClient.o ./src/MQTTPacket.d ./src/MQTTPacket.o ./src/MQTTPacketOut.d ./src/MQTTPacketOut.o ./src/MQTTPersistence.d ./src/MQTTPersistence.o ./src/MQTTPersistenceDefault.d ./src/MQTTPersistenceDefault.o ./src/MQTTProperties.d ./src/MQTTProperties.o ./src/MQTTProtocolClient.d ./src/MQTTProtocolClient.o ./src/MQTTProtocolOut.d ./src/MQTTProtocolOut.o ./src/MQTTReasonCodes.d ./src/MQTTReasonCodes.o ./src/MQTTTime.d ./src/MQTTTime.o ./src/Messages.d ./src/Messages.o ./src/OsWrapper.d ./src/OsWrapper.o ./src/Proxy.d ./src/Proxy.o ./src/SHA1.d ./src/SHA1.o ./src/SSLSocket.d ./src/SSLSocket.o ./src/Socket.d ./src/Socket.o ./src/SocketBuffer.d ./src/SocketBuffer.o ./src/StackTrace.d ./src/StackTrace.o ./src/Thread.d ./src/Thread.o ./src/Tree.d ./src/Tree.o ./src/WebSocket.d ./src/WebSocket.o ./src/main.d ./src/main.o ./src/utf-8.d ./src/utf-8.o

.PHONY: clean-src

