
//
// Este archivo contiene las declaraciones de las funciones auxiliares
// que ustedes necesiten implementar. Tienen que coincidir con el código
// de esas mismas funciones, que estará en auxiliares.cpp
//

#pragma once   // esta línea es para que el archivo se incluya una sola vez

#include "definiciones.h"

bool posValida(tablero& t, pos p);
bool coordenadaValida(tablero& t, int pi);
vector<pos> devolverPosAdyacentes(tablero& t, pos p);
bool perteneceAJugadas(jugadas& j,pos p);
bool perteneceABanderitas(banderitas& b,pos p);
banderitas borrarBanderitas(banderitas& b,pos p);
bool hayMinas(tablero& t,pos p);
int cantidadMinasTotales(tablero& t,jugadas& j);
int cantidadDeNoMinas(tablero& t);
bool existeJugada121(tablero t);
vector<pos> jugadas121(tablero t,jugadas j);
