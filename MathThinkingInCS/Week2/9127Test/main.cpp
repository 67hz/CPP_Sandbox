#include <iostream>
using namespace std;

int findDivisibleMatch(int i) {
  for (int j=100000; j<100999; j++) {
    if (j % i == 0) {
      return j;
    }
  }

  return -1;
}

int main() {
  int result = findDivisibleMatch(9127);
  cout << "result: " << result << endl;


  return 0;
}
