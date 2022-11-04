// Tests para la función perdio.
// Ver el archovo README.md para ayuda

#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

// Primer TEST: Jugador perdio

tablero t6 = {
        { cMINA,  cMINA,  cVACIA, cVACIA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cMINA,  cVACIA },
        { cVACIA, cMINA,  cVACIA, cVACIA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
        { cMINA,  cVACIA, cMINA,  cVACIA, cVACIA },
};
jugadas jugadasValidas2 = {
        jugada(pos(0, 2), 2),jugada(pos(0, 4), 1),
        jugada(pos(1, 0), 3),jugada(pos(1, 1), 3),
        jugada(pos(1, 2), 3),jugada(pos(1, 3), 0),
};

TEST(perdio,jugadorPerdio){
    ASSERT_TRUE(perdio(t6,jugadasValidas2));
}

// Segundo TEST: No perdio

tablero t7 = {
        { cMINA,  cMINA,  cVACIA, cVACIA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cMINA,  cVACIA },
        { cVACIA, cMINA,  cVACIA, cVACIA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
        { cMINA,  cVACIA, cMINA,  cVACIA, cVACIA },
};
jugadas jugadasValidas3 = {
        jugada(pos(0, 2), 2),jugada(pos(0, 4), 1),
        jugada(pos(1, 0), 3),jugada(pos(1, 1), 3),
        jugada(pos(1, 2), 3),jugada(pos(4, 4), 0),
};

TEST(perdio,jugadorNoPerdio){
    ASSERT_FALSE(perdio(t7,jugadasValidas3));
}
