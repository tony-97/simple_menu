#include <simple_menu.h>

// First we declare our menus as an array of const char*.
const char* MAIN_MENU[] =
{
    "WELCOME!",
    "=================",
    "1.- 1st Option.",
    "2.- 2nd Option.",
    "3.- Exit Option.",
    NULL
};

const char* SUB_MENU2[] =
{
    "Sub Menu2",
    "================",
    "2.1.- 1st Option.",
    "2.2.- 2nd Option.",
    "2.3.- Return Option.",
    NULL
};

// then we declare our functions that will be called with the current
// option selected by the user 

void sub_menu2(void* data, int opt)
{
    switch (opt) {
    case 1:
        printf("Entered first option from the sub menu2...\n");
        break;
    case 2:
        printf("Entered second option from the sub menu2...\n");
        break;
    }
}

// opt is the option selected by the user
void main_menu(void* data, int opt)
{
    switch (opt) {
        case 1:
            printf("Entered first option...\n");
            break;
        case 2:
            // we can call recusive menus
            smn_do_menu(SUB_MENU2, 3, NULL, sub_menu2);
            break;
    }
}

int main()
{
    /*
     * 1.- The first argument is the menu that will be displayed on the console
     * 2.- The second argument is the option to exit the current menu.
     * 3.- The third argument is the data to be passed to the fourth argument,
     *     can be NULL if we have no data to pass.
     * 4.- The fourth argument is the function that will be called with the current user-selected option
     */
    smn_do_menu(MAIN_MENU, 3, NULL, main_menu);
    return 0;
}
