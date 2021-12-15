#include <menu_simple.h>

#define MAX_LETRAS 64

#define MAX_MEDICAMENTOS 2000

typedef struct st_medicamento
{
    int codigo;
    char nombre[MAX_LETRAS];
    int nro_unidades;
} Medicamento_t;

typedef struct st_farmacia
{
    Medicamento_t medicamentos[MAX_MEDICAMENTOS];
    int nro_medicamentos;
} Farmacia_t;

const char* FARMACIA_MENU[] = 
{
    "FARMACIA EPN",
    "==================================",
    "1.- Registrar Medicamento.",
    "2.- Registrar Ingreso-Medicamento.",
    "3.- Mostrar Detalles-Medicamento.",
    "4.- Salir",
    NULL
};

void lee_medicamento(Medicamento_t* medicamento)
{
    printf("Ingrese codigo: ");
    scanf("%d", &medicamento->codigo);
    getchar();
    printf("Ingrese nombre: ");
    fgets(medicamento->nombre, MAX_LETRAS, stdin);
    medicamento->nombre[strcspn(medicamento->nombre, "\n")] = '\0';
}

void registrar_medicamento(Farmacia_t* farmacia)
{
    printf("::::::::Registrar-Medicamento::::::::\n\n");
    int ultimo = farmacia->nro_medicamentos;
    if (ultimo < MAX_MEDICAMENTOS) {
        Medicamento_t* medicamentos = farmacia->medicamentos;
        lee_medicamento(medicamentos + ultimo);
        ++farmacia->nro_medicamentos;
    } else {
        printf("NO se pueden registrar mas medicamentos,"
               "exedio el limite de la farmacia...\n");
    }
}

int busca_medicamento(const Farmacia_t* farmacia, int codigo)
{
    for (int i = 0; i < farmacia->nro_medicamentos; ++i) {
        if (farmacia->medicamentos[i].codigo == codigo) {
            return i;
        }
    }

    return -1;
}

void registrar_ingreso_medicamento(Farmacia_t* farmacia)
{
    printf("::::::::Registrar-Ingreso-Medicamento::::::::\n\n");
    int codigo;
    printf("Ingrese el codigo: ");
    scanf("%d", &codigo);
    getchar();

    int indice = busca_medicamento(farmacia, codigo);
    if (indice != -1) {
        int nro_unidades;
        printf("Ingrese numero de unidades: ");
        scanf("%d", &nro_unidades);
        getchar();
        farmacia->medicamentos[indice].nro_unidades += nro_unidades;
    } else {
        printf("Medicamento NO existe en el Registro!\n");
    }
}

void imprime_medicamento(const Medicamento_t* medicamento)
{
    printf("Detalles del Medicamento \n");
    printf("Codigo: %d\n", medicamento->codigo);
    printf("Nombre: %s\n", medicamento->nombre);
    printf("Numero de unidades: %d\n", medicamento->nro_unidades);
}

void mostrar_detalles_de_medicamento(const Farmacia_t* farmacia)
{
    printf("::::::::Mostrar Detalles-Medicamento::::::::\n\n");
    int codigo;
    printf("Ingrese codigo: ");
    scanf("%d", &codigo);
    getchar();

    int indice = busca_medicamento(farmacia, codigo);
    if (indice != -1) {
        imprime_medicamento(&farmacia->medicamentos[indice]);
    } else {
        printf("Medicamento NO existe en Registro!\n");
    }
}

void menu_principal(void* farmacia, int opc)
{
    switch (opc) {
    case 1:
        registrar_medicamento(farmacia);
        break;
    case 2:
        registrar_ingreso_medicamento(farmacia);
        break;
    case 3:
        mostrar_detalles_de_medicamento(farmacia);
        break;
    case 4:
        printf("Adios! vuelva pronto...\n");
        break;
    }
}

int main()
{
    Farmacia_t farmacia = { 0 };
    mns_hacer_menu(FARMACIA_MENU, 4, &farmacia, menu_principal);
    return 0;
}
