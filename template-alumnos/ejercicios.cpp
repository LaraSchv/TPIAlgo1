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

    for (int i=-1; i<=1; i++){
        for (intj=-1; j<=1; j++){
            int q0 = p.first()+i;
            int q1 = p.second()+j;
            if (posValida(t, pos(q0, q1)) && i != 0 && j != 0){
                if (t[q0][q1]){
                    res++;
                }
            } 
        }
    }

    return res;
}

bool coordenadaValida(tablero& t, int pi){
    if (0 <= pi && pi < t.size()){
        return true;
    }else{
        return false;
    }
}

bool posValida(tablero& t, pos p){
    if (coordenadaValida(t, p.first()) && coordenadaValida(t, p.second())){
        return true;
    }else{
        return false;
    }
}

/******++++**************************** EJERCICIO plantarBanderita ***********+++***********************/

void cambiarBanderita(tablero& t, jugadas& j, pos p, banderitas& b) {
    // ...
}

/******++++**************************** EJERCICIO perdio ***********+++***********************/
bool perdio(tablero& t, jugadas& j) {
    // ...
}

/******++++**************************** EJERCICIO gano ***********+++***********************/
bool gano(tablero& t, jugadas& j) {
    // ...
}

/******++++**************************** EJERCICIO jugarPlus ***********+++***********************/
void jugarPlus(tablero& t, banderitas& b, pos p, jugadas& j) {
    // ...
}

/******++++**************************** EJERCICIO sugerirAutomatico121 ***********+++***********************/
bool sugerirAutomatico121(tablero& t, banderitas& b, jugadas& j, pos& p) {
    // ...
}
