#include <stdio.h>
#include <stdarg.h>

void va(const char* format, ...) {
  printf("va(\"%s\")\n", format);

  va_list list;

  va_start(list, format);

  const char* s;
  while (s = va_arg(list, const char*)) {
    printf("va_arg(): \"%s\"\n", s);
  }

  va_end(list);
}

void main() {
  va("one", "two", "three");
}
