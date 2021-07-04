#include "LinkedList.h"
#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {
    int id;
    char nombre[20];
    char sexo;
    int edad;
}eMascota;

#endif // FUNCIONES_H_INCLUDED


/** \brief Muestra un item
 *
 * \param this eMascota* - paramero a mostrar
 * \return
 *
 */
void* mostrarMascota(eMascota* this);

/** \brief muestra los items de un listado
 *
 * \param list LinkedList* - lista a mostrar
 * \return
 *
 */
void* mostrarMascotas(LinkedList* list);
/** \brief Ordena las mascotas por orden alfabetico
 *
 * \param m1 void* - primer valor a evaluar
 * \param m2 void* - segundo valor a evaluar
 * \return int 0 si fallo
 *             -1 forma ascendente
 *              1 forma descendiente
 *
 */
int ordenarMascotas(void* m1, void* m2);
