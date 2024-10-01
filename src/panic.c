/*
    PANIC.C - Program abort behavior

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

#include <panic.h>

#include <stdbool.h>

PanicFunction panic_function = &PANIC_FUNCTION;
bool panic_exit_on_panic = true;

void panic_set_panic_function(PanicFunction new)
{
    if (new == NULL) panic("Api abuse on panic_set_panic_function (new == NULL).");
    panic_function = new;
}

void ___default_panic(RESULT_PANIC_FUNCTION_PARAMTETERS)
{
    va_list arguments;
    va_start(arguments, message);

    fprintf(stderr, "The program panicked with a following message: \"");
    vfprintf(stderr, message, arguments);
    fprintf(stderr, 
            "\", at %s:%d in the %s function\n\n", 
            src_file, 
            src_line, 
            src_function
        );

    fprintf(stderr, "The program %s with exit code %d.\n", panic_exit_on_panic ? "exited" : "\"exited\"", exit_code);
    va_end(arguments);
    if (panic_exit_on_panic) exit(exit_code);
}
