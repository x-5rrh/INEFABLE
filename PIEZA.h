#ifndef FIGURA_H_INCLUDED
#define FIGURA_H_INCLUDED
#include "MATRIZ.h"

typedef struct{
    MATRIZ pieza;
    int cord_fila;
    int cord_columna;
}PIEZA;

void crear_pieza(PIEZA* pieza, int indice_pieza, int cord_x, int cord_y);
void rotar_figura(PIEZA* p);
void mover_figura(PIEZA* p);

#endif // FIGURA_H_INCLUDED
