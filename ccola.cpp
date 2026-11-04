#include "ccola.h" // Declaración de la clase ccola y del tipo cnodo.

/**
 * @file ccola.cpp
 * @brief Implementación de las operaciones de una cola enlazada FIFO.
 *
 * La cola conserva punteros al frente y al final. Insertar agrega nodos al
 * final, eliminar retira el nodo del frente, y destruir libera toda la memoria
 * reservada dinámicamente.
 */

// Inicializa los extremos en nullptr, el contador en cero y el estado en falso.
ccola::ccola() : aPrimero(nullptr), aUltimo(nullptr), aM(0), aI(false) {}

// Al salir de alcance, libera los nodos que todavía pertenezcan a la cola.
ccola::~ccola()
{
    mDestruir();
}

// Devuelve cuántos nodos están almacenados en la cola.
int ccola::getaN() const { return aM; }

// Devuelve el resultado (éxito o fallo) de la última operación modificadora.
bool ccola::getaI() const { return aI; }

// Devuelve el puntero al frente de la cola, o nullptr si está vacía.
cnodo* ccola::getainicio() const { return aPrimero; }

// Primitiva 1: crea el primer elemento únicamente si la cola está vacía.
void ccola::mCrear(int pdato)
{
    if (aPrimero != nullptr)
    {
        aI = false; // La cola ya tiene elementos.
        return;
    }

    aPrimero = new cnodo(pdato);
    aUltimo = aPrimero;
    aM = 1;
    aI = true;
}

// Primitiva 2: inserta un elemento nuevo al final, manteniendo el orden FIFO.
void ccola::mInsertar(int pdato)
{
    if (aPrimero == nullptr)
    {
        aI = false; // Primero debe utilizarse mCrear.
        return;
    }

    cnodo* nuevo = new cnodo(pdato);
    aUltimo->asig = nuevo;
    aUltimo = nuevo;
    ++aM;
    aI = true;
}

// Primitiva 3: elimina el nodo del frente y actualiza ambos extremos si queda vacía.
void ccola::mEliminar()
{
    if (aPrimero == nullptr)
    {
        aI = false; // No se puede eliminar de una cola vacía.
        return;
    }

    cnodo* eliminado = aPrimero;
    aPrimero = aPrimero->asig;
    delete eliminado;
    --aM;

    // Si se eliminó el último elemento, ambos extremos quedan vacíos.
    if (aPrimero == nullptr)
        aUltimo = nullptr;

    aI = true;
}

// Primitiva 4: muestra el dato del frente sin modificar ni retirar la cola.
void ccola::mVer() const
{
    if (aPrimero == nullptr)
    {
        std::cout << "Cola vacia.\n";
        return;
    }

    std::cout << "Elemento del frente: " << aPrimero->ainfo << '\n';
}

// Primitiva 5: recorre la cola, elimina sus nodos y reinicia sus atributos.
void ccola::mDestruir()
{
    while (aPrimero != nullptr)
    {
        cnodo* eliminado = aPrimero;
        aPrimero = aPrimero->asig;
        delete eliminado;
    }

    aUltimo = nullptr;
    aM = 0;
    aI = true;
}
