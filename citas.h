#ifndef CITAS_H
#define CITAS_H

#define MAX_CITAS 100
#define ARCHIVO_CITAS "citas.txt"

typedef struct {
    int dia;
    int mes;
    int anio;
    char descripcion[100];
} Cita;

#endif
