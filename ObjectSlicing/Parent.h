#include <iostream>
using namespace std;

class Parent {
  private:
    int one;

  public:
    Parent();
    Parent(const Parent &other);
    virtual void print();
    void test();
    virtual ~Parent();
};


class Child: public Parent {
  private:
    int two;

  public:
    Child();
    Child(const Child &other);
    void print();
    ~Child();
};
