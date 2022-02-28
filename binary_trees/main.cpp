#include <iostream>

using namespace std;
struct Nodo{
    int dato;
    Nodo *izq;
    Nodo *der;
};

Nodo *arbol = NULL;

Nodo *crearNodo(int);
void insertarNodo(Nodo *&, int);
void mostrarArbol(Nodo *arbol, int);
bool buscar(Nodo *, int);
int main()
{
    int dato, opcion, cont = 0;
    do{
    cout << "Que desea hacer?\n 1-Insertar\n2-Imprimir\n4-Salir" << endl;
    cin >> opcion;
    switch(opcion){
     case 1: cout << "Inserte un numero\n";cin >> dato;insertarNodo(arbol, dato);
     break;
     case 2: mostrarArbol(arbol, cont);
     break;
    }
    }while(opcion != 4);

    return 0;
}


Nodo *crearNodo(int n){
    Nodo *nuevo_nodo = new Nodo();

    nuevo_nodo->dato = n;
    nuevo_nodo->der = NULL;
    nuevo_nodo->izq = NULL;

    return nuevo_nodo;
}

void insertarNodo(Nodo *&arbol, int n){
    if(arbol == NULL){
        Nodo *nuevo_nodo = crearNodo(n);
        arbol = nuevo_nodo;
    }else{
        int valorRaiz = arbol->dato;
        if(n < valorRaiz){
            insertarNodo(arbol->izq, n);
        }else{
            insertarNodo(arbol->der, n);
        }
    }
}

void mostrarArbol(Nodo *arbol, int cont){
    if(arbol == NULL){
    //cout << "No hay nodos en el arbol\n";

    }else{
        mostrarArbol(arbol->der, cont+1);
        for(int i=0; i<cont; i++){
            cout << "  ";
        }
        cout << arbol->dato << endl;
        mostrarArbol(arbol->izq, cont+1);
    }
}

bool buscar(Nodo *arbol, int n){
    if(arbol == NULL){
        return false;
    }else if(arbol->dato == n){
        return true;
    }else if(n < arbol->dato){
        return buscar(arbol->izq, n);
    }else{
        return buscar(arbol->der, n);
    }
}
