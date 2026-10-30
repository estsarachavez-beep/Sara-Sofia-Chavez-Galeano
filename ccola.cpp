#include "ccola.h"

ccola::ccola() : aPrimero(nullptr), aUltimo(nullptr), aM(0), aI(false) {}

ccola::~ccola()
{
    mDestruir();
}

int ccola::getaN() const { return aM; }
bool ccola::getaI() const { return aI; }
cnodo* ccola::getainicio() const { return aPrimero; }

// Primitiva 1: crea el primer elemento de la cola.
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

// Primitiva 2: inserta un elemento al final de la cola.
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

// Primitiva 3: elimina el elemento que está en el frente.
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

// Primitiva 4: muestra el elemento del frente sin eliminarlo.
void ccola::mVer() const
{
    if (aPrimero == nullptr)
    {
        std::cout << "Cola vacia.\n";
        return;
    }

    std::cout << "Elemento del frente: " << aPrimero->ainfo << '\n';
}

// Primitiva 5: libera todos los nodos de la cola.
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



