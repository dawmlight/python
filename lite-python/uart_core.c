#include <unistd.h>
#include "py/mpconfig.h"


// Receive single character
int mp_hal_stdin_rx_chr(void) {
    extern int getchar();
    return getchar();
}

// Send string of given length
void mp_hal_stdout_tx_strn(const char *str, mp_uint_t len) {
    extern int putchar(int ch);
    while (len--) {
        putchar(*str++);
    }
}
