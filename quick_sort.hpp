#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP
#include "clase_vector.hpp"
#include <cstdlib> //para std::rand()
#include <utility> //habilita std::swap

template<class T>
struct Less {
  bool operator()(const T &a, const T &b) const { return a < b; }
};

template<class T>
struct Greater {
  bool operator()(const T &a, const T &b) const { return a > b; }
};

struct Pivot01 { // El pivote es el primer elemento
  template<class T>
  long operator()(const Vector<T> &v, long init, long end) {
    return init;
  }
};
struct Pivot02 { // El pivote es el último elemento
  template<class T>
  long operator()(const Vector<T> &v, long init, long end) {
    return end;
  }
};
struct Pivot03 { // El pivote es el el elemento del centro
  template<class T>
  long operator()(const Vector<T> &v, long init, long end) {
    return init + (end - init) / 2;
  }
};
struct Pivot04 { // El pivote es random
  template<class T>
  long operator()(const Vector<T> &v, long init, long end) {
    return init + (std::rand() % (end - init + 1));
  }
};
struct Pivot05 { // El pivote es la mediana del inicio, medio y fin
  template<class T>
  long operator()(const Vector<T> &v, long init, long end) {
    long mid_pos = init + (end - init) / 2;

    const T &init_pivot = v[init];
    const T &mid_pivot = v[mid_pos];
    const T &end_pivot = v[end];

    if ((init_pivot <= mid_pivot && init_pivot >= end_pivot) ||
        (init_pivot <= end_pivot && init_pivot >= mid_pivot)) {
      return init;
    }
    if ((mid_pivot <= init_pivot && mid_pivot >= end_pivot) ||
        (mid_pivot <= end_pivot && mid_pivot >= init_pivot)) {
      return mid_pos;
    }
    return end;
  }
};

template<class data_type, class compare, class PivotSelector>
long partition(Vector<data_type> &v, long init, long end, compare comp,
               PivotSelector piv_sel) {

  long chosen_pivot = piv_sel(v, init, end);

  std::swap(v[chosen_pivot], v[end]);

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

template<class data_type, class compare, class PivotSelector>
void recursive_quick_sort(Vector<data_type> &v, long init, long end,
                          compare comp, PivotSelector piv_sel) {
  if (init < end) {
    long pivot = partition(v, init, end, comp, piv_sel);

    recursive_quick_sort(v, init, pivot - 1, comp, piv_sel);
    recursive_quick_sort(v, pivot + 1, end, comp, piv_sel);
  }
}

template<class data_type, class compare = Less<data_type>,
         class PivotSelector = Pivot01>
void quick_sort(Vector<data_type> &v, compare comp = compare(),
                PivotSelector piv_sel = PivotSelector()) {
  if (v.get_size() > 0) {

    recursive_quick_sort(v, 0, static_cast<long>(v.get_size() - 1), comp,
                         piv_sel);
  }
}

#endif // !QUICK_SORT_HPP
