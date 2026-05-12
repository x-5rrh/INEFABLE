#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

typedef struct{
    int difucultad;
    int estado;
}MENU;

void dibujar_menu(MENU* menu, int offset_x, int offset_y);

#endif // MENU_H_INCLUDED
