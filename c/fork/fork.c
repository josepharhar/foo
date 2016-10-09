#include <stdio.h>

int main() {
    printf("Test\n");
    
    int asdf = fork();

    printf("\npid: %d\n", asdf);
}
