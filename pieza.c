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

void crear_pieza(PIEZA* p, int indice_pieza, int fil, int col){
    p->cord_fila = fil;
    p->cord_columna = col;
    p->id = indice_pieza;
    crear_matriz_molde(&p->pieza, pieza_lista[indice_pieza], pieza_fil[indice_pieza], pieza_col[indice_pieza]);
}

void pieza_bajar(PIEZA* p, int cantidad){
    p->cord_fila += cantidad;
}

void pieza_eliminar(PIEZA* p){
    p->cord_columna = -1;
    p->cord_fila = -1;
    p->id = -1;
    eliminar_matriz(&p->pieza);
}
