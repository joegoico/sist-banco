#include "MesaEntrada.h"
MesaEntrada::MesaEntrada(){
   cursor=nullptr;
}
void MesaEntrada::agregarCliente(Cliente persona){
    if(cursor==nullptr){
        cursor->cliente=persona;
        cout<<"hola";
        cursor->sig =nullptr;
    }
    else if(persona.monto<cursor->cliente.monto){
        Nodo *aux;
        aux->cliente=persona;
        aux->sig=cursor;
        cursor=aux;
    }
    else{
        Nodo *aux;
        Nodo *aux2;
        aux=cursor;
        while(aux->sig!=nullptr && persona.monto>aux->sig->cliente.monto)
            aux=aux->sig;
        aux2->cliente=persona;
        aux2->sig=aux->sig;
        aux->sig=aux2;
    }
}
/*Cliente MesaEntrada::listar(int montomin,int montomax,float &promedio){
    Nodo *aux=new Nodo;
    aux=cursor;
    int suma=0,cant=0;
    while (aux->sig!=nullptr)&&(aux->cliente.monto<montomax){
        if (aux->cliente.monto>montomin){
            En esta linea deberia imprimir por pantalla los datos del cliente
            suma+=aux->cliente.edad;
            cant++;
        }
        aux=aux->sig;
    }
    promedio=suma/cant;
}*/
//MesaEntrada::~MesaEntrada()
//{
//    //dtor
//}

