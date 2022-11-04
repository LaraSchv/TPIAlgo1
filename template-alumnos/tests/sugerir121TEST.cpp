// Tests para la función minasAdyacentes.
// Ver el archivo README.md para ayuda

#include "../ejercicios.h"
#include "../auxiliares.h"
#include "../definiciones.h"
#include "gtest/gtest.h"

using namespace std;


tablero t5 = {
        { cMINA,  cVACIA,  cMINA, cVACIA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cVACIA,  cMINA },
        { cVACIA, cVACIA,  cVACIA, cVACIA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
        { cMINA,  cVACIA, cMINA,  cVACIA, cVACIA },
};

banderitas b8 = { {3,0} };

pos pVacio = {0,0};

jugadas jugadasPatron = {
        jugada(pos(1, 0), 1), jugada(pos(1, 1), 2), jugada(pos(1, 2), 1),
        jugada(pos(4, 1), 2)
};


TEST(sugerirAutomatico121, jugadaBuena){
    pos pSugerida = pVacio;
    bool hay = sugerirAutomatico121(t5, b8, jugadasPatron, pSugerida);
    ASSERT_EQ(pSugerida, pos(0, 1));
}
