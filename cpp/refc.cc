#include <iostream>

static int refcount = 0;

class Class {


 public:
  Class() {
    std::cout << "Class::Class() refcount: " << refcount << " -> " << (refcount + 1) << std::endl;
    refcount++;
  }

  ~Class() {
    std::cout << "Class::~Class() refcount: " << refcount << " -> " << (refcount - 1) << std::endl;
    refcount--;
  }

  /*Class(Class && other_class) {
    std::cout << "Class::Class(Class&& other_class)" << std::endl;
  }*/

  Class(const Class& other_class) {
    std::cout << "Class::Class(const Class& other_class) refcount: " << refcount << " -> " << (refcount + 1) << std::endl;
    refcount++;
  }

  void Hello() {
    std::cout << "Class::Hello()" << std::endl;
  }

  Class& operator=(const Class& other_class) {
    std::cout << "Class::operator= refcount: " << refcount << " -> " << (refcount + 1) << std::endl;
    refcount++;
  }
};

Class UseClass(Class my_class) {
  my_class.Hello();
}

int main(int argc, char** argv) {

  Class my_class;
  std::cout << "UseClass()" << std::endl;
  my_class = UseClass(my_class);
  std::cout << "UseClass() returned" << std::endl;

  return 0;
}
