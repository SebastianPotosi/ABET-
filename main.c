#include <stdio.h>
#include <stdlib.h>
#include "citas.h"
#include "funciones.h"

int main() {
    Cita citas[MAX_CITAS];
    int numCitas = 0;
    int opcion;

    Cita *Citas = citas;

    cargarCitasDesdeArchivo(Citas, &numCitas);

    do {
        printf("Agendamiento de citas:\n");
        printf("1. Agendar cita\n");
        printf("2. Reagendar cita\n");
        printf("3. Cancelar cita\n");
        printf("4. Mostrar citas agendadas\n");
        printf("5. Salir\n");
        printf("6. Borrar historial de citas\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                if (numCitas >= MAX_CITAS) {
                    printf("Maximo de citas\n");
                } else {
                    printf("Agendar cita:\n");
                    printf("Ingrese la fecha (DD(Dia) MM(Mes) AAAA(Anio)): ");
                    scanf("%d %d %d", &(Citas[numCitas].dia), &(Citas[numCitas].mes), &(Citas[numCitas].anio));
                    printf("Ingrese una descripcion: ");
                    scanf(" %[^\n]", Citas[numCitas].descripcion);
                    numCitas++;
                    printf("Cita agendada correctamente\n");
                }
                break;
            case 2:
                printf("Reagendar cita:\n");
                printf("Ingrese el numero de cita a reagendar: ");
                int numCitaReagendar;
                scanf("%d", &numCitaReagendar);
                if (numCitaReagendar >= 1 && numCitaReagendar <= numCitas) {
                    printf("Ingrese la nueva fecha (DD MM AAAA): ");
                    scanf("%d %d %d", &(Citas[numCitaReagendar - 1].dia), &(Citas[numCitaReagendar - 1].mes), &(Citas[numCitaReagendar - 1].anio));
                    printf("Ingrese la nueva descripción: ");
                    scanf(" %[^\n]", Citas[numCitaReagendar - 1].descripcion);
                    printf("Cita reagendada correctamente.\n");
                } else {
                    printf("Numero de cita invalido.\n");
                }
                break;
            case 3:
                printf("Cancelar cita:\n");
                printf("Ingrese el número de cita a cancelar: ");
                int numCitaCancelar;
                scanf("%d", &numCitaCancelar);
                if (numCitaCancelar >= 1 && numCitaCancelar <= numCitas) {
                    for (int i = numCitaCancelar - 1; i < numCitas - 1; i++) {
                        Citas[i] = Citas[i + 1];
                    }
                    numCitas--;
                    printf("Cita cancelada correctamente.\n");
                } else {
                    printf("Namero de cita invalido.\n");
                }
                break;
            case 4:
                imprimirCitas(Citas, numCitas);
                break;
            case 5:
                printf("Gracias por contar con nosotros\n");
                break;
            case 6:
                borrarHistorialCitas();
                printf("Historial de citas borrado correctamente\n");
                numCitas = 0;
                break;
            default:
                printf("Opción invalida, seleccione una opcion valida\n");
                break;
        }

        printf("\n");
    } while (opcion != 5);

    guardarCitasEnArchivo(Citas, numCitas);

    return 0;
}
