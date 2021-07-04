#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "string.h"

void* mostrarMascota(eMascota* this){
    if(this != NULL){
        printf("%d  %s  %c  %d\n",
           this->id,
           this->nombre,
           this->sexo,
           this->edad);
    }
}

void* mostrarMascotas(LinkedList* list){

    int flag = 1;
    int tam;
    eMascota* pElement = NULL;

    if(list != NULL){
        tam = ll_len(list);
        printf("\n*****Listado de mascotas*****\n");
        printf("Legajo  Nombre  Sexo  Edad\n\n");
        for (int i = 0;i < tam ;i++ )
        {
            pElement = (eMascota*) ll_get(list, i); // casteo del ll_get
            if(pElement != NULL){
                mostrarMascota(pElement);
                flag = 0;
            }
        }
        if(flag){
            printf("No hay mascotas que mostrar");
        }
    }
    printf("\n\n");
}

int ordenarMascotas(void* m1, void* m2)
{
	int retorno = 0;

	if(strcmp(((eMascota *)m1)->nombre,((eMascota *)m2)->nombre) > 0)
	{
		return 1;
	}
	else if(strcmp(((eMascota *)m1)->nombre,((eMascota *)m2)->nombre) < 0)
	{
		return -1;
	}

	return retorno;
}

