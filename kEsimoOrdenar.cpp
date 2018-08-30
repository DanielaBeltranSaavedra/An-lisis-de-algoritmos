#include <ctime>
#include <time.h>
#include <iostream>
using namespace std;

int arreglosDivididos(int *arreglo, int inicio, int fin){
    int derecha,pivote,izquierda;
    derecha=inicio;
    pivote=arreglo[inicio];
    izquierda=fin;
   int auxiliar;
    while(derecha<izquierda){
       if((derecha<izquierda)&&(arreglo[derecha]<=pivote))
            derecha++;
    if (arreglo[izquierda]>pivote)
            izquierda--;
        if (derecha<izquierda){
            auxiliar=arreglo[derecha];
            arreglo[derecha]=arreglo[izquierda];
            arreglo[izquierda]=auxiliar;
        }
    }
    auxiliar=arreglo[izquierda];
    arreglo[izquierda]=arreglo[inicio];
    arreglo[inicio]=auxiliar;
    return izquierda;
}
void ordenar(int *arreglo, int inicio, int fin){
    int pivote;
    if (inicio<fin){
        pivote=arreglosDivididos(arreglo,inicio,fin);
        ordenar(arreglo,inicio,(pivote-1));
        ordenar(arreglo,(pivote+1),fin);
    }
}
int main ()
{

    int tamanio;
    cout<<"Ingrese tamanio de los numeros a ordenar"<<endl;
    cin>>tamanio;
    int k,arregloNumerosOrdenar[tamanio];
    cout<<"Ingrese el k numero"<<endl;
    cin>>k;
    double ellapsedSeconds=0.0000000000000000000;
     srand(time(0));
    std::clock_t startTime,endTime;
    for (int i=0;i<tamanio;i++){
        arregloNumerosOrdenar[i]=rand()%100;
        cout<<arregloNumerosOrdenar[i]<<" ";
    }

    startTime = std::clock( );
    cout<<"K_ecimo ordenado"<<endl;
    ordenar(arregloNumerosOrdenar,0,(tamanio--));
    for (int i=0;i<=tamanio;i++){
        cout<<arregloNumerosOrdenar[i]<<" ";
    }
    endTime=std::clock( );
    ellapsedSeconds=double(endTime-startTime)/double(CLOCKS_PER_SEC);
   cout <<"Tiempo que tardo:"<<ellapsedSeconds<<"seg"<<endl;
    cout<<"El numero k es"<<arregloNumerosOrdenar[k]<<endl;
}

