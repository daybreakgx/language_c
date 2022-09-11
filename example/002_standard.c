#include <stdio.h>
#include <unistd.h>

void main() {
    printf("c standard: %ld\n", __STDC_VERSION__);
    printf("posix standard: %ld\n", _POSIX_VERSION);
}
