#ifndef CLASES_VECTOR_HPP
#define CLASES_VECTOR_HPP

#include <iostream>
typedef unsigned long ulong;
#define VectorCT Vector<vector_data_type> // VectorCustomType

template<class vector_data_type>
class Vector {
private:
  ulong size_;
  vector_data_type *data_;

public:
  Vector(ulong size = 0);
  ~Vector();
  Vector(VectorCT const &v);

  VectorCT &operator=(const VectorCT &v2);

  vector_data_type &operator[](ulong index);
  const vector_data_type &operator[](ulong index) const;

  ulong get_size() const { return size_; };

  friend std::ostream &operator<<(std::ostream &os, const VectorCT &v) {
    for (ulong i = 0; i < v.size_; i++) {
      os << *(v.data_ + i) << " ";
    }
    os << std::endl;

    return os;
  }
};

template<class vector_data_type>
VectorCT::Vector(ulong size) : size_(size) {
  data_ = new vector_data_type[size_];
}

template<class vector_data_type>
VectorCT::~Vector() {
  delete[] data_;
}

template<class vector_data_type>
VectorCT::Vector(VectorCT const &v) {
  size_ = v.size_;
  data_ = new vector_data_type[size_];
  for (ulong i = 0; i < size_; i++) {
    *(data_ + i) = *(v.data_ + i);
  }
}

template<class vector_data_type>
VectorCT &VectorCT::operator=(const VectorCT &v2) {
  if (this == &v2) {
    return *this;
  }
  if (size_ != v2.size_) {
    delete[] data_;
    size_ = v2.size_;

    data_ = new vector_data_type[size_];
  }
  for (ulong i = 0; i < v2.size_; i++) {
    *(data_ + i) = *(v2.data_ + i);
  }
  return *this;
}

template<class vector_data_type>
vector_data_type &VectorCT::operator[](ulong index) {
  return *(data_ + index);
}

template<class vector_data_type>
const vector_data_type &VectorCT::operator[](ulong index) const {
  return *(data_ + index);
}
#endif // !CLASES_VECTOR_HPP
