#pragma once

#include "cnodo.h" // Define los nodos enlazados que almacenan los elementos de la cola.
#include <iostream> // Permite mostrar mensajes y datos en la consola.

/**
 * @brief Cola enlazada de enteros con comportamiento FIFO.
 *
 * En una cola FIFO (First In, First Out), el primer elemento insertado es el
 * primero que se elimina. La clase administra nodos dinámicos y conserva
 * referencias al frente y al final para insertar y retirar elementos.
 */
class ccola
{
private:
	cnodo* aPrimero; // Puntero al frente: nodo que se eliminará primero.
	cnodo* aUltimo;  // Puntero al final: ubicación donde se insertan elementos nuevos.
	int aM;          // Número de nodos almacenados actualmente.
	bool aI;         // Indica si la última operación tuvo éxito (true) o falló (false).

public:
	ccola();  // Inicializa una cola vacía y sus atributos.
	~ccola(); // Libera todos los nodos dinámicos antes de destruir el objeto.

	// Consultan el tamaño, el estado de la última operación y el nodo del frente.
	int getaN() const;            // Devuelve la cantidad actual de elementos.
	bool getaI() const;            // Devuelve el resultado de la última operación.
	cnodo* getainicio() const;     // Devuelve un puntero al primer nodo o nullptr si está vacía.

	// Operaciones básicas de la cola enlazada.
	void mCrear(int pdato);        // Crea la cola con su primer elemento.
	void mInsertar(int pdato);     // Agrega un elemento al final de la cola.
	void mEliminar();              // Retira el elemento que está en el frente.
	void mVer() const;             // Muestra el elemento del frente sin eliminarlo.
	void mDestruir();              // Elimina todos los nodos y deja la cola vacía.
};

