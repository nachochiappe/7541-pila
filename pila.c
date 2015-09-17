#include "pila.h"
#include <stdlib.h>

#define TAM_INICIAL 5
#define MULTIPLICADOR 2

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
	pila->datos = malloc(TAM_INICIAL * sizeof(void*));
	if (!pila->datos) {
        free(pila);
        return NULL;
    }
    pila->tam = TAM_INICIAL;
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
		void **aux = realloc(pila->datos, (pila->tam * MULTIPLICADOR) * sizeof(void*));
		if (!aux)
			return false;
		pila->datos = aux;
		pila->tam = pila->tam * MULTIPLICADOR;
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
		if ((pila->largo > 0) && (pila->tam / pila->largo == MULTIPLICADOR)) {
			void **aux = realloc(pila->datos, (pila->tam / MULTIPLICADOR) * sizeof(void*));
			if (!aux)
				return NULL;
			pila->datos = aux;
			pila->tam = pila->tam / MULTIPLICADOR;
		}
	}
	return elemento;
}
