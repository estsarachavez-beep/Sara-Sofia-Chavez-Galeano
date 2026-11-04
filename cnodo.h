#pragma once
#include <iostream>

/**
 * @brief Nodo que almacena un entero y enlaza con el siguiente nodo.
 *
 * Se utiliza como unidad básica en las estructuras enlazadas del programa:
 * lista, cola y pila. El campo asing permite recorrer la estructura nodo a nodo.
 */
class cnodo {
public:
	int ainfo;       // Dato entero almacenado en este nodo.
	cnodo* asing;    // Enlace al siguiente nodo; NULL indica que no hay otro nodo.

	// Construye un nodo vacío, sin enlace al siguiente elemento.
	cnodo() { asing = NULL; }

	// Construye un nodo con el dato indicado y sin sucesor.
	cnodo(int pdato)
		: ainfo(pdato), asing(NULL) {}
};



