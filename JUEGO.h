#ifndef TABLERO_H_INCLUDED
#define TABLERO_H_INCLUDED

typedef struct{
    MATRIZ matriz;
    int size_f;
}JUEGO;

void constructor_tablero(JUEGO* j, int x, int y, int size_f);
void dibujar_tablero(JUEGO* j, int ancla_x, int ancla_y);

#endif // TABLERO_H_INCLUDED
