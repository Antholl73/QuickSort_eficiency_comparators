#ifndef VECTOR_UTILS_HPP
#define VECTOR_UTILS_HPP

#include "clase_vector.hpp"
#include <iomanip>
#include <iostream>
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

// Imprime el encabezado de la tabla una sola vez
inline void print_table_header() {
  // Línea separadora
  std::cout << std::string(85, '-') << "\n";

  // Nombres de las columnas con anchos fijos
  std::cout << std::left << std::setw(12) << "ELEMENTOS" << std::setw(14)
            << "P. INICIO(ms)" << std::setw(14) << "P. FINAL(ms)"
            << std::setw(14) << "P. MEDIO(ms)" << std::setw(14)
            << "P. RANDOM(ms)" << std::setw(15) << "P. MEDIA DE 3(ms)" << "\n";

  // Línea separadora
  std::cout << std::string(85, '-') << "\n";
}

// Imprime una fila con los tiempos exactos en milisegundos
inline void print_table_row(ulong size, double t1, double t2, double t3,
                            double t4, double t5) {
  // std::fixed y std::setprecision(4) aseguran que siempre se vean 4 decimales
  std::cout << std::left << std::fixed << std::setprecision(4) << std::setw(12)
            << size << std::setw(14) << t1 << std::setw(14) << t2
            << std::setw(14) << t3 << std::setw(14) << t4 << std::setw(15) << t5
            << "\n";
}

#endif // !VECTOR_UTILS_HPP
