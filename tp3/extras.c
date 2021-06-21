#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "extras.h"

int menu()
{
    int opcion;

    system ("cls");
    printf("**********NOMINA DE EMPLEADOS (usando LinkedList)**********\n\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario)\n");
    printf("3. Alta empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n");
    printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario)\n");
    printf("10. Salir\n\n");

    printf("Ingrese opcion (1-10): ");
    scanf("%d", &opcion);

    while(opcion < 0 || opcion > 10)
    {
        printf("ERROR. Ingrese opcion (1-10): ");
        scanf("%d", &opcion);
    }

    return opcion;
}

char confirmar()
{
    char respuesta;

    printf("Presione s para confirmar o n para cancelar: ");
    fflush(stdin);
    respuesta = getchar();

    while(respuesta != 's' && respuesta != 'n')
    {
        printf("Error. Presione s para confirmar o n para cancelar: ");
        fflush(stdin);
        respuesta = getchar();
    }

    return respuesta;
}

int menuModificar()
{
    int opcion;

    system ("cls");
    printf("Que desea modificar?\n\n");
    printf("1. Nombre\n");
    printf("2. Horas Trabajadas\n");
    printf("3. Sueldo\n\n");

    printf("4. Salir\n");
    printf("\n");
    printf("Ingrese opcion (1-4): ");
    scanf("%d", &opcion);
    printf("\n");

    return opcion;
}
