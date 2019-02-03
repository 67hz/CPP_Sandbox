#include <iostream>
#include <vector>
#include "Animal.h"

using namespace std;


void test(Animal &a) {
  a.run();
}


int main() {
  Labrador lab;
  lab.run();
  lab.speak();

  // Animal bud = Animal(); // cannot allocate an object of abstract class
  //
  // ptrs to abstract class
  Animal *animals[5];


  // ref to concrete class
  animals[0] = &lab;
  animals[0]->run();

  cout << "test(lab): " << flush;
  test(lab);



}
