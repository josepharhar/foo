#include <stdio.h>

void squareArray(int *array, int dim) {
    int i;

    for (i = 0; i < dim; i++) {
        *(array + i) = *(array + i) * *(array + i);
    }
}

void printArray(int *array, int dim) {
    int i;

    for (i = 0; i < dim; i++) {
        printf("array[%d]: %d\n", i, *(array + i));
    }
}

int main() {
    int *iPtr;
    int intArr[5];

    intArr[0] = 2;
    intArr[1] = 3;

    squareArray(intArr, 2);

    printArray(intArr, 2);
}
