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

    // minas = true

    for (int i = 0; i < j.size(); ++i) {
        if (hayMinas(t,j[i].first)){
            res = true;
        }
    }

    return res;
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
