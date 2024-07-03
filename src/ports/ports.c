/*
    PORTS/PORTS.C - Common functions for porting functions to result based error handling.

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

#include <ports/ports.h>
#include <ports/libc/errors.h>

const Error* ____result_bind_errno_to_error(int c_err)
{
    for (int i= 0; i < ___errno_binds_size; i++)
        if (___errno_binds[i].c_errno == c_err) return ___errno_binds[i].error;

    return ERR(UnknownError);
}
