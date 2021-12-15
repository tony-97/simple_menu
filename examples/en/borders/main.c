
// we can define the following macros to customize the borders
// [WARNING]: only standard ASCII is supported
#define SMN_TOP_LEFT_CORNER     '#'
#define SMN_TOP_RIGHT_CORNER    '#'
#define SMN_BOTTOM_LEFT_CORNER  '#'
#define SMN_BOTTOM_RIGHT_CORNER '#'
#define SMN_HORIZONTAL_BAR      '='
#define SMN_VERTICAL_BAR        '|'

#include <simple_menu.h>

const char* MAIN_MENU[] =
{
    "Welcome!",
    "====================",
    "1.- First option.",
    "2.- Second option.",
    "3.- Exit.",
    NULL
};

int main()
{
    smn_do_menu(MAIN_MENU, 3, NULL, NULL);
    return 0;
}
