#include "pila.h"
#include "testing.h"
#include <stddef.h>

#define MAX_VOLUMEN 1000

/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/

void prueba_pila_alumno() {
    // PRUEBA CREAR PILA
	pila_t* pila;
	print_test("Prueba crear pila", (pila = pila_crear()));
	
	// PRUEBA TOPE PILA VACIA
	print_test("Prueba tope de la pila vacia devuelve NULL", (!pila_ver_tope(pila)));
	
	// PRUEBA PILA_ESTA_VACIA EN PILA VACIA
	print_test("Prueba pila debe estar vacia al inicializar", (pila_esta_vacia(pila)));
	
	// PRUEBA VER_TOPE
	// Genero elementos a apilar
	int a = 1, b = 2, c = 3, d = 4, e = 5;
	int* p_a = &a;
	int* p_b = &b;
	int* p_c = &c;
	int* p_d = &d;
	int* p_e = &e;
	// Apilo todos los elementos
	pila_apilar(pila, p_a);
	pila_apilar(pila, p_b);
	pila_apilar(pila, p_c);
	pila_apilar(pila, p_d);
	pila_apilar(pila, p_e);
	print_test("Prueba apilar hasta TAMANO", (pila_ver_tope(pila) == p_e));
	
	// PRUEBA PILA_ESTA_VACIA EN PILA CON DATOS
	print_test("Prueba pila NO debe estar vacia luego de apilar", (!pila_esta_vacia(pila)));
	
	// PRUEBA DESAPILAR ELEMENTO
	void* elemento;
	elemento = pila_desapilar(pila);
	print_test("Prueba desapilar elemento", (elemento == p_e));
	
	// PRUEBA APILAR MÁS ELEMENTOS QUE EL MÁXIMO DEFINIDO
	// Apilo el elemento que había desapilado antes
	pila_apilar(pila, p_e);
	// Genero nuevos elementos
	int f = 6, g = 7;
	int* p_f = &f;
	int* p_g = &g;
	// Apilo los nuevos elementos
	pila_apilar(pila, p_f);
	pila_apilar(pila, p_g);
	print_test("Prueba apilar mas elementos que TAMANO", (pila_ver_tope(pila) == p_g));
	
	// PRUEBA DESAPILAR VARIOS ELEMENTOS
	// Desapilo 2 elementos, para pasar de pila->largo == 7 a pila->largo == 5, necesitando un realloc
	elemento = pila_desapilar(pila);
	elemento = pila_desapilar(pila);
	print_test("Prueba desapilar elementos (realloc)", (pila_ver_tope(pila) == p_e));
	
	// PRUEBA DESAPILAR TODOS LOS ELEMENTOS RESTANTES
	// Desapilo todos los elementos restantes hasta dejar la pila vacía
	elemento = pila_desapilar(pila);
	elemento = pila_desapilar(pila);
	elemento = pila_desapilar(pila);
	elemento = pila_desapilar(pila);
	elemento = pila_desapilar(pila);
	print_test("Prueba pila vacia luego de desapilar todos los elementos", (pila_esta_vacia(pila)));
	
	// PRUEBA DESAPILAR PILA VACIA
	print_test("Prueba desapilar pila vacia igual a NULL", (!pila_desapilar(pila)));
	
	// PRUEBA DE VOLUMEN
	for (int i = 1; i <= MAX_VOLUMEN; i++) {
		pila_apilar(pila, p_a);
		pila_apilar(pila, p_b);
		pila_apilar(pila, p_c);
		pila_apilar(pila, p_d);
		pila_apilar(pila, p_e);
	}
	print_test("Prueba de volumen", (pila_ver_tope(pila) == p_e));
	
	// PRUEBA DESAPILAR ELEMENTOS  DE LA PRUEBA DE VOLUMEN
	for (int i = 1; i <= MAX_VOLUMEN * 5; i++) {	// 5 es porque apilo esa cantidad de elementos en cada ciclo de la PRUEBA DE VOLUMEN
		elemento = pila_desapilar(pila);
	}
	print_test("Prueba desapilar luego de prueba volumen", (pila_esta_vacia(pila)));
	
	// PRUEBA DESTRUIR PILA
	pila_destruir(pila);
}
