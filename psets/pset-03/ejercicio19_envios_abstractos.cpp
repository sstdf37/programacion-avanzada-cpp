// Ejercicio 19: Envio, EnvioNacional y EnvioInternacional (desde cero, clase abstracta)
//
// Este archivo no tiene codigo de partida. Escribe tus propios includes, tus
// propias clases y tu propio main().
//
#include <iostream>
#include <iomanip>
// Disena tres clases:
//
// Envio: clase abstracta, que no se puede instanciar. Destructor virtual
// con cuerpo vacio y una funcion virtual pura double costo().
class Envio {
public:
    virtual double costo() const = 0;
    virtual ~Envio() {}
};
//
// EnvioNacional: hereda publicamente de Envio. Atributo privado pesoKg
// (double), asignado en el constructor; si el peso recibido es negativo,
// guarda 0. costo() con override: 2 mas 1.5 por kilo.
class EnvioNacional : public Envio {
private:
    double pesoKg;
public:
    EnvioNacional(double peso) {
        if (peso < 0) {
            pesoKg = 0;
        } else {
            pesoKg = peso;
        }
    }
    double costo() const override {
        return 2 + 1.5 * pesoKg;
    }
};
//
// EnvioInternacional: igual que EnvioNacional, pero costo() devuelve 10
// mas 4 por kilo.
class EnvioInternacional : public Envio {
private:
    double pesoKg;
public:
    EnvioInternacional(double peso) {
        if (peso < 0) {
            pesoKg = 0;
        } else {
            pesoKg = peso;
        }
    }
    double costo() const override {
        return 10 + 4 * pesoKg;
    }
};
//
// Dos funciones libres:
// - void imprimirCosto(Envio* envio): imprime "Costo: " y el costo.
// - Envio* masBarato(Envio* a, Envio* b): el de menor costo; si cuestan lo
//   mismo, a.
void imprimirCosto(Envio* envio) {
    std::cout << "Costo: " << envio->costo() << std::endl;
}
Envio* masBarato(Envio* a, Envio* b) {
    if (a->costo() <= b->costo()) {
        return a;
    } else {
        return b;
    }
}
//
// En main(): crea un EnvioNacional de 3 kg, un EnvioInternacional de 0.5 kg
// y un EnvioNacional de -4 kg. Imprime el costo de los tres en ese orden
// con imprimirCosto. Despues imprime el costo del mas barato entre el
// nacional de 3 kg y el internacional, con el texto de la salida esperada.
int main() {
    EnvioNacional envio1(3);
    EnvioInternacional envio2(0.5);
    EnvioNacional envio3(-4);

    imprimirCosto(&envio1);
    imprimirCosto(&envio2);
    imprimirCosto(&envio3);

    Envio* barato = masBarato(&envio1, &envio2);
    std::cout << "El mas barato cuesta " << barato->costo() << std::endl;

    return 0;
}
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio19 ejercicio19_envios_abstractos.cpp
// Ejecutar: ./ejercicio19
//
// Salida esperada:
// Costo: 6.5
// Costo: 12
// Costo: 2
// El mas barato cuesta 6.5
