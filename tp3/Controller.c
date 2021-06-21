#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "parser.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    if(path != NULL && pArrayListEmployee != NULL){

    // Abre el archivo y llama a parser. Carga los datos y luego cierra el archivo.
        FILE* f = fopen(path, "r");
        if(f == NULL)
        {
            printf("No se pudo abrir el archivo de texto.\n");
            exit(1);
        }else{
            parser_EmployeeFromText(f, pArrayListEmployee);
        }
        fclose(f);

    }
    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    if(path != NULL && pArrayListEmployee != NULL){

    // Abre el archivo y llama a parser. Carga los datos y luego cierra el archivo.
        FILE* f = fopen(path, "rb");
        if(f == NULL)
        {
            printf("No se pudo abrir el archivo binario.\n");
            exit(1);
        }else{
            parser_EmployeeFromBinary(f, pArrayListEmployee);
        }

        fclose(f);
    }

    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* pNextId)
{
    char auxNombre[128];
    int auxHorasTrabajadas;
    int auxSueldo;

    Employee* auxEmpleado = employee_new();

    if(auxEmpleado == NULL){
            printf("No se pudo cargar la nueva estructura Empleado.\n");
        }

    if(pArrayListEmployee != NULL && pNextId != NULL){

        printf("ID Asignado: %d\n", *pNextId);
        employee_setId(auxEmpleado, *pNextId);

        printf("Ingrese Nombre: ");
        fflush(stdin);
        gets(auxNombre);
        while(!employee_setNombre(auxEmpleado, auxNombre)){
            printf("Error.Ingrese Nombre: ");
            fflush(stdin);
            gets(auxNombre);
        }

        printf("Ingrese Horas Trabajadas: ");
        scanf("%d", &auxHorasTrabajadas);
        while(!employee_setHorasTrabajadas(auxEmpleado, auxHorasTrabajadas)){
            printf("Error.Ingrese Horas Trabajadas: ");
            scanf("%d", &auxHorasTrabajadas);
        }

        printf("Ingrese Sueldo: ");
        scanf("%d", &auxSueldo);
        while(!employee_setSueldo(auxEmpleado, auxSueldo)){
            printf("Error. Ingrese Sueldo: ");
            scanf("%d", &auxSueldo);
        }

        // muestro el empleado a cargar
        controller_ListEmployee(auxEmpleado);

        // copio el puntero auxEmpleado (la direccion de la estructura) en el primer item de la lista
        ll_add(pArrayListEmployee, auxEmpleado);
        *(pNextId)++;
        printf("Empleado cargado con exito.\n");

        auxEmpleado = NULL; // desactivo el aux

    }

    return 1;
}


/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int id;
    int* indice;
    int salir = 'n';
    int todoOk = 0;
    Employee* auxEmpleado = NULL;

    system("cls");
    printf("          Modificar empleado\n\n");
    printf("Ingrese el numero de ID del empleado a modificar: ");
    scanf("%d", &id);
    printf("\n");

    indice = (int*) ll_get(pArrayListEmployee, id);

    if(indice == NULL)
    {
        printf("El legajo indicado no existe.\n\n");
    }
    else
    {
        printf("El empleado a modificar es: \n");
        auxEmpleado = (Employee*) ll_get(pArrayListEmployee, indice);
        controller_ListEmployee(auxEmpleado);

        if(confirmar() == 's')
        {
            do
            {
                switch(menuModificar())
                {
                case 1:
                    printf("Ingrese nuevo nombre: ");
                    fflush(stdin);
                    //gets(*(pArrayListEmployee + indice)->nombre);
                    todoOk = 1;
                    break;
                case 2:
                    printf("Ingrese nuevas horas trabajadas: ");
                    //scanf("%d", *(pArrayListEmployee + indice)->horasTrabajadas);
                    todoOk = 1;
                    break;
                case 3:
                    printf("Ingrese nuevo sueldo: ");
                    //scanf("%d", *(pArrayListEmployee + indice)->sueldo);
                    todoOk = 1;
                    break;
                case 4:
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
                    controller_ListEmployee(auxEmpleado);
                }
            }
            while(salir == 'n');
        }
    }
    return todoOk;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    int id;
    int* indice;
    Employee* auxEmpleado = NULL;

    system("cls");
    printf("          Baja empleado\n\n");
    printf("Ingrese el id del empleado a dar de baja: ");
    scanf("%d", &id);
    printf("\n");

    indice = (int*) ll_get(pArrayListEmployee, id);

    if(indice == NULL)
    {
        printf("El id indicado (%d) no existe.\n\n", id);
    }
    else
    {
        printf("El empleado a dar de baja es:\n");
        auxEmpleado = (Employee*) ll_get(pArrayListEmployee, indice);
        controller_ListEmployee(auxEmpleado);

        if(confirmar() == 's')
        {
            ll_remove(pArrayListEmployee, indice);
            todoOk = 1;
        }
        printf("\n");
    }

    return todoOk;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;

    if(pArrayListEmployee != NULL &&
       employee_getId(pArrayListEmployee, &id) &&
       employee_getNombre(pArrayListEmployee, nombre) &&
       employee_getHorasTrabajadas(pArrayListEmployee, &horasTrabajadas) &&
       employee_getSueldo(pArrayListEmployee, &sueldo)
       )
    {
        printf("%d  %10s    %c    %.2f\n\n",
               id,
               nombre,
               horasTrabajadas,
               sueldo);
        todoOk = 1;
    }
    return todoOk;

}

int controller_ListEmployees(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    Employee* auxEmpleado = NULL;

    if(pArrayListEmployee != NULL){
        printf("ID  Nombre  Horas Trabajadas    Sueldo\n");

        for (int i = 0;i < ll_len(pArrayListEmployee) ;i++ ){
            auxEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
            controller_ListEmployee(auxEmpleado);
        }
        todoOk = 1;
    }
    return todoOk;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    Employee* aux = NULL;
    int tam = ll_len(pArrayListEmployee);

    if(pArrayListEmployee !=NULL && tam > 1)
    {
        for (int i = 0;i<tam -1 ;i++ )
        {
            for (int j = i+1;j<tam ;j++ )
            {
                if(ll_get(pArrayListEmployee, i) != NULL && ll_get(pArrayListEmployee, j) != NULL)
                {
                  if(strcmp((ll_get(pArrayListEmployee, i))->nombre,(ll_get(pArrayListEmployee, j))->nombre) > 0)
                    {
                        aux = *(pArrayListEmployee + i);
                        *(pArrayListEmployee + i) = *(pArrayListEmployee + j);
                        *(pArrayListEmployee + j) = aux;
                    }
                }
            }
        }
        aux = NULL;
        todoOk = 1;
    }
    return todoOk;

}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
   if(fwrite(numeros, sizeof(int), TAM, f) == TAM){
        printf("Se guardaron los datos con exito.\n");
    } else{
        printf("No se pudo guardar.\n");
    }


}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

