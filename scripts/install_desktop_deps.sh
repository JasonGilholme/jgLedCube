#!/usr/bin/env bash

sudo apt-get -qq update

# Clang
sudo apt-get install clang

# Boost
sudo apt-get install libboost1.55-all-dev

# Python Dev
sudo apt-get install python-dev

# GoogleTest
sudo apt-get install -y libgtest-dev
cd /usr/src/gtest
sudo cmake .
sudo cmake --build .
sudo mv libg* /usr/local/lib/

# Qt5
sudo apt-get install -y qt5-default qt5-qmake
sudo add-apt-repository --yes ppa:ubuntu-sdk-team/ppa
sudo apt-get update -qq
sudo apt-get install -qq qt5-qmake qtbase5-dev qtdeclarative5-dev qtserialport5-dev

# Socat - serial port virtualisation for testing
sudo apt-get install socat

cd -
