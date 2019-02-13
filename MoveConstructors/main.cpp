#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

class Test {
  private:
    static const int SIZE=100;

    // init pointer with nullptr - good practice
    int *_pBuffer{nullptr}; // common convention is to start members with '_'

  public:
    Test() {
      // _pBuffer = new int[SIZE];
      // _pBuffer = new int[SIZE](); // init all to 0
      _pBuffer = new int[SIZE]{}; // C++11 set all to 0, make sure to delete memory in destructor

      // 1st arg is pointer, 2nd is all 4 bytes of int, 3rd total bytes in buffer
      // memset is prone to bugs
      // memset(_pBuffer, 0, sizeof(int)*SIZE);

    }

    // use default parameterless constructor to create _pBuffer
    Test(int i): Test() {
      // _pBuffer = new int[SIZE]{}; // C++!1 set all to 0

      for (int j = 0; j < SIZE; j++) {
        _pBuffer[j] = 7 * j;
      }
    }

    // copy constructor
    Test(const Test &other) {
      _pBuffer = new int[SIZE]{};
      memcpy(_pBuffer, other._pBuffer, SIZE*sizeof(int));
    }

    // move constructor
    // takes mutable rValue ref
    Test(Test &&other) {
      cout << "Move constructor" << endl;

      // steal resources that rValue owns and then set to null in rValue
      _pBuffer = other._pBuffer;
      other._pBuffer = nullptr;
    }

    Test &operator=(const Test &other)  {
      _pBuffer = new int[SIZE]{};

      // memcpy(dest, source. # bytes to copy)
      memcpy(_pBuffer, other._pBuffer, SIZE*sizeof(int));
      return *this;
    }

    // move operator
    Test &operator=(Test &&other) {
      cout << "move assignment " << endl;
      delete [] _pBuffer;
      _pBuffer = other._pBuffer;
      other._pBuffer = nullptr;
      return *this;
    }

    ~Test() {
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

  vector<Test> vec;
  vec.push_back(Test());

  // Rule of 3: if implementing an assignment operator, implement a copy constructor,
  // and destructor
  // now should implement move constructor and move assignment operator


  Test test;
  test = getTest();


  return 0;
}
