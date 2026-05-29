#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP
#include "clase_vector.hpp"
#include <utility> //habilita std::swap

template<class T>
struct Less {
  bool operator()(const T &a, const T &b) { return a < b; }
};

template<class T>
struct Greater {
  bool operator()(const T &a, const T &b) { return a > b; }
};

template<class data_type, class compare>
long partition(Vector<data_type> &v, long init, long end, compare comp) {
  data_type pivot = v[end];
  long i = init - 1;

  for (long j = init; j <= end - 1; j++) {
    if (comp(v[j], pivot)) {
      i++;
      std::swap(v[i], v[j]);
    }
  }
  std::swap(v[i + 1], v[end]);

  return (i + 1);
}

template<class data_type, class compare>
void recursive_quick_sort(Vector<data_type> &v, long init, long end,
                          compare comp) {
  if (init < end) {
    long pivot = partition(v, init, end, comp);

    recursive_quick_sort(v, init, pivot - 1, comp);
    recursive_quick_sort(v, pivot + 1, end, comp);
  }
}

template<class data_type, class compare = Less<data_type>>
void quick_sort(Vector<data_type> &v, compare comp = compare()) {
  if (v.get_size() > 0) {

    recursive_quick_sort(v, 0, static_cast<long>(v.get_size() - 1), comp);
  }
}

#endif // !QUICK_SORT_HPP
