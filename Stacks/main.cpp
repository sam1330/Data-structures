#include <iostream>

using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;
};
void insertarPila(Nodo *&, int);
void sacarPila(Nodo *&, int &);
void mostrarPila(Nodo *);
int main()
{
    int dato;
    Nodo *pila = NULL;
    cout << "Ingrese Valor\n";
    cin>>dato;
    insertarPila(pila, dato);
    cout << "\nIngrese Otro Valor\n";
    cin>>dato;
    insertarPila(pila, dato);
    cout<<"\nSacando los datos de la pila\n";
    while(pila != NULL){
        sacarPila(pila, dato);
        if(pila != NULL){cout<<dato<<", ";}
        else{cout<<dato<<".";}
    }
    return 0;
}

void insertarPila(Nodo *&pila, int n){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = pila;
    pila = nuevo_nodo;
    cout<<"Pila ingresada";
}

void sacarPila(Nodo *&pila, int &n){
     Nodo *aux = pila;
     n = aux->dato;
     pila = aux->siguiente;
     delete aux;
}

