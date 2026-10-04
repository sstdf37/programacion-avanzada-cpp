// Ejercicio 12: new[] y delete[] basico
//
// Completa las lineas marcadas con TODO dentro de main(). No agregues includes
// ni cambies el resto del archivo.
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio12 ejercicio12_new_delete_basico.cpp
// Ejecutar: ./ejercicio12
//
// Salida esperada:
// Suma: 150

#include <iostream>

int main() {
    int* valores = new int[5];
    // TODO: reserva dinamicamente un arreglo de 5 int con new[] y guarda el
    // puntero en una variable llamada valores.
valores[0] = 10;
    valores[1] = 20;
    valores[2] = 30;
    valores[3] = 40;
    valores[4] = 50;
    // TODO: asigna a valores los numeros 10, 20, 30, 40 y 50 (en ese orden,
    // por indice).

    int suma = 0;
    for (int i = 0; i < 5; i++) {
        // TODO: suma valores[i] a suma.
        suma += valores[i];
    }
    std::cout << "Suma: " << suma << std::endl;

    delete[] valores;
    // TODO: libera la memoria reservada con delete[].

    return 0;
}
