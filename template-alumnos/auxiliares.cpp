//
// Este archivo contiene las definiciones de las funciones auxiliares
// que ustedes necesiten implementar. Tienen que coincidir con las 
// declaraciones de auxiliares.h
//

#include <iostream>
#include <vector>

#include "definiciones.h"
#include "ejercicios.h"
#include "auxiliares.h"

using namespace std;

bool posValida(tablero& t, pos p){
    if (coordenadaValida(t, p.first) && coordenadaValida(t, p.second)){
        return true;
    }else{
        return false;
    }
}

bool coordenadaValida(tablero& t, int pi){
    if (0 <= pi && pi < t.size()){
        return true;
    }else{
        return false;
    }
}

vector<pos> devolverPosAdyacentes(tablero& t, pos p){
    vector<pos> posAdyacentes;

    for (int i=-1; i<=1; i++){
        for (int j=-1; j<=1; j++){
            int q0 = p.first+i; //
            int q1 = p.second+j; //

            if (posValida(t, pos(q0, q1) )){
                if (! (q0 == p.first && q1 == p.second))
                {
                    posAdyacentes.push_back(pos(q0, q1));
                }
            }
        }
    }

    return posAdyacentes;
}

bool perteneceAJugadas(jugadas& j,pos p){
    bool pertenece = false;

    for (int i = 0; i < j.size(); ++i) {
        if (p == j[i].first){
            pertenece = true;
        }
    }
    return pertenece;
}

bool perteneceABanderitas(banderitas& b,pos p){
    bool pertenece = false;

    for (int i = 0; i < b.size(); ++i) {
        if (p == b[i]){
            pertenece = true;
        }
    }
    return pertenece;
}

banderitas borrarBanderitas(banderitas& b,pos p){
    for (int i = 0; i < b.size(); ++i) {
        if (p == b[i])
            b.erase(b.begin()+i);
    }
    return b;
}

bool hayMinas(tablero& t,pos p){
    bool minas = false;

    for (int i = 0; i < t.size(); ++i) {
        for (int j = 0; j < t.size(); ++j) {
            if (i == p.first && j == p.second){
                if (t[i][j]){
                    minas = true;
                }
            }
        }
    }

    return minas;
}

// Si una posicion que pertenece a jugadas tiene una mina entonces suma +1.

int cantidadMinasTotales(tablero& t,jugadas& j){
    int cantidad = 0;

    for (int i = 0; i < j.size(); ++i) {
        if (t[j[i].first.first][j[i].first.second]){
            cantidad++;
        }
    }

    return cantidad;
}

// Cuenta las cantidad de posiciones totales en las que no hay minas en el tablero.

int cantidadDeNoMinas(tablero& t){
    int posVacias = 0;

    for (int i = 0; i < t.size(); ++i) {
        for (int j = 0; j < t.size(); ++j) {
            if(!t[i][j]){
                posVacias++;
            }
        }
    }

    return posVacias;
}

bool existeJugada121(tablero t){
    int existe121 = false;

    for (int i = 0; i < t.size(); ++i) {
        for (int j = 0; j < t.size(); ++j){
            if ((minasAdyacentes(t,{i,j})) == 2 && (minasAdyacentes(t,{i+1,j})) == 1 && (minasAdyacentes(t,{i-1,j})) == 1 || (minasAdyacentes(t,{i,j})) == 2 && (minasAdyacentes(t,{i,j-1})) == 1 && (minasAdyacentes(t,{i,j+1})) == 1){
                existe121 = true;
            }
        }
    }

    return existe121;
}

vector<pos> jugadas121(tablero t,jugadas j){
    vector<pos> jugada121;


    for (int i = 0; i < j.size(); ++i) {
        if (j[i].second == 2){
            // Vertical
            if (perteneceAJugadas(j,{j[i].first.first-1,j[i].first.second}) && perteneceAJugadas(j,{j[i].first.first+1,j[i].first.second})){
                if (minasAdyacentes(t,{j[i].first.first-1,j[i].first.second}) == 1 && minasAdyacentes(t,{j[i].first.first+1,j[i].first.second}) == 1){
                    jugada121.push_back({j[i].first.first-1,j[i].first.second});
                    jugada121.push_back({j[i].first.first,j[i].first.second});
                    jugada121.push_back({j[i].first.first+1,j[i].first.second});
                    jugada121.push_back({1,0});
                } //
            }
            // Horizontal
            else if (perteneceAJugadas(j,{j[i].first.first,j[i].first.second-1}) && perteneceAJugadas(j,{j[i].first.first,j[i].first.second+1})){
                if (minasAdyacentes(t,{j[i].first.first,j[i].first.second-1}) == 1 && minasAdyacentes(t,{j[i].first.first,j[i].first.second+1}) == 1){
                    jugada121.push_back({j[i].first.first,j[i].first.second-1});
                    jugada121.push_back({j[i].first.first,j[i].first.second});
                    jugada121.push_back({j[i].first.first,j[i].first.second+1});
                    jugada121.push_back({0,1});
                }
            }
        }
    }

    return jugada121;
}
