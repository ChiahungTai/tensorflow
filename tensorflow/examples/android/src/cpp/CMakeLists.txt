cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Werror")

add_library(ocl_tensor SHARED
            ocl-jni.cpp)

set(lib_src_DIR "/home/ctai/Qualcomm_OCL_SDK")

include_directories(${lib_src_DIR}/)

add_library(OpenCL
            SHARED
            IMPORTED)

set_target_properties(OpenCL
                      PROPERTIES IMPORTED_LOCATION
# change to lib64 when ABI is arm64-v8a.
#                     ${lib_src_DIR}/lib64/libOpenCL.so)
                      ${lib_src_DIR}/lib/libOpenCL.so)


# include libraries needed for hello-jni lib
target_link_libraries(ocl_tensor
                      android
                      log
                      OpenCL)

# Android Studio 2.2.0 with CMake support does not pack stl shared libraries,
# so app needs to pack the right shared lib into APK. This sample uses solution
# from https://github.com/jomof/ndk-stl to find the right stl shared lib to use
# and copy it to the right place for Android Studio to pack
# Usage: download ndk-stl-config.cmake into app's directory hosting CMakeLists.txt
#        and just use it with the following line

#include(ndk-stl-config.cmake)
