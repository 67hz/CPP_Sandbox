#include <iostream>
#include "instrument.h"
using namespace std;


int main() {
  instrument<int>::iterator it;
  it.print();

  return 0;
}
