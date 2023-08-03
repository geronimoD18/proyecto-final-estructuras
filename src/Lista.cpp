#include "Lista.h"

Lista::Lista() : _primer(NULL), _ultimo(NULL)
{

}

void Lista::agregar(Elemento* elemento)
{
    if (_primer == NULL)
    {
        _primer = elemento;
        _ultimo = elemento;
        elemento->setSiguiente(NULL);
    }
    else
    {
        _ultimo->setSiguiente(elemento);
        _ultimo = elemento;
        elemento->setSiguiente(NULL);
    }
}

bool Lista::eliminar(int indice)
{
    if (_primer == NULL)
    {
        return false;
    }

    if (indice == 0)
    {
        Elemento* temp = _primer;
        _primer = _primer->getSiguiente();
        delete temp;
        return true;
    }

    Elemento* anterior = _primer;
    int currentIndex = 0;
    while (currentIndex < indice - 1 && anterior->getSiguiente() != NULL)
    {
        anterior = anterior->getSiguiente();
        currentIndex++;
    }

    if (anterior->getSiguiente() == NULL)
    {
        return false;
    }

    Elemento* eliminarElemento = anterior->getSiguiente();
    anterior->setSiguiente(eliminarElemento->getSiguiente());
    delete eliminarElemento;
    return true;
}
