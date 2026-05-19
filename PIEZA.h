#ifndef FIGURA_H_INCLUDED
#define FIGURA_H_INCLUDED
#include "MATRIZ.h"

typedef struct{
    MATRIZ pieza;
    int cord_fila;
    int cord_columna;
    int id;
}PIEZA;

void crear_pieza(PIEZA* pieza, int indice_pieza, int fil, int col);
void pieza_bajar(PIEZA* p, int cantidad);
void pieza_rotar(PIEZA* p);
void pieza_eliminar(PIEZA* p);

#endif // FIGURA_H_INCLUDED
