#include <iostream>

class Class {
 public:
  int asdf;
};

void ModifyRef(Class& asdf) {
  asdf.asdf = 2;
}

Class GiveCopy() {
  Class asdf;
  asdf.asdf = 3;
  return asdf;
}

int main(int argc, char** argv) {

  Class asdf;
  asdf.asdf = 1;

  std::cout << "asdf.asdf: " << asdf.asdf << std::endl;
  ModifyRef(asdf);
  std::cout << "asdf.asdf: " << asdf.asdf << std::endl;

  Class& copy = GiveCopy();
  copy.asdf = 4;

  return 0;
}
