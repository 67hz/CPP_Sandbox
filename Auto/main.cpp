#include <iostream>
using namespace std;

template <class T, class S>  
auto test(T value, S value2) -> decltype(value + value2) {
  return value + value2;
}

int get() {
  return 999;
}

auto test2() -> decltype(get()) {
  return get();
}

int main() {
  auto value = 8;
  auto name = "Jake";

  cout << name << endl;
  cout << test(5, 4) << endl;
  cout << test2() << endl;
  return 0;
}
