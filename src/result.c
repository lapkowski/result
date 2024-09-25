/*
    RESULT.C - Definitions of the libc result types

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

#include <result.h>

#include <wchar.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/* RESULT_DEFINE(void) */
#define ___RESULT_void_declare(error, src_line, src_file, src_function, ...)    \
    ___RESULT_void_declare_real(error, src_line, src_file, src_function)

Result(void) ___RESULT_void_declare_real(const ErrorType* error,
                                         int src_line, char* src_file,
                                         const char* src_function)
{
    Result(void) result = {
        .error = error,
        .src_file = src_file,
        .src_line = src_line,
        .src_function = src_function,
    };

    return result;
}

void ___RESULT_void_unwrap(int src_line, char* src_file,
                           const char* src_function, Result(void) self)
{
    if (is_err(self))
        panic_function(src_line,
                       src_file,
                       src_function,
                       self.error->exit_code,
                       "Tried to unwrap from an error result."
                       "\n\tError: %s (from %s at %s:%d)",
                       self.error->message,
                       self.src_function,
                       self.src_file,
                       self.src_line
            );
}

void ___RESULT_void_unwrap_or(Result(void) result)
{
    (void)(result);
}

void ___RESULT_void_expect(int src_line, char* src_file,
                           const char* src_function, Result(void) self,
                           const char* error)
{
    if (is_err(self))
        panic_function(src_line,
                       src_file,
                       src_function,
                       6,
                       "%s: %s (from %s at %s:%d)",
                       error,
                       self.error->message,
                       self.src_function,
                       self.src_file,
                       self.src_line
            );
}

const ErrorType* ___RESULT_void_expect_err(int src_line, char* src_file,
                                       const char* src_function,
                                       Result(void) self,
                                       const char* error)
{
    if (is_ok(self))
        panic_function(src_line,
                       src_file,
                       src_function,
                       6,
                       "%s",
                       error
            );

    return self.error;
}

const ErrorType* ___RESULT_void_unwrap_err(int src_line, char* src_file,
                                       const char* src_function,
                                       Result(void) self)
{
    if (is_ok(self))
        panic_function(src_line,
                       src_file,
                       src_function,
                       6,
                       "Tried to unwrap an error from an ok result."
            );

    return self.error;
}

Result(void) ___RESULT_void_and(Result(void) self, Result(void) other)
{
    if (is_ok(self)) return other;

    return self;
}

Result(void) ___RESULT_void_and_then(Result(void) self,
                                     Result(void) (*c)(void))
{
    if (is_ok(self)) return (*c)();

    return self;
}

Result(void) ___RESULT_void_or(Result(void) self, Result(void) other)
{
    if (is_err(self)) return other;

    return self;
}

const ErrorType* ___RESULT_void_unwrap_err_or(Result(void) self,
                                          const ErrorType* fallback)
{
    if (is_ok(self)) return fallback;

    return self.error;
}

Result(void) ___RESULT_void_or_else(Result(void) self,
                                    Result(void) (*c)(const ErrorType*))
{
    if (is_err(self)) return (*c)(self.error);

    return self;
}

void ___RESULT_void_inspect(Result(void) self, void (*c)(void))
{
    if (is_ok(self))
        (*c)();
}

void ___RESULT_void_inspect_err(Result(void) self, void (*c)(const ErrorType*))
{
    if (is_err(self))
        (*c)(self.error);
}

bool ___RESULT_void_is_err_and(Result(void) self, bool (*c)(const ErrorType*))
{
    return is_err(self) && (*c)(self.error);
}

bool ___RESULT_void_is_ok_and(Result(void) self, bool (*c)(void))
{
    return is_ok(self) && (*c)();
}

RESULT_DEFINE(char)
RESULT_DEFINE(char_ptr)
RESULT_DEFINE(int8_t)
RESULT_DEFINE(int16_t)
RESULT_DEFINE(int32_t)
RESULT_DEFINE(int64_t)
RESULT_DEFINE(int_fast8_t)
RESULT_DEFINE(int_fast16_t)
RESULT_DEFINE(int_fast32_t)
RESULT_DEFINE(int_fast64_t)
RESULT_DEFINE(int_least8_t)
RESULT_DEFINE(int_least16_t)
RESULT_DEFINE(int_least32_t)
RESULT_DEFINE(int_least64_t)
RESULT_DEFINE(intmax_t)
RESULT_DEFINE(intptr_t)
RESULT_DEFINE(uint8_t)
RESULT_DEFINE(uint16_t)
RESULT_DEFINE(uint32_t)
RESULT_DEFINE(uint64_t)
RESULT_DEFINE(uint_fast8_t)
RESULT_DEFINE(uint_fast16_t)
RESULT_DEFINE(uint_fast32_t)
RESULT_DEFINE(uint_fast64_t)
RESULT_DEFINE(uint_least8_t)
RESULT_DEFINE(uint_least16_t)
RESULT_DEFINE(uint_least32_t)
RESULT_DEFINE(uint_least64_t)
RESULT_DEFINE(uintmax_t)
RESULT_DEFINE(uintptr_t)
RESULT_DEFINE(bool)
RESULT_DEFINE(int)
RESULT_DEFINE(short)
RESULT_DEFINE(size_t)
RESULT_DEFINE(ptrdiff_t)
RESULT_DEFINE(wchar_t)
