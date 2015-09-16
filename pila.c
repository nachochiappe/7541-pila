#include "pila.h"
#include <stdlib.h>

#define TAMANO 5

/* Definición del struct pila proporcionado por la cátedra.
 */
struct pila {
    void **datos;
    size_t tam;
    size_t largo;
};

/* *****************************************************************
 *                    PRIMITIVAS DE LA PILA
 * *****************************************************************/

pila_t* pila_crear() {
	pila_t* pila = malloc(sizeof(pila_t));
	if (!pila)
		return NULL;
	pila->datos = malloc(TAMANO * sizeof(void*));
	if (!pila->datos) {
        free(pila);
        return NULL;
    }
    pila->tam = TAMANO;
	pila->largo = 0;
    return pila;
}

void pila_destruir(pila_t *pila) {
	free(pila->datos);
	free(pila);
}

bool pila_esta_vacia(const pila_t *pila) {
	return (pila->largo == 0);
}

bool pila_apilar(pila_t *pila, void* valor) {
	if (pila->largo == pila->tam) {
		void **datos_nuevo = realloc(pila->datos, (pila->tam + TAMANO) * sizeof(void*));
		if (!datos_nuevo) {
			free(pila->datos);
			return false;
		}
		pila->datos = datos_nuevo;
		pila->tam += TAMANO;
	}
	*(pila->datos + pila->largo) = valor;
	pila->largo += 1;
	return true;
}

void* pila_ver_tope(const pila_t *pila) {
	if (pila->largo == 0) {
		return NULL;
	}
	return pila->datos[pila->largo - 1];
}

void* pila_desapilar(pila_t *pila) {
	void* elemento = pila_ver_tope(pila);
	if (elemento) {
		pila->largo -= 1;
		if ((pila->tam - pila->largo == TAMANO) && (pila->largo > 0)) {
			void **datos_nuevo = realloc(pila->datos, (pila->tam - TAMANO) * sizeof(void*));
			if (!datos_nuevo) {
				free(pila->datos);
				return NULL;
			}
			pila->datos = datos_nuevo;
			pila->tam -= TAMANO;
		}
	}
	return elemento;
}
