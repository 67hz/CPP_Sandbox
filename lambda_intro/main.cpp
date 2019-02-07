#include <iostream>
using namespace std;

// function pointer *pFunc
void test(void (*pFunc)() ) {
    pFunc();
}

int main() {


  // lambda - [capture list] (args) {function body}
  // requires c++11 (auto)
  auto func = [](){
    cout << "Howdy" << endl;
  };

  // [](){
  //   cout << "Howdy" << endl;
  // }();

  // func();

  test(func);

  // function pointer compatible with lambda expression
  test([](){
      cout << "Howdy" << endl;
  });



  return 0;
}
