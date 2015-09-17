#include "pila.h"
#include "testing.h"
#include <stddef.h>
#include <stdio.h>

#define MAX_VOLUMEN 1000

/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/

void prueba_pila_vacia() {
	printf("\nINICIO DE PRUEBAS CON PILA VACIA\n");
	
	/* Declaro las variables a utilizar*/
	pila_t* pila = pila_crear();
	
	/* Inicio de pruebas */
	print_test("Prueba crear pila", pila != NULL);
	print_test("Prueba tope de la pila vacia devuelve NULL", !pila_ver_tope(pila));
	print_test("Prueba pila debe estar vacia al inicializar", pila_esta_vacia(pila));
	print_test("Prueba desapilar pila vacia igual a NULL", !pila_desapilar(pila));
	
	/* Destruyo la pila */
	pila_destruir(pila);
	print_test("La pila fue destruida", true);
}

void prueba_pila_con_elementos() {
	printf("\nINICIO DE PRUEBAS CON PILA CON ALGUNOS ELEMENTOS\n");
	
	/* Declaro las variables a utilizar*/
	pila_t* pila = pila_crear();
	
	/* Inicio de pruebas */
	// Genero elementos a apilar
	int a = 1, b = 2, c = 3, d = 4, e = 5;
	int* p_a = &a;
	int* p_b = &b;
	int* p_c = &c;
	int* p_d = &d;
	int* p_e = &e;
	
	// Apilo todos los elementos
	print_test("Prueba apilar &a", pila_apilar(pila, p_a));
	print_test("Prueba apilar &b", pila_apilar(pila, p_b));
	print_test("Prueba apilar &c", pila_apilar(pila, p_c));
	print_test("Prueba apilar &d", pila_apilar(pila, p_d));
	print_test("Prueba apilar &e", pila_apilar(pila, p_e));
	print_test("Prueba ver tope igual a &e", pila_ver_tope(pila) == p_e);
	print_test("Prueba pila NO debe estar vacia luego de apilar", !pila_esta_vacia(pila));
	
	// Desapilo un elemento
	void* elemento = pila_desapilar(pila);
	print_test("Prueba desapilar elemento", (elemento == p_e));
	
	/* Destruyo la pila */
	pila_destruir(pila);
	print_test("La pila fue destruida", true);
}

void prueba_pila_memoria_dinamica() {
	printf("\nINICIO DE PRUEBAS DE MEMORIA DINAMICA\n");
	
	/* Declaro las variables a utilizar*/
	pila_t* pila = pila_crear();
	
	/* Inicio de pruebas */
	// Genero elementos a apilar
	int a = 1, b = 2, c = 3, d = 4, e = 5, f = 6, g = 7;
	int* p_a = &a;
	int* p_b = &b;
	int* p_c = &c;
	int* p_d = &d;
	int* p_e = &e;
	int* p_f = &f;
	int* p_g = &g;
	
	// Apilo todos los elementos
	print_test("Prueba apilar &a", pila_apilar(pila, p_a));
	print_test("Prueba apilar &b", pila_apilar(pila, p_b));
	print_test("Prueba apilar &c", pila_apilar(pila, p_c));
	print_test("Prueba apilar &d", pila_apilar(pila, p_d));
	print_test("Prueba apilar &e", pila_apilar(pila, p_e));
	print_test("Prueba apilar &f", pila_apilar(pila, p_f));
	print_test("Prueba apilar &g", pila_apilar(pila, p_g));
	print_test("Prueba ver tope igual a &g", pila_ver_tope(pila) == p_g);
	
	// Desapilo todos los elementos restantes hasta dejar la pila vacía
	for (int i = 1; i <= 7; i++) {	// Son 7 elementos
		pila_desapilar(pila);
	}
	print_test("Prueba pila vacia luego de desapilar todos los elementos", pila_esta_vacia(pila));
		
	/* Destruyo la pila */
	pila_destruir(pila);
	print_test("La pila fue destruida", true);
}

void prueba_pila_volumen() {
    printf("\nINICIO DE PRUEBAS DE VOLUMEN\n");
	
	/* Declaro las variables a utilizar*/
	pila_t* pila = pila_crear();
	
	/* Inicio de pruebas */
	// Genero elementos a apilar
	int a = 1, b = 2, c = 3, d = 4, e = 5;
	int* p_a = &a;
	int* p_b = &b;
	int* p_c = &c;
	int* p_d = &d;
	int* p_e = &e;
	
	// Apilo los 5 elementos MAX_VOLUMEN veces
	for (int i = 1; i <= MAX_VOLUMEN; i++) {
		pila_apilar(pila, p_a);
		pila_apilar(pila, p_b);
		pila_apilar(pila, p_c);
		pila_apilar(pila, p_d);
		pila_apilar(pila, p_e);
	}
	print_test("Prueba de volumen", pila_ver_tope(pila) == p_e);
	
	// Desapilo todos los elementos restantes hasta dejar la pila vacía
	for (int i = 1; i <= MAX_VOLUMEN * 5; i++) {	// 5 es porque apilo esa cantidad de elementos en cada ciclo de la PRUEBA DE VOLUMEN
		pila_desapilar(pila);
	}
	print_test("Prueba desapilar luego de prueba volumen", pila_esta_vacia(pila));
	
	/* Destruyo la pila */
	pila_destruir(pila);
	print_test("La pila fue destruida", true);
}

void prueba_pila_alumno() {
	prueba_pila_vacia();
	prueba_pila_con_elementos();
	prueba_pila_memoria_dinamica();
	prueba_pila_volumen();
}
