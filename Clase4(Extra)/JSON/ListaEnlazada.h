#ifndef LISTA_ENLAZADA_H
#define LISTA_ENLAZADA_H

#include "Usuario.h"


struct Nodo {
    Usuario* usuario;
    Nodo* siguiente;

    Nodo(Usuario* usuario) {
        this->usuario = usuario;
        this->siguiente = nullptr;
    }
};

class ListaEnlazada {
private:
    Nodo* cabeza;

public:
    ListaEnlazada() {
        cabeza = nullptr;
    }

    void insertar(Usuario* usuario) {
        Nodo* nuevoNodo = new Nodo(usuario);
        if (cabeza == nullptr) {
            cabeza = nuevoNodo;
        } else {
            Nodo* temp = cabeza;
            while (temp->siguiente != nullptr) {
                temp = temp->siguiente;
            }
            temp->siguiente = nuevoNodo;
        }
    }

    void mostrar() {
        Nodo* temp = cabeza;
        while (temp != nullptr) {
            cout << "Nombre: " << temp->usuario->nombre << ", Edad: " << temp->usuario->edad << endl;
            temp = temp->siguiente;
        }
    }

    ~ListaEnlazada() {
        Nodo* actual = cabeza;
        while (actual != nullptr) {
            Nodo* siguiente = actual->siguiente;
            delete actual;
            actual = siguiente;
        }
    }
};

#endif
