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

// takes lValue ref to test object
void check(const Test &value) {
  cout << "lValue function" << endl;
}

// takes rValue ref
void check(Test &&value) {
  cout << "rValue function" << endl;
}

int main() {

  // copy initialization - when a new object has to be created
  Test test1 = getTest();
  //
  // cout << test1 << endl;

  vector<Test> vec;
  vec.push_back(Test());

  // Lvalue ref to lvalue
  Test &ltest1 = test1;

  // &&rtest1 is rValue ref (&&)
  // Test &&rtest1 = test1; // binding r to l value won't work


  // rval to rval
  Test &&rtest1 = Test();

  // rval to rval
  Test &&rtest2 = getTest();

  // lvalue version
  check(test1);

  // rvalue version
  check(getTest());
  check(Test());

  return 0;
}
