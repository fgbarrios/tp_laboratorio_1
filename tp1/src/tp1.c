/*
 ============================================================================
 Name        : tp1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "barrios.h"

int main()
{
	setbuf(stdout,NULL);

    int num1 = 0;
    int num2 = 0;
    char respuesta = 's';
    char opcion;

    int flagOpcion1 = 0;
    int flagOpcion2 = 0;

    int resultadoSuma;
    int resultadoResta;
    int resultadoMultiplicar;
    float resultadoDivision;
    int resultadoFact1;
    int resultadoFact2;

    int errorDivision = 0;
    int errorFactorial = 0;


    do {


    	system("cls");
        printf("***Calculadora***\n");
        printf("1. Ingresar 1er operando (A=%d)\n", num1);
        printf("2. Ingresar 2do operando (B=%d)\n", num2);
        printf("3. Calcular todas las operaciones\n");
        printf("a) Calcular la suma (%d+%d)\n", num1, num2);
        printf("b) Calcular la resta (%d-%d)\n", num1, num2);
        printf("c) Calcular la division (%d/%d)\n", num1, num2);
        printf("d) Calcular la multiplicacion (%d*%d)\n", num1, num2);
        printf("e) Calcular el factorial (%d!)(%d!)\n", num1, num2);
        printf("4. Informar resultados\n");
        printf("5. Salir\n\n");

        printf("Elegir opcion: ");
        fflush(stdin);
        scanf("%c", &opcion);

        switch (opcion)
        {
        case '1':
            printf("Ingresar el 1er numero: \n");
            fflush(stdin);
            scanf("%d", &num1);
            flagOpcion1 = 1;
        break;

        case '2':
            printf("Ingresar el 2do numero: \n");
            fflush(stdin);
            scanf("%d", &num2);
            flagOpcion2 = 1;
        break;

        case '3': // CALCULAR TODAS LAS OPERACIONES
            if(flagOpcion1 == 0 || flagOpcion2 == 0)
            {
                printf("Primero debe ingresar los operandos\n");
                fflush(stdin);
                system("pause");
            }else{

                resultadoSuma = suma(num1, num2); // SUMA
                resultadoResta = resta(num1, num2); // RESTA

                if(num2 == 0){ // DIVISION
                        errorDivision = 1;
                    }else{
                        resultadoDivision = dividir(num1, num2);
                    }
                resultadoMultiplicar = multiplicar(num1, num2); // MULTIPLICACION


                if(num1 < 1 || num2 < 1){ // FACTORIAL
                    errorFactorial = 1; //NO SE PUEDE FACTORIZAR UN NUMERO NEGATIVO

                }else if(num1 == 1){
                    resultadoFact1 = 1;
                }else if(num2 == 1)
                {
                    resultadoFact2 = 1;
                }else
                {
                    resultadoFact1 = factorial(num1);
                    resultadoFact2 = factorial(num2);
                }
            printf("\n****************************\n\n");
            printf("***Operaciones realizadas***\n\n");
            printf("****************************\n\n");
            fflush(stdin);
            system("pause");
            }
        break;


        case '4': // IMPRIMIR LOS RESULTADOS DE LAS OPCIONES SELECCIONADAS
            if(flagOpcion1 == 0 || flagOpcion2 == 0)
            {
                printf("Primero debe ingresar los operandos\n");
                fflush(stdin);
                system("pause");
            }else{
                printf("\n***************************************\n");
                printf("a) El resultado de A+B es: %d\n", resultadoSuma);
                printf("b) El resultado de A-B es: %d\n", resultadoResta);
                if(errorDivision == 1){
                    printf("c) No es posible dividir por cero\n");
                }else{
                    printf("c) El resultado de A/B es: %.2f\n", resultadoDivision);
                }
                printf("d) El resultado de A*B es: %d\n", resultadoMultiplicar);
                if(errorFactorial == 1)
                {
                    printf("e) No se pueden factorizar numeros menores a cero\n");
                }else{
                    printf("e) El factorial de A es: %d y El factorial de B es: %d\n", resultadoFact1, resultadoFact2);
                }
                printf("\n***************************************\n");
                system("pause");
                flagOpcion1 = 0;
                flagOpcion2 = 0;
                num1 = 0;
                num2 = 0;
            }
        break;

        case '5':
            printf("¿Seguro desea salir? Presione 's' para continuar calculando, 'n' para confirmar salida: \n");
            fflush(stdin);
            scanf("%c", &respuesta);

        break;

        default:
            printf("Ingrese una opcion valida\n");
            fflush(stdin);
            //system("pause");
            system("cls");
        break;
    }


    }while (respuesta == 's');


    return 0;
}
