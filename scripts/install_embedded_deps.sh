
sudo apt-get -qq update

# AVR GCC
sudo apt-get install -qq gcc-avr binutils-avr avr-libc

# ARDUINO SDK
sudo apt-get install arduino arduino-core
export PATH=$PATH:/usr/bin:/usr/local/bin
