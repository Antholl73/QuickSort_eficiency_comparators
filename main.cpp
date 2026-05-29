#include "clase_vector.hpp"
#include "quick_sort.hpp"
#include <iostream>

int main() {
  std::cout << "=== PRUEBA CON ENTEROS (INT) ===" << std::endl;
  // Creamos un vector de 6 posiciones
  Vector<int> vec_int(6);

  // Lo llenamos con números desordenados
  vec_int[0] = 42;
  vec_int[1] = 7;
  vec_int[2] = 15;
  vec_int[3] = 89;
  vec_int[4] = 23;
  vec_int[5] = 4;

  std::cout << "Vector original:  " << vec_int;

  // Llamamos a tu función de ordenamiento
  quick_sort(vec_int);

  std::cout << "Vector ordenado:  " << vec_int;
  std::cout << "--------------------------------" << std::endl;

  std::cout << "\n=== PRUEBA CON DECIMALES (FLOAT) ===" << std::endl;
  // Creamos un vector de 5 posiciones
  Vector<float> vec_float(5);

  vec_float[0] = 3.14f;
  vec_float[1] = 1.61f;
  vec_float[2] = 9.81f;
  vec_float[3] = 0.5f;
  vec_float[4] = 2.71f;

  std::cout << "Vector original:  " << vec_float;

  quick_sort(vec_float);

  std::cout << "Vector ordenado:  " << vec_float;
  std::cout << "--------------------------------" << std::endl;

  return 0;
}
