#include <iostream>
#include <thread>

void foo() {

  std::cout << "Hello from foo - " << std::this_thread::get_id() << std::endl;
}

struct callable_class {
  void operator()()
  {
  std::cout << "hello from class with functor call operator -" << std::this_thread::get_id() << std::endl;
  }
};

int main() {

  std::thread thread1(foo);

  callable_class obj;
  std::thread thread2(obj);

  std::thread thread3([]{
    std::cout << "Hello from lambda - " << std::this_thread::get_id() << std::endl;
  });

  thread1.join(); // forces main thread to wait for this to finish
  thread2.join();
  thread3.join();

  printf("hello from main\n");

  return 0;
}
