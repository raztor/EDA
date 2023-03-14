//
// Created by benjamin on 14-03-23.
//

#include <stdio.h>

int main(){
    printf("Ingrese temperatura en grados Fahrenheit:  ");
    float fahrenheit, celsius;
    scanf("%f", &fahrenheit);
    celsius = (fahrenheit - 32) * 5/9;
    printf("La temperatura en grados Celsius es: %f", celsius);
    return 0;
}