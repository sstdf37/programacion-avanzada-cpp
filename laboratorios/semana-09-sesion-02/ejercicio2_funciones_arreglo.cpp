#include <iostream>

// Salida esperada:
// Suma de pasos: 9300
// Suma de temperaturas: 64.5
// Suma de desplazamientos: (4, 5)
// Dias con mas de 3000 pasos: 2
// Temperaturas sobre 21.0: 2

class Vector2D {
private:
    double x;
    double y;

public:
    // Constructor por defecto
    Vector2D() {
        x = 0;
        y = 0;
    }

    Vector2D(double xInicial, double yInicial) {
        x = xInicial;
        y = yInicial;
    }

    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }

    Vector2D operator+(const Vector2D& otro) const {
        return Vector2D(x + otro.x, y + otro.y);
    }
};

std::ostream& operator<<(std::ostream& os, const Vector2D& v) {
    os << "(" << v.getX() << ", " << v.getY() << ")";
    return os;
}

// Plantilla de función para sumar elementos de un arreglo
template <typename T>
T sumarArreglo(T datos[], int cantidad) {
    T suma = T();

    for (int i = 0; i < cantidad; i++) {
        suma = suma + datos[i];
    }

    return suma;
}

// Plantilla de función para contar elementos mayores que un umbral
template <typename T>
int contarMayoresQue(T datos[], int cantidad, T umbral) {
    int contador = 0;

    for (int i = 0; i < cantidad; i++) {
        if (datos[i] > umbral) {
            contador++;
        }
    }

    return contador;
}

int main() {
    int pasos[3] = {4200, 1800, 3300};
    double temperaturas[3] = {20.5, 21.5, 22.5};
    Vector2D desplazamientos[3] = {
        Vector2D(1.0, 2.0),
        Vector2D(3.0, -1.0),
        Vector2D(0.0, 4.0)
    };

    std::cout << "Suma de pasos: "
              << sumarArreglo(pasos, 3) << std::endl;

    std::cout << "Suma de temperaturas: "
              << sumarArreglo(temperaturas, 3) << std::endl;

    std::cout << "Suma de desplazamientos: "
              << sumarArreglo(desplazamientos, 3) << std::endl;

    std::cout << "Dias con mas de 3000 pasos: "
              << contarMayoresQue(pasos, 3, 3000) << std::endl;

    std::cout << "Temperaturas sobre 21.0: "
              << contarMayoresQue(temperaturas, 3, 21.0) << std::endl;

    return 0;
}