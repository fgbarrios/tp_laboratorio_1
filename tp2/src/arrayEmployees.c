/*
 * arrayEmployees.c
 *
 *  Created on: 15 may. 2021
 *      Author: PC
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployees.h"


/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(eEmployee lista[], int tam)
{
    int todoOk = 0;
    if(lista != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            //saco la basura del campo .isEmpty de todo el array,
            //para poder usarlo mas adelante para asignar empleados.
            lista[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    else{
        todoOk = 0;
    }
    return todoOk;
}


/** \brief Buscar en el array lista el primer lugar libre
 *
 * \param lista[] eEmpleado - array sobre el cual hacer la busqueda
 * \param tam int - largo del array
 * \return int - primera posicion libre
 *
 */
int findFree(eEmployee lista[], int tam)
{
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if(lista[i].isEmpty)
        {
            indice = i;
            break; // si no se coloca break, devolveria la ultima ubicacion encontrada vacia
        }
    }
    return indice;
}


/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*
*/

int addEmployee(eEmployee lista[], int tam, char nombre[], char apellido[], float salario, int idSector, int legajo, int indice)
{
    int todoOk = 0;
    eEmployee nuevoEmpleado;

        strcpy(nuevoEmpleado.nombre, nombre);
        strcpy(nuevoEmpleado.apellido, apellido);
        nuevoEmpleado.salario = salario;
        nuevoEmpleado.sector = idSector;

        nuevoEmpleado.id= legajo;
        nuevoEmpleado.isEmpty = 0;

        lista[indice] = nuevoEmpleado;
        todoOk = 1;

        return todoOk;
}


int addEmployees(eEmployee lista[], int tam, int* pLegajo)
{
    int todoOk = 0;
    int indice;
    char nombre[51];
    char apellido[51];
    float salario;
    int idSector;
    int legajo = (*pLegajo);

    system("cls");
    if(lista != NULL && tam > 0 && pLegajo != NULL)
    {
        printf("     Alta empleado\n\n");

        indice = findFree(lista, tam);

        if(indice == -1)
        {
            printf("No hay lugar en el sistema!.\n");
        }
        else
        {
            printf("Legajo: %d\n", *pLegajo);

            printf("Ingrese nombre (max. 50 caracteres): ");
            fflush(stdin);
            gets(nombre);
            while(validarPalabra(nombre) != 1)
            {
                printf("Error.Reingrese nombre: ");
                fflush(stdin);
                gets(nombre);
            }

            printf("Ingrese apellido (max. 50 caracteres): ");
            fflush(stdin);
            gets(apellido);
            while(validarPalabra(apellido) != 1)
            {
                printf("Error. Reingrese apellido:");
                fflush(stdin);
                gets(apellido);
            }

            printf("Ingrese salario (mayor a 0 y menor a 500.000): ");
            scanf("%f", &salario);
            while(validarSalario(salario)!= 1)
            {
                printf("Error.Reingrese salario(mayor a 0 y menor a 500.000): ");
                scanf("%f", &salario);
            }

            printf("Ingrese el ID del sector (100/150/200/250/300): ");
            scanf("%d", &idSector);
            while(validarSector(idSector) != 1)
            {
                    printf("Error. Reingrese el ID del sector(100/150/200/250/300):");
                    scanf("%d", &idSector);
            }

            if(addEmployee(lista, tam, nombre, apellido, salario, idSector, legajo, indice))
            {
                (*pLegajo)++;
                todoOk = 1;
            }
        }
    }
    return todoOk;
}

int findEmployeeById(eEmployee lista[], int tam, int legajo)
{
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if(lista[i].id == legajo && !lista[i].isEmpty)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

void printEmployee(eEmployee unEmpleado, int tam)
{
       printf("%d    %10s   %10s    %.2f    %d \n",
       unEmpleado.id,
       unEmpleado.nombre,
       unEmpleado.apellido,
       unEmpleado.salario,
       unEmpleado.sector
      );

    printf("\n");
}

void printEmployees(eEmployee lista[], int tam)
{
    printf("         Listado de Empleados\n");
    printf(" ID       Nombre        Apellido    Salario    Sector\n");

    for(int i=0; i<tam; i++)
    {
        if(!lista[i].isEmpty) // Si .isEmpty es falso (osea, tiene un empleado), los muestro
        {
            printEmployee(lista[i], tam);
        }
    }
   printf("\n");
}

int modifyEmployee(eEmployee lista[], int tam)
{
    int legajo;
    int indice;
    int salir = 'n';
    int todoOk = 0;

    system("cls");
    printf("          Modificar empleado\n\n");
    printEmployees(lista, tam);
    printf("Ingrese el numero de ID del empleado a modificar: ");
    scanf("%d", &legajo);
    printf("\n");

    indice = findEmployeeById(lista, tam, legajo);

    if(indice == -1)
    {
        printf("El legajo indicado no existe.\n\n");
    }
    else
    {
        printf("El empleado a modificar es: \n");
        printEmployee(lista[indice], tam);

        if(confirmar() == 's')
        {
            do
            {
                switch(menuModificar())
                {
                case 1:
                    printf("Ingrese nuevo nombre: ");
                    fflush(stdin);
                    gets(lista[indice].nombre);
                    todoOk = 1;
                    break;
                case 2:
                    printf("Ingrese nuevo apellido: ");
                    fflush(stdin);
                    gets(lista[indice].apellido);
                    todoOk = 1;
                    break;
                case 3:
                    printf("Ingrese nuevo salario: ");
                    scanf("%f", &lista[indice].salario);
                    todoOk = 1;
                    break;
                case 4:
                    printf("Ingrese nuevo sector: ");
                    scanf("%d", &lista[indice].sector);
                    todoOk = 1;
                    break;
                case 5:
                    salir = confirmar();
                    break;
                default:
                    printf("Opcion invalida!\n");
                    break;
                }
                printf("\n");
                system("pause");
                system("cls");

                if(todoOk == 1)
                {
                    printf("Asi quedo modificado el empleado:\n\n");
                    printEmployee(lista[indice], tam);
                }
            }
            while(salir == 'n');
        }
    }
    return todoOk;
}

int removeEmployee(eEmployee lista[], int tam)
{
    int todoOk = 0;
    int legajo;
    int indice;

    system("cls");
    printf("          Baja empleado\n\n");
    printEmployees(lista, tam);
    printf("Ingrese el legajo del empleado a dar de baja: ");
    scanf("%d", &legajo);
    printf("\n");

    indice = findEmployeeById(lista, tam, legajo);

    if(indice == -1)
    {
        printf("El legajo indicado (%d) no existe.\n\n", legajo);
    }
    else
    {
        printf("El empleado a dar de baja es:\n");
        printEmployee(lista[indice],tam);

        if(confirmar() == 's')
        {
            lista[indice].isEmpty = 1;
            todoOk = 1;
        }
        printf("\n");
    }

    return todoOk;
}

void sortEmployees(eEmployee lista[], int tam)
{
    eEmployee auxEmpleado;

    for(int i = 0; i < tam -1; i++)
    {
        for(int j = i +1; j < tam; j++)
        {
            if(lista[i].sector > lista[j].sector || (lista[i].sector == lista[j].sector && strcmp(lista[i].apellido,lista[j].apellido) > 0))
            {
                auxEmpleado = lista[i];
                lista[i] = lista[j];
                lista[j] = auxEmpleado;
            }
        }
    }
}



//////////////////////////////////////////////////////////

int menu()
{
    int opcion;

    system ("cls");
    printf("**********NOMINA DE EMPLEADOS**********\n\n");
    printf("1. Alta empleado\n");
    printf("2. Modificar empleado\n");
    printf("3. Baja empleado\n");
    printf("4. Informar\n");
    printf("5. Salir\n\n");
    printf("Ingrese opcion (1-5): ");
    scanf("%d", &opcion);

    while(opcion < 0 || opcion > 5)
    {
        printf("ERROR. Ingrese opcion (1-5): ");
        scanf("%d", &opcion);
    }

    return opcion;
}

int subMenuInformes()
{
    int opcion;

    system ("cls");
    printf("**********INFORMES**********\n\n");
    printf("1. Listado de los empleados ordenados alfabticamente por Apellido y Sector.\n");
    printf("2. Total y promedio de los salarios, y cuantos empleados superan el salario promedio.\n\n");
    printf("Ingrese opcion (1-2): ");
    scanf("%d", &opcion);

    while(opcion < 0 || opcion > 2)
    {
        printf("ERROR. Ingrese opcion (1-2): ");
        scanf("%d", &opcion);
    }

    return opcion;
}

int menuModificar()
{
    int opcion;

    system ("cls");
    printf("Que desea modificar?\n\n");
    printf("1. Nombre\n");
    printf("2. Apellido\n");
    printf("3. Salario\n");
    printf("4. Sector\n\n");

    printf("5. Salir\n");
    printf("\n");
    printf("Ingrese opcion (1-5): ");
    scanf("%d", &opcion);
    printf("\n");

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

int validarPalabra(char palabra[])
{
    int todoOk = -1;
    int tamanioCadena = 51;

    if(palabra != NULL && strlen(palabra) < tamanioCadena && palabra[0] != '\0')
    {
        for(int i = 0;i < tamanioCadena; i++)
        {
            if((palabra[i] < 'a' || palabra[i] > 'z') && (palabra[i] < 'A' || palabra[i] > 'Z'))
            {
                todoOk = 1;
            }
        }
    }
    return todoOk;
}

int validarSalario(int salario)
{
    int todoOk = -1;

    if(salario  > 0 && salario < 500000 )
    {
        todoOk = 1;
    }
    return todoOk;

}

int validarSector(int idSector){

    int todoOk = -1;

    if(idSector == 100 || idSector == 150 || idSector == 200 || idSector == 250 || idSector == 300 )
    {
        todoOk = 1;
    }
    return todoOk;
}

void totalPromSalarios(eEmployee lista[], int tam)
{
    int cantidad = 0;
    int acumuladorSalario = 0;
    float promedioSalarios;
    int contadorPromedio = 0;

    if(lista != NULL && tam > 0){
        system("cls");
        printf("    Informe Total y promedio de los salarios, y cuantos empleados superan el salario promedio\n\n");
        printEmployees(lista, tam);

        for(int i = 0; i < tam ; i++)
        {
            if(lista[i].isEmpty == 0)
            {
                acumuladorSalario = acumuladorSalario + lista[i].salario;
                cantidad++;
            }
        }
        printf("El total de sueldos es: %d \n\n", acumuladorSalario);
        printf("------------------------------------------------------------------\n");
        promedioSalarios = (float) acumuladorSalario / cantidad;
        printf("El promedio es: $ %.2f\n\n", promedioSalarios);
        printf("------------------------------------------------------------------\n");
        printf("Los siguientes superan el promedio:\n");

        for(int i = 0; i < cantidad ; i++)
        {
            if(lista[i].salario >= promedioSalarios)
            {
                printEmployee(lista[i], cantidad);
                contadorPromedio = contadorPromedio + 1;
            }
        }

        if(contadorPromedio == 0)
        {
           printf("No hay empleados que superen el promedio.\n");
        }
    }

}
