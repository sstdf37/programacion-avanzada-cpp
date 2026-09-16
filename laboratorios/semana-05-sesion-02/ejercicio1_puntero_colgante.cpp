#include <iostream>

class LecturaSensor{
    private:
        int valor; 
    public:
        LecturaSensor(int v){
            valor = v;
            std::cout << "LecturaSensor creado con valor: " << valor << std::endl;
        }   

};
// TODO: predice antes de compilar. ¿que advertencia esperas que de
// el compilador sobre esta funcion?
int* obtenerLecturaInsegura(int valorSensor) {
    int lectura = valorSensor * 2;
    return &lectura;
}

int main() {
    int* resultado = obtenerLecturaInsegura(10);
    std::cout << "Lectura (puntero colgante): " << *resultado << std::endl;
    return 0;
}
