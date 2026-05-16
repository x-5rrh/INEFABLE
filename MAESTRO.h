#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED
#include "JUEGO.h"
#include "FIGURA.h"
#include "MENU.h"
#include "GRAFICADOR.h"

//MAESTRO tiene, por asi decirlo, los datos originale. El resto de TDA tiene una "copia", pueden modificarlo pero para manetener la jerarquia maestro tiene el acceso total de estos//
typedef struct{
    JUEGO juego;
    FIGURA figura;
    MENU menu;
    GRAFICADOR* graficador;
    int estado_juego; //0 = MENU, 1 = JUEGO, 2 = GAME OVER
    int* dificultad;
    int* velocidad;
    int* puntos;
    int* modo_juego;
}MAESTRO;

void contructor_maestro(MAESTRO* m, GRAFICADOR* g ,int filas, int columnas);
void alternar_estados(MAESTRO* m);

#endif // JUEGO_H_INCLUDED
