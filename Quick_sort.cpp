#include <assert.h>
#include <iostream>
#include <ostream>
using namespace std;
typedef unsigned long ulong;

template <class dataType> class Vector {
private:
  ulong size_;
  dataType *data_;

public:
  Vector(ulong size);
  ~Vector();
  Vector(const Vector &v);

  Vector &operator=(const Vector &v2);

  friend ostream &operator<<(ostream &os, const Vector<dataType> &v) {
    for (ulong i = 0; i < v.size_; i++) {
      os << *(v.data_ + i) << " ";
    }
    os << endl;
    return os;
  }
};

template <class dataType> Vector<dataType>::Vector(ulong size) : size_(size) {
  data_ = new dataType[size_];
}

template <class dataType> Vector<dataType>::~Vector() { delete[] data_; }

template <class dataType> Vector<dataType>::Vector(const Vector<dataType> &v2) {
  size_ = v2.size_;
  data_ = new dataType[v2.size_];

  for (ulong i = 0; i < v2.size_; i++) {
    *(data_ + i) = *(v2.data_ + i);
  }
}

template <class dataType>
Vector<dataType> &Vector<dataType>::operator=(const Vector<dataType> &v2) {
  if (this == &v2) {
    return *this;
  }
  if (size_ != v2.size_) {
    delete[] data_;
    size_ = v2.size_;

    data_ = new dataType[size_];
  }

  for (ulong i = 0; i < size_; i++) {
    *(data_ + i) = *(v2.data_ + i);
  }
  return *this;
}

int main(int argc, char *argv[]) {
  cout << "hola";
  return 0;
}
