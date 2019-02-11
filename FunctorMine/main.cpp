#include <iostream>
#include <assert.h>
class add_x {
private:
    int x;

public:
  add_x(int x): x(x) {};

  int operator()(int y) const {return x + y;}
};




int main() {

  add_x add42(42); // create an instance of the functor class with private x
  int i = add42(8);
  assert(i == 50);

  add_x add10(10); // x = 10
  int j = add10(100);

  assert(j == 110);

  std::cout << "assertion good" << std::endl;

  return 0;
}
