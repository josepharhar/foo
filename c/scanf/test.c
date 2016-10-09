#include <stdio.h>
#include <stdlib.h>

void main() {
    int* iptr = (int*) malloc(sizeof(int));

    printf("program running\n");
    printf("enter a thing: ");
    scanf("%d", iptr);

    printf("scanned: %d\n", *iptr);
}
