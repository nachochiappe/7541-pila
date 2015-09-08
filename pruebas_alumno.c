#include "pila.h"
#include "testing.h"
#include <stddef.h>


/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/

void prueba_pila_alumno() {
    pila_t* ejemplo = NULL;
	print_test("Puntero inicializado a NULL", ejemplo == NULL);
	
	// PRUEBA CREAR PILA
	pila_t* pila;
	print_test("Prueba crear pila", (pila = pila_crear()));
	
	// PRUEBA TOPE PILA VACIA
	print_test("Prueba tope de la pila vacia devuelve NULL", (pila_ver_tope(pila) == NULL));
	
	// PRUEBA PILA_ESTA_VACIA EN PILA VACIA
	print_test("Prueba pila debe estar vacia al inicializar", (pila_esta_vacia(pila) == true));
	
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
	print_test("Prueba pila NO debe estar vacia luego de apilar", (pila_esta_vacia(pila) == false));
	
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
	print_test("Prueba pila vacia luego de desapilar todos los elementos", (pila_esta_vacia(pila) == true));
	
	// PRUEBA DESAPILAR PILA VACIA
	print_test("Prueba desapilar pila vacia igual a NULL", (pila_desapilar(pila) == NULL));
	
	// PRUEBA DESTRUIR PILA
	// Apilo los 7 elementos generados
	pila_apilar(pila, p_a);
	pila_apilar(pila, p_b);
	pila_apilar(pila, p_c);
	pila_apilar(pila, p_d);
	pila_apilar(pila, p_e);
	pila_apilar(pila, p_f);
	pila_apilar(pila, p_g);
	// Destruyo la pila
	pila_destruir(pila);
	print_test("Prueba destruir pila", (pila_esta_vacia(pila) == true));
}