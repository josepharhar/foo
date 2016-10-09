#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {

    // string constants are stored in the string table
    char *stringTable = "This string is in the string table";

    // this string is stored in the stack (i think)
    char *stringArray[10];

    // this string is stored in the heap
    char *stringDynAlloc = (char *) malloc(10 * sizeof(char));

    
    // this will print the next thing in the string table
    printf("printing...\n");
    printf("%s\n", "" + 1);
    char *nextString = "this is the next string in the string table";
    printf("done printing\n");

    return 0;
}
