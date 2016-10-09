#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int *array, int size) {
   int *last = array + size;
   int *iPtr1 = array;
   int *iPtr2;
   while (iPtr1 < last) {
       for (iPtr2 = iPtr1; iPtr2 > array && *iPtr2 < *(iPtr2 - 1); iPtr2--) {
           swap(iPtr2, iPtr2 - 1);
           iPtr2--;
       }
       iPtr1++;
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

    array[0] = 2;
    array[1] = 4;
    array[2] = -2;
    array[3] = 3;
    array[4] = 2;

    sort(array, 5);

    printArray(array, 5);
}
