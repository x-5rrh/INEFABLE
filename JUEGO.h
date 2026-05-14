#ifndef TABLERO_H_INCLUDED
#define TABLERO_H_INCLUDED
#include "GRAFICADOR.h"
#include "MATRIZ.h"

typedef struct{
    MATRIZ matriz;
    GRAFICADOR* graficador;
    int* puntos;

}JUEGO;

void constructor_juego(JUEGO* j, GRAFICADOR* g, int x, int y);
void dibujar_juego(JUEGO* j);

#endif // TABLERO_H_INCLUDED
