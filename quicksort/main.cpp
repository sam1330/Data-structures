#include <iostream>
#include <conio.h>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;
int a[100], b[60];
int pos_pivote(int array[], int izquierda, int derecha){
 int pivote = array[derecha], i = izquierda;
 for(int j = izquierda; j<derecha; j++){
    if(array[j]<pivote){
        swap(array[i], array[j]);
        i++;
    }
 }
 swap(array[derecha], array[i]);
 return i;
}
void quicksort(int array[], int izquierda, int derecha){
    int i;
    if(izquierda<derecha){
        i = pos_pivote(array, izquierda, derecha);
        quicksort(array, izquierda, i-1);
        quicksort(array, i+1, derecha);
    }
}
//para yo hacer lo demas tengo que entonces buscar la longitud del array,

bool checkrep(int n, int num[])
{
    for(int i=0; i<100; i++)
        if(n == num[i])
            return true;
    return false;
}
bool checkrepB(int n, int num[])
{
    for(int i=0; i<60; i++)
        if(n == num[i])
            return true;
    return false;
}
void random(){
    srand(time(NULL));
    int n;
    for(int i=0; i<100; i++)
    {
        do
            n = 1 + rand() % 200;
        while(checkrep(n, a));
        a[i] = n;
    }
    for(int i=0; i<60; i++)
    {
        do
            n = 1 + rand() % 200;
        while(checkrepB(n, b));
        b[i] = n;
    }
}
void intercalacion(int arrayA[], int arrayB[]){
int contadorA=0, contadorB=0, vector[160];
int a=0;
    do{
        vector[a] = arrayA[contadorA];
        contadorA++;
        a++;
    }while(contadorA<100);
    do{
        vector[a] = arrayB[contadorB];
        contadorB++;
        a++;
    }while(contadorB<60);
    quicksort(vector, 0, 159);
    cout <<"\n array por intercalacion\n";
    for(int i=0; i<160; i++){
        cout << vector[i] << " ";
    }
}
int main()
{
    random();
    quicksort(a, 0, 99);
    quicksort(b, 0, 59);
    intercalacion(a, b);

    return 0;
}
