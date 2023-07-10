#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void imprimirCitas(Cita *citas, int numCitas) {
    printf("Citas agendadas:\n");
    for (int i = 0; i < numCitas; i++) {
        printf("%d/%d/%d - %s\n", citas[i].dia, citas[i].mes, citas[i].anio, citas[i].descripcion);
    }
}

void guardarCitasEnArchivo(Cita *citas, int numCitas) {
    FILE *archivo = fopen(ARCHIVO_CITAS, "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    for (int i = 0; i < numCitas; i++) {
        fprintf(archivo, "%d %d %d %s\n", citas[i].dia, citas[i].mes, citas[i].anio, citas[i].descripcion);
    }

    fclose(archivo);
}

void cargarCitasDesdeArchivo(Cita *citas, int *numCitas) {
    FILE *archivo = fopen(ARCHIVO_CITAS, "r");
    if (archivo == NULL) {
        printf("No hay citas agendadas.\n");
        return;
    }

    *numCitas = 0;
    while (fscanf(archivo, "%d %d %d %[^\n]", &(citas[*numCitas].dia), &(citas[*numCitas].mes), &(citas[*numCitas].anio), citas[*numCitas].descripcion) == 4) {
        (*numCitas)++;
    }

    fclose(archivo);
}

void borrarHistorialCitas() {
    FILE *archivo = fopen(ARCHIVO_CITAS, "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    fclose(archivo);
}
