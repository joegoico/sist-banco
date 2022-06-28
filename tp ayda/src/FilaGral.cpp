#include "FilaGral.h"

FilaGral::FilaGral(){
    primero=nullptr;
    ultimo=nullptr;
}
bool FilaGral::filaVacia(){
    if (primero==nullptr && ultimo==nullptr)
        return true;
    else
        return false;
}
void FilaGral::agregarCliente(Cliente persona){
    nodoCliente * aux=new nodoCliente;
    aux->cliente=persona;
    aux->sigCliente =nullptr;
    if(primero==nullptr){
        primero=aux;
        ultimo=aux;
    }
    else{
        aux->sigCliente=ultimo;
        ultimo->sigCliente=aux;
    }
}
void FilaGral::atenderCliente(int nfila){
    while(aux->sigCliente!=primero)
        aux=aux->sigCliente;
    primero=aux;
    aux=aux->sigCliente;
    primero->sigCliente=aux->sigCliente;
    delete(aux);
}
void FilaGral::crearFila(int cantfilas){
   if (primero==nullptr && ultimo==nullptr)
        agregarnodo(persona,primero,ultimo);
}


//FilaGral::~FilaGral()
//{
    //dtor
//}
