#include <iostream>
#include <vector>
using namespace std;

int main() {

  // C++11
  int value{5};

  cout << value << endl;

  string text{"Hello"};
  cout << text << endl;


  int numbers[]{1, 2, 3, 4};
  cout << numbers[1] << endl;

  // int ints98[] = {1, 2, 3};
  // int *pInts98 = ints98;
  // cout << "c++98 way: " << pInts98[1] << endl;

  int *pInts = new int[3]{1, 2, 3};
  cout << "c++11 way: " << pInts[1] << endl;
  delete [] pInts;

  int value1{};
  cout << "value1: " << value1 << endl;

  // int *pSomething{}; // same as int *pSomething{NULL}
  // int *pSomething = &value; // C++98
  int *pSomething{&value};
  cout << *pSomething << endl;

  int numbers1[5]{}; // init array to 0's
  cout << numbers1[1] << endl;

  // C++98
  // struct {
  //   int value;
  //   string text;
  // } s1 = {5, "Howdy"};

  // C++!1 = no need for = sign
  struct {
    int value;
    string text;
  } s1{5, "Howdy"};


  vector<string> strings{"one", "two", "three"};
  cout << strings[2] << endl;









  return 0;
}
