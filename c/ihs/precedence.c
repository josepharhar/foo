#include <stdio.h>

int main() {
    int array[2];
    array[0] = 4;
    array[0] = 5;

    int *iPtr = array;

    printf("%d\n", *iPtr++);

    return 0;
}
