// Tests para la función minasAdyacentes.
// Ver el archivo README.md para ayuda

#include "../ejercicios.h"
#include "../auxiliares.h"
#include "../definiciones.h"
#include "gtest/gtest.h"

using namespace std;


tablero t = {
    { cMINA,  cMINA,  cVACIA, cVACIA, cVACIA },
    { cVACIA, cVACIA, cVACIA, cMINA,  cVACIA },
    { cVACIA, cMINA,  cVACIA, cVACIA, cVACIA },
    { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
    { cMINA,  cVACIA, cMINA,  cVACIA, cVACIA },
};

pos pNormal = {<2,2>};

pos pBorde = {<0,0>};

TEST(minasAdyacentesTEST, casoNormal){
    pos p = pNormal;
    ASSERT_EQUAL(minasAdyacentes(t,p),2);
}

TEST(minasAdyacentesTEST, casoBorde){
    pos p = pBorde;
    ASSERT_EQUAL(minasAdyacentes(t,p),1);
}
