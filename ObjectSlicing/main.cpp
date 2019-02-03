#include <iostream>
#include "Parent.h"
using namespace std;


int main() {
  Child c1;
  Parent &p1 = c1;
  p1.print();

  // invokes copy constructor from parent class
  // Upcasting child to parent type - Object slicing
  // child members get sliced off (two)
  Parent p2 = Child();
  p2.print();

  return 0;
}

