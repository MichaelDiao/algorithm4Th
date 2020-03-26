cmake_minimum_required (VERSION 2.6)

#必须在project之前设定好编译器用哪个，否则在project之后设置会在编译时无线循环，提示
#You have changed variables that require your cache to be deleted.
#Configure will be re-run and you may have to reset some variables.
#SET(CMAKE_C_COMPILER "/usr/local/bin/gcc-9")
#SET(CMAKE_CXX_COMPILER "/usr/local/bin/g++-9")
#MESSAGE(STATUS "host operation system is ${CMAKE_HOST_SYSTEM_NAME}")

project(algorithm)

MESSAGE(STATUS "operation system is ${CMAKE_SYSTEM_NAME}")
IF ( ${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    MESSAGE(STATUS "OS: Linux")
    SET(CMAKE_C_COMPILER "gcc")
    SET(CMAKE_CXX_COMPILER "g++")
ELSEIF ( ${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    MESSAGE(STATUS "OS: Mac os, kernal: Darwin.")
    SET(CMAKE_C_COMPILER "/usr/local/bin/gcc-9")
    SET(CMAKE_CXX_COMPILER "/usr/local/bin/g++-9")
ELSE ()
    MESSAGE(FATAL_ERROR "OS: ${CMAKE_SYSTEM_NAME}, stop cmake.")
ENDIF ()

#设置编译器
message(STATUS " compiler: $ENV{CXX} log.")
#设置构建类型，及相应的编译选项
SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "-std=c++11 -O0 -Wall -g -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "-std=c++11 -O2 -Wall")

SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)
LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/lib)

ADD_SUBDIRECTORY( ${PROJECT_SOURCE_DIR}/src)
ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/test)
ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/tools)
