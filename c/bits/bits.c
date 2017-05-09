#include <stdio.h>
#include <stdint.h>

struct BitField {
  /*uint32_t one:3;
  uint32_t two:1;
  uint32_t three:8;
  uint32_t four:5;
  uint32_t five:10;
  uint32_t six:5;*/
  uint32_t d1:4;
  uint32_t d2:4;
  uint32_t d3:4;
  uint32_t d4:4;
  uint32_t d5:4;
  uint32_t d6:4;
  uint32_t d7:4;
  uint32_t d8:4;
} __attribute__((packed));

struct BitField ToBitField(uint32_t data) {
  struct BitField* pointer= (struct BitField*) &data;
  return *pointer;
}

uint32_t FromBitField(struct BitField bit_field) {
  uint32_t* pointer = (uint32_t*) &bit_field;
  return *pointer;
}

void main() {
  /*uint32_t data = 0x12345678;
  printf("  data: 0x%X\n", data);

  struct BitField bit_field 
  printf("struct: 0x%X\n", */

  struct BitField asdf;
  asdf.d1 = 8;
  asdf.d2 = 7;
  asdf.d3 = 6;
  asdf.d4 = 5;
  asdf.d5 = 4;
  asdf.d6 = 3;
  asdf.d7 = 2;
  asdf.d8 = 1;

  printf("data: 0x%X\n", FromBitField(asdf));
}
