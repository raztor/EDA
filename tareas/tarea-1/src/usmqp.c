//
// Created by Raztor on 13-04-23.
//
#include <string.h>
#include "usmqp.h"

struct WazaaaApp;

struct WazaaaApp parse_message(char *text) {
    char name[50], cellphone[15];
    mensaje msg;
    sscanf(text, "[%10[^]] %8[^]]] %[^\n] %[+0-9 ]:%[^\n]",
           msg.fecha, msg.hora, name, cellphone, msg.contenido);
    sscanf(name, "%s", msg.emisor->nombre);
    sscanf(cellphone, "+%[0-9 ]", msg.emisor->telefono);
    msg.sgte = NULL;
    return msg;
}



void read_file(char filename[31], mensaje **HEAD) {
    FILE *archivo;
    char buffer[1024];
    archivo = fopen(filename, "r");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        exit(1);
    }
    while (fgets(buffer, sizeof(buffer), archivo) != NULL) {
        mensaje temp_lector = parse_message(buffer);

        mensaje *nuevo = malloc(sizeof(mensaje));
        nuevo->emisor = temp_lector.emisor;
        nuevo->hora = temp_lector.hora;
        nuevo->fecha = temp_lector.fecha;
        nuevo->contenido = temp_lector.contenido;

        mensaje *recorredor = HEAD;
        while(recorredor->sgte!=NULL){
            recorredor=recorredor->sgte;
        }

        nuevo->sgte = recorredor->sgte;
        recorredor->sgte = nuevo;
    }
}


int main(int argc, char *argv[]) {
    char filename[16];
    mensaje *inicio = malloc(sizeof(mensaje));
    inicio->sgte=NULL;
    if (argc != 2) {
        printf("Error: debe ingresar el nombre del archivo de entrada.\n");
        exit(1);
    }
    strcpy(filename, argv[1]);
    read_file(filename, &inicio);





    return 0;
}