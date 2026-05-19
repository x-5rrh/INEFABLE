#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED

typedef struct {
    int **matriz;
    int filas;
    int columnas;
    int is_especial;
    int is_created;
    int bloque_especial[8][8];
}MATRIZ;

int crear_matriz_vacia(MATRIZ* m,int fil, int col);
int crear_matriz_molde(MATRIZ* m, int *molde, int fil, int col);
//void matriz_copiar_pieza(MATRIZ* m, PIEZA* p);
int fila_llena(MATRIZ* m , int fil);
void eliminar_matriz(MATRIZ* m);

#endif // MATRIZ_H_INCLUDED
