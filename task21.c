#include <stdio.h>
#include <time.h>
#include <limits.h>

int main() {
    // time_t time_end = (((time_t) 1 << (sizeof(time_t) * CHAR_BIT - 2)) - 1) * 2 + 1; // Reddit допоміг
    time_t time_end = LONG_MAX;
    printf("Кінець time_t: %ld\n", time_end);
    return 0;
}

// 32 bit - 2^32, 64 bit - 2^64