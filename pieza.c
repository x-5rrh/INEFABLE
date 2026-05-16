#include <stdio.h>
#include "PIEZA.h"
#include "MATRIZ.h"

static int pieza_1[] = {5 ,  5,    5, -1,  5,   -1,-1,  5,   -1};
static int pieza_2[] = {-1,  1, -1,  1, 1 ,  1};
static int pieza_3[] = {4 ,  4, -1, -1,  4,  4};
static int pieza_4[] = {14,  14, 14,  14};
static int pieza_5[] = {-1,  2,  2, 2,  2, -1};
static int pieza_6[] = {-1, -1 , 166, 166, 166, 166};
static int pieza_7[] = {3, 3, 3, 3};
//arrays paralelos, cada indice corresponde a las filas y columnas de una pieza
static int *pieza_lista[7] = {pieza_1, pieza_2, pieza_3, pieza_4, pieza_5, pieza_6, pieza_7};
static int pieza_fil[7] = {3, 3, 2, 2, 2, 2, 1};
static int pieza_col[7] = {3, 2, 3, 2, 3, 3, 4};

void crear_pieza(PIEZA* p, int indice_pieza, int cord_x, int cord_y){
    p->cord_columna = cord_y;
    p->cord_fila = cord_x;
    crear_matriz_molde(&p->pieza, pieza_lista[indice_pieza], pieza_fil[indice_pieza], pieza_col[indice_pieza]);

}
