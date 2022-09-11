#include "util_err.h"

static void err_doit(int errnoflag, int error_num, const char* fmt, va_list ap) {
    char buf[MAXLINE];

    vsnprintf(buf, MAXLINE-1, fmt, ap);
    if(errnoflag) {
        snprintf(buf+strlen(buf),  MAXLINE-strlen(buf)-1, ": %s", strerror(error_num));
    }
    strcat(buf, "\n");
    fflush(stdout);     /* in case stdout and stderr are the same */
    fputs(buf, stderr);
    fflush(NULL);       /* flushes all stdio output streams */
}

/*
 * Fatal error related to a system call.
 * Print a message and terminate.
 */
void err_sys(const char* fmt, ...) {
    va_list ap;
    
    va_start(ap, fmt);
    err_doit(1, errno, fmt, ap);
    va_end(ap);
    exit(1);
}

/*
 * Fatal error unrelated to a system call.
 * Print a message and terminate.
 */
void err_quit(const char* fmt, ...) {
    va_list ap;

    va_start(ap, fmt);
    err_doit(0, 0, fmt, ap);
    va_end(ap);
    exit(1);
}