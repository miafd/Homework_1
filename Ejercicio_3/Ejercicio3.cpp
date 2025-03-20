#include <iostream>
#include <memory>

using namespace std;

// Definición de un nodo
struct Nodo {
    int valor;
    unique_ptr<Nodo> siguiente;
};

// Definición de la lista enlazada
struct ListaEnlazada {
    unique_ptr<Nodo> cabeza = nullptr; // Puntero al primer nodo de la lista
    Nodo* cola = nullptr;              // Puntero al último nodo de la lista
};

// Función para crear un nodo
unique_ptr<Nodo> create_nodo(int valor) {
    unique_ptr<Nodo> nodo = make_unique<Nodo>();
    nodo->valor = valor;
    return nodo;
}

//Función para insertar un nodo al frente de la lista
void push_front(ListaEnlazada &lista, int valor) {
    unique_ptr<Nodo> nodo = create_nodo(valor);
    nodo->siguiente = move(lista.cabeza);
    lista.cabeza = move(nodo);
    if (!lista.cola) {
        lista.cola = lista.cabeza.get();
    }
}

//Función para insertar un nodo al final de la lista
void push_back(ListaEnlazada &lista, int valor) {
    unique_ptr<Nodo> nodo = create_nodo(valor);
    if (!lista.cola) {
        lista.cabeza = move(nodo);
        lista.cola = lista.cabeza.get();
    } else {
        lista.cola->siguiente = move(nodo);
        lista.cola = lista.cola->siguiente.get();
    }
}

//Función para insertar un nodo en una posición específica
void insert(ListaEnlazada &lista, int valor, size_t index) {
    if (index == 0) {
        push_front(lista, valor);
    } else {
        unique_ptr<Nodo>* actual = &lista.cabeza;
        size_t i = 0;
        for (; i < index - 1 && *actual; i++) {
            actual = &((*actual)->siguiente);
        }
        if (*actual) {
            unique_ptr<Nodo> nodo = create_nodo(valor);
            nodo->siguiente = move((*actual)->siguiente);
            (*actual)->siguiente = move(nodo);
            if (!(*actual)->siguiente->siguiente) { // Si el nuevo nodo es el último
                lista.cola = (*actual)->siguiente.get();
            }
        } else {
            cerr << "Índice fuera de rango. Insertando " << valor << " al final de la lista." << endl;
            push_back(lista, valor);
        }
    }
}


//Función para borrar un nodo en una posición específica
void erase(ListaEnlazada &lista, size_t index) {
    if (!lista.cabeza) {
        cerr << "La lista está vacía. No se puede borrar." << endl;
        return;
    }

    if (index == 0) {
        lista.cabeza = move(lista.cabeza->siguiente);
        if (!lista.cabeza) {
            lista.cola = nullptr;
        }
    } else {
        unique_ptr<Nodo>* actual = &lista.cabeza;
        size_t i = 0;
        for (; i < index - 1 && (*actual)->siguiente; i++) {
            actual = &((*actual)->siguiente);
        }
        if ((*actual)->siguiente) {
            if ((*actual)->siguiente.get() == lista.cola) {
                lista.cola = (*actual).get();
            }
            (*actual)->siguiente = move((*actual)->siguiente->siguiente);
        } else {
            cerr << "Índice fuera de rango. Borrando el último nodo." << endl;
            if (lista.cola == lista.cabeza.get()) {
                lista.cabeza = nullptr;
                lista.cola = nullptr;
            } else {
                actual = &lista.cabeza;
                while ((*actual)->siguiente.get() != lista.cola) {
                    actual = &((*actual)->siguiente);
                }
                (*actual)->siguiente = nullptr;
                lista.cola = (*actual).get();
            }
        }
    }
}

//Función para imprimir la lista 
void print_list (ListaEnlazada &lista) {
    cout << "Lista resultante: ";
    unique_ptr<Nodo>* actual = &lista.cabeza;
    while (*actual) {
        cout << (*actual)->valor << " -> ";
        actual = &((*actual)->siguiente);
    }
    cout << "nullptr" << endl; // Indicar el final de la lista
}


int main(){
    ListaEnlazada lista;

    // Insertar elementos en la lista
    cout << "=== Insertando elementos en la lista ===" << endl;

    cout << "Insertando 10 al frente." << endl;
    push_front(lista,10); 

    cout << "Insertando 20 al frente." << endl;
    push_front(lista,20); 

    cout << "Insertando 30 al final." << endl;
    push_back(lista,30); 

    cout << "Insertando 40 en la posición 1." << endl;
    insert(lista,40,1); 

    cout << "Insertando 50 en una posición fuera de rango (índice 10)." << endl;
    insert(lista,50,10); 

    cout << "=== Imprimo la lista luego de las inserciones ===" << endl;
    print_list(lista); 

    cout << "=== Borrando elementos de la lista ===" << endl;

    cout << "Borrando el 10 (posición 2)" << endl;
    erase(lista,2); 

    cout << "Borrando un elemento fuera de rango (índice 10)" << endl;
    erase(lista,10); 

    cout << "=== Imprimo la lista luego de las eliminaciones ===" << endl;
    print_list(lista);

    return 0;
}

