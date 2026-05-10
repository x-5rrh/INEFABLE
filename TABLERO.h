#ifndef TABLERO_H_INCLUDED
#define TABLERO_H_INCLUDED

typedef struct{
    int **tablero;
    int filas, columnas;
    int size_f;
}TABLERO;

void iniciar_tablero(TABLERO* tablero, int x, int y, int size_f);
void dibujar_tablero(TABLERO* t, int offset_x, int offset_y);

#endif // TABLERO_H_INCLUDED
