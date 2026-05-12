#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED

typedef struct {
    int **matriz;
    int filas;
    int columnas;
    int is_especial;
    int bloque_especial[8][8];
}MATRIZ;

void crear_matriz(MATRIZ* m,int fil, int col);
void cambiar_indice(MATRIZ* m ,int fil, int col, int valor);
int fila_llena(MATRIZ* m , int fil);
void eliminar_matriz(MATRIZ* m);

#endif // MATRIZ_H_INCLUDED
