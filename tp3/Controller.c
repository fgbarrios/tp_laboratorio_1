#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Controller.h"
#include "extras.h"


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

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
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
            printf("Error al crear nuevo empleado.\n");
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

        // copio el puntero auxEmpleado (la direccion de la estructura) en la lista
        if(!ll_add(pArrayListEmployee, auxEmpleado)){
            printf("Empleado cargado con exito.\n");
            (*pNextId)++;
        }

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
    int indice;
    int salir = 'n';
    int todoOk = 0;
    Employee* auxEmpleado = NULL;

    char auxNombre[128];
    int auxHorasTrabajadas;
    int auxSueldo;

    system("cls");
    printf("          Modificar empleado\n\n");
    printf("Ingrese el numero de ID del empleado a modificar: ");
    scanf("%d", &id);
    printf("\n");

    employee_buscarPorId(pArrayListEmployee, id, &indice);

    if(indice == -1)
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
                    gets(auxNombre);
                    while(!employee_setNombre(auxEmpleado, auxNombre)){
                        printf("Error.Ingrese Nombre: ");
                        fflush(stdin);
                        gets(auxNombre);
                    }
                    todoOk = 1;
                    break;
                case 2:
                    printf("Ingrese nuevas horas trabajadas: ");
                    scanf("%d", &auxHorasTrabajadas);
                    while(!employee_setHorasTrabajadas(auxEmpleado, auxHorasTrabajadas)){
                        printf("Error.Ingrese Horas Trabajadas: ");
                        scanf("%d", &auxHorasTrabajadas);
                    }
                    todoOk = 1;
                    break;
                case 3:
                    printf("Ingrese nuevo sueldo: ");
                    scanf("%d", &auxSueldo);
                    while(!employee_setSueldo(auxEmpleado, auxSueldo)){
                        printf("Error. Ingrese Sueldo: ");
                        scanf("%d", &auxSueldo);
                    }
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
    int indice;
    Employee* auxEmpleado = NULL;

    system("cls");
    printf("          Baja empleado\n\n");
    printf("Ingrese el id del empleado a dar de baja: ");
    scanf("%d", &id);
    printf("\n");

    employee_buscarPorId(pArrayListEmployee, id, &indice);

    if(indice == -1)
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
            printf("Empleado dado de baja con exito.\n");
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
int controller_ListEmployee(Employee* pEmployee)
{
    int todoOk = 0;
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;

    if(pEmployee != NULL &&
       employee_getId(pEmployee, &id) &&
       employee_getNombre(pEmployee, nombre) &&
       employee_getHorasTrabajadas(pEmployee, &horasTrabajadas) &&
       employee_getSueldo(pEmployee, &sueldo)
       )
    {
        printf("%4d  %15s      %3d         %5d\n\n",
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
        printf("  ID         Nombre    Hs Trabajadas    Sueldo\n");

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
	int opcion;
	int orden;

	if(pArrayListEmployee != NULL)
	{
		do
		{
			system("cls");
			opcion = employee_submenuOrdenar();

			if(opcion != 5)
			{
				printf("Ingrese 0 para ordenar de forma ascendente o 1 para ordenar de forma descendiente. 0/1 :");
				scanf("%d", &orden);
				while(orden != 1 && orden != 0){
                    printf("Error. Ingrese opcion ascendente o descendente. 0/1 :");
                    scanf("%d", &orden);
				}
			}
			if(orden == 1 || orden == 0)
			{
				switch(opcion)
				{
				case 1:
				    printf("Ordenando...\n\n");
					ll_sort(pArrayListEmployee, employee_compararIds, orden);
					controller_ListEmployees(pArrayListEmployee);
					system("pause");
					break;
				case 2:
				    printf("Ordenando...\n\n");
					ll_sort(pArrayListEmployee, employee_compararNombres, orden);
					controller_ListEmployees(pArrayListEmployee);
					system("pause");
					break;
				case 3:
				    printf("Ordenando...\n\n");
					ll_sort(pArrayListEmployee, employee_compararHoras, orden);
					controller_ListEmployees(pArrayListEmployee);
					system("pause");
					break;
				case 4:
				    printf("Ordenando...\n\n");
					ll_sort(pArrayListEmployee, employee_compararSueldos, orden);
					controller_ListEmployees(pArrayListEmployee);
					system("pause");
					break;
				}
			}
		}
		while(opcion != 5);
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
    int todoOk = 0;
	char confirma = 's';

	FILE* f = NULL;
	Employee* auxEmp = NULL;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		f = fopen(path,"r");
		if(f != NULL)
		{
			printf("Cuidado el archivo existe y se va a sobrescribir. Desea confirmar? s/n :\n ");
			fflush(stdin);
			scanf("%c", &confirma);
		}
		fclose(f);

		if(confirma == 's')
		{
			f = fopen(path,"w");
			if(f == NULL)
			{
				printf("\n   No se pudo abrir el archivo\n\n");
			}
			else
			{
				fprintf(f,"id,nombre,horasTrabajadas,sueldo\n");
				for(int i = 0; i < ll_len(pArrayListEmployee); i++)
				{
					auxEmp = (Employee*) ll_get(pArrayListEmployee,i);
					if(auxEmp != NULL)
					{
						fprintf(f,"%d,%s,%d,%d\n",
								auxEmp->id,
								auxEmp->nombre,
								auxEmp->horasTrabajadas,
								auxEmp->sueldo);
					}
					auxEmp = NULL;
				}
				todoOk = 1;
				printf("Archivo de texto guardado con exito.\n");
			}
			fclose(f);
		}
	}

	return todoOk;
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
	int todoOk = 0;
	char confirma = 's';
	FILE* f = NULL;
	Employee* auxEmp;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		f = fopen(path,"rb"); // pruebo abrir el archivo a ver si existe, si existe entro al if
		if(f != NULL)
		{
			printf("Cuidado el archivo existe y se va a sobrescribir. Desea confirmar? s/n :\n");
			fflush(stdin);
			scanf("%c", &confirma);
		}
		fclose(f);

		if(confirma == 's')
		{
			f = fopen(path,"wb");
			if(f == NULL)
			{
				printf("\n   No se pudo abrir el archivo\n\n");
			}
			else
			{
				for(int i = 0; i < ll_len(pArrayListEmployee) ; i++)
				{
					auxEmp = (Employee*) ll_get(pArrayListEmployee,i);
					fwrite(auxEmp,sizeof(Employee),1,f);
				}
				todoOk = 1;
				printf("Archivo binario guardado con exito.\n");
			}
			fclose(f);
		}
	}
	return todoOk;

}

