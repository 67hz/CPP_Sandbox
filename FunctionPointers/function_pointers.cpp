#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool match(string test) {
  return test.size() == 4;
}

int countStrings(vector<string> &texts, bool (*match)(string test) ) {
  int count = 0;
  for (int i = 0; i < texts.size(); i++) {
    if(match(texts[i])) {
      count++;
    }
  }
  return count;
}

int main() {

  vector<string> texts;
  
  texts.push_back("one");
  texts.push_back("two");
  texts.push_back("three");
  texts.push_back("two");
  texts.push_back("four");
  texts.push_back("two");
  texts.push_back("three");

  cout << match("one") << endl;

  cout << count_if(texts.begin(), texts.end(), match) << endl;
  
  cout << countStrings(texts, match) << endl;

  return 0;
}
