import pandas as pd
import matplotlib.pyplot as plt

def main():
    print("Leyendo los datos de tiempos_quickSort.csv...")
    
    try:
        # 1. Leer el archivo CSV
        # skipinitialspace=True evita errores si hay espacios extra después de las comas
        df = pd.read_csv('tiempos_quickSort.csv', skipinitialspace=True)
    except FileNotFoundError:
        print("Error: No se encontró el archivo 'tiempos_quickSort.csv'.")
        print("Asegúrate de ejecutar tu programa en C++ primero.")
        return

    # 2. Configurar el tamaño de la ventana del gráfico
    plt.figure(figsize=(12, 7))

    # El Eje X siempre será la cantidad de elementos
    eje_x = df['ELEMENTOS']

    # 3. Dibujar cada una de las 5 líneas (una por cada pivote)
    # Le ponemos diferentes marcadores (o, s, ^, d, x) para distinguirlas mejor
    plt.plot(eje_x, df['PIVOTE_INICIO'], label='Pivote al Inicio', linewidth=1)
    plt.plot(eje_x, df['PIVOTE_FINAL'], label='Pivote al Final', linewidth=1)
    plt.plot(eje_x, df['PIVOTE MEDIO'], label='Pivote en el Medio', linewidth=1)
    plt.plot(eje_x, df['PIVOTE RANDOM'], label='Pivote Aleatorio', linewidth=1)
    plt.plot(eje_x, df['PIVOTE MEDIA DE 3'], label='Pivote Mediana de 3', linewidth=1)

    # 4. Personalizar textos, títulos y estilos
    plt.title('Comparación de Rendimiento: Estrategias de Pivote en QuickSort', fontsize=16, fontweight='bold', pad=15)
    plt.xlabel('Número de Elementos (N)', fontsize=12, fontweight='bold')
    plt.ylabel('Tiempo de Ejecución (milisegundos)', fontsize=12, fontweight='bold')
    
    # Activar la cuadrícula de fondo para leer mejor los valores
    plt.grid(True, linestyle='--', alpha=0.7)
    
    # Mostrar el recuadro con la leyenda de colores
    plt.legend(title='Estrategias', fontsize=11, title_fontsize=12)

    # Ajustar márgenes para que no se corte nada
    plt.tight_layout()

    # 5. Opcional: Guardar el gráfico automáticamente como una imagen de alta calidad
    plt.savefig('rendimiento_quicksort.png', dpi=300)
    print("Gráfico guardado como 'rendimiento_quicksort.png'")

    # 6. Mostrar la ventana interactiva
    plt.show()

if __name__ == '__main__':
    main()
