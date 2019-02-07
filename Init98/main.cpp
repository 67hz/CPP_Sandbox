#include <iostream>
#include <vector>
using namespace std;

int main() {
  // C++98
  // int values[] = {1, 4, 5};
  //
  // cout << values[0] << endl;
  //
  // class C {
  //   public:
  //     string text;
  //     int id;
  // };
  //
  // C c1 = {"Hello", 7};
  //
  // cout << c1.text << endl;
  //
  struct Guitar {
    string name;
    string type;
    double price;
  };

  Guitar strat = {"fender", "stratocaster", 1200};
  cout << strat.price << endl;

  struct S {
    string text;
    int id;
  };

  S s1 = {"Howdy", 8};
  cout << s1.text << endl;

  struct R {
    string text;
    int id;
  } r1 = {"Hola", 9}, r2 = {"Bienvenitos", 2};

  cout << r1.text << endl;
  cout << r2.text << endl;

  vector<string> strings;
  strings.push_back("one");
  strings.push_back("two");
  strings.push_back("three");



  return 0;
}
