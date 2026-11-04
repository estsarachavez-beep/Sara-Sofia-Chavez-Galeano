#include "clista.h"
#include <iostream>
using namespace std;

/*
 * POSCONDICION: Inicializa los atributos del objeto lista.
 *               aInicio, aP y aU en NULL, aN en 0 y aI en false.
 */
clista::clista() {
	aInicio = NULL; // Puntero inicial nulo
	aP = NULL;      // Primero nulo
	aU = NULL;      // Ultimo nulo
	aN = 0;         // Conteo inicial en cero
	aI = false;     // Bandera inicial en falso
}

/*
 * POSCONDICION: Llama al metodo mDestruir() para liberar toda la memoria dinamica asignada.
 */
clista::~clista() {
	mDestruir(); // Invoca la liberacion completa de la memoria
}

// Getters y Setters
int clista::getaN() { 
    return aN; 
}
void clista::setaN(int paN) {
    aN = paN; 
}
bool clista::getaI() { 
    return aI; 
}
void clista::setaI(bool paI) {
    aI = paI; 
}
cnodo* clista::getaInicio() { 
    return aInicio;
}
void clista::setaInicio(cnodo* paInicio) { 
    aInicio = paInicio;
}
cnodo* clista::getaP() { 
    return aP;
}
void clista::setaP(cnodo* paP) { 
    aP = paP;
}
cnodo* clista::getaU() { 
    return aU;
}
void cLista_setaU_dummy(clista* obj, cnodo* paU) { 
    obj->setaU(paU);
}
void clista::setaU(cnodo* paU) {
    aU = paU;
}

/*
 * PRECONDICION: La lista no debe haber sido creada (aInicio == NULL) y pTamano > 0.
 * POSCONDICION: Crea una lista dinamica inicializada con pTamano nodos con valor cero.
 */

void clista::mCrearVector(int pTamano) {  // Inicio del metodo mCrearVector
	if (aInicio == NULL && pTamano > 0) { // Verifica lista vacia y tamano valido
		for (int i = 1; i <= pTamano; i++) { // Bucle de repetición base 1
			cnodo* Q = new cnodo(0); // Reserva dinamica de nuevo nodo inicializado en 0
			if (aInicio == NULL) {   // Si es el primer nodo de la secuencia
				aInicio = Q;         // Asigna cabeza de la lista
				aP = Q;              // Asigna puntero Primero
				aU = Q;              // Asigna puntero Ultimo
			} else {
				aU->asing = Q; // Enlaza el ultimo nodo previo con el nuevo Q
				aU = Q;        // Mueve el puntero Ultimo al nuevo nodo
			} // Fin de verificacion de primer nodo
			aN++; // Incrementa el contador total de elementos
		} // Fin del ciclo for
		aI = true; 
	} else { 
		aI = false; 
	} // Fin del condicional
	return; // Retorna el control
} // Fin del metodo mCrearVector

/*
 * PRECONDICION: La lista debe estar creada y la posicion pk estar dentro de los limites (1 <= pk <= aN + 1).
 * POSCONDICION: Inserta pdato en la posicion pk (base 1) e incrementa aN.
 */
void clista::mInsertar(int pdato, int pk) { // Inicio del metodo mInsertar por posicion
	if (aInicio != NULL && pk >= 1 && pk <= (aN + 1)) { // Valida limites de posicion
		cnodo* Q = new cnodo(pdato); // Crea dinamicamente el nuevo nodo Q
		if (pk == 1) { // Caso 1: Repetición al inicio (cabeza)
			Q->asing = aInicio; // Enlaza Q con el inicio previo
			aInicio = Q;        // Actualiza inicio a Q
			aP = Q;             // Actualiza primero a Q
			if (aN == 0) { aU = Q; } // Si estaba vacia, Q es tambien el ultimo
		} else { // Caso 2: Insercion en medio o al final
			cnodo* Ant = aInicio; // Puntero auxiliar para recorrer la lista
			int i = 1; // Contador de iteracion
			while (i < (pk - 1)) { // Recorre hasta el nodo anterior a pk
				Ant = Ant->asing; // Avanza al siguiente nodo
				i++; // Incrementa contador
			} // Fin del recorrido
			Q->asing = Ant->asing; // Enlaza Q con el siguiente nodo
			Ant->asing = Q;        // Enlaza el nodo anterior con Q
			if (pk == (aN + 1)) { aU = Q; } // Si se inserto al final, actualiza aU
		} // Fin de casos de posicion
		aN++; // Incrementa el conteo de elementos
		aI = true;
	} else {
		aI = false; 
	} // Fin del condicional
	return; 
} // Fin del metodo mInsertar

/*
 * PRECONDICION: La lista debe existir y la posicion pk ser valida (1 <= pk <= aN).
 * POSCONDICION: Retorna el dato contenido en el nodo en la posicion pk.
 */
int clista::mver(int pk) { // Inicio del metodo mver por posicion
	int vx = -1; // Variable de respaldo para el valor consultado
	if (aInicio != NULL && pk >= 1 && pk <= aN) { // Valida existencia y posicion
		cnodo* Q = aInicio; // Puntero de recorrido inicializado en la cabeza
		int i = 1; // Contador de iteracion base 1
		while (i < pk) { // Recorre hasta alcanzar la posicion pk
			Q = Q->asing; // Avanza puntero al siguiente nodo
			i++; // Incrementa contador
		} // Fin del recorrido
		vx = Q->ainfo; // Copia el valor guardado en el nodo
		aI = true; 
	} else {
		aI = false; 
	} // Fin de validacion
	return vx; // Retorna el valor encontrado
} // Fin del metodo mver

/*
 * PRECONDICION: La lista debe poseer elementos y la posicion pk ser valida (1 <= pk <= aN).
 * POSCONDICION: Elimina el nodo de la posicion pk, reorganiza los enlaces y retorna su valor.
 */
int clista::mEliminar(int pk) { // Inicio del metodo mEliminar por posicion
	int vx = -1; // Variable para almacenar el dato extraido
	if (aInicio != NULL && pk >= 1 && pk <= aN) { // Verifica posicion valida
		cnodo* Q = NULL; // Puntero al nodo a borrar
		if (pk == 1) {   // Caso 1: Eliminar el primer nodo
			Q = aInicio; // Marca el nodo inicial
			aInicio = aInicio->asing; // Avanza el inicio al segundo nodo
			aP = aInicio; // Actualiza el puntero Primero
			if (aN == 1) { aU = NULL; } // Si era el unico elemento, limpia aU
		} else { // Caso 2: Eliminar un nodo intermedio o final
			cnodo* Ant = aInicio; // Puntero al nodo previo
			int i = 1;            // Contador base 1
			while (i < (pk - 1)) { // Recorre hasta la posicion previa a pk
				Ant = Ant->asing; // Avanza al siguiente nodo
				i++; // Incrementa iterador
			}
			Q = Ant->asing; // Marca el nodo a eliminar
			Ant->asing = Q->asing; // Puentea los enlaces saltando Q
			if (pk == aN) { aU = Ant; } // Si era el ultimo, actualiza aU
		} // Fin de casos
		vx = Q->ainfo; // Respalda el valor entero del nodo a borrar
		Q->asing = NULL; // Aísla el nodo
		delete Q; // Libera la memoria dinamica del nodo
		aN--; // Decrementa la cantidad de elementos
		aI = true; // Marca proceso exitoso
	} else { // Posicion fuera de limites
		aI = false; // Marca proceso fallido
	} // Fin del condicional
	return vx; // Retorna el entero eliminado
} // Fin del metodo mEliminar

/*
 * POSCONDICION: Libera todos los nodos de la lista e informa la suma total de sus valores.
 */
int clista::mDestruir() { // Inicio del metodo mDestruir
	int sumaAcumulada = 0; // Acumulador de datos para el retorno
	if (aInicio != NULL) { // Evalua si la lista contiene elementos
		while (aInicio != NULL) { // Recorre mientras existan nodos
			sumaAcumulada += mEliminar(1); // Suma el valor eliminado de la posicion 1
		} // Fin del bucle
		aInicio = NULL; // Garantiza inicio en NULL
		aP = NULL;      // Garantiza primero en NULL
		aU = NULL;      // Garantiza ultimo en NULL
		aN = 0;         // Reinicia el contador
		aI = true;      // Marca destruccion exitosa
	} else {
		aI = false; 
	} // Fin del condicional
	return sumaAcumulada; // Retorna la suma total de elementos destruidos
} // Fin del metodo mDestruir

/*
 * PRECONDICION: Las listas pV1 y pV2 deben estar creadas y tener igual cantidad de nodos (aN).
 * POSCONDICION: Suma los datos nodo a nodo de pV1 y pV2 asignando el resultado a la lista actual.
 */
void clista::mSumarV(clista& pV1, clista& pV2) { // Inicio del metodo mSumarV
	if (pV1.getaInicio() != NULL && pV2.getaInicio() != NULL && pV1.getaN() == pV2.getaN()) { // Valida tamanos
		mDestruir(); // Limpia la lista receptora
		mCrearVector(pV1.getaN()); // Crea la lista con el tamano requerido
		cnodo* N1 = pV1.getaInicio(); // Puntero de recorrido para pV1
		cnodo* N2 = pV2.getaInicio(); // Puntero de recorrido para pV2
		cnodo* NR = aInicio;          // Puntero de recorrido para lista actual
		while (N1 != NULL && N2 != NULL) { // Recorre ambas listas simultaneamente
			NR->ainfo = N1->ainfo + N2->ainfo; // Suma los valores elemento por elemento
			N1 = N1->asing; // Avanza puntero pV1
			N2 = N2->asing; // Avanza puntero pV2
			NR = NR->asing; // Avanza puntero resultado
		} // Fin de recorrido
		aI = true; 
	} else { 
		aI = false; 
	} // Fin de validacion
	return; // Retorna el control
} // Fin del metodo mSumarV

/*
 * PRECONDICION: La lista debe tener nodos (aInicio != NULL).
 * POSCONDICION: Ordena la lista en forma ascendente mediante el metodo directo (ordenamiento lineal).
 */
void clista::mOrdLineal() { // Inicio de mOrdLineal
	if (aInicio != NULL && aN > 1) { // Verifica minimo 2 elementos
		for (cnodo* i = aInicio; i != NULL; i = i->asing) { // Ciclo exterior de seleccion
			for (cnodo* j = i->asing; j != NULL; j = j->asing) { // Ciclo interior de comparacion
				if (i->ainfo > j->ainfo) { // Si el elemento i es mayor que j
					int aux = i->ainfo; // Intercambia datos de los nodos
					i->ainfo = j->ainfo;
					j->ainfo = aux;
				} // Fin del condicional de intercambio
			} // Fin del ciclo j
		} // Fin del ciclo i
		aI = true; 
	} else { 
		aI = (aInicio != NULL); // Mantiene estado de existencia
	} // Fin de la condicion
	return; // Retorna el control
} // Fin de mOrdLineal

/*
 * PRECONDICION: La lista debe tener nodos (aInicio != NULL).
 * POSCONDICION: Ordena la lista en forma ascendente mediante el algoritmo de Burbuja.
 */
void clista::mOrdBurbuja() { // Inicio de mOrdBurbuja
	if (aInicio != NULL && aN > 1) { // Evalua requerimiento minimo de nodos
		bool huboIntercambio = true; // Bandera para controlar pasadas
		while (huboIntercambio) { // Repite mientras existan ordenamientos pendientes
			huboIntercambio = false; // Reinicia bandera
			cnodo* Actual = aInicio; // Apunta al nodo inicial
			while (Actual->asing != NULL) { // Recorre hasta el penultimo nodo
				if (Actual->ainfo > Actual->asing->ainfo) { // Compara parejas consecutivas
					int aux = Actual->ainfo; // Intercambia datos de la pareja
					Actual->ainfo = Actual->asing->ainfo;
					Actual->asing->ainfo = aux;
					huboIntercambio = true; // Se realizo al menos un cambio
				} // Fin del condicional
				Actual = Actual->asing; // Avanza al siguiente par
			} // Fin del recorrido
		} // Fin del bucle de burbuja
		aI = true; // Operacion exitosa
	} else { // Caso lista vacia o de un elemento
		aI = (aInicio != NULL);
	} // Fin de verificacion
	return; // Retorna el control
} // Fin de mOrdBurbuja

/*
 * PRECONDICION: La lista debe estar previamente ordenada o ser creada.
 * POSCONDICION: Inserta pdato manteniendo el orden ascendente de la lista.
 */
void clista::mOrdInsercion(int pdato) { // Inicio de mOrdInsercion
	if (aInicio == NULL) { // Caso 1: Lista vacia
		mInsertar(pdato, 1); // Inserta en la primera posicion
	} else { // Caso 2: Buscar posicion ordenada
		cnodo* Q = aInicio; // Puntero de recorrido
		int pos = 1; // Contador de posicion base 1
		while (Q != NULL && Q->ainfo < pdato) { // Avanza mientras los datos sean menores
			Q = Q->asing; // Avanza al siguiente nodo
			pos++; // Incrementa posicion
		} // Fin de busqueda
		mInsertar(pdato, pos); // Inserta el dato en la posicion calculada
	} // Fin del condicional
	return; // Retorna el control
} // Fin de mOrdInsercion

/*
 * PRECONDICION: La lista debe tener nodos (aInicio != NULL).
 * POSCONDICION: Realiza una busqueda secuencial directa del valor pdato.
 *               Retorna la posicion base 1 donde se encuentra, o -1 si no existe.
 */
int clista::mBusquedaSecD(int pdato) { // Inicio de mBusquedaSecD
	int posEncontrada = -1; // Posicion resultado inicializada en no encontrado (-1)
	if (aInicio != NULL) { // Valida lista no vacia
		cnodo* Q = aInicio; // Puntero auxiliar de recorrido
		int posActual = 1; // Contador de posicion base 1
		while (Q != NULL) { // Recorre toda la lista
			if (Q->ainfo == pdato) { // Si encuentra el dato
				posEncontrada = posActual; // Guarda la posicion
				break; // Interrumpe la busqueda
			} // Fin de hallazgo
			Q = Q->asing; // Avanza al siguiente nodo
			posActual++; // Incrementa iterador
		} // Fin de recorrido
		aI = (posEncontrada != -1); // Marca true si lo encontro
	} else { // Lista vacia
		aI = false;
	} // Fin de verificacion
	return posEncontrada; // Retorna la posicion o -1
} // Fin de mBusquedaSecD

/*
 * PRECONDICION: La lista debe estar previamente ORDENADA de forma ascendente.
 * POSCONDICION: Realiza una busqueda secuencial optimizada. Retorna posicion (base 1) o -1.
 */
int clista::mBusquedaOrdenado(int pdato) { // Inicio de mBusquedaOrdenado
	int posEncontrada = -1; // Resultado por defecto
	if (aInicio != NULL) { // Valida lista activa
		cnodo* Q = aInicio; // Puntero auxiliar
		int posActual = 1; // Posicion base 1
		while (Q != NULL && Q->ainfo <= pdato) { // Avanza solo si los datos son <= pdato
			if (Q->ainfo == pdato) { // Si coincide el dato
				posEncontrada = posActual; // Asigna posicion
				break; // Sale de la busqueda
			} // Fin de coincidencia
			Q = Q->asing; // Avanza nodo
			posActual++; // Incremente posicion
		} // Fin de recorrido optimizado
		aI = (posEncontrada != -1); // Marca exito o fallo
	} else {
		aI = false;
	} // Fin del condicional
	return posEncontrada; // Retorna posicion o -1
} // Fin de mBusquedaOrdenado

/*
 * PRECONDICION: La lista debe estar previamente ORDENADA de forma ascendente.
 * POSCONDICION: Realiza busqueda binaria indexando los nodos mediante pos. Retorna posicion (base 1) o -1.
 */
int clista::mBusquedaBinaria(int pdato) { // Inicio de mBusquedaBinaria
	int posEncontrada = -1; // Inicializa sin hallar dato
	if (aInicio != NULL) { // Valida lista activa
		int izq = 1; // Limite izquierdo base 1
		int der = aN; // Limite derecho equivalente a la cantidad aN
		while (izq <= der) { // Ciclo de particion binaria
			int medio = izq + (der - izq) / 2; // Calculo del punto medio
			int valorMedio = mver(medio); // Obtiene el valor indexado de la mitad
			if (valorMedio == pdato) { // Si el elemento medio es el buscado
				posEncontrada = medio; // Asigna la posicion
				break; // Termina la busqueda
			} else if (valorMedio < pdato) { // Si el buscado esta en la mitad derecha
				izq = medio + 1; // Desplaza limite izquierdo
			} else { // Si el buscado esta en la mitad izquierda
				der = medio - 1; // Desplaza limite derecho
			} // Fin de comparacion
		} // Fin de ciclo binario
		aI = (posEncontrada != -1); // Marca bandera de estado
	} else {
		aI = false;
	} // Fin de validacion
	return posEncontrada; // Retorna la posicion encontrada o -1
} // Fin de mBusquedaBinaria
