#ifndef FIGURA_H_INCLUDED
#define FIGURA_H_INCLUDED

typedef struct{
    int forma[4][4];
    int x, y, id;
}FIGURA;

void rotar_figura();
void mover_figura();

#endif // FIGURA_H_INCLUDED
