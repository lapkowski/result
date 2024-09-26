#include <error.h>

#include <stdlib.h>
#include <string.h>

#if defined(_POSIX_VERSION) || defined(__unix__)
#include <execinfo.h>
#endif

#define BACKTRACE_POINTER_ARRAY_INCREMENT 100

static inline void
___Error_obtain_backtrace(Error* error)
{
/* TODO: Win32 implementation */
#if defined(_POSIX_VERSION) || defined(__unix__)
  int allocated_backtrace_size = BACKTRACE_POINTER_ARRAY_INCREMENT;
  error->backtrace = NULL;
  error->backtrace_symbols = NULL;
  for (;;) {
    error->backtrace = malloc(allocated_backtrace_size * sizeof(void*));
    error->backtrace_size =
      backtrace(error->backtrace, allocated_backtrace_size);

    if (error->backtrace_size == allocated_backtrace_size) {
      allocated_backtrace_size += BACKTRACE_POINTER_ARRAY_INCREMENT;
      free(error->backtrace);
      continue;
    }

    error->backtrace_symbols =
      backtrace_symbols(error->backtrace, error->backtrace_size);
    break;
  }
#else
  error->backtrace = NULL;
  error->backtrace_symbols = NULL;
  error->backtrace_size = 0;
#endif
}

Error*
___Error_construct(const ErrorType* type,
                   char* custom_message,
                   Error* source,
                   char* src_file,
                   int src_line,
                   const char* src_function)
{
  Error* error = (Error*)malloc(sizeof(Error));
  error->type = type;

  error->custom_message = NULL;
  if (custom_message) {
    error->custom_message = malloc(strlen(custom_message) + 1);
    memcpy(error->custom_message, custom_message, strlen(custom_message) + 1);
  }

  error->src_file = src_file;
  error->src_line = src_line;
  error->src_function = src_function;
  error->source = source;

  ___Error_obtain_backtrace(error);

  return error;
}

void
error_free(Error* error)
{
  if (error->custom_message)
    free(error->custom_message);
  if (error->source)
    free(error->source);
  if (error->backtrace) {
    free(error->backtrace);
    free(error->backtrace_symbols);
  }

  free(error);
}
