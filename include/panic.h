/*
    PANIC.H - Program abort behavior

    Copyright (C) 2024 Mariusz Łapkowski

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#ifndef ___RESULT__PANIC___
#define ___RESULT__PANIC___

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define RESULT_PANIC_FUNCTION_PARAMTETERS                                       \
    int src_line,                                                               \
    const char* src_file,                                                       \
    const char* src_function,                                                   \
    int exit_code,                                                              \
    void* message,                                                              \
    ...

#define FIX_RESULT_UNUSED                                                       \
    (void) src_file;                                                            \
    (void) src_line;                                                            \
    (void) src_function;                                                        \
    (void) exit_code;                                                           \
    (void) message;

typedef void (*___PanicFunction)(RESULT_PANIC_FUNCTION_PARAMTETERS);

#define panicf(code, ...)                                                       \
    panic_function(__LINE__, __FILE__, __func__, code, __VA_ARGS__)

#ifndef PANIC_FUNCTION
#define PANIC_FUNCTION ___default_panic
#endif

extern ___PanicFunction panic_function;

#endif
