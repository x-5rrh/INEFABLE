#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED
#include "TABLERO.h"
#include "FIGURA.h"
#include "MENU.h"


typedef struct{
    JUEGO tablero;
    FIGURA figura;
    MENU menu;
    int estado_juego; //0 = MENU, 1 = JUEGO, 2 = GAME OVER
    int dificultad;
    int velocidad;
    int puntos;
    int modo_juego;
    int tamanio_bloque;
    int offset_x;
    int offset_y;
}MAESTRO;

void contructor_juego(MAESTRO* m, int offset_x, int offset_y, int filas, int columnas);
void alternar_estados(MAESTRO* m);

#endif // JUEGO_H_INCLUDED
