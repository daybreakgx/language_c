#include <stdio.h>
#include <gnu/libc-version.h>

void main() {
    printf("GNU C library version: %s\n", gnu_get_libc_version());
    printf("GNU C library release: %s\n", gnu_get_libc_release());
}
