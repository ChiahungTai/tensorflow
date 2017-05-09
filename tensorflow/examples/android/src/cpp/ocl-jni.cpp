/*
 * Copyright (C) 2016 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
#include <string.h>
#include <jni.h>

#include <CL/cl2.hpp>
#include "android_debug.h"

void
OCL_error_message( int error_code, const char* error_message )
{
    if ( error_code != CL_SUCCESS )
    {
        LOGE( "ERROR %i: (%s)\n", error_code, error_message );
    }
}

extern "C" {

JNIEXPORT void JNICALL
Java_org_tensorflow_demo_ClassifierActivity_Test(JNIEnv *env, jclass type) {

    cl_uint platform_number;    // number of available platforms

    OCL_error_message(clGetPlatformIDs(0, NULL, &platform_number), "clGetPlatformIDs failed");
    if (platform_number == 0) {
        LOGE("There are no any available OpenCL platforms\n");
    }

    LOGE("\n\n  @@@@OpenCL rock %d \n\n", platform_number);

}

}