
#include <iostream>
int main() {
    int numero = 10;

    int *ptr_numero = &numero;

    std::cout << "Direccion de numero: " << ptr_numero << std::endl ;
    std::cout << "Valor de numero: " << *ptr_numero << std::endl ;
    std::cout << "Valor en memoria desde la variable: " << numero << std::endl << std::endl;

    int notas[5] = {80, 90, 60, 50, 71};
    int *ptr_notas = notas;

    std::cout << "Direccion de notas: " << ptr_notas << std::endl << std::endl;

    for (int i = 0; i < 5; i++) {
        std::cout << "Valor de notas: " << *ptr_notas << std::endl;
        ptr_notas++;
    }
    return 0;
}