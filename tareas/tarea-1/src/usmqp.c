//
// Created by Raztor on 13-04-23.
//
#include <string.h>
#include "usmqp.h"

struct WazaaaApp;

struct WazaaaApp parse_message(char *text) {
    char date[11], time[10], name[50], phone[15], message[100];
    mensaje msg;

    sscanf(text,"[%[^]]] %[^ ] %[^+]+%[^:]: %[^\n]", date, time, name, phone, message);
    msg.fecha = date;
    msg.hora = time;
    msg.emisor->nombre = name;
    msg.emisor->telefono = phone;
    msg.contenido = message;
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
        char date[11], time[10], name[50], phone[15], message[100];
        sscanf(buffer,"[%[^]]] %[^ ] %[^+]+%[^:]: %[^\n]", date, time, name, phone, message);
             



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

void print_list(mensaje *cabeza){
    mensaje *recorredor = cabeza;
    // Recorre todos los nodos hasta encontrar el NULL
    while(recorredor != NULL){
        printf("%s ", recorredor->contenido);
        recorredor = recorredor->sgte;
    }
    printf("\n");
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

    print_list(inicio);

    return 0;
}