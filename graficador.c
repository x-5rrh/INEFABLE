#include "GRAFICADOR.h"
#include <stdio.h>
#include <stdlib.h>
#include "GBT/gbt.h"


void graficar_cuadrado(int pos_x, int pos_y, int lado, int color) {
    int ancho, alto;
    for (ancho = 0; ancho < lado; ancho++) {
        for (alto = 0; alto < lado; alto++) {
            gbt_dibujar_pixel(pos_x + ancho, pos_y + alto, color);
        }
    }
}

void constructor_graficador(GRAFICADOR* g, int x, int y){
    g->offset_x = x;
    g->offset_y = y;
}

void graficar_matriz(GRAFICADOR* g, MATRIZ* m, int cord_x, int cord_y, int escala) {
    if (m == NULL || m->matriz == NULL) {
        return;
    }
    int color, i, j, pixel_x, pixel_y;
    for(i = 0; i < m->columnas; i++) {
        for(j = 0; j < m->filas; j++) {

            color = m->matriz[j][i];
            if(color != -1) {
                pixel_x = cord_x + (i * escala);
                pixel_y = cord_y + (j * escala);
                graficar_cuadrado(pixel_x, pixel_y, escala, color);
            }
        }
    }
}
