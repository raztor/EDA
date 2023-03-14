//
// Created by benjamin on 14-03-23.
//
#include <stdio.h>

int main(){

    float celsius, resultado;
    int opcion;
    printf("Ingrese temperatura en grados Celsius:  ");
    scanf("%f", &celsius);
    printf("Ingrese 1 para convertir a Fahrenheit o 2 para convertir a Kelvin:  ");
    scanf("%d", &opcion);
    if (opcion == 1){
        resultado = (celsius * 9/5) + 32;
        printf("La temperatura en grados Fahrenheit es: %f", resultado);
    }
    else if (opcion == 2){
        resultado = celsius + 273.15;
        printf("La temperatura en grados Kelvin es: %f", resultado);
    }
    else{
        printf("Opcion invalida");
    }
}