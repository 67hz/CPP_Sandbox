#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;

bool check(string &test) {
  return test.size() == 3;
}

struct Check {
  bool operator()(string &test) {
    return test.size() == 5;
  }
} check1;

// can accept anything callable that returns a bool and accepts a ref to a string
// function<return type(params)> name)
void run(function<bool(string&)> check) {
  string test = "three";
  cout << check(test) << endl;
}

int main() {
  int size = 5;
  vector<string> vec{"one", "two", "three"};

  auto lambda = [size](string test) {return test.size() == size;};

  int count = count_if(vec.begin(), vec.end(), lambda);

  cout << "lambda count: " << count << endl;

  count = count_if(vec.begin(), vec.end(), check);
  cout << "function pointer count: " << count << endl;

  // Check check1;
  count = count_if(vec.begin(), vec.end(), check1);
  cout << "functor check count: " << count << endl;

  run(lambda);
  run(check1);
  run(check);

  // returns int and accepts (int, int)
  function<int(int, int)> add = [](int one, int two){return one+two;};
  cout << add(5,14) << endl;

  function<double(double, double)> divide = [](int one, int two) -> double {
    if (two == 0) {
      return 0;
    }
    return one / two;
  };
  cout << "divide: " << divide(10.0, 3.0) << endl;

  // mutable lambdas - affects capture list within scope of lambda only
  // useful if you want to change values within scope but leave list intact
  // in outer scope
  int cats = 5;
  [cats]() mutable {
    cats = 8; // mutable within lambda only
    cout << "cats: " << cats << endl;
  }();

  // cats maintains original value
  cout << "outer cats: " << cats << endl;

  return 0;
}
