#ifndef INSTRUMENT_H_
#define INSTRUMENT_H_
#include <iostream>

template<class T>
class instrument {
  public:
    class iterator;

  public:
    int m_size;
    T *m_values;
    int m_pos;

    instrument(int size): m_size(size), m_values(NULL), m_pos(0) {
      // allocate memory for new array
      m_values = new T[m_size];
    }

    // int size() {
    //   return m_size;
    // }

    ~instrument() {
      delete[] m_values;
    }

    void add(T value) {
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

template<class T>
class instrument<T>::iterator {
  private:
    int m_pos;
    instrument &m_instrument;
  public:
    iterator(int pos, instrument &instr): m_pos(pos), m_instrument(instr) { }

    // postfix
    iterator &operator++(int) {
      m_pos++;
      return *this;
    }

    //prefix
    iterator &operator++() {
      m_pos++;
      return *this;
    }

    T &operator*() {
      return m_instrument.get(m_pos);
    }

    bool operator!=(const iterator &other) const {
      return m_pos != other.m_pos;
    }
};


#endif  // INSTRUMENT_H_
