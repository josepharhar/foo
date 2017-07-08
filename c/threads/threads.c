#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include <stdint.h>

#define NUM_THREADS 2

// do threads have their own pid just like fork()ed processes?
// is a thread id (tid) just some library/pthread concept that the OS does not recognize?

void PrintPrefix() {
  printf("[%d] ", getpid());
}

void* Thread(void* arg) {
  PrintPrefix();
  printf("hello from Thread() %lu\n", *((uint64_t*) arg));
  return 0;
}

void main() {
  PrintPrefix();
  printf("main()\n");

  pthread_t thread[NUM_THREADS];
  uint64_t args[NUM_THREADS];

  for (int i = 0; i < NUM_THREADS; i++) {
    args[i] = i + 1;
    pthread_create(thread + i, NULL, &Thread, args + i);
  }

  pthread_exit(NULL);
}
