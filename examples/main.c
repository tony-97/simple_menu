#include <menu_simple.h>

const char* MENU[] =
{
    "WELCOME!",
    "=================",
    "1.- 1st Option.",
    "2.- 2nd Option.",
    "3.- 3rd Option.",
    "4.- Exit Option.",
    NULL
};

const char* SUB_MENU1[] =
{
    "Sub Menu1",
    "================",
    "1.1.- 1st Option.",
    "1.2.- 2nd Option.",
    "1.3.- 3rd Option.",
    "1.4.- Exit Option.",
    NULL
};

const char* SUB_MENU2[] =
{
    "Sub Menu2",
    "================",
    "2.1.- 1st Option.",
    "2.2.- 2nd Option.",
    "2.3.- 3rd Option.",
    "2.4.- Exit Option.",
    NULL
};

void do_things(void* data, int opt)
{
    switch (opt) {
        case 1:
            smn_do_menu(SUB_MENU1, 4, NULL, NULL);
            break;
        case 2:
            smn_do_menu(SUB_MENU2, 4, NULL, NULL);
            break;
    }
}

int main()
{
    smn_do_menu(MENU, 4, NULL, do_things);
    return 0;
}
