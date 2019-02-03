#include <iostream>
#include <algorithm> //std::transform
#include <vector>
#include <functional>


int op_increase (int i) { return ++i; }

int main() {
  std::vector<int> foo;
  std::vector<int> bar;

  // set some values
  for (int i = 1; i < 6; i++)
    foo.push_back(i * 10);

  bar.resize(foo.size());  // allocate space

  std::transform(foo.begin(), foo.end(), bar.begin(), op_increase);

  // std::cout << sizeof(bar)/sizeof(bar[0]) << std::endl;
  for (int i = 0; i < bar.size(); i++) {
    std::cout << "bar[" << i << "]:" << bar[i] << "\t" << std::flush;
  }
  std::cout << std::endl;


  std::transform(foo.begin(), foo.end(), bar.begin(), foo.begin(), std::plus<int>());

  for (int i = 0; i < foo.size(); i++) {
    std::cout << "foo[" << i << "]:" << foo[i] << "\t" << std::flush;
  }
  std::cout << std::endl;

  for (std::vector<int>::iterator it = foo.begin(); it != foo.end(); it++) {
    std::cout << "foo: " << *it << "\t" << std::flush;
  }

  std::cout << std::endl;


}

