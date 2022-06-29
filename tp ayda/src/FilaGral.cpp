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
    nodoCliente *aux;
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
void FilaGral::atenderCliente(){
    nodoCliente *aux;
    aux=ultimo;
    while(aux->sigCliente!=primero)
        aux=aux->sigCliente;
    primero=aux;
    aux=aux->sigCliente;
    primero->sigCliente=aux->sigCliente;
    delete(aux);
}
void FilaGral::abrirFilaEspecial(){
    this->esEspecial=true;
}
bool FilaGral::getFilaAbierta(){
    return this->estaAbierta;
}

//FilaGral::~FilaGral()
//{
    //dtor
//}
