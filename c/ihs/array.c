#include <stdio.h>

void fillArray(int *array, int size) {
    int *iPtr = array;
    while (array + size > iPtr) {
        printf("enter a number: ");
        scanf("%d", iPtr);
        iPtr += 1;
    }
}

void printArray(int *array, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d: %d\n", i, array[i]);
    }
}

int main() {
    int array[5];
    
    fillArray(array, 5);

    printArray(array, 5);

    return 0;
}
