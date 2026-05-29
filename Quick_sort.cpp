#include <assert.h>
#include <iostream>
using namespace std;
typedef unsigned long ulong;

int partition(int *array, ulong init, ulong end) {
  int pivot = *(array);
  ulong i = init + 1;

  for (int j = i; j <= end; j++) {
    if (*(array + j) < pivot) {
      swap(*(array + j), *(array + i));
      i++;
    }
  }

  swap(*(array), *(array + i - 1));

  return i - 1;
}

void quickSort(int *array, ulong init, ulong end) {
  if (init < end) {
    int pivot = partition(array, init, end);
    quickSort(array, init, pivot - 1);
    quickSort(array, pivot + 1, end);
  }
}

int main(int argc, char *argv[]) {
  cout << "hola";
  return 0;
}
