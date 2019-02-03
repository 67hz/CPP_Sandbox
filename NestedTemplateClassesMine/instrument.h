#ifndef INSTRUMENT_H_
#define INSTRUMENT_H_
#include <iostream>

template<class T>
class instrument {
  public:
    class iterator;

};

template<class T>
class instrument<T>::iterator {
  public:
    void print() {
      std::cout << "print from iterator" << T() << std::endl;
    }

};


#endif  // INSTRUMENT_H_
