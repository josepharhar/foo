#include <stdio.h>

void shared() {
  printf("hello from shared library!\n");
}

void* malloc(size_t size) {
  printf("hello from malloc()\n");
  return NULL;
}
