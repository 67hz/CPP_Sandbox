#include <iostream>
using namespace std;

void testGreet(void (*pFunc)(string) ) {
  pFunc("Jake");
}

void runDivide(double (*pDivide)(double, double) ) {
  double rval = pDivide(9, 3);
  cout << rval << endl;
}

void runSum(double (*pSum)(double, double) ) {
  double rval = pSum(5, 5);
  cout << rval << endl;
}

int main() {

  auto pGreet = [](string name){
    cout << "Howdy " << name << endl;
  };

  pGreet("Jake");

  testGreet(pGreet);

  auto pDivide = [](double a, double b) -> double {
    if(b == 0.0) {
      return 0;
    }
    return a / b;
  };

  auto pSum = [](double a, double b) {
    return a + b;
  };

  cout << pDivide(10.0, 2.0) << endl;
  cout << pDivide(10.0, 0) << endl;

  runDivide(pDivide);

  runSum(pSum);

  return 0;
} 

