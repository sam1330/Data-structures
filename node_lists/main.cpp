#include <iostream>

using namespace std;

using namespace std;
struct Nodo{
    int dato;
    Nodo *izq;
    Nodo *der;
};

int numeros[15] = {14, 15, 4, 9, 7, 18, 3, 5, 16, 4, 20, 17, 9, 14, 5}, orden[12];

/*Prototipos de funciones*/
Nodo *crearNodo(int);
void insertarNodo(Nodo *&, int);
void imprimir(Nodo *, int);
int descendente(Nodo*);
void menu();
bool verificar(int, int);
void ordenar(int []);

int main()
{

    menu();
    cout << "Hello world!" << endl;
    return 0;
}

void menu(){
        int raiz = 0, opcion = 0, hojas = 0;
        Nodo *arbol = NULL;
        do{
            cout << "<---¿Que Desea Hacer?--->\n 1-Llenar Arbol\n 2-Imprimir decendente\n 3-Imprimir Arbol\n 4-Salir\n";
            cin >> opcion;
            switch(opcion){
            case 1:
                for(int i = 0; i<15; i++){
                    if(!verificar(numeros[i], i)){
                        orden[i] = numeros[i];
                        insertarNodo(arbol, numeros[i]);
                    }
                }
                cout << "<----Nodos Insertados Correctamente En El Arbol--->\n\n";
            break;
            case 2:
                ordenar(orden);
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

bool verificar(int num, int index){
    for(int i = 0; i<index; i++){
        if(numeros[i] == num){
            return true;
        }
    }
    return false;
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

void ordenar(int num[12]){
    int temp;
    for(int i = 0; i<12; i++){
        for(int j = 0; j<i; j++){
            if(num[i] > num[j]){
                temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }
      cout << "<--- Nodos en manera Descendente--->\n\n";
      for(int i = 0; i<11; i++){
           cout << num[i] << ", ";
      }
      cout << "\n\n";
}
