#include <stdio.h>

void shared();
void* malloc();

int main() {
  printf("main calling shared()\n");
  shared();
  malloc(1234);
  printf("main returned from shared()\n");
  return 0;
}
