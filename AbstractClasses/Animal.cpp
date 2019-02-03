#include <iostream>
#include "Animal.h"
using namespace std;

void Dog::speak() {
  cout << "Woof" << endl;
}

void Labrador::run() {
  cout << "Labrador running" << endl;
}

Labrador::Labrador() {
  cout << "New labrador constructor" << endl;
}
