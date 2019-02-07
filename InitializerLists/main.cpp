#include <iostream>
#include <vector>
using namespace std;

class Test {
  public:
    Test(initializer_list<string> texts) {
      // for(auto value: texts) {
      //   cout << value << endl;
      // }

    }

    void print(initializer_list<string> texts) const {
      for(auto value: texts) {
        cout << value << endl;
      }
    }

};

int main() {

  // C++11
  vector<int> numbers {1, 2, 3, 4, 5};
  cout << numbers[2] << endl;

  Test test{"guitar", "banjo", "dobro"};

  test.print({"have", "a", "good", "day"});


  return 0;
}
