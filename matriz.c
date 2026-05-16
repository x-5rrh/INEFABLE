#include <stdlib.h>
#include "MATRIZ.h"

int crear_matriz_vacia(MATRIZ* m ,int fil, int col){
    if(m->is_created) return -1;
    m->filas = fil;
    m->columnas = col;
    m->is_especial = 0;

    m->matriz = malloc(fil * sizeof(int*));
    for(int i = 0; i < fil; i++){
        m->matriz[i] = calloc(col, sizeof(int));

        for (int j = 0; j < col; j++) { //llenamos la matriz con "aire"
            m->matriz[i][j] = -1;
        }
    }

    m->is_created = 1;
}


/**
* @brief Crear una "matriz" copiando los datos de una array molde. La "matriz" resultante es un array de punteros.
* La "matriz" molde debe ser si o si una array unidimecional
* @param m Puntero a la matriz a inicializar.
* @param molde Array unidimencional con valores.
* @param fil Cantidad de filas.
* @param col Cantidad de columnas.
*/
int crear_matriz_molde(MATRIZ* m, int *molde, int fil, int col){
    if(m->is_created) return -1;
    int indice_molde = 0;
    m->filas = fil;
    m->columnas = col;
    m->is_especial = 0;

    crear_matriz_vacia(m, fil, col);

    for (int i = 0; i < fil; i++) {
        for (int j = 0; j < col; j++) {
            m->matriz[i][j] = molde[indice_molde];
            indice_molde++;
        }
    }
    m->is_created = 1;

    return 1;
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
