/*
    ERROR.H - Implementation of the Error type

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

#ifndef ___RESULT__ERROR___
#define ___RESULT__ERROR___

#define ___RESULT_USE(x)

typedef struct
{
  char* message;
  int exit_code;
} ErrorType;

struct Error
{
  const ErrorType* type;
  char* custom_message;
  char* src_file;
  int src_line;
  const char* src_function;
  struct Error* source;
  void* backtrace;
  int backtrace_size;
  char** backtrace_symbols;
};

typedef struct Error Error;

Error*
__Error_construct(const ErrorType* type,
                  char* custom_message,
                  Error* source,
                  char* src_file,
                  int src_line,
                  const char* src_function);

#define ___ERROR_ARG(_1, _2, _3, _4, ...) _4
#define ___ERROR_COUNT_COMMAS(...) ___ERROR_ARG(__VA_ARGS__, 2, 1, 0, 0)

#define ___ERROR_CONSTRUCT_EXPAND(x) ___ERROR_CONSTRUCT##x
#define ___ERROR_CONSTRUCT_HELPER(x) ___ERROR_CONSTRUCT_EXPAND(x)
#define Error_construct(...)                                                   \
  ___ERROR_CONSTRUCT_HELPER(___ERROR_COUNT_COMMAS(__VA_ARGS__)(__VA_ARGS__))

#define ___ERROR_CONSTRUCT0(type)                                              \
  ___Error_construct(type, NULL, NULL, __FILE__, __LINE__, __func__)
#define ___ERROR_CONSTRUCT1(type, ...)                                         \
  ___Error_construct(type, __VA_ARGS__, NULL, __FILE__, __LINE__, __func__)
#define ___ERROR_CONSTRUCT2(type, ...)                                         \
  ___Error_construct(type, __VA_ARGS__, __FILE__, __LINE__, __func__)

void
Error_free(Error* error);

#define ERRTYPE(id) &___ERRORTYPE_##_##id

#define ERRORTYPE_DECLARE(id) extern const ErrorType ___ERRORTYPE_##_##id;

#define ERRORTYPE_DEFINE(id, _exit_code, _message)                             \
  const ErrorType ___ERRORTYPE_##_##id = { .message = _message,                \
                                           .exit_code = _exit_code };          \
  ___RESULT_USE(___ERROR_##_##id)

#endif
