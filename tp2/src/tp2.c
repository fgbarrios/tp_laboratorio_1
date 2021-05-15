/*
 ============================================================================
 Name        : tp2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployees.h"

#define CANTEMP 1000

int main()
{
	setbuf(stdout,NULL);

	int nextLegajo = 1000;
	int flag = 0;

	eEmployee nomina[CANTEMP];

	initEmployees(nomina, CANTEMP);

	char salir = 'n';

	do
	{
		switch (menu())
		{
		case 1: // Alta Empleado
			if(!addEmployees(nomina, CANTEMP, &nextLegajo))
			{
				printf("Hubo un problema al hacer la carga.\n\n");
			}else{
				printf("Carga Exitosa!.\n\n");
				flag = 1;
			}
			break;
		case 2:// Modificar Empleado
			flag = findFree(nomina, CANTEMP);
			if(flag == 0)
			{
				printf("Primero debe ingresar a la opcion 1\n\n");
			}
			else
			{
				modifyEmployee(nomina, CANTEMP);
			}
			break;
		case 3:// BAJA Empleado
			if(flag == 0)
			{
				printf("Primero debe ingresar a la opcion 1\n\n");
			}
			else
			{
				removeEmployee(nomina, CANTEMP);
			}
			break;
		case 4: // INFORMES
			if(flag == 0)
			{
				printf("Primero debe ingresar a la opcion 1\n\n");
			}
			else
			{
				switch (subMenuInformes())
				{
					case 1:
						sortEmployees(nomina, CANTEMP);
						system("cls");
						printEmployees(nomina, CANTEMP);
					break;
					case 2:
						system("cls");
						totalPromSalarios(nomina, CANTEMP);
					break;

					default:
						printf("Ingrese una opcion correcta.\n");
					break;
				}
			}
			break;
		case 5:
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
