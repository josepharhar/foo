#include <stdio.h>
#include <stdint.h>

struct Rofl {
  uint8_t one; // 0x01
  uint8_t two; // 0x23
  uint16_t three; // 0x4567

  // 0x89
  uint8_t four:4;
  uint8_t five:2;
  uint8_t six:2;
} __attribute__((packed));

void main() {

  struct Rofl asdf = {0};
  asdf.one = 0x01;
  asdf.two = 0x23;
  asdf.three = 0x4567;

  asdf.four = 0x8;
  asdf.five = (0x9 >> 2) & 0x3;
  asdf.six = 0x9 & 0x3;

  // should be   ABCD1234
  // actually is B0ABD0CD40342012
  
  printf("number of bytes (expecting 4): %d\n", sizeof(struct Rofl));

  for (int i = 0; i < sizeof(struct Rofl); i++) {
    uint8_t byte = ((uint8_t*) &asdf)[i];
    printf("%X", (byte >> 4) & 0xF);
    printf("%X", byte & 0xF);
  }

  printf("\n");
}
