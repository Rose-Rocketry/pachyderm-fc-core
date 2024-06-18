#include "DataSink.h"
#include <cstdarg>
#include <cstdio>

// This default implementation is kinda clunky, it may be worth rewriting it if
// the particular implementation supports better formats
void pachy::DataSink::printf(const char *format, ...) {
    // printf is kinda awful because it's a C-style vararg - a function that
    // takes a runtime-variable number of arguments via ugly macro hacks
    va_list args, args2;
    va_start(args, format);
    // varargs are single-use, so we have to make a copy so that the first call
    // doesn't destroy it
    va_copy(args2, args);
    // Trick to predict the length of a printf string
    int n = vsnprintf(NULL, 0, format, args) + 1;
    va_end(args);
    // Sorta hacky variable length stack array
    char buf[n];
    // Finally actually print it
    vsnprintf(buf, n, format, args2);
    va_end(args2);

    write(buf, n-1);
}