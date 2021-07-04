#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "funciones.h"

#define TAM 6

int main()
{
    int tam;
    int tam2;
    int tam3;
    int ubicacionPepe;
    LinkedList* listaClon = NULL;
    LinkedList* listaCopiaOriginal = NULL;

    // CREACION DEL LINKEDLIST PRINCIPAL
    LinkedList* lista = ll_newLinkedList();

    if(lista != NULL){
        printf("LinkedList MASCOTAS creado con exito.\n\n");
    }


    eMascota m1 = {1234, "Bobby", 'm', 2};
    eMascota m2 = {3322, "Pepe", 'm', 5};
    eMascota m3 = {6543, "Lola", 'h', 1};
    eMascota m4 = {1111, "Bunny", 'h', 7};
    eMascota m5 = {9891, "Susy", 'h', 2};
    eMascota m6 = {2310, "Lolo", 'm', 1};
    eMascota m7 = {3232, "Tommy", 'm', 3};//reemplazo por la 3ra
    eMascota m8 = {9999, "Lazzy", 'f', 5};

    // LARGO DEL LINKEDLIST CREADO
    tam = ll_len(lista);
    printf("El largo del LinkedList creado es: %d\n\n",tam);
    system("pause");
    system("clear");

    // AGREGAMOS NUEVOS NODOS (CON INFORMACION) AL LINKEDLIST
    ll_add(lista, &m1);
    ll_add(lista, &m2);
    ll_add(lista, &m3);
    ll_add(lista, &m4);
    ll_add(lista, &m5);
    ll_add(lista, &m6);

    if(ll_len(lista) == 6){
        printf("Nuevos items agregados con exito a la LinkedList MASCOTAS.\n\n");
    }
    // LARGO DEL LINKEDLIST CON LOS NUEVOS ITEMS
    printf("El LinkedList ahora contiene: %d mascotas\n\n",ll_len(lista));
     system("pause");
     system("clear");

    // MOSTRAMOS EL LISTADO DE LAS MASCOTAS
    mostrarMascotas(lista);

    // MODIFICAMOS UN ELEMENTO DE LA LISTA
    printf("Modicaremos el item 3 'Lola' de la lista:\n");
    printf("Reemplazamos su contenido por otra mascota.\n\n");
    system("pause");
    system("clear");

    ll_set(lista, 2, &m7);
    mostrarMascotas(lista);

    printf("Vamos a agregar una mascota mas al listado...\n\n");
    system("pause");
    system("clear");

    // AGREGAMOS UNA MASCOTA MAS AL LINKEDLIST
    ll_push(lista, 3, &m8);

    mostrarMascotas(lista);

    tam = ll_len(lista);
    printf("El LinkedList ahora contiene: %d mascotas\n\n",ll_len(lista));
    printf("Vamos a elminar una mascota del listado: Bobby\n\n");
    system("pause");
    system("clear");

    // ELIMINAMOS UNA MASCOTA DEL LINKEDLIST
    ll_remove(lista,0);
    mostrarMascotas(lista);

    tam = ll_len(lista);
    printf("El LinkedList ahora contiene: %d mascotas\n\n",ll_len(lista));
    printf("Buscamos si existe otro Bobby en el listado.\n\n");
    system("pause");
    system("clear");

    if(ll_contains(lista, &m1)){
        printf("No se encontraron mas bobbys en la lista.\n");
        printf("------------------------------------------\n\n");
    }

    printf("Vamos a recorrer la lista y buscar un elemento.\n\n");
    printf("Buscamos donde aparece Pepe y devolvemos su posicion.\n\n");
    system("pause");
    system("clear");


    // BUSCAMOS UN ELEMENTO EN LA LISTA Y MOSTRAMOS SU UBICACION
    mostrarMascotas(lista);
    ubicacionPepe = ll_indexOf(lista, &m2);

    if(ubicacionPepe != -1){
        printf("Pepe esta ubicado en la posicion: %d\n\n", (ubicacionPepe + 1));
    }

    printf("Vamos a crear una nueva lista copiando algunos elementos del listado.\n\n");
    system("pause");
    system("clear");


    // CREAMOS UNA NUEVA LISTA CLONANDO ALGUNOS ITEMS DE LA LISTA ANTERIOR
    printf("Lista Original:\n");
    mostrarMascotas(lista);
    listaClon = ll_subList(lista,2,5);

    // CHEQUEAMOS SI LA LISTA NO ES NULL O SI ESTA VACIA
    if( listaClon != NULL && !ll_isEmpty(listaClon)){
        printf("Nuevo listado:\n");
        mostrarMascotas(listaClon);

    }

    printf("Vamos a crear una nueva lista copiando el listado MASCOTAS.\n\n");
    system("pause");
    system("clear");

    // HACEMOS OTRA LINKEDLIST EN BASE A LA ORIGINAL
    listaCopiaOriginal = ll_clone(lista);

    if(listaCopiaOriginal != NULL){
        printf("Lista 2, clonada de MASCOTAS: \n");
        mostrarMascotas(listaCopiaOriginal);
    }

    printf("Vamos a comparar el listado MASCOTAS (original) con el nuevo recientemente creado:\n");

    if(!ll_containsAll(lista,listaCopiaOriginal)){
        printf("Confirmado, todos los elementos del listado original estan incluidos en el nuevo listado.\n\n");
    }else{
        printf("NO contienen los mismos items.");
    }

    printf("Ordenamos el nuevo listado por nombre alfabeticamente:\n\n");

    ll_sort(listaCopiaOriginal, ordenarMascotas, 1);
    mostrarMascotas(listaCopiaOriginal);

    system("pause");
    system("clear");

    printf("Vamos a vaciar los 3 listados que creamos:\n\n");
    tam = ll_len(lista);
    tam2 = ll_len(listaClon);
    tam3 = ll_len(listaCopiaOriginal);
    printf("Largo del listado MASCOTAS: %d\n", tam);
    printf("Largo del listado mas chico: %d\n", tam2);
    printf("Largo del listado clonado de MASCOTAS: %d\n\n", tam3);

    ll_clear(lista);
    ll_clear(listaClon);
    ll_clear(listaCopiaOriginal);

    tam = ll_len(lista);
    tam2 = ll_len(listaClon);
    tam3 = ll_len(listaCopiaOriginal);

    printf("Largo del listado MASCOTAS: %d\n", tam);
    printf("Largo del listado mas chico: %d\n", tam2);
    printf("Largo del listado clonado de MASCOTAS: %d\n\n", tam3);

    printf("Y vamos a eliminarlos:\n\n");
    // ELIMINAMOS EL LINKEDLIST CREADO
    if(!ll_deleteLinkedList(lista)){
        printf("Lista 1 eliminada con exito.\n");
    }
    if(!ll_deleteLinkedList(listaClon)){
        printf("Lista 2 eliminada con exito.\n");
    }
    if(!ll_deleteLinkedList(listaCopiaOriginal)){
        printf("Lista 3 eliminada con exito.\n");
    }


    return 0;
}
