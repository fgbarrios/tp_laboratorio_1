#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "extras.h"
#include "parser.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/

int main()
{
    int nextId = 1001;
    char salir = 'n';
    int flagBinario = 0;
    int flag = 0;

    LinkedList* lista = ll_newLinkedList();

    if(lista == NULL){
        printf("Error.No se pudo crear la lista.\n");
        exit(1);
    }

    do{
        switch(menu())
        {
            case 1: //Cargar los datos de los empleados desde el archivo data.csv (modo texto).
                system("cls");
                controller_loadFromText("data.csv",lista);
                flagBinario = 1;
                flag = 1;
            break;

            case 2: //Cargar los datos de los empleados desde el archivo data.bin (modo binario).
                system("cls");
                if(flagBinario == 1){
                    controller_loadFromBinary("data.bin",lista);
                }else{
                    printf("Primero debes cargar los empleados desde el archivo de texto (opcion 1) y\n");
                    printf("luego guardarlos como binario (opcion 9) para poder acceder a esta opcion.\n");
                }

            break;

            case 3: //Alta de empleado
                system("cls");
                if(flag == 1){
                    controller_addEmployee(lista, &nextId);
                }else{
                    printf("Primero debes cargar los empleados desde el texto (opcion 1).\n");
                }

            break;

            case 4: //Modificar datos de empleado
                system("cls");
                if(flag == 1){
                    controller_editEmployee(lista);
                }else{
                    printf("Primero debes cargar los empleados desde el texto (opcion 1).\n");
                }

            break;

            case 5: //Baja de empleado
                system("cls");
                if(flag == 1){
                    controller_removeEmployee(lista);
                }else{
                    printf("Primero debes cargar los empleados desde el texto (opcion 1).\n");
                }

            break;

            case 6: //Listar empleados
                system("cls");
                if(flag == 1){
                    controller_ListEmployees(lista);
                }else{
                    printf("Primero debes cargar los empleados desde el texto (opcion 1).\n");
                }

            break;

            case 7: //Ordenar empleados
                system("cls");
                if(flag == 1){
                    controller_sortEmployee(lista);
                }else{
                    printf("Primero debes cargar los empleados desde el texto (opcion 1).\n");
                }
            break;

            case 8: //Guardar los datos de los empleados en el archivo data.csv (modo texto).
                system("cls");
                if(flag == 1){
                    controller_saveAsText("data.csv", lista);
                }else{
                    printf("Primero debes cargar los empleados desde el texto (opcion 1).\n");
                }

            break;

            case 9: // Guardar los datos de los empleados en el archivo data.bin (modo binario).
                system("cls");
                if(flag == 1){
                    controller_saveAsBinary("data.bin", lista);
                }else{
                    printf("Primero debes cargar los empleados desde el texto (opcion 1).\n");
                }

            break;

            case 10: // Salir
            salir = confirmar();
            break;

        default:
            printf("Opcion invalida!\n");
            break;
        }

        system("pause");
    }while(salir == 'n');
    return 0;
}


