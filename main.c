#include "pila.h"
#include "testing.h"
#include <stdio.h>

/* ******************************************************************
 *                        PROGRAMA PRINCIPAL
 * *****************************************************************/

int main(void)
{
    /* Ejecuta todas las pruebas unitarias. */
    printf("~~~ PRUEBAS ALUMNO ~~~\n");
    prueba_pila_vacia();
	prueba_pila_con_elementos();
	prueba_pila_memoria_dinamica();
	prueba_pila_volumen();
    return failure_count() > 0;
}
