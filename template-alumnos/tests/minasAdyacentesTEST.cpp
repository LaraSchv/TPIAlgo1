// Tests para la función minasAdyacentes.
// Ver el archivo README.md para ayuda

#include "../ejercicios.h"
#include "../auxiliares.h"
#include "../definiciones.h"
#include "gtest/gtest.h"

using namespace std;


tablero t1 = {
        { cMINA,  cMINA,  cVACIA, cVACIA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cMINA,  cVACIA },
        { cVACIA, cMINA,  cVACIA, cVACIA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
        { cMINA,  cVACIA, cMINA,  cVACIA, cVACIA },
};

pos p1 = {0,0};
pos p2 = {2,2};
pos p3 = {4,4};

TEST(minasAdyacentes,bordeSuperiorIzquierdo){
    int result = minasAdyacentes(t1, p1);
    ASSERT_EQ(result, 1);
}

TEST(minasAdyacentes,medio){
    int result = minasAdyacentes(t1, p2);
    ASSERT_EQ(result, 2);
}

TEST(minasAdyacentes,noHayMinas){
    int result = minasAdyacentes(t1, p3);
    ASSERT_EQ(result, 0);
}
