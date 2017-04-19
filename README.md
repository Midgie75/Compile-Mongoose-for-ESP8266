# Compile-Mongoose-for-ESP8266 [DRAFT]

Following steps are run in a Ubuntu Yakkety Virtual Box on a Windows 10 host.

1. Followed https://github.com/pfalcon/esp-open-sdk
2. Cloned https://github.com/espressif/ESP8266_RTOS_SDK
3. Cloned https://github.com/cesanta/mongoose
4. Said export SDK_PATH=/path/to/ESP8266_RTOS_SDK
5. Said export BIN_PATH=./bin
6. Said export PATH=/path/to/esp-open-sdk/xtensa-lx106-elf/bin:$PATH
7. Made a local copy of https://github.com/cesanta/mongoose/tree/master/examples/ESP8266_RTOS
8. Edited Makefile: LINKFLAGS -lgcc_sdk ---> -lgcc
9. run ./gen_misc.sh 
10. I use a ESP8266 ESP01-S module. I run gen_misc.sh with parameters for app=user1.bin, SPI-speed=40MHz, SPI-mode=QIO, SPI-size=1024kB
11. I copied boot_v1.6.bin from ESP8266_RTOS_SDK/bin directory to BIN_PATH
12. I downloaded Espressif FLASH_DOWNLOAD_TOOLS_V3.4.4
