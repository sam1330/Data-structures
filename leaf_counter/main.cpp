#include <iostream>

using namespace std;

struct Nodo{
    int dato;
    Nodo *izq;
    Nodo *der;
};

int numeros[15] = {14, 15, 4, 9, 7, 18, 3, 5, 16, 4, 20, 17, 9, 14, 5};

/*Prototipos de funciones*/
Nodo *crearNodo(int);
void insertarNodo(Nodo *&, int);
void imprimir(Nodo *, int);
int contar(Nodo*);
void menu();

int main()
{
    menu();
    return 0;
}

void menu(){
        int raiz = 0, opcion = 0, hojas = 0;
        Nodo *arbol = NULL;
        do{
            cout << "<---¿Que Desea Hacer?--->\n 1-Llenar Arbol\n 2-Contar Hojas\n 3-Imprimir arbol\n 4-Salir\n";
            cin >> opcion;
            switch(opcion){
            case 1:
                for(int i = 0; i<15; i++){
                    insertarNodo(arbol, numeros[i]);
                }
                cout << "<----Nodos Insertados Correctamente En El Arbol--->\n\n";
            break;
            case 2:
                hojas = contar(arbol);
                cout << "<---Hay " << hojas << " hojas en el arbol--->\n\n";
            break;
            case 3:
                cout << "\n<-----------------ARBOL------------------->\n\n";
                imprimir(arbol, raiz);
            break;
            case 4:
                cout << "<---Gracias por usar mi programa--->\n";
                exit(0);
            break;
            default:
                cout <<"Ingrese una opcion Valida\n\n";
                menu();
            break;
        }
    }while(opcion != 4);
}

Nodo *crearNodo(int num){
    Nodo *nodo = new Nodo();
    nodo->dato = num;
    nodo->der = NULL;
    nodo->izq = NULL;
    return nodo;
}

void insertarNodo(Nodo *&arbol, int num){
    if(arbol == NULL){
        Nodo *nuevo = crearNodo(num);
        arbol = nuevo;
    }else{
        int raiz = arbol->dato;
        if(num < raiz){
            insertarNodo(arbol->izq, num);
        }else{
            insertarNodo(arbol->der, num);
        }
    }
}

int contar(Nodo *arbol){
    if (arbol == NULL){
        return 0;
    }else if (arbol->izq == NULL && arbol->der == NULL){
        return 1;
    }else{
        return contar(arbol->der)+contar(arbol->izq);
    }
}

void imprimir(Nodo *arbol, int raiz){
    if(arbol != NULL){
        imprimir(arbol->der, raiz+1);
        for(int i=0; i<raiz; i++){
            cout << " ";
        }
        cout << arbol->dato << endl;
        imprimir(arbol->izq, raiz+1);
    }
}


