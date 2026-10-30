#pragma once

#include "cnodo.h"
#include <iostream>

// Cola enlazada de enteros. Funciona con la regla FIFO:
// el primero que entra es el primero que sale.
class ccola
{
private:
	cnodo* aPrimero; // Frente de la cola.
	cnodo* aUltimo;  // Final de la cola.
	int aM;          // Cantidad de nodos.
	bool aI;         // Estado de la última operación.

public:
	ccola();
	~ccola();

	int getaN() const;
	bool getaI() const;
	cnodo* getainicio() const;

	// Las cinco primitivas de la cola.
	void mCrear(int pdato);
	void mInsertar(int pdato);
	void mEliminar();
	void mVer() const;
	void mDestruir();
};
