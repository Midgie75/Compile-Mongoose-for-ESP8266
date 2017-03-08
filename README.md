# Compile-Mongoose-for-ESP8266 [DRAFT]

Following steps are run in a Ubuntu Yakkety Virtual Box on a Windows 10 host.

1. Follow https://github.com/pfalcon/esp-open-sdk
2. Clone https://github.com/espressif/ESP8266_RTOS_SDK
3. Clone https://github.com/cesanta/mongoose
4. export SDK_PATH=/path/to/ESP8266_RTOS_SDK
5. export BIN_PATH=./bin
6. export PATH=/path/to/esp-open-sdk/xtensa-lx106-elf/bin:$PATH
7. https://github.com/cesanta/mongoose/tree/master/examples/ESP8266_RTOS
8. correct Makefile: LINKFLAGS -lgcc_sdk ---> -lgcc
9. run ./gen_misc.sh 
10. git clone https://github.com/espressif/esptool
11. sudo apt install python-pip
12. pip install esptool
13. sudo apt install arduino
