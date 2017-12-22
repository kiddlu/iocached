cmake_minimum_required(VERSION 2.8)
project (iocached CXX)
add_definitions ()

#static link
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")

file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/*.cpp")
add_executable(iocached  ${SOURCES})
