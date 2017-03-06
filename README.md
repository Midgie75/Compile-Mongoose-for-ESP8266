# Compile-Mongoose-for-ESP8266
1. Follow https://github.com/pfalcon/esp-open-sdk
2. Clone https://github.com/espressif/ESP8266_RTOS_SDK
3. Clone https://github.com/cesanta/mongoose
4. export SDK_PATH=/path/to/ESP8266_RTOS_SDK
5. export BIN_PATH=./bin
6. export PATH=/home/mig/esp-open-sdk/xtensa-lx106-elf/bin:$PATH
7. https://github.com/cesanta/mongoose/tree/master/examples/ESP8266_RTOS
8. correct Makefile: LINKFLAGS -lgcc_sdk ---> -lgcc
9. run ./gen_misc.sh 
