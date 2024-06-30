/*
    RESULT.H - Implementation of the Result type

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

#ifndef ___RESULT__RESULT___
#define ___RESULT__RESULT___

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include <wchar.h>

#include "panic.h"
#include "error.h"
#include "ports/libc/errors.h"
#include "version.h"

#define Result(type) ___RESULT_ ## type

#define RESULT_DEFINE_WITH_TYPE(type)                                           \
    typedef struct {                                                            \
        type            value;                                                  \
        const Error*    error;                                                  \
        char*           src_file;                                               \
        int             src_line;                                               \
        const char*     src_function;                                           \
    } Result(type);                                                             \
                                                                                \
    RESULT_DEFINE(type)                                                         \

#define RESULT_DECLARE(type)                                                    \
    typedef struct {                                                            \
        type    	    value;                                                  \
        const Error*    error;                                                  \
        char*   	    src_file;                                               \
        int     	    src_line;                                               \
        const char*     src_function;                                           \
    } Result(type);                                                             \
                                                                                \
    Result(type) ___RESULT_## type ##_declare(const Error* error, int src_line, \
                                              char* src_file,                   \
                                              const char* src_function,         \
                                              type value);                      \
                                                                                \
    type ___RESULT_## type ##_unwrap(int src_line, char* src_file,              \
                                     const char* src_function,                  \
                                     Result(type) self);                        \
                                                                                \
    type ___RESULT_## type ##_unwrap_or(Result(type) self, type fallback);      \
                                                                                \
    const Error* ___RESULT_## type ##_unwrap_err_or(Result(type) self,          \
                                                    const Error* fallback);     \
                                                                                \
    type ___RESULT_## type ##_expect(int src_line, char* src_file,              \
                                     const char* src_function,                  \
                                     Result(type) self, const char* error);     \
                                                                                \
    const Error* ___RESULT_## type ##_expect_err(int src_line, char* src_file,  \
                                                 const char* src_function,      \
                                                 Result(type) self,             \
                                                 const char* error);            \
                                                                                \
    const Error* ___RESULT_## type ##_unwrap_err(int src_line, char* src_file,  \
                                                 const char* src_function,      \
                                                 Result(type) self);            \
                                                                                \
    Result(type) ___RESULT_## type ##_and(Result(type) self,                    \
                                          Result(type) other);                  \
                                                                                \
    Result(type) ___RESULT_## type ##_and_then(Result(type) self,               \
                                               Result(type) (*c)(type));        \
                                                                                \
    Result(type) ___RESULT_## type ##_or(Result(type) self,                     \
                                         Result(type) other);                   \
                                                                                \
    const Error* ___RESULT_## type ##_unwrap_err_or(Result(type) self,          \
                                                    const Error* fallback);     \
                                                                                \
    Result(type) ___RESULT_## type ##_or_else(Result(type) self,                \
                                              Result(type) (*c)(const Error*)); \
                                                                                \
    void ___RESULT_## type ##_inspect(Result(type) self, void (*c)(type));      \
                                                                                \
    void ___RESULT_## type ##_inspect_err(Result(type) self,                    \
                                          void (*c)(const Error*));             \
                                                                                \
    bool ___RESULT_## type ##_is_err_and(Result(type) self,                     \
                                         bool (*c)(const Error*));              \
                                                                                \
    bool ___RESULT_## type ##_is_ok_and(Result(type) self, bool (*c)(type));    \


#define RESULT_DEFINE(type)                                                     \
    Result(type) ___RESULT_## type ##_declare(const Error* error, int src_line, \
                                              char* src_file,                   \
                                              const char* src_function,         \
                                              type value)                       \
    {                                                                           \
        Result(type) result = {                                                 \
            .value = value,                                                     \
            .error = error,                                                     \
            .src_file = src_file,                                               \
            .src_line = src_line,                                               \
            .src_function = src_function,                                       \
        };                                                                      \
                                                                                \
        return result;                                                          \
    }                                                                           \
                                                                                \
    type ___RESULT_## type ##_unwrap(int src_line, char* src_file,              \
                                     const char* src_function,                  \
                                     Result(type) self)                         \
    {                                                                           \
        if (is_err(self))                                                     	\
            panic_function(src_line,                                            \
                           src_file,                                            \
                           src_function,                                        \
                           self.error->exit_code,                               \
                           "Tried to unwrap from an error result.\""            \
                           "\n\t\"Error: %s (from %s at %s:%d)",                \
                           self.error->message,                                 \
                           self.src_function,                                 	\
                           self.src_file,                                     	\
                           self.src_line                                      	\
                );                                                              \
                                                                                \
        return self.value;                                                    	\
    }                                                                           \
                                                                                \
    type ___RESULT_## type ##_unwrap_or(Result(type) self, type fallback)       \
    {                                                                           \
        if (is_err(self)) return fallback;                                      \
                                                                                \
        return self.value;                                                      \
    }                                                                           \
                                                                                \
    const Error* ___RESULT_## type ##_unwrap_err_or(Result(type) self,          \
                                                    const Error* fallback)      \
    {                                                                           \
        if (is_ok(self)) return fallback;                                       \
                                                                                \
        return self.error;                                                      \
    }                                                                           \
                                                                                \
    type ___RESULT_## type ##_expect(int src_line, char* src_file,              \
                                     const char* src_function,                  \
                                     Result(type) self, const char* error)      \
    {                                                                           \
        if (is_err(self))                                                     	\
            panic_function(src_line,                                            \
                           src_file,                                            \
                           src_function,                                        \
                           6,                                                   \
                           "\n%s: %s (from %s at %s:%d)",                       \
                           error,                                               \
                           self.error->message,                               	\
                           self.src_function,                                 	\
                           self.src_file,                                     	\
                           self.src_line                                      	\
                );                                                              \
                                                                                \
        return self.value;                                                    	\
    }                                                                           \
                                                                                \
    const Error* ___RESULT_## type ##_expect_err(int src_line, char* src_file,  \
                                                 const char* src_function,      \
                                                 Result(type) self,             \
                                                 const char* error)	            \
    {                                                                           \
        if (is_ok(self))                                                      	\
            panic_function(src_line,                                            \
                           src_file,                                            \
                           src_function,                                        \
                           6,                                                   \
                           "%s",                                                \
                           error                                                \
                );                                                              \
                                                                                \
        return self.error;                                                    	\
    }                                                                           \
                                                                                \
    const Error* ___RESULT_## type ##_unwrap_err(int src_line, char* src_file,  \
                                                 const char* src_function,      \
                                                 Result(type) self)             \
    {                                                                           \
        if (is_ok(self))                                                        \
            panic_function(src_line,                                            \
                           src_file,                                            \
                           src_function,                                        \
                           6,                                                   \
                           "\nTried to unwrap an error from an ok result."      \
                );                                                              \
                                                                                \
        return self.error;                                                      \
    }                                                                           \
                                                                                \
    Result(type) ___RESULT_## type ##_and(Result(type) self,                    \
                                          Result(type) other)                   \
    {                                                                           \
        if (is_ok(self)) return other;                                          \
                                                                                \
        return self;                                                            \
    }                                                                           \
                                                                                \
    Result(type) ___RESULT_## type ##_and_then(Result(type) self,               \
                                               Result(type) (*c)(type))         \
    {                                                                           \
        if (is_ok(self)) return (*c)(self.value);                               \
                                                                                \
        return self;                                                            \
    }                                                                           \
                                                                                \
    Result(type) ___RESULT_## type ##_or(Result(type) self, Result(type) other) \
    {                                                                           \
        if (is_err(self)) return other;                                         \
                                                                                \
        return self;                                                            \
    }                                                                           \
                                                                                \
    Result(type) ___RESULT_## type ##_or_else(Result(type) self,                \
                                              Result(type) (*c)(const Error*))  \
    {                                                                           \
        if (is_err(self)) return (*c)(self.error);                              \
                                                                                \
        return self;                                                            \
    }                                                                           \
                                                                                \
    void ___RESULT_## type ##_inspect(Result(type) self, void (*c)(type))       \
    {                                                                           \
        if (is_ok(self))                                                        \
            (*c)(self.value);                                                   \
    }                                                                           \
                                                                                \
    void ___RESULT_## type ##_inspect_err(Result(type) self,                    \
                                          void (*c)(const Error*))              \
    {                                                                           \
        if (is_err(self))                                                       \
            (*c)(self.error);                                                   \
    }                                                                           \
                                                                                \
    bool ___RESULT_## type ##_is_err_and(Result(type) self,                     \
                                         bool (*c)(const Error*))               \
    {                                                                           \
        return is_err(self) && (*c)(self.error);                                \
    }                                                                           \
                                                                                \
    bool ___RESULT_## type ##_is_ok_and(Result(type) self, bool (*c)(type))     \
    {                                                                           \
        return is_ok(self) && (*c)(self.value);                                 \
    }                                                                           \

#define result_and(type, self, other)                                           \
    ___RESULT_## type ##_and(self, other)

#define result_and_then(type, self, call) ___RESULT_## type ##_and(self, call)

#define result_expect(type, result, error)                                      \
    ___RESULT_## type ##_expect(__LINE__, __FILE__, __func__, result, error)

#define result_expect_err(type, result, error)                                  \
    ___RESULT_## type ##_expect_err(__LINE__, __FILE__, __func__, result, error)

#define result_inspect(type, result, call)                                      \
    ___RESULT_## type ##_inspect(result, call)

#define result_inspect_err(type, result, call)                                  \
    ___RESULT_## type ##_inspect_err(result, call)

#define result_is_err_and(type, self, call)                                     \
    ___RESULT_## type ##_is_err_and(self, call)

#define result_is_ok_and(type, self, call)                                      \
    ___RESULT_## type ##_is_ok_and(self, call)

#define result_unwrap(type, result)                                             \
    ___RESULT_## type ##_unwrap(__LINE__, __FILE__, __func__, result)

#define result_unwrap_err(type, result)                                         \
    ___RESULT_## type ##_unwrap_err(__LINE__, __FILE___, __func__, result)

#define result_unwrap_or(type, result, fallback)                                \
    ___RESULT_## type ##_unwrap_or(result, fallback)

#define result_unwrap_err_or(type, result, fallback)                            \
    ___RESULT_## type ##_unwrap_err_or(result, fallback)

#define result_or(type, self, other) ___RESULT_## type ##_or(self, other)

#define result_or_else(type, self, call)                                        \
    ___RESULT_## type ##_or_else(self, call)


#define result_ERR(type, error)                                                 \
    ___RESULT_## type ##_declare(ERR(error), __LINE__, __FILE__, __func__, 0)

#define ___RESULT_ERR_RAW(type, error)                                          \
    ___RESULT_## type ##_declare(error, __LINE__, __FILE__, __func__, 0)


#define result_is_ok(self) self.error == NULL
#define result_is_err(self) self.error != NULL


#define ___RESULT_ARG(_1, _2, _3, ...) _3
#define ___RESULT_HAS_COMMA(...) ___RESULT_ARG(__VA_ARGS__, 0, 0, 1, 1)

#define ___RESULT_OK_EXPAND(x) ___RESULT_OK ## x
#define ___RESULT_OK_HELPER(x) ___RESULT_OK_EXPAND(x)

#define result_OK(...)                                                          \
    ___RESULT_OK_HELPER(___RESULT_HAS_COMMA(__VA_ARGS__))(__VA_ARGS__)

#define ___RESULT_OK0(...)                                                      \
    ___RESULT_void_declare(NULL, __LINE__, __FILE__, __func__, __VA_ARGS__)

#define ___RESULT_OK1(type, ...)                                                \
    ___RESULT_## type ##_declare(NULL, __LINE__, __FILE__, __func__)

#ifndef RESULT_DONT_DEFINE_SHORTCUTS

#define expect result_expect
#define expect_err result_expect_err
#define is_err_and result_is_err_and
#define is_ok_and result_is_ok_and
#define unwrap_err result_unwrap_err
#define unwrap result_unwrap
#define unwrap_or result_unwrap_or

#define is_ok result_is_ok
#define is_err result_is_err

#endif

RESULT_DECLARE(char)
typedef char* char_ptr;
RESULT_DECLARE(char_ptr)
RESULT_DECLARE(int8_t)
RESULT_DECLARE(int16_t)
RESULT_DECLARE(int32_t)
RESULT_DECLARE(int64_t)
RESULT_DECLARE(int_fast8_t)
RESULT_DECLARE(int_fast16_t)
RESULT_DECLARE(int_fast32_t)
RESULT_DECLARE(int_fast64_t)
RESULT_DECLARE(int_least8_t)
RESULT_DECLARE(int_least16_t)
RESULT_DECLARE(int_least32_t)
RESULT_DECLARE(int_least64_t)
RESULT_DECLARE(intmax_t)
RESULT_DECLARE(intptr_t)
RESULT_DECLARE(uint8_t)
RESULT_DECLARE(uint16_t)
RESULT_DECLARE(uint32_t)
RESULT_DECLARE(uint64_t)
RESULT_DECLARE(uint_fast8_t)
RESULT_DECLARE(uint_fast16_t)
RESULT_DECLARE(uint_fast32_t)
RESULT_DECLARE(uint_fast64_t)
RESULT_DECLARE(uint_least8_t)
RESULT_DECLARE(uint_least16_t)
RESULT_DECLARE(uint_least32_t)
RESULT_DECLARE(uint_least64_t)
RESULT_DECLARE(uintmax_t)
RESULT_DECLARE(uintptr_t)
RESULT_DECLARE(bool)
RESULT_DECLARE(int)
RESULT_DECLARE(short)
RESULT_DECLARE(size_t)
RESULT_DECLARE(ptrdiff_t)
RESULT_DECLARE(wchar_t)

/* RESULT_DECLARE(void) */
typedef struct {
        const Error*    error;
        char*           src_file;
        int             src_line;
        const char*     src_function;
} ___RESULT_void;

Result(void) ___RESULT_void_declare_real(const Error* error,
                                         int src_line, char* src_file,
                                         const char* src_function);

void ___RESULT_void_unwrap(int src_line, char* src_file,
                           const char* src_function, Result(void) self);

void ___RESULT_void_unwrap_or(Result(void) result);

void ___RESULT_void_expect(int src_line, char* src_file,
                           const char* src_function, Result(void) self,
                           const char* error);

const Error* ___RESULT_void_expect_err(int src_line, char* src_file,
                                       const char* src_function,
                                       Result(void) self,
                                       const char* error);

const Error* ___RESULT_void_unwrap_err(int src_line, char* src_file,
                                       const char* src_function,
                                       Result(void) self);

Result(void) ___RESULT_void_and(Result(void) self, Result(void) other);

Result(void) ___RESULT_void_and_then(Result(void) self,
                                     Result(void) (*c)(void));

Result(void) ___RESULT_void_or(Result(void) self, Result(void) other);

const Error* ___RESULT_void_unwrap_err_or(Result(void) self,
                                          const Error* fallback);

Result(void) ___RESULT_void_or_else(Result(void) self,
                                    Result(void) (*c)(const Error*));

void ___RESULT_void_inspect(Result(void) self, void (*c)(void));

void ___RESULT_void_inspect_err(Result(void) self, void (*c)(const Error*));

bool ___RESULT_void_is_err_and(Result(void) self, bool (*c)(const Error*));

bool ___RESULT_void_is_ok_and(Result(void) self, bool (*c)(void));

#endif
