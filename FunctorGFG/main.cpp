#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Increment {
  private:
    int num;

  public:
    Increment(int n): num(n) {}

    int operator()(int arr_num) const {
      cout << "num: " << num << endl;
      return num + arr_num;
    }
};

struct Decrement {
  int num;

  Decrement(int n): num(n) { }

  int operator()(int arr_num) const {
    return arr_num - num;
  }

};

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  int n = sizeof(arr)/sizeof(arr[0]);
  int newArr[n];
  int to_add = 5;
  int to_dec = 2;

  // transform(arr, arr+n, newArr, Increment(to_add));
  transform(arr, arr+n, newArr, Decrement(to_dec));


  for (int i = 0; i < n; i++) {
    cout << newArr[i] << " " << flush;
  }
  cout << endl;

  return 0;
}
