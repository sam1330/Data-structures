#include <iostream>

using namespace std;

int mayor = 0, index = 0, mayores[14];
int derecha(int array[], int tam){
    int suma = 0;

    for(int j=tam/2; j>=0; j--){
            index++;
        cout << "# " << index << "   ";
        for(int i = 0; i<=j; i++){
            suma = suma + array[i];
            cout << array[i] << " + ";
        }

        cout << " = " << suma << endl;
        if(mayor < suma){
            mayor = suma;
            mayores[index] = mayor;
        }
        suma=0;
    }
    for(int j=0; j<tam/2; j++){
        index++;
        cout << "# " << index << "   ";
        for(int i = tam/2; i>=j; i--){
            suma = suma + array[i];
            cout << array[i] << " + ";
        }

        cout << " = " << suma << endl;
        if(mayor < suma){
            mayor = suma;
            mayores[index] = mayor;
        }
        suma=0;
    }
    return suma;
}
int izquierda(int array[], int tam){
    int suma;

    for(int j=tam; j>tam/2; j--){
        index++;
        cout << "# " << index << "   ";
        for(int i = tam/2; i<=j; i++){
            suma = suma + array[i];
            cout << array[i] << " + ";
        }

        cout << " = " << suma << endl;
        if(mayor < suma){
            mayor = suma;
            mayores[index] = mayor;
        }
        suma=0;
    }
    return suma;
}

int centro(int array[], int tam){
    int suma;
    for(int j=2; j<tam-2; j++){
        index++;
        cout << "# " << index << "   ";
        for(int i = j; i<=tam-2; i++){
            suma = suma + array[i];
            cout << array[i] << " + ";
        }
        cout << " = " << suma << endl;
        if(mayor < suma){
            mayor = suma;
            mayores[index] = mayor;
        }
        suma=0;
    }
    return suma;
}
int main()
{

    int array[] = {4,-3,5,-2,-1,2,6,-2}, tam = 7, indexMayor=0;
    derecha(array, tam);
    izquierda(array, tam);
    centro(array, tam);

    for(int i = 0; i<index; i++){
        if(indexMayor < mayores[i]){
            indexMayor = i;
        }
    }
    cout << "La maxima Subsuma es la Numero: " << indexMayor << endl;
    cout << "Que es igual a: " << mayor;
    return 0;
}


