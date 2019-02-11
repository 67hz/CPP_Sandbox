#include <iostream>
using namespace std;

class Parent {
  int dogs;
  string text;

public:

  // Delegating Constructors C++11
  Parent(): Parent("Hello") {
    dogs = 5;
    cout << "No parameter parent constructor" << endl;
  }

  Parent(string text) {
    dogs = 5;
    this->text = text;
    cout << "string parameter parent constructor" << endl;
  }
};


class Child: public Parent {
public:
  Child() = default;

};


int main() {

  Parent parent("Hello");
  Child child;
     
  return 0;
}
