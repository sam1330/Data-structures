#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};
//Mis Prototipos
void insertar(Nodo*&, Nodo*&, int);
void suprimir(Nodo*&, Nodo*&, int &);
bool cola_vacia(Nodo*);

int main() {
    Nodo* frente = NULL;
    Nodo* fin = NULL;

    int dato, continuar, eliminar;

    do {
        cout << "Digite un numero: \n";
        cin >> dato;
        insertar(frente, fin, dato);
        cout << "Elemento inserado a cola correctamente \n";

        cout << "Desea continuar insertando  \n 1) Si \n 2) No \n \n";
        cin >> continuar;


    } while (continuar == 1);


    cout << "\n Eliminando los nodos de la cola ";
    while (frente != NULL) {

        suprimir(frente, fin, dato);

        if (frente != NULL) {
            cout << dato << " , ";
        }
        else {
            cout << dato << " \n ....Cola Vacia..... ";
        }


    }

    system("pause");
    return 0;
}

//insertar elementos en la cola/
void insertar(Nodo*& frente, Nodo*& fin, int n) {
    Nodo* Nuevo_nodo = new Nodo();

    Nuevo_nodo->dato = n;
    Nuevo_nodo->siguiente = NULL;

    if (cola_vacia(frente)) {
        frente = Nuevo_nodo;
    }
    else {
        fin->siguiente = Nuevo_nodo;
    }
    fin = Nuevo_nodo;

}//elimina los elementos de la Cola
void suprimir(Nodo*& frente, Nodo*& fin, int &n){
    n = frente->dato;
    Nodo *aux = frente;

    if (frente == fin) {
        frente = NULL;
        fin = NULL;
    }
    else {
        frente = frente->siguiente;
    }
    delete aux;
}
//determinar si la cola esta vacia
bool cola_vacia(Nodo* frente) {
    return(frente == NULL) ? true : false;
}
