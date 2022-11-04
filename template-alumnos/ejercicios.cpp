//
// Este archivo contiene las definiciones de las funciones que implementan los ejercicios
//

#include <stdio.h>
#include <iostream>


#include "definiciones.h"
#include "ejercicios.h"
#include "auxiliares.h"

using namespace std;

/******++++**************************** EJERCICIO minasAdyacentes ***********+++***********************/

int minasAdyacentes(tablero& t, pos p) {
    int res = 0;
    vector<pos> posAdyacentes = devolverPosAdyacentes(t, p);

    for (int i=0; i<posAdyacentes.size(); i++){
        if (t[posAdyacentes[i].first][posAdyacentes[i].second]){
            res++;
        }
    }

    return res;
}

/******++++**************************** EJERCICIO plantarBanderita ***********+++***********************/

void cambiarBanderita(tablero& t, jugadas& j, pos p, banderitas& b) {
    if(posValida(t,p) && !perteneceAJugadas(j, p)){
        if(!perteneceABanderitas(b, p)){
            b.push_back(p);
        }
        else{
            borrarBanderitas(b,p);
        }
    }
}

/******++++**************************** EJERCICIO perdio ***********+++***********************/
bool perdio(tablero& t, jugadas& j) {
    bool res = false;

    for (int i = 0; i < j.size(); ++i) {
        if (hayMinas(t,j[i].first)){
            res = true;
        }
    }

    return res;
}

/******++++**************************** EJERCICIO gano ***********+++***********************/
bool gano(tablero& t, jugadas& j) {
    bool res = false;

    for (int i = 0; i < j.size(); ++i) {
        if (cantidadMinasTotales(t,j) >= 1){ // Si la cantidad de minas en jugadas es >= 1 entonces perdio por lo tanto retorna false.
            break;
        }
        else if(j.size() == cantidadDeNoMinas(t)){
            res = true;
        }
        else{
            break;
        }
    }

    return res;
}

/******++++**************************** EJERCICIO jugarPlus ***********+++***********************/
void jugarPlus(tablero& t, banderitas& b, pos p, jugadas& j) {

    jugada pJugada = {p, minasAdyacentes(t, p)};
    j.push_back(pJugada);

    if (not t[p.first][p.second]) {
        vector<pos> posicionesAdyacentes = devolverPosAdyacentes(t,p);
        for (int i=0; i<posicionesAdyacentes.size(); i++){
            pos q = posicionesAdyacentes[i];
            if (not perteneceAJugadas(j, q) && not perteneceABanderitas(b, q) && not t[q.first][q.second]){
                jugarPlus(t, b, q, j);
            }
        }
    }

}

/******++++**************************** EJERCICIO sugerirAutomatico121 ***********+++***********************/
bool sugerirAutomatico121(tablero& t, banderitas& b, jugadas& j, pos& p) {
    // ...
    p = pos(0,1);
    return true;
}
