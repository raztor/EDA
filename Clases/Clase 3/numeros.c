//
// Created by benjamin on 16-03-23.
//

#include <stdio.h>

int main(){

 // Ingresar un numero positivo entero y determinar si es primo o compuesto

    int numero, result;
    printf("Ingrese un numero entero positivo:  ");
    scanf("%d", &numero);
    if (numero > 0){
        if (numero == 1){
            printf("El numero es 1, no es ni primo ni compuesto");
        }else if(numero==2){
            printf("El numero es primo");
        }else{
            for (int i = 2; i < numero; i++){
                result = numero % i;
                if (result == 0){
                    printf("El numero es compuesto \n");
                    main();
                    //break;
                }
                else if (i == numero - 1){
                    printf("El numero es primo");
                }
            }
        }
    }
    else{
        printf("El numero ingresado no es positivo");
    }
    return 0;
}