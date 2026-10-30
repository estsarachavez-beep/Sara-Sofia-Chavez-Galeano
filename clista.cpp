#include "clista.h"

clista::clista() : ainicio(nullptr), aN(0), aI(false) {}

clista::~clista()
{
    mDestruir();
}

int clista::getaN() const { return aN; }
bool clista::getaI() const { return aI; }
cnodo* clista::getainicio() const { return ainicio; }

// Primitiva 1: crea el primer nodo de la lista.
void clista::mCrear(int pdato)
{
    if (ainicio != nullptr)
    {
        aI = false; // La lista ya contiene elementos.
        return;
    }

    ainicio = new cnodo(pdato);
    aN = 1;
    aI = true;
}

// Primitiva 2: inserta un nodo al inicio de la lista.
void clista::mInsertar(int pdato)
{
    if (ainicio == nullptr)
    {
        aI = false; // Primero debe utilizarse mCrear.
        return;
    }

    cnodo* nuevo = new cnodo(pdato);
    nuevo->asig = ainicio;
    ainicio = nuevo;
    ++aN;
    aI = true;
}

// Primitiva 3: elimina el nodo de la posición p (la primera es 1).
void clista::mEliminar(int p)
{
    if (p < 1 || p > aN || ainicio == nullptr)
    {
        aI = false;
        return;
    }

    cnodo* eliminado = ainicio;

    if (p == 1)
    {
        ainicio = ainicio->asig;
    }
    else
    {
        cnodo* anterior = ainicio;
        for (int i = 1; i < p - 1; ++i)
            anterior = anterior->asig;

        eliminado = anterior->asig;
        anterior->asig = eliminado->asig;
    }

    delete eliminado;
    --aN;
    aI = true;
}

// Primitiva 4: muestra el dato de la posición p sin modificar la lista.
void clista::mVer(int p) const
{
    if (p < 1 || p > aN || ainicio == nullptr)
    {
        std::cout << "Posicion no valida o lista vacia.\n";
        return;
    }

    const cnodo* actual = ainicio;
    for (int i = 1; i < p; ++i)
        actual = actual->asig;

    std::cout << "Elemento en posicion " << p << ": "
              << actual->ainfo << '\n';
}

// Primitiva 5: destruye la lista y libera toda la memoria dinámica.
void clista::mDestruir()
{
    while (ainicio != nullptr)
    {
        cnodo* eliminado = ainicio;
        ainicio = ainicio->asig;
        delete eliminado;
    }

    aN = 0;
    aI = true;
}