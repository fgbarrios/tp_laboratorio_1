#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"


Employee* employee_new(){

    Employee* nuevoEmpleado =  (Employee*) malloc(sizeof(Employee));

    if(nuevoEmpleado != NULL)
    {
        // inicializar la estructura con el id correspondiente y el resto en cero
        nuevoEmpleado->id = 0;
        strcpy(nuevoEmpleado->nombre, " ");
        nuevoEmpleado->horasTrabajadas = 0;
        nuevoEmpleado->sueldo = 0;
    }

    return nuevoEmpleado;

}
Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr){

    Employee* nuevoEmpleado =  (Employee*) malloc(sizeof(Employee));

    if(nuevoEmpleado != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
    {
        if(!(employee_setId(nuevoEmpleado, atoi(idStr)) &&
           employee_setNombre(nuevoEmpleado, nombreStr) &&
           employee_setHorasTrabajadas(nuevoEmpleado, atoi(horasTrabajadasStr)) &&
           employee_setSueldo(nuevoEmpleado, atoi(sueldoStr))
           ))
        {
            employee_delete(nuevoEmpleado);
            nuevoEmpleado = NULL;
        }
    }
    return nuevoEmpleado;
}

void employee_delete(Employee* this){
    free(this);
}

//////////////////////////////////////////////////////////// FUNCIONES SETTER ///////////////////////////////////////////


int employee_setId(Employee* this,int id){
    int todoOk = 0;
    if(this != NULL && id > 0)
    {
        this->id = id;
        todoOk = 1;
    }
    return todoOk;
}

int employee_setNombre(Employee* this,char* nombre){
    int todoOk = 0;
    if(this != NULL && nombre != NULL && strlen(nombre) < 128 && strlen(nombre) >= 2)
    {
        strcpy(this->nombre, nombre);
        todoOk = 1;
    }
    return todoOk;

}

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas){
    int todoOk = 0;
    if(this != NULL && horasTrabajadas > 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;
}

int employee_setSueldo(Employee* this,int sueldo){
    int todoOk = 0;
    if(this != NULL && sueldo > 0)
    {
        this->sueldo = sueldo;
        todoOk = 1;
    }
    return todoOk;

}

///////////////////////////////////////////////////////////// FUNCIONES GETTER ///////////////////////////////////////////


int employee_getId(Employee* this,int* id){
    int todoOk = 0;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        todoOk = 1;
    }
    return todoOk;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int todoOk = 0;
    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        todoOk = 1;
    }
    return todoOk;
}


int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){
    int todoOk = 0;
    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;
}

int employee_getSueldo(Employee* this,int* sueldo){
    int todoOk = 0;
    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        todoOk = 1;
    }
    return todoOk;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

int employee_buscarPorId(LinkedList* pArrayListEmployee, int id, int* indice)
{
	int todoOk = 0;
	Employee* employee = NULL;

	if(pArrayListEmployee != NULL && id > 0 && indice != NULL)
	{
		*indice = -1;
		for(int i = 0; i < ll_len(pArrayListEmployee) ; i++)
		{
			employee = (Employee*) ll_get(pArrayListEmployee,i);
			if(employee != NULL)
			{
				if(employee->id == id)
				{
					*indice = i;
					todoOk = 1;
					break;
				}
			}
		}
	}
	return todoOk;
}

////////////////////////////////////////////////// FUNCIONES  COMPARAR ///////////////////////////////////////////////////////

int employee_submenuOrdenar()
{
	int opcion;

	printf("***  Ordenar Empleados ***\n\n");
	printf("Menu de opciones: \n");
	printf("1. Ordenar por Id\n");
	printf("2. Ordenar por Nombre\n");
	printf("3. Ordenar por Horas Trabajadas\n");
	printf("4. Ordenar por Sueldo\n");
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

int employee_compararIds(void* idUno, void* idDos)
{
	int todoOk = 0;
	Employee* aux1 = NULL;
	Employee* aux2 = NULL;

	if(idUno != NULL && idDos != NULL)
	{
		aux1 = (Employee*) idUno;
		aux2 = (Employee*) idDos;

		if(aux1->id > aux2->id)
		{
			todoOk = 1;
		}
		else if(aux1->id < aux2->id)
        {
            todoOk = -1;
        }
	}
	return todoOk;
}

int employee_compararNombres(void* nombreUno, void* nombreDos)
{
	int todoOk = -2;
	Employee* aux1 = NULL;
	Employee* aux2 = NULL;

	if(nombreUno != NULL && nombreDos != NULL)
	{
		aux1 = (Employee*) nombreUno;
		aux2 = (Employee*) nombreDos;
		todoOk = strcmp(aux1->nombre,aux2->nombre);
	}
	return todoOk;
}

int employee_compararHoras(void* horasUno, void* horasDos)
{
	int todoOk = 0;
	Employee* aux1 = NULL;
	Employee* aux2 = NULL;

	if(horasUno != NULL && horasDos != NULL)
	{
		aux1 = (Employee*) horasUno;
		aux2 = (Employee*) horasDos;

		if(aux1->horasTrabajadas > aux2->horasTrabajadas)
		{
			todoOk = 1;
		}
		else if(aux1->horasTrabajadas < aux2->horasTrabajadas)
        {
            todoOk = -1;
        }
	}
	return todoOk;
}

int employee_compararSueldos(void* sueldoUno, void* sueldoDos)
{
	int todoOk = 0;
	Employee* aux1 = NULL;
	Employee* aux2 = NULL;

	if(sueldoUno != NULL && sueldoDos != NULL)
	{
		aux1 = (Employee*) sueldoUno;
		aux2 = (Employee*) sueldoDos;

		if(aux1->sueldo > aux2->sueldo)
		{
			todoOk = 1;
		}
		else if(aux1->sueldo < aux2->sueldo)
        {
            todoOk = -1;
        }
	}
	return todoOk;
}

