#ifndef MENU_SIMPLE_H_98543095843097189471
#define MENU_SIMPLE_H_98543095843097189471

#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef MNS_ESQUINA_SUPERIOR_IZQUIERDA
#define MNS_ESQUINA_SUPERIOR_IZQUIERDA '+'
#endif

#ifndef MNS_ESQUINA_SUPERIOR_DERECHA
#define MNS_ESQUINA_SUPERIOR_DERECHA '+'
#endif

#ifndef MNS_ESQUINA_INFERIOR_IZQUIERDA
#define MNS_ESQUINA_INFERIOR_IZQUIERDA '+'
#endif

#ifndef MNS_ESQUINA_INFERIOR_DERECHA
#define MNS_ESQUINA_INFERIOR_DERECHA '+'
#endif

#ifndef MNS_BARRA_VERTICAL
#define MNS_BARRA_VERTICAL   '|'
#endif

#ifndef MNS_BARRA_HORIZONTAL
#define MNS_BARRA_HORIZONTAL '-'
#endif

static inline size_t mns_busca_tamanio_mas_grande(const char* menu[])
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

static inline void mns_imprime_barra(size_t len, int begin, int end, int middle)
{
    putchar(begin);
    for (size_t i = 0; i < len + 2; ++i) {
        putchar(middle);
    }
    putchar(end);
    putchar('\n');
}

static inline void mns_imprime_alineado_al_centro(const char* str, int width)
{
    int h_len = strlen(str) / 2;
    int h_w   = width / 2;
    printf("%*s%*s", h_w + h_len, str, h_w - h_len + (width % 2 != 0 ? 1 : 0), "");
}

static inline void mns_imprime_alineado_a_la_izquierda(const char* str, int width)
{
    printf("%s%*s", str, width - (int)strlen(str), "");
}

static inline void mns_imprime_alineado_a_la_derecha(const char* str, int width)
{
    printf("%*s%s", width - (int)strlen(str), "", str);
}

static inline void mns_imprime_menu(const char* menu[])
{
    const size_t max_len = mns_busca_tamanio_mas_grande(menu);
    mns_imprime_barra(max_len,
                      MNS_ESQUINA_SUPERIOR_IZQUIERDA,
                      MNS_ESQUINA_SUPERIOR_DERECHA,
                      MNS_BARRA_HORIZONTAL);
    for (size_t i = 0; menu[i] != NULL; ++i) {
        printf("%c ", MNS_BARRA_VERTICAL);
        if (i == 0) {
            mns_imprime_alineado_al_centro(menu[i], max_len);
        } else {
            mns_imprime_alineado_a_la_izquierda(menu[i], max_len);
        }
        printf(" %c\n", MNS_BARRA_VERTICAL);
    }
    mns_imprime_barra(max_len,
                      MNS_ESQUINA_INFERIOR_IZQUIERDA,
                      MNS_ESQUINA_INFERIOR_DERECHA,
                      MNS_BARRA_HORIZONTAL);
}

static inline void mns_limpia_stdin()
{
    char c;
    while ((c = getchar()) != EOF && c != '\n');
}

static inline int mns_valida_opcion(int max_opt)
{
    int opt;
    int err = 0;
    do {
        printf("Opción: ");
        scanf("%d", &opt);
        mns_limpia_stdin();
        err = opt < 1 || opt > max_opt;
        if (err) {
            printf("Opción ivalida, intente nuevamente...\n");
        }
    } while (err);

    return opt;
}

static inline void mns_limpia_pantalla()
{
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    system("clear");
#elif defined(_WIN32) || defined(_WIN64)
    system("cls");
#endif
}

static inline void mns_pausa()
{
putchar('\n');
#if defined(_WIN32) || defined(_WIN64)
    system("pause");
#else 
    printf("Presione [INTRO] para continuar...");
    mns_limpia_stdin();
#endif
putchar('\n');
}

static inline void mns_hacer_menu(const char* menu_opts[], int max_opt,
                                  void* data, void (*func_opts)(void*, int))
{
    static int called_once = 1;
    int opt;
    for ( ; ; ) {
        mns_limpia_pantalla();
        mns_imprime_menu(menu_opts);
        opt = mns_valida_opcion(max_opt);
        mns_limpia_pantalla();
        if (func_opts != NULL) {
            func_opts(data, opt);
        }
        if (opt != max_opt) {
            if (called_once) {
                mns_pausa();
            }
            called_once = 1;
        } else {
            break;
        }
    }
    called_once = 0;
}

#endif // MENU_SIMPLE_H
