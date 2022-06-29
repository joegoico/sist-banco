#include "FilaGral.h"
FilaGral::FilaGral(){
    primero=nullptr;
    ultimo=nullptr;
}
bool FilaGral::existeCliente(Cliente persona){
//retorna false si no existe el cliente, de lo contrario devuelve true
    nodoCliente *aux;
    aux=ultimo;
    if(ultimo==nullptr){
        while(aux!=nullptr && aux->cliente.nombre!=persona.nombre)
            aux=aux->sigCliente;
        if(aux=nullptr)
            return false;
        else
            return true;
    }
    else
        return false;
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
void FilaGral::abrirFilaEspecial(bool x){
    this->esEspecial=x;
    this->estaAbierta=x;
}
bool FilaGral::getFilaAbierta(){
    return this->estaAbierta;
}
//FilaGral::~FilaGral()
//{
    //dtor
//}
