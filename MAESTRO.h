#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED
#include "JUEGO.h"
#include "PIEZA.h"
#include "MENU.h"
#include "GRAFICADOR.h"

//MAESTRO tiene, por asi decirlo, los datos originale. El resto de TDA tiene una "copia", pueden modificarlo pero para manetener la jerarquia maestro tiene el acceso total de estos//
typedef struct{
    JUEGO juego;
    PIEZA pieza;
    MENU menu;
    GRAFICADOR* graficador;
    int estado_juego; //0 = MENU, 1 = JUEGO, 2 = GAME OVER
    double* velocidad;
    int* puntos;
    int* modo_juego;
}MAESTRO;

void contructor_maestro(MAESTRO* m, GRAFICADOR* g ,int filas, int columnas);
void maestro_dibujar(MAESTRO* m);
void maestro_actualizar(MAESTRO* m);

#endif // JUEGO_H_INCLUDED
