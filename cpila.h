#pragma once
#include "cnodo.h" // Incluye la clase cnodo para utilizar punteros autorreferenciados
#include <iostream>

class cpila {
private:
	cnodo* aInicio; // Puntero al tope de la pila en memoria dinámica
	cnodo* aP;      // Puntero al primero (Tope de la pila)
	cnodo* aU;      // Puntero al último (Base de la pila)
	int aN;         // Conteo de elementos almacenados
	bool aI;        // Bandera de estado de la operación (true/false)

public:
	cpila();  // Constructor por defecto
	~cpila(); // Destructor para liberar la memoria dinámica

	// Métodos Getters y Setters
	int getaN();
	void setaN(int paN);
	bool getaI();
	void setaI(bool paI);
	cnodo* getaInicio();
	void setaInicio(cnodo* paInicio);
	cnodo* getaP();
	void setaP(cnodo* paP);
	cnodo* getaU();
	void setaU(cnodo* paU);

	// Métodos principales de la Pila (LIFO)
	void mCrear(int pdato);    // Crea el primer nodo en el tope de la pila
	void mInsertar(int pdato); // Apilar (Push): Inserta un nodo en el tope (aInicio / aP)
	int mEliminar();           // Desapilar (Pop): Elimina el nodo del tope y retorna su valor
	void mDestruir();          // Libera iterativamente todos los nodos de la pila
};
