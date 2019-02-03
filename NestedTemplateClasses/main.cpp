#include <iostream>
#include "ring.h"
using namespace std;

int main() {

  ring<string> textring(3);

  textring.add("one");
  textring.add("two");
  textring.add("three");
  textring.add("four");
  textring.add("five");


  // C++98 style
  for(ring<string>::iterator it = textring.begin(); it != textring.end(); it++) {
    cout << *it << endl;
  }

  // C++11 style
  for(string value: textring) {
    cout << value << endl;
  }

  return 0;
}
