#include "test.h"
#include <stdio.h>

int main() {
    char *asdf = "TEST_MESSAGE";
    int number = TEST_NUMBER;
    printf("test number: %d\n", number);

    testPrint(asdf);
}
