#include <iostream>
#include <vector>
using namespace std;


int main() {
  auto texts = {"one", "two", "three"};

  for(auto text: texts) {
    cout << text << endl;
  }

  vector<int> numbers;
  numbers.push_back(5);
  numbers.push_back(7);
  numbers.push_back(9);
  numbers.push_back(11);

  // enhanced for loop - known as range-based loop in C++
  for(auto number: numbers) {
    cout << number << endl;
  }

  // same as above
  // for(vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
  //   cout << *it << endl;
  // }

  string hello = "Hello";

  for(auto c: hello) {
    cout << c << " " << flush;
  }

  cout << endl;


  return 0;
}
