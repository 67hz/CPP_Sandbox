#include <iostream>
using namespace std;

class Test {
  // C++11 
  int id{3};
  string name{"Jake"};

public:

  // supplying constructor loses implicit constructor
  //
  // C++!! use below to add implicit constructor (default)
  Test() = default;

  // C++11 above works for copy constructor 
  // Test(const Test &other) = default; // use default to use implicit constructor
  Test(const Test &other) = delete; // delete/disable copy constructor
  //

  // explicitly declare = operator
  Test &operator=(const Test &other) = default;


  Test(int id): id(id) {
    cout << "Parameterized constructor called with id: " << id << endl;
  }


  void print() {
    cout << id << ": " << name << endl;
  }

};

int main() {

  Test test;
  test.print();

  Test test1(88);
  test1.print();

  // won't work due to deleted constructors
  // Test test2 = test1;
  // test2 = test;



  return 0;
}
