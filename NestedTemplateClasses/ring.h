#ifndef RING_H_
#define RING_H_

#include <iostream>
using namespace std;


template <class T>
class ring {
  private:
    // m_ prefix is common convention for members of class: m_values
    T *m_values;
    int m_size;
    int m_pos;

  public:
    class iterator;

  public:
    ring(int size): m_size(size), m_values(NULL), m_pos(0) {
      // using new keyword allocated memory so we need to deallocate in deconstructor
      m_values = new T[size];
    }

    ~ring() {
      delete [] m_values;
    }

    int size() {
      return m_size;
    }

    void add(T value) {
      // posfix
      m_values[m_pos++] = value;

      if (m_pos == m_size) {
        m_pos = 0;
      }
    }

    T &get(int pos) {
      return m_values[pos];
    }

    iterator begin() {
      return iterator(0, *this);
    }

    iterator end() {
      return iterator(m_size, *this);
    }
};

// nested class
template <class T>
class ring<T>::iterator {
  private:
    int m_pos;
    ring &m_ring;

  public:
    iterator(int pos, ring &myRing): m_pos(pos), m_ring(myRing) {

    }

    // postfix type override
    iterator &operator++(int) {
      m_pos++;

      return *this;
    }

    // prefix 
    iterator &operator++() {
      m_pos++;

      return *this;
    }

    T &operator*() {
      return m_ring.get(m_pos);
    }

    bool operator!=(const iterator &other) const {
      return m_pos != other.m_pos;
    }

};

#endif /* RING_H_ */
