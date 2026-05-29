#ifndef VECTOR_UTILS_HPP
#define VECTOR_UTILS_HPP

#include "clase_vector.hpp"
#include <random>
#include <type_traits> // Necesario para saber si T es int o float

template<class T>
void fill_random(Vector<T> &v, T min_val, T max_val) {
  // 1. Configuramos el motor de números aleatorios (Estándar de C++ moderno)
  std::random_device rd; // Obtiene una semilla real basada en el hardware
  std::mt19937 gen(
      rd()); // Generador Mersenne Twister (muy rápido y de alta calidad)

  // 2. Evaluamos en tiempo de compilación qué tipo de dato (T) estamos usando
  if constexpr (std::is_integral<T>::value) {
    // Si T es un entero (int, long, short...)
    std::uniform_int_distribution<T> dis(min_val, max_val);

    for (unsigned long i = 0; i < v.get_size();
         i++) {        // Usamos get_size() de tu clase
      v[i] = dis(gen); // Usamos tu operador []
    }

  } else if constexpr (std::is_floating_point<T>::value) {
    // Si T es un decimal (float, double...)
    std::uniform_real_distribution<T> dis(min_val, max_val);

    for (unsigned long i = 0; i < v.get_size(); i++) {
      v[i] = dis(gen);
    }
  }
}

#endif // !VECTOR_UTILS_HPP
