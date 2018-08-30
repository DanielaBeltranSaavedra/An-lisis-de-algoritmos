#include <ctime>
#include <time.h>
#include <iostream>
using namespace std;
int OrdenamientoContando (int arregloParaOrdenar[],int arregloContadores[],int tamanio, int posicionArregloOrdenar,int posicionArregloContadores ){
while(posicionArregloOrdenar<tamanio)
{

    if(arregloParaOrdenar[posicionArregloOrdenar]==posicionArregloContadores){
          //  cout<<posicionArregloContadores<<"cont"<<arregloParaOrdenar[posicionArregloOrdenar]<<endl;

        arregloContadores[posicionArregloContadores]++;
         posicionArregloOrdenar++;
         posicionArregloContadores=0;
    }
    else{
             //cout<<posicionArregloContadores<<"cont"<<arregloParaOrdenar[posicionArregloOrdenar]<<endl;
        return OrdenamientoContando(arregloParaOrdenar,arregloContadores,tamanio,posicionArregloOrdenar,posicionArregloContadores+1);
    }


}

}


void imprimir(int arregloContadores[],int posicionArregloContadores){
    for(int i=0;i<10001;i++){
        if(arregloContadores[i]!=0){
            for(int k=0;k<arregloContadores[i];k++){
            cout<<i;
            }
        }
    }

}

int main()
{
    int tamanio,numero,posicionArregloOrdenar=0,posicionArregloContadores=0;
    cout << "Ingrese el tamaño del arreglo" << endl;
       cin>>tamanio;
       int arregloParaOrdenar[tamanio];
       int arregloContadores[10001];
       for(int j=0;j<tamanio;j++){

        arregloParaOrdenar[j]=rand()%10000;

    }
for(int i=0;i<10001;i++){
      arregloContadores[i]=0;
}

 double ellapsedSeconds=0.0000000000000000000;
     srand(time(0));
    std::clock_t startTime,endTime;

    startTime = std::clock( );
 OrdenamientoContando (arregloParaOrdenar,arregloContadores, tamanio,  posicionArregloOrdenar, posicionArregloContadores );
imprimir(arregloContadores,posicionArregloContadores);
endTime=std::clock( );
    ellapsedSeconds=double(endTime-startTime)/double(CLOCKS_PER_SEC);
   cout <<"Tiempo que tardo:"<<ellapsedSeconds<<"seg"<<endl;
}
