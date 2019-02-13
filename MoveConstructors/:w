#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

class Test {
  private:
    static const int SIZE=100;
    int *_pBuffer; // common convention is to start members with '_'

  public:
    Test() {
      cout << "constructor" << endl;
      // _pBuffer = new int[SIZE];
      // _pBuffer = new int[SIZE](); // init all to 0
      _pBuffer = new int[SIZE]{}; // C++11 set all to 0, make sure to delete memory in destructor

      // 1st arg is pointer, 2nd is all 4 bytes of int, 3rd total bytes in buffer
      // memset is prone to bugs
      // memset(_pBuffer, 0, sizeof(int)*SIZE);

    }

    // use default parameterless constructor to create _pBuffer
    Test(int i): Test() {
      cout << "parameterized constructor" << endl;
      // _pBuffer = new int[SIZE]{}; // C++!1 set all to 0

      for (int j = 0; j < SIZE; j++) {
        _pBuffer[j] = 7 * j;
      }
    }

    Test(const Test &other) {
      cout << "copy constructor" << endl;

      _pBuffer = new int[SIZE]{};
      memcpy(_pBuffer, other._pBuffer, SIZE*sizeof(int));
    }

    Test &operator=(const Test &other)  {
      cout << "assignment" << endl;
      _pBuffer = new int[SIZE]{};

      // memcpy(dest, source. # bytes to copy)
      memcpy(_pBuffer, other._pBuffer, SIZE*sizeof(int));
      return *this;
    }

    ~Test() {
      cout << "destructor" << endl;
      delete [] _pBuffer;
    }

    friend ostream &operator<<(ostream &out, const Test &test);

};

ostream &operator<<(ostream &out, const Test &test) {
  out << "Hello from test";
  return out;
}

// when functions return objects, they have to copy those objects
// into temp return values
Test getTest() {
  return Test();
}

int main() {

  // copy initialization - when a new object has to be created
  Test test1 = getTest();
  //
  // cout << test1 << endl;

  vector<Test> vec;
  vec.push_back(Test());
  vec.push_back(Test());

  // Return values of functions are rValues - they are temp

  // C++11 has LValue and RValue references

  // can only bind to lValue
  // unless const - const can bind to rValues
  Test &rTest1 = test1;

  // extends temp return value from function to const life
  const Test &rTest2 = getTest();

  // RValue (Test(1)) being passed into copy constructor
  // test2 lValue, Test(1) rValue
  // copy constructor is const
  Test test2(Test(1));

  return 0;
}
