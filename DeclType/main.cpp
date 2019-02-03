#include <iostream>
#include <typeinfo>

using namespace std;

int main() {
  string value;

  cout << typeid(value).name() << endl;


  // decltype used to declare variables based on prev declared variables
  decltype(value) name = "Jake";

  cout << name << endl;


  return 0;
}
