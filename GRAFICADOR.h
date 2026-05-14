#ifndef GRAFICADOR_H_INCLUDED
#define GRAFICADOR_H_INCLUDED
#include "GBT/gbt.h"
#include "MATRIZ.h"


typedef struct {
    int offset_x;
    int offset_y;
    int unidad_base;
} GRAFICADOR;

void constructor_graficador(GRAFICADOR* g, int x, int y);
void graficar_cuadrado(int pos_x, int pos_y, int lado, int color);
void graficar_matriz(GRAFICADOR* g, MATRIZ* m, int cord_x, int cord_y, int escala);

#endif // GRAFICADOR_H_INCLUDED
