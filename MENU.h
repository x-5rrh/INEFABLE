#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "GRAFICADOR.h"

typedef struct{
    GRAFICADOR* graficador;
    int is_render;
    int* difucultad;
    int* estado;
}MENU;

void constructor_menu(MENU* menu, GRAFICADOR* g, int* dificultad);
void dibujar_menu(MENU* menu);

#endif // MENU_H_INCLUDED
