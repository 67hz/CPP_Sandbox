#include <iostream>
using namespace std;

int main() {
  int one{1};
  int two{2};
  int three{3};

  // Capture one and two by value
  [one, two](){
    cout << "Hello: " << one << ", " << two << endl;
  }();

  // Capture all local vars by value
  [=](){
    cout << "Hello: " << one << ", " << two << endl;
  }();

  // Capture mix of value and reference
  // three is by ref, one/two by val;
  [=, &three](){

    // two = 2; // will not work because passed by value. can only reassign things passed by &ref
    three = 4;
    cout << "Hello: " << one << ", " << two << " ," << three << endl;
  }();

  // capture all by reference
  [&](){
    three = 8;
    two = 4;
    cout << "Hello: " << one << ", " << two << " ," << three << endl;
  }();

  // capture mix
  [&, two, three](){
    // three = 8; // will error
    // two = 4; // will error
    one = 9;
    cout << "Hello: " << one << ", " << two << " ," << three << endl;
  }();

  return 0;
}
