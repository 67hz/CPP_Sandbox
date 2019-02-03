#include <iostream>
using namespace std;

struct Test {

  // abstract class
  virtual bool operator()(string &text)=0;

  virtual ~Test(){}

};

// struct public by default
// functor - class or struct that overloads () operator
struct MatchTest: public Test {
  bool operator()(string &text) {
    return text == "lion";
  }
};

struct MatchTestDoggy: public Test {
  bool operator()(string &text) {
    return text == "doggy";
  }

};

void check(string text, Test &test) {
  if(test(text)) {
    cout << "Text matches" << endl;
  } else {
    cout << "No match" << endl;
  }

}

int main() {
  MatchTest pred;

  string value = "lion";
  string otherValue = "doggy";

  MatchTest m;
  check("lion", m);

  MatchTestDoggy d;
  check("doggies", d);


  return 0;
}
