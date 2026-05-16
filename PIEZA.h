#ifndef FIGURA_H_INCLUDED
#define FIGURA_H_INCLUDED
#include "MATRIZ.h"

typedef struct{
    MATRIZ pieza;
    int x;
    int y;
}FIGURA;

void contructor_figura(FIGURA* g);
void rotar_figura(FIGURA* g);
void mover_figura(FIGURA* g);

#endif // FIGURA_H_INCLUDED
