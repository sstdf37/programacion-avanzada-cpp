#include <gtest/gtest.h>

#include <stdexcept>

#include "tarifa.h"

// Tarifa del estacionamiento de visitas de la universidad. Las cuatro
// carpetas version_a a version_d tienen cada una su tarifa.h con una
// implementacion distinta de la misma funcion:
//
//     int tarifaEnCentavos(int minutos)

int tarifaEnCentavos(int minutos);

TEST(Tarifa, MinutosNegativosLanza) {
    EXPECT_THROW(tarifaEnCentavos(-1), std::invalid_argument);
}

TEST(Tarifa, HastaQuinceMinutosNoSeCobra) {
    EXPECT_EQ(tarifaEnCentavos(0), 0);
    EXPECT_EQ(tarifaEnCentavos(15), 0);
}

TEST(Tarifa, DieciseisMinutosCobranUnaHora) {
    EXPECT_EQ(tarifaEnCentavos(16), 50);
    EXPECT_EQ(tarifaEnCentavos(60), 50);
}

TEST(Tarifa, SesentaUnMinutosCobranDosHoras) {
    EXPECT_EQ(tarifaEnCentavos(61), 100);
}

TEST(Tarifa, NingunaEstadiaCuestaMasDeQuinientosCentavos) {
    EXPECT_EQ(tarifaEnCentavos(1000), 500);
}

//
// Lo que tiene que cumplir:
// - Con minutos negativos lanza std::invalid_argument.
// - Hasta 15 minutos, inclusive, no se cobra.
// - Desde el minuto 16, se cobran 50 centavos por cada hora o fraccion,
//   contadas desde el minuto 0: 16 minutos son una hora, 60 minutos son
//   una hora, 61 minutos son dos horas.
// - Ninguna estadia cuesta mas de 500 centavos.
//

// TODO: Verificar que otros valores negativos tambien lancen excepcion.
TEST(Tarifa, VariosNegativosLanzan) {
    EXPECT_THROW(tarifaEnCentavos(-10), std::invalid_argument);
    EXPECT_THROW(tarifaEnCentavos(-100), std::invalid_argument);
}

// TODO: Verificar valores intermedios dentro de los primeros 15 minutos.
TEST(Tarifa, TodosLosPrimerosQuinceMinutosSonGratis) {
    EXPECT_EQ(tarifaEnCentavos(1), 0);
    EXPECT_EQ(tarifaEnCentavos(14), 0);
}

// TODO: Verificar que cualquier fraccion de hora cobre la hora completa.
TEST(Tarifa, FraccionDeHoraCobraUnaHora) {
    EXPECT_EQ(tarifaEnCentavos(30), 50);
    EXPECT_EQ(tarifaEnCentavos(59), 50);
}

// TODO: Verificar el cambio correcto entre una y dos horas.
TEST(Tarifa, LimiteEntreUnaYDosHoras) {
    EXPECT_EQ(tarifaEnCentavos(60), 50);
    EXPECT_EQ(tarifaEnCentavos(61), 100);
}

// TODO: Verificar horas adicionales.
TEST(Tarifa, TresHoras) {
    EXPECT_EQ(tarifaEnCentavos(121), 150);
}

// TODO: Verificar que el tope maximo se mantenga.
TEST(Tarifa, TopeMaximo) {
    EXPECT_EQ(tarifaEnCentavos(10000), 500);
}


//
// Escribe aqui tus pruebas a partir de esta descripcion, antes de abrir
// cualquier tarifa.h. Compila el mismo archivo contra cada version
// cambiando la carpeta de -I:
//
//     g++ -std=c++20 -Wall -Wextra -g -I ejercicio3/version_a ejercicio3/test_tarifa.cpp -lgtest_main -lgtest -pthread -o bin/test_tarifa_a
//     ./bin/test_tarifa_a
