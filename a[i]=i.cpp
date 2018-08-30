#include <iostream>

using namespace std;
int EsnumeroIgualaPosicion(int arreglo[],int tamanio, int inicio,int fin, int i){
    int pos;


    pos=(inicio+fin)/2;
    if(pos==3){
        pos++;
    }
    if(pos%2!=0&&pos!=3){
        pos++;
    }

// cout<<pos<<endl;
    if(pos<1){
cout<<"aca paila"<<arreglo[pos]<<endl;
        return -1;
    }

        else if(arreglo[pos]==i){
                cout<<"1";
            return 1;
        }


else{
       // cout<<pos;
        if(arreglo[pos]>i){
cout<<"acavoy"<<arreglo[pos]<<endl;
i++;
            return EsnumeroIgualaPosicion(arreglo,tamanio,inicio,pos++,i);
        }
        else{
cout<<"acavoy2"<<arreglo[pos]<<endl;
i++;
           return  EsnumeroIgualaPosicion(arreglo,tamanio,pos++,fin,i);
        }
}

}
int main()
{
    int tamanio,inicio=0,fin,numero;
    int i=0;
       cout << "Ingrese el tamaño del arreglo" << endl;
       cin>>tamanio;
       fin=(tamanio-1);
    int arreglo [tamanio];
    for(int j=0;j<tamanio;j++){
        cout<<"ingrese el numero del arreglo"<<endl;
        cin>>numero;
        arreglo[j]=numero;
    }

    EsnumeroIgualaPosicion(arreglo,tamanio,inicio,fin,i);

    return 0;
}
