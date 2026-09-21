<<<<<<< HEAD

#include <iostream>
int main() {
=======
#include <iostream>

int main() {

>>>>>>> 90fbb9ebee6bf1a2548f0f6706eb3d0f1ca11491
    int numero = 10;

    int *ptr_numero = &numero;

<<<<<<< HEAD
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
=======
    std::cout << "Direccion de memoria: " << ptr_numero << std::endl;    
    std::cout << "Valor en memoria desde puntero: " << *ptr_numero << std::endl;    
    std::cout << "Valor en memoria desde la variable:" << numero << std::endl;
    
    int notas[5] = {80, 90, 60, 50, 71};

    int *ptr_notas = notas;
 
    std::cout << "Direccion de memoria: " << ptr_notas << std::endl;    
    std::cout << "Valor en memoria desde puntero: " << *ptr_notas << std::endl;    

    ptr_notas += 1;
    std::cout << "Valor en memoria desde puntero: " << *ptr_notas << std::endl;    

>>>>>>> 90fbb9ebee6bf1a2548f0f6706eb3d0f1ca11491
    return 0;
}