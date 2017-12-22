#!/bin/bash 

set -e 
PWD=$(pwd)
BUILD_DIR=${PWD}/output

if [ ! -e "$BUILD_DIR" ];then
    mkdir -p "$BUILD_DIR"
    cmake ..
fi

cd "$BUILD_DIR"
make -j2
