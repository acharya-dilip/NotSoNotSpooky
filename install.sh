#!/bin/bash

#Installing Dependencies
sudo pacman -S base-devel
sudo pacman -S cmake
sudo pacman -S gtk
sudo pacman -S curl
sudo pacman -S gstreamer
#Building the C program
mkdir build
cd build
cmake ..
cmake --build .
#Moving the required files in the build directory
mv styles.css src sounds ~/build
