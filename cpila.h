#pragma once
#include "cnodo.h" // Permite construir y enlazar los nodos que forman la pila.
#include <iostream> // Incluye operaciones de entrada y salida estándar.

/**
 * @brief Pila enlazada de enteros que sigue el principio LIFO.
 *
 * LIFO (Last In, First Out) significa que el último elemento apilado es el
 * primero en salir. Las operaciones de inserción y eliminación se realizan
 * en el tope de la pila.
 */
class cpila {
private:
	cnodo* aInicio; // Puntero al nodo del tope y comienzo del encadenamiento.
	cnodo* aP;      // Referencia al primer nodo, que corresponde al tope.
	cnodo* aU;      // Referencia al último nodo, que corresponde a la base.
	int aN;         // Cantidad de elementos almacenados en la pila.
	bool aI;        // Estado de éxito o fallo de la última operación.

public:
	cpila();  // Construye una pila vacía e inicializa sus atributos.
	~cpila(); // Destruye la pila y libera la memoria de sus nodos.

	// Métodos de acceso para consultar o modificar el estado interno.
	int getaN();                    // Devuelve la cantidad de elementos.
	void setaN(int paN);            // Actualiza el contador de elementos.
	bool getaI();                   // Devuelve el estado de la última operación.
	void setaI(bool paI);           // Actualiza el estado de la operación.
	cnodo* getaInicio();            // Devuelve el puntero al tope/inicio.
	void setaInicio(cnodo* paInicio); // Actualiza el puntero al inicio de la pila.
	cnodo* getaP();                 // Devuelve el puntero al tope.
	void setaP(cnodo* paP);         // Actualiza el puntero al tope.
	cnodo* getaU();                 // Devuelve el puntero a la base.
	void setaU(cnodo* paU);         // Actualiza el puntero a la base.

	// Operaciones principales de la pila (LIFO).
	void mCrear(int pdato);         // Crea la pila con un primer elemento.
	void mInsertar(int pdato);      // Apila (push) un nuevo elemento en el tope.
	void mVer();                    // Muestra los elementos desde el tope hasta la base.
	int mEliminar();                // Desapila (pop) y devuelve el valor que estaba en el tope.
	void mDestruir();               // Libera todos los nodos y deja la pila vacía.
};
