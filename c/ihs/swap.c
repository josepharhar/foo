#include <stdio.h>

int swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int x, y;

    scanf("%d", &x);
    scanf("%d", &y);

    printf("before swap: x = %d and y = %d\n", x, y);

    swap(&x, &y);

    printf("after swap: x = %d and y = %d\n", x, y);
    
    return 0;
}
