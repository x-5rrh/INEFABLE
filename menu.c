#include "MENU.h"
#include "GBT/gbt.h"
#include "GRAFICADOR.h"

void constructor_menu(MENU* menu, GRAFICADOR* graficador_ajeno, int* dificulta_m){
    menu->difucultad = dificulta_m;
    menu->graficador = graficador_ajeno;
}

void dibujar_menu(MENU* menu){
    MATRIZ matriz;
    int letra_c[] = {
        1,  1,  1,  1,
        1, 2, 2, 2,
        1 ,2, 2, 2,
        1,  1,  1,  1,
    };
    gbt_borrar_backbuffer(12);

    crear_matriz_molde(&matriz, letra_c, 4, 4);
    graficar_matriz(menu->graficador, &matriz, 100, 100, 30);

    eliminar_matriz(&matriz);
}
