#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int cant;
    char buffer[4][20];
    int flag = 0;
    Employee* auxEmpleado = NULL;

    if(pFile != NULL && pArrayListEmployee != NULL){

        // lectura fantasma para el encabezado del archivo
        cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

        while(!feof(pFile))
            {
                cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
                if(cant == 4){
                    // si la lectura fue exitosa creo un empleado con el constructor

                    auxEmpleado = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);

                    if(auxEmpleado != NULL)
                    {
                        ll_add(pArrayListEmployee, auxEmpleado); // agrego el nuevo empleado al array Lista
                        auxEmpleado = NULL; // desactivo el auxiliar
                    }else{
                        flag = 1; // 1 problema al cargar empleado
                        break;
                        }
                }else{
                    flag = 2; // 2 error en la lectura del renglon (cant != 4)
                    break;
                }
            }// fin del while
        }

    switch(flag)
    {
        case 0:
            printf("Empleados cargados correctamente (desde texto).\n");
        break;
        case 1:
            printf("No se pudo crear el empleado.\n");
        break;
        case 2:
            printf("Error en la lectura del archivo de texto.\n");
        break;
    }
    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    int cant = 0;
    int flag = 0;
    Employee* auxEmp = NULL;

    // no se hace lectura fantasma porque se guardaron solo los elementos que habia en el LinkedList

        if(pFile != NULL && pArrayListEmployee != NULL)
        {
            while(!feof(pFile))
            {
                auxEmp = employee_new();
                if(auxEmp != NULL)
                {
                    cant = fread(auxEmp,sizeof(Employee),1,pFile);
                    if(cant == 1){
                        ll_add(pArrayListEmployee, auxEmp);
                        todoOk = 1;
                    }
                    if(cant < 1){
                        break;
                    }
                }else{
                    flag = 1; // no se pudo crear el empleado
                    break;
                }
        }

        switch(flag)
        {
            case 0:
                printf("Empleados cargados correctamente (desde binario).\n");
            break;
            case 1:
                printf("No se pudo crear el empleado.\n");
            break;
        }

    }
    return todoOk;
}

