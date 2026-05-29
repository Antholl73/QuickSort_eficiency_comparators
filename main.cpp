#include "clase_vector.hpp"
#include "quick_sort.hpp"
#include "utils.hpp"
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>

using namespace std;
using VectorInt = Vector<int>; // define el tipo de los vectores

int main() {
  srand(time(nullptr));

  ofstream archivo_csv("tiempos_quickSort.csv");
  archivo_csv << "ELEMENTOS, PIVOTE_INICIO, PIVOTE_FINAL, PIVOTE MEDIO, PIVOTE "
                 "RANDOM, PIVOTE MEDIA DE 3\n";

  ulong size = 1;

  while (size <= 500001) {
    VectorInt v01(size);
    VectorInt v02;
    VectorInt v03;
    VectorInt v04;
    VectorInt v05;

    fill_random(v01, 1, static_cast<int>(size * 10));

    v05 = v04 = v03 = v02 = v01;

    // PIVOTE INICIO
    auto inicio1 = chrono::high_resolution_clock::now();

    quick_sort(v01, Less<int>(), Pivot01());

    auto fin1 = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> tiempo1 = fin1 - inicio1;

    // PIVOTE FINAL
    auto inicio2 = chrono::high_resolution_clock::now();

    quick_sort(v02, Less<int>(), Pivot02());

    auto fin2 = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> tiempo2 = fin2 - inicio2;

    // PIVOTE MEDIO
    auto inicio3 = chrono::high_resolution_clock::now();

    quick_sort(v03, Less<int>(), Pivot03());

    auto fin3 = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> tiempo3 = fin3 - inicio3;

    // PIVOTE RANDOM
    auto inicio4 = chrono::high_resolution_clock::now();

    quick_sort(v04, Less<int>(), Pivot04());

    auto fin4 = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> tiempo4 = fin4 - inicio4;

    // PIVOTE MEDIA DE 3
    auto inicio5 = chrono::high_resolution_clock::now();

    quick_sort(v05, Less<int>(), Pivot05());

    auto fin5 = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> tiempo5 = fin5 - inicio5;

    archivo_csv << size << "," << tiempo1.count() << "," << tiempo2.count()
                << "," << tiempo3.count() << "," << tiempo4.count() << ","
                << tiempo5.count() << "\n";

    size += 10000;
  }

  archivo_csv.close();
  cout << "datos exportados :)";

  return 0;
}
