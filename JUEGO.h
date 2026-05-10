#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED
#include "TABLERO.h"
#include "FIGURA.h"


typedef struct{
    TABLERO tablero;
    FIGURA figura;
    int estado_juego;
    int dificultad;
    int velocidad;
    int puntos;
    int modo_juego;
    int tamanio_bloque;
    int offset_x;
    int offset_y;
    int ancla_x;
    int ancla_y;
}JUEGO;

void contructor_juego(JUEGO* juego, int offset_x, int offset_y, int filas, int columnas);
void cambiar_estado(JUEGO* juego, int estado);

#endif // JUEGO_H_INCLUDED
