#include "GRAFICADOR.h"
#include <stdio.h>
#include <stdlib.h>
#include "GBT/gbt.h"


void constructor_graficador(GRAFICADOR* g, int x, int y, int unidad_default){
    g->screen_x = x;
    g->screen_y = y;
    g->mid_screen_x = (int)x / 2;
    g->mid_screen_y = (int) y / 2;
    g->unidad_base = unidad_default;
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

void graficar_matriz_consola(MATRIZ* m){
    int i, j;
    for(i = 0; i < m->filas; i++){
        for(j = 0; j < m->columnas; j++){
            printf("%d \t|", m->matriz[i][j]);
        }
        printf("\n");
    }
}

/*void graficar_palabra(GRAFICADOR* g, char c[], int cord_x, int cord_y, int escala){
    int i = 0;
    while(c[i] != 0){
        switch(c[i]){
            case 72:
                graficar_matriz(g, g->letra, )
            break;
        }
    }
}*/

static void graficar_cuadrado(int pos_x, int pos_y, int lado, int color) {
    int ancho, alto;
    for (ancho = 0; ancho < lado; ancho++) {
        for (alto = 0; alto < lado; alto++) {
            gbt_dibujar_pixel(pos_x + ancho, pos_y + alto, color);
        }
    }
}
