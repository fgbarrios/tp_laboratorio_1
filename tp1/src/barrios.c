/*
 * barrios.c
 *
 *  Created on: 10 abr. 2021
 *      Author: PC
 */

#include <stdio.h>
#include <stdlib.h>
#include "barrios.h"

int suma(int num1, int num2){
    int resultado;
    resultado = num1 + num2;
    return resultado;
}

int resta(int num1, int num2){
    int resultado;
    resultado = num1 - num2;
    return resultado;
}

float dividir(int num1, int num2){
    float resultado;
    resultado = (float)num1 / num2;
    return resultado;
}

int multiplicar(int num1, int num2){
    int resultado;
    resultado = num1 * num2;
    return resultado;
}

int factorial(int n){
    int fact = 1;
    for(int i = 1;i <= n; i++){
        fact *= i;

    }
    return fact;

}



