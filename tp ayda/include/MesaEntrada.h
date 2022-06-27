#ifndef MESAENTRADA_H
#define MESAENTRADA_H
#include "Cliente.h"
#include"FilaGral.h"
class MesaEntrada
{
    private:
        struct Nodo{
            Cliente cliente;
            Nodo *sig;
        };
    public:
        Nodo *cursor;
        MesaEntrada();
        //~MesaEntrada();
        void agregarCliente(Cliente persona);//Agrega al cliente en el registro historico de clientes

};
MesaEntrada::MesaEntrada(){
   primero=nullptr;
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
#endif // MESAENTRADA_H
