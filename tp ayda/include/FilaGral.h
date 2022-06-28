#ifndef FILAGRAL_H
#define FILAGRAL_H
#include"Cliente.h"
class FilaGral
{
    public:
        FilaGral();
        //~FilaGral();
        void agregarCliente(Cliente persona);//agrega al cliente en la fila
        void crearFila();
        void atenderCliente(int nfila);
        int cantfilas;
        void agregarnodo(Cliente persona);
        void borrarnodo(nodoCliente *aux);
    private:
        struct nodoCliente{
            Cliente cliente;
            nodoCliente *sigCliente;
        }; nodoCliente *primero,*primero2,*primero3,*ultimo,*ultimo2,*ultimo3;
};
FilaGral::FilaGral(){
    primero=nullptr;
    ultimo=nullptr;
}
void FilaGral::borrarnodo(nodoCliente aux,nodoCliente paux){
    while(aux->sigCliente!=paux)
        aux=aux->sigCliente;
    paux=aux;
    aux=aux->sigCliente;
    paux->sigCliente=aux->sigCliente;
    delete(aux);
}
void FilaGral::agregarnodo(Cliente persona,nodoCliente paux,nodoCliente uaux){
    nodoCliente * aux=new nodoCliente;
    aux->cliente=persona;
    aux->sigCliente =nullptr;
    if(paux==nullptr){
        paux=aux;
        uaux=aux;
    }
    else{
        aux->sigCliente=uaux;
        uaux->sigCliente=aux;
    }
}
void FilaGral::agregarCliente(Cliente persona,int fila){
    if(fila==0)
        agregarnodo(persona,primero,ultimo)
    else if(fila==1)
        agregarnodo(persona,primero2,ultimo2)
    else
        agregarnodo(persona,primero3,ultimo3)
}
void FilaGral::atenderCliente(int nfila){
    if(nfila==1)
        borrarnodo(ultimo2,primero2)
    else if(nfila==2)
        borrarnodo(ultimo3,primero3)
    else
        borrarnodo(ultimo,primero);
}
void FilaGral::crearFila(int cantfilas){
   if (primero2==nullptr && ultimo2==nullptr){
        primero2=nullptr;
        ultimo2=nullptr;
   }
   else if(primero3==nullptr && ultimo3==nullptr){
        primero3=nullptr;
        ultimo3=nullptr;
   }
}
#endif // FILAGRAL_H
