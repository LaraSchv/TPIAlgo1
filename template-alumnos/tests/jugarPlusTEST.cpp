// Tests para la función minasAdyacentes.
// Ver el archivo README.md para ayuda

#include "../ejercicios.h"
#include "../auxiliares.h"
#include "../definiciones.h"
#include "gtest/gtest.h"

using namespace std;


tablero t3 = {
        { cMINA,  cMINA,  cVACIA, cVACIA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cMINA,  cVACIA },
        { cVACIA, cMINA,  cVACIA, cVACIA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
        { cMINA,  cVACIA, cMINA,  cVACIA, cVACIA },
};

banderitas b = { {3,0} };

pos p = {0,2};

jugadas jugadasVacias = {};


TEST(jugarPlus, jugadaBuena){
    jugarPlus(t3, b, p, jugadasVacias);
    ASSERT_EQ(jugadasVacias.size(), 18);
}
