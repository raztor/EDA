//
// Created by benjamin on 13-04-23.
//

#ifndef EDA_USMQP_H
#define EDA_USMQP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ll_Wzzp.h"

typedef struct user {
    char *telefono; // string : teléfono movil del usuario
    char *nombre; // string : nombre del usuario
    struct user *sgte; // puntero: siguiente.
} contacto;
typedef struct WazaaaApp {
    char *fecha; // string: fecha de mensaje
    char *hora; // string: hora de mensaje
    contacto *emisor; // puntero a emisor del mensaje
    char *contenido; // string : contenido del mensaje
    struct WazaaaApp *sgte; // puntero: siguiente.
} mensaje;

#endif //EDA_USMQP_H
