// Tests para la función cambiarBanderita.
// Ver el archovo README.md para ayuda


#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

tablero t2 = {
        { cMINA,  cMINA,  cVACIA, cVACIA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cMINA,  cVACIA },
        { cVACIA, cMINA,  cVACIA, cVACIA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
        { cMINA,  cVACIA, cMINA,  cVACIA, cVACIA },
};

jugadas jugadasValidas1 = {
        jugada(pos(0, 2), 2),jugada(pos(0, 4), 1),
        jugada(pos(1, 0), 3),jugada(pos(1, 1), 3),
        jugada(pos(1, 2), 3),jugada(pos(1, 4), 1)
};

// Primer TEST: pos pertenece a jugadas

pos p4 = {0,2};

banderitas b1 = { {3,0} };
banderitas b2 = {{3,0}};

TEST(cambiarBanderita,posPertenceAJugadas){
    jugadas j = jugadasValidas1;
    cambiarBanderita(t2, jugadasValidas1, p4, b1);
    ASSERT_EQ(b1,b2);
}

// Segundo TEST: Quita una banderita.

pos p5 = {3,0};

banderitas b3 = { {3,0} };
banderitas b4 = {};

TEST(cambiarBanderita,quitaBanderita){
    jugadas j = jugadasValidas1;
    cambiarBanderita(t2, jugadasValidas1, p5, b3);
    ASSERT_EQ(b3,b4);
}

// Tercer TEST: Agrega una nueva banderita a la secuencia.

pos p6 = {2,2};

banderitas b5 = { {3,0}};
banderitas b6 = {{3,0},{2,2}};

TEST(cambiarBanderita,agregaBanderita){
    jugadas j = jugadasValidas1;
    cambiarBanderita(t2, jugadasValidas1, p6, b5);
    ASSERT_EQ(b5,b6);
}
