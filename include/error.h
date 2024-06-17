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

typedef struct {
    char* message;
    int exit_code;
} Error;

#define ERR(id) &___ERROR_##_##id

#define ERROR_DEFINE(id, _exit_code, _message)                                  \
    const Error ___ERROR_##_##id = {                                            \
        .message = _message,                                                    \
        .exit_code = _exit_code                                                 \
    };                                                                          \
    ___RESULT_USE(___ERROR_##_##id)

#endif
