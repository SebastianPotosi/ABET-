#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "citas.h"

void imprimirCitas(Cita *citas, int numCitas);
void guardarCitasEnArchivo(Cita *citas, int numCitas);
void cargarCitasDesdeArchivo(Cita *citas, int *numCitas);
void borrarHistorialCitas();

#endif
