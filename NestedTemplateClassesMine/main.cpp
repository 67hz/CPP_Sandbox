#include <iostream>
#include "instrument.h"
using namespace std;


int main() {
  instrument<string> corpusCollection(5);

  corpusCollection.add("fender");
  corpusCollection.add("deneve");
  corpusCollection.add("gibson");
  corpusCollection.add("martin");
  corpusCollection.add("paul reed smith");
  corpusCollection.add("cordoba");
  corpusCollection.add("copeland");

  for(instrument<string>::iterator it = corpusCollection.begin(); it != corpusCollection.end(); it++) {
    cout << *it << endl;
  }

  cout << endl;

  for(auto value: corpusCollection) {
    cout << value << endl;
  }


  return 0;
}
