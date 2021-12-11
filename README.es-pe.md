# Simple Menu

Simple menú es una sencilla librería de solo inclusión en C para mostrar menús en la consola, con opciones numéricas.

## Instalación

Solo copialo e incluyelo a tu proyecto.

## Ejemplo
```c
#include <simple_menu.h>
#include <stdio.h>

// Primero declaramos nuestros menús como arreglo de puntero a caracteres(un arreglo de palabras).
// [ADVERTENCIA]: tiene que terminar en NULL
const char* MENU_PRINCIPAL[] =
{
    "Bienvenido!",
    "=================",
    "1.- 1era Opción.",
    "2.- 2nda Opción.",
    "3.- Salir.",
    NULL
};

const char* SUB_MENU2[] =
{
    "Sub Menu2",
    "================",
    "2.1.- 1era Opción.",
    "2.2.- 2nda Opción.",
    "2.3.- Volver.",
    NULL
};

// Luego declaramos las funciones que se van a llamar con la
// opción seleccionada por el usuario
void sub_menu2(void* data, int opt)
{
    switch (opt) {
    case 1:
        printf("Primera opción seleccionada del sub menu2...\n");
        break;
    case 2:
        printf("Segunda opción seleccionada del sub menu2...\n");
        break;
    }
}

// opt es la opción seleccionada por el usuario
void menu_principal(void* data, int opt)
{
    switch (opt) {
        case 1:
            printf("Primera opción seleccionada...\n");
            break;
        case 2:
            // podemos llamar otros menús dentro de otros menús
            smn_do_menu(SUB_MENU2, 3, NULL, sub_menu2);
            break;
    }
}

int main()
{
    /*
     * 1.- El primer argumento es el menú que se va mostrar por pantalla.
     * 2.- El segundo argumento es la opción para salir del menú actual.
     * 3.- El tercer argumento son los datos que serán pasados a la función del 4to argumento, 
     *     Puede ser NULL si no tenemos datos que pasar.
     * 4.- El cuarto argumento es la función que sera llamada con la opción seleccionada por el usuario.
     */
    smn_do_menu(MENU_PRINCIPAL, 3, NULL, menu_principal);
    return 0;
}
```
## Licencia
[MIT](https://choosealicense.com/licenses/mit/)
