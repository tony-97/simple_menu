
// podemos definir las siguientes macros para personalisar los bordes
// [ADVERTENCIA]: solo el estandar ASCII esta soportado
#define MNS_ESQUINA_SUPERIOR_IZQUIERDA '#'
#define MNS_ESQUINA_SUPERIOR_DERECHA   '#'
#define MNS_ESQUINA_SUPERIOR_IZQUIERDA '#'
#define MNS_ESQUINA_INFERIOR_DERECHA   '#'
#define MNS_BARRA_HORIZONTAL           '='
#define MNS_BARRA_VERTICAL             '|'

#include <menu_simple.h>

const char* MAIN_MENU[] =
{
    "Bienvenido!",
    "====================",
    "1.- Primero.",
    "2.- Segundo.",
    "3.- Salir.",
    NULL
};

int main()
{
    mns_hacer_menu(MAIN_MENU, 3, NULL, NULL);
    return 0;
}
