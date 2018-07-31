#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <sstream>
using namespace std;
void CrearArchivoNumeros(char *nombreArchivo,int cantidadNumeros)
{
    int numeroImprimir;
    ofstream archivo;
    archivo.open(nombreArchivo, ios::out);
    for(int i=0; i<cantidadNumeros; i++)
    {
        numeroImprimir=rand()%1000000;
        if(i==(cantidadNumeros-1)){
            archivo<<numeroImprimir;
        }
        else {
        archivo<<numeroImprimir<<" ";
        }
    }
    archivo.close();


}
void OrdenamientoSeleccion(char *nombreArchivo,int cantidadNumeros)
{
    ifstream archivo;
    char numero[5000];
    int numeroAuxiliar;
    int arregloNumeros[cantidadNumeros];
    archivo.open(nombreArchivo, ios::in);
    if (!archivo.good())
    {
        cout<<"No se pudo abrir el archivo, verifique si el archivo está creado "<<endl;
    }
      for(int i=0; i<cantidadNumeros; i++){
        archivo.getline(numero,5000,' ');
        numeroAuxiliar=atoi(numero);

                arregloNumeros[i]=numeroAuxiliar;

        }
     archivo.close();
int minimo,auxiliar;
    for (int i=0; i<cantidadNumeros-1; i++)
    {
        minimo=i;
        for(int j=i+1; j<cantidadNumeros; j++)
            if(arregloNumeros[minimo] > arregloNumeros[j])
                minimo=j;
        auxiliar=arregloNumeros[minimo];
        arregloNumeros[minimo]=arregloNumeros[i];
        arregloNumeros[i]=auxiliar ;
    }
   /*  for ( int i= 0; i < cantidadNumeros; ++i ){
    cout << arregloNumeros[ i ]<<endl;
    }*/

}

int main()
{
    char nombreArchivo[200];
    int cantidadNumeros;
    cout << "Ingrese el nombre del archivo" << endl;
    cin>>nombreArchivo;
    strcat(nombreArchivo,".txt");
    cout<<"Ingrese la cantidad de numeros que desea tener en el archivo"<<endl;
    cin>>cantidadNumeros;
    CrearArchivoNumeros(nombreArchivo,cantidadNumeros);
    double ellapsedSeconds;
  std::clock_t startTime,endTime;
  startTime = std::clock( );
     OrdenamientoSeleccion(nombreArchivo,cantidadNumeros);
     endTime   = std::clock( );
     ellapsedSeconds = double( endTime - startTime ) / double( CLOCKS_PER_SEC );
     ofstream archivo;
    archivo.open(nombreArchivo, ios::out);

archivo<< "Finalizado. Demoró " << ellapsedSeconds << " segundos" << std::endl;

}
