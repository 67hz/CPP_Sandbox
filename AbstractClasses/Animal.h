// abstract class contains pure virtual functions
class Animal {
  public:
    // = 0 indicates abstract
    virtual void speak() = 0;
    virtual void run() = 0;
};

class Dog: public Animal {
  public:
    virtual void speak();

};

class Labrador: public Dog {
  public:
    Labrador();
    virtual void run();

};
