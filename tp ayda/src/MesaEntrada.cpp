#include "MesaEntrada.h"
#include<iostream>
using namespace std;
MesaEntrada::MesaEntrada(){
   primero=nullptr;
}
Cliente MesaEntrada::listar(int montomin,int montomax,float &promedio){
    Nodo *aux=new Nodo;
    aux=cursor;
    int suma=0,cant=0;
    while (aux->sig!=nullptr)&&(aux->cliente.monto<montomax){
        if (aux->cliente.monto>montomin){
            /*En esta linea deberia imprimir por pantalla los datos del cliente*/
            suma+=aux->cliente.edad;
            cant++;
        }
        aux=aux->sig;
    }
    promedio=suma/cant;
}
void MesaEntrada::agregarCliente(Cliente persona){
    if(primero=nullptr){
        primero->cliente=persona;
        primero->sig=nullptr;
    }
    else if(persona.monto<primero->cliente.monto){
        Nodo *aux=new Nodo;
        aux->cliente=persona;
        aux->sig=primero;
        primero=aux;
    }
    else{
        Nodo *aux=new Nodo;
        Nodo *aux2=new Nodo;
        aux=primero;
        while(aux->sig!=nullptr) && (persona.monto>aux->sig->cliente.monto)
            aux=aux->sig;
        aux2->cliente=persona;
        aux2->sig=aux->sig;
        aux->sig=aux2;
    }
}
//MesaEntrada::~MesaEntrada()
//{
//    //dtor
//}

