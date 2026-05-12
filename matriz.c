#include "MATRIZ.h"

void crear_matriz(MATRIZ* m ,int fil, int col){
    m->filas = fil;
    m->columnas = col;

    m->matriz = malloc(fil * sizeof(int*));

    for(int i = 0; i < x; i++){
        m->matriz[i] = calloc(col, sizeof(int));

        for (int j = 0; j < col; j++) { //llenamos la matriz con "aire"
            m->matriz[i][j] = -1;
        }
    }
}

void eliminar_matriz(MATRIZ* m){
    if (m == NULL || m->matriz == NULL) {
        return;
    }

    for(int i = 0; i < m->filas; i++) {
        free(m->matriz[i]);
    }

    free(m->matriz);

    m->matriz = NULL;
    m->filas = 0;
    m->columnas = 0;
}
