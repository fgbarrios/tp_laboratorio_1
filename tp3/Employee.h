#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_buscarPorId(LinkedList* pArrayListEmployee, int id, int* indice);

int employee_submenuOrdenar();

int employee_compararHoras(void* horasUno, void* horasDos);
int employee_compararSueldos(void* sueldoUno, void* sueldoDos);
int employee_compararNombres(void* nombreUno, void* nombreDos);
int employee_compararIds(void* idUno, void* idDos);



#endif // employee_H_INCLUDED
