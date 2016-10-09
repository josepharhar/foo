#include <stdio.h>

int main() {
    FILE *fp = fopen("/home/jarhar/rofl", "wb");

    int val = 0xFF;

    fwrite((const void*) & val, sizeof(int), 1, fp);

    return 0;
}
