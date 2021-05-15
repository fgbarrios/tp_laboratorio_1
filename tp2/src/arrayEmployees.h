/*
 * arrayEmployees.h
 *
 *  Created on: 15 may. 2021
 *      Author: PC
 */

#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    int isEmpty;
}eEmployee;

#endif // ARRAYEMPLOYEES_H_INCLUDED

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(eEmployee lista[], int len);

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

int addEmployee(eEmployee lista[], int tam, char nombre[], char apellido[], float salario, int idSector, int legajo, int indice);

int addEmployees(eEmployee lista[], int tam, int* pLegajo);

/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(eEmployee lista[], int tam, int legajo);
//--------------------------------------------------------------------------

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
//int removeEmployee(eEmployee lista[], int len, int id);
//--------------------------------------------------------------------------

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
void sortEmployees(eEmployee lista[], int tam);

/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/
//int printEmployees(eEmployee lista[], int length);
//--------------------------------------------------------------------------

int findFree(eEmployee lista[], int tam);

int modifyEmployee(eEmployee lista[], int tam);

void printEmployee(eEmployee unEmpleado, int tam);
void printEmployees(eEmployee lista[], int tam);
// INFORMES
int removeEmployee(eEmployee lista[], int tam);
void totalPromSalarios(eEmployee lista[], int tam);

//////////////////////////////////////////////////////////////////

/** \brief Menu principal de opciones. NOTA; no se podra ingresar a las opciones 2, 3 y 4 sin antes haber realizado la
 * carga de algun empleado (case 1).
 *
 * \return int Devuelve la opcion elegida.
 *
 */
int menu();


/** \brief Confirmacion de la salida del programa
 *
 * \return char caracter que confirmar o anula la salida
 *
 */
char confirmar();

/** \brief Sub menu para la solapa INFORMES
 *
 * \return int devuelve la opcion elegida.
 *
 */
int subMenuInformes();

/** \brief Menu para la opcion 2 - Modificar
 *
 * \return int Devuelve la opcion a modificar
 *
 */
int menuModificar();

/** \brief Valida una cadena de caracteres
 *
 * \param palabra[] char cadena de caracteres a validar
 * \return int devuele 1 si es una cadena de caracteres
 *
 */
int validarPalabra(char palabra[]);

/** \brief Valida entre 1 y 500.000 la variable Salario
 *
 * \param salario int varible ingresada por el usuario
 * \return int devuelve 1 si esta dentro de los parametros.
 *
 */
int validarSalario(int salario);

/** \brief Valida el sector ingresado dentro de 0 a 999
 *
 * \param idSector int sector indicado por el usuario
 * \return int devuelve 1 si esta dentro de los parametros
 *
 */
int validarSector(int idSector);
