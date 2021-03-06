#ifndef SIMPLE_MENU_H_98543095843097189471
#define SIMPLE_MENU_H_98543095843097189471

#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>

#ifndef SMN_TOP_LEFT_CORNER
#define SMN_TOP_LEFT_CORNER  '+'
#endif

#ifndef SMN_TOP_RIGHT_CORNER
#define SMN_TOP_RIGHT_CORNER '+'
#endif

#ifndef SMN_BOTTOM_LEFT_CORNER
#define SMN_BOTTOM_LEFT_CORNER '+'
#endif

#ifndef SMN_BOTTOM_RIGHT_CORNER
#define SMN_BOTTOM_RIGHT_CORNER '+'
#endif

#ifndef SMN_VERTICAL_BAR
#define SMN_VERTICAL_BAR   '|'
#endif

#ifndef SMN_HORIZONTAL_BAR
#define SMN_HORIZONTAL_BAR '-'
#endif

static inline size_t smn_find_max_len(const char* menu[])
{
    size_t max_len = 0;
    for (size_t i = 0; menu[i] != NULL; ++i) {
        const size_t len = strlen(menu[i]);
        if (max_len < len) {
            max_len = len;
        }
    }

    return max_len;
}

static inline void smn_print_bar(size_t len, int begin, int end, int middle)
{
    putchar(begin);
    for (size_t i = 0; i < len + 2; ++i) {
        putchar(middle);
    }
    putchar(end);
    putchar('\n');
}

static inline void smn_print_align_center(const char* str, int width)
{
    int h_len = strlen(str) / 2;
    int h_w   = width / 2;
    printf("%*s%*s", h_w + h_len, str, h_w - h_len + (width % 2 != 0 ? 1 : 0), "");
}

static inline void smn_print_align_left(const char* str, int width)
{
    printf("%s%*s", str, width - (int)strlen(str), "");
}

static inline void smn_print_align_right(const char* str, int width)
{
    printf("%*s%s", width - (int)strlen(str), "", str);
}

static inline void smn_print_menu(const char* menu[])
{
    const size_t max_len = smn_find_max_len(menu);
    smn_print_bar(max_len,
                  SMN_TOP_LEFT_CORNER,
                  SMN_TOP_RIGHT_CORNER,
                  SMN_HORIZONTAL_BAR);
    for (size_t i = 0; menu[i] != NULL; ++i) {
        printf("%c ", SMN_VERTICAL_BAR);
        if (i == 0) {
            smn_print_align_center(menu[i], max_len);
        } else {
            smn_print_align_left(menu[i], max_len);
        }
        printf(" %c\n", SMN_VERTICAL_BAR);
    }
    smn_print_bar(max_len,
                  SMN_BOTTOM_LEFT_CORNER,
                  SMN_BOTTOM_RIGHT_CORNER,
                  SMN_HORIZONTAL_BAR);
}

static inline void smn_stdin_clear()
{
    char c;
    while ((c = getchar()) != EOF && c != '\n');
}

static inline int smn_validate_opt(int max_opt)
{
    int opt;
    int err = 0;
    do {
        printf("Option: ");
        scanf("%d", &opt);
        smn_stdin_clear();
        err = opt < 1 || opt > max_opt;
        if (err) {
            printf("Invalid option, please try again...\n");
        }
    } while (err);

    return opt;
}

static inline void smn_clear_screen()
{
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    system("clear");
#elif defined(_WIN32) || defined(_WIN64)
    system("cls");
#endif
}

static inline void smn_pause()
{
putchar('\n');
#if defined(_WIN32) || defined(_WIN64)
    system("pause");
#else 
    printf("Press [ENTER] to continue...");
    smn_stdin_clear();
#endif
putchar('\n');
}

static inline int smn_menu(const char* menu_opts[], int max_opt)
{
    smn_clear_screen();
    smn_print_menu(menu_opts);
    int opt = smn_validate_opt(max_opt);
    smn_clear_screen();

    return opt;
}

static inline void smn_do_menu(const char* menu_opts[], int max_opt,
                               void* data, void (*func_opts)(void*, int))
{
    static int called_once = 1;
    int opt;
    while ((opt = smn_menu(menu_opts, max_opt)) != max_opt) {
        if (func_opts != NULL) {
            func_opts(data, opt);
        }
        if (called_once) {
            smn_pause();
        }
        called_once = 1;
    }
    called_once = 0;
}

#endif // SIMPLE_MENU_H
