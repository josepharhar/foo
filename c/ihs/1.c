#include <stdio.h>

int main() {
       int i = 42;
          int *iPtr1 = &i, *iPtr2;
             
    iPtr2 = &i;

    printf("%d\n", *iPtr2);

    return 0;
}
