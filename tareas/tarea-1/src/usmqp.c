//
// Created by Raztor on 13-04-23.
//
#include <string.h>
#include "usmqp.h"

struct WazaaaApp;

mensaje *parse_message(char *text) {
    char name[50], cellphone[15];
    mensaje *msg = malloc(sizeof(mensaje));
    sscanf(text, "[%10[^]] %8[^]]] %[^\n] %[+0-9 ]:%[^\n]",
           msg->fecha, msg->hora, name, cellphone, msg->contenido);
    msg->emisor = malloc(sizeof(contacto));
    sscanf(name, "%s", msg->emisor->nombre);
    sscanf(cellphone, "+%[0-9 ]", msg->emisor->telefono);
    msg->sgte = NULL;
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
        mensaje *msg = parse_message(buffer);
        if (*HEAD == NULL) {
            *HEAD = msg;
        } else {
            mensaje *temp = *HEAD;
            while (temp->sgte != NULL) {
                temp = temp->sgte;
            }
            temp->sgte = msg;
        }
    }
    fclose(archivo);
}


int main(int argc, char *argv[]) {
    char filename[16];
    mensaje *HEAD = NULL;
    if (argc != 2) {
        printf("Error: debe ingresar el nombre del archivo de entrada.\n");
        exit(1);
    }
    strcpy(filename, argv[1]);
    read_file(filename, &HEAD);

    // test print
    mensaje *temp = HEAD;
    while (temp != NULL) {
        printf("Date: %s\n", temp->fecha);
        printf("Time: %s\n", temp->hora);
        printf("Name: %s\n", temp->emisor->nombre);
        printf("Cellphone: %s\n", temp->emisor->telefono);
        printf("Message: %s\n", temp->contenido);
        printf("\n");
        temp = temp->sgte;
    }

    // free memory
    temp = HEAD;
    while (temp != NULL) {
        mensaje *sig = temp->sgte;
        free(temp->fecha);
        free(temp->hora);
        free(temp->emisor->nombre);
        free(temp->emisor->telefono);
        free(temp->emisor);
        free(temp->contenido);
        free(temp);
        temp = sig;
    }
    return 0;
}