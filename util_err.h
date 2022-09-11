#include <errno.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

#define MAXLINE 4096

void err_sys(const char* fmt, ...) __attribute__((noreturn));
void err_quit(const char* fmt, ...) __attribute__((noreturn));
