#include "Parent.h"

Parent::Parent():one(0) {
  cout << "Parent constructor" << endl;
}

Parent::Parent(const Parent &other) {
  one = other.one;
  cout << "Copy Constructor from Parent" << endl;
}

void Parent::print() {
  cout << "Parent" << endl;
}

void Parent::test() {
  cout << "Test" << endl;
}

Parent::~Parent() {
  cout << "Parent deconstructor" << endl;
}

Child::Child():two(2) {
  cout << "Child constructor" << endl;
}

Child::Child(const Child &other) {
  two = other.two;
  cout << " Child copy constructor" << endl;

}

void Child::print() {
  cout << "Child" << endl;
};

Child::~Child() {
  cout << "Child deconstructor" << endl;
}
