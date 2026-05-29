#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP
#include "clase_vector.hpp"
#include <utility> //habilita std::swap

template<class data_type>
long partition(Vector<data_type> &v, ulong init, ulong end) {
  data_type pivot = v[0];
  long i = init - 1;

  for (long j = init; j <= end - 1; j++) {
    if (v[j] < pivot) {
      i++;
      std::swap(v[i], v[j]);
    }
  }
  std::swap(v[i + 1], v[end]);

  return (i + 1);
}

template<class data_type>
void recursive_quick_sort(Vector<data_type> &v, long init, ulong end) {
  if (init < end) {
    long pivot = partition(v, init, end);

    recursive_quick_sort(v, init, pivot - 1);
    recursive_quick_sort(v, pivot + 1, end);
  }
}

template<class data_type>
void quick_sort(Vector<data_type> &v) {
  if (v.get_size() > 0) {

    recursive_quick_sort(v, 0, static_cast<long>(v.get_size() - 1));
  }
}

#endif // !QUICK_SORT_HPP
