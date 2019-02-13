#include <iostream>
using namespace std;

struct Test {
  int id{1};
  string name{"Jake"};
};

Test getTest() {
  return Test();
}

int main() {

  // Can only take the address of lValues, not rValues

  // return values of functions are rvalues - often temp values (values returned by functions)
  Test test1 = getTest();

  // value1 LValue, 7 RValue
  int value1 = 7;

  //value1 is an LValue
  int *pValue1 = &value1;

  // will not work - cannot take the address of an rvalue
  // int *pValue2 = &7;
  
  Test *pTest1 = &test1;
  // Test *pTest2 = &getTest(); // can't take address of a temp object (return value)

  int *pValue3 = &++value1;
  cout << *pValue3 << endl;

  // postfix will not work because a copy of value1 has to be made
  // int *pValue4 = &value1++;  // cannot take the address of an rValue
  // cout << *pValue4 << endl;

  // int *s = &(7 + value1); // cannot take the address of an rvalue
  // cout << *s << endl;

  return 0;
}
