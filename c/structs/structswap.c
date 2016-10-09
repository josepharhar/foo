#include <stdio.h>

typedef struct MyStruct {
    int num1;
    int num2;
} MyStruct;

void structSwap(MyStruct *s1, MyStruct *s2) {
    MyStruct temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

void main() {

    MyStruct my1;
    my1.num1 = 1;
    my1.num2 = 2;

    MyStruct my2;
    my2.num1 = 3;
    my2.num2 = 4;

    printf("before\n");
    printf("my1.num1: %d\nmy1.num2: %d\n", my1.num1, my1.num2);
    printf("my2.num1: %d\nmy2.num2: %d\n", my2.num1, my2.num2);

    structSwap(&my1, &my2);

    printf("\nafter\n");
    printf("my1.num1: %d\nmy1.num2: %d\n", my1.num1, my1.num2);
    printf("my2.num1: %d\nmy2.num2: %d\n", my2.num1, my2.num2);
}
