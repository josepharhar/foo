#include <stdio.h>

void swap(int* one, int* two) {
    int temp = *one;
    *one = *two;
    *two = temp;
}

void sort(int* vals, int size) {
    int *next = vals + 1, *loc, *pLoc, *valsEnd = vals + size;

    while (next < valsEnd) {
        pLoc = next - 1;
        loc = next++;

        while (loc > vals && *loc < *pLoc) {
            swap(loc--, pLoc--);
        }
    }
}

void main() {
    int array[5];

    array[0] = 3;
    array[1] = 2;
    array[2] = -1;
    array[3] = 5;
    array[4] = -3;

    sort(array, 5);

    int i = 0;
    while (i < 5) {
        printf("%d: %d\n", i, array[i]);
        i++;
    }
}
