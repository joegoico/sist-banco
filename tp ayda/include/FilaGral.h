#ifndef FILAGRAL_H
#define FILAGRAL_H
#include"Cliente.h"

template<typename T>
class FilaGral
{
    public:
        FilaGral();
        ~FilaGral();
        void agregarCliente(T persona);//agrega al cliente en la fila
        void atenderCliente();
        void crearFila();

    private:
        struct nodoCliente{
            T cliente;
            nodoCliente *sigCliente;
        }; nodoCliente *primero,*ultimo;
};
template <typename T> FilaGral<T>::FilaGral(){
    primero=nullptr;
    ultimo=nullptr;
}
template <typename T>void FilaGral<T>::agregarCliente(T persona){
    nodoCliente * aux=new nodoCliente;
    aux->cliente=persona;
    aux->sigCliente =nullptr;
    if(primero==nullptr){
        primero=aux;
        ultimo=aux;
    }
    else{
        aux->sigCliente=primero;
        primero->sigCliente=aux;
    }
}
template<typename T> void FilaGral<T>::atenderCliente(){
    nodoCliente* aux= new aux;
    aux=primero;
    while(aux->sigCliente!=ultimo)
        aux=aux->sigCliente;
    ultimo=aux;
    aux=aux->sigCliente;
    ultimo->sigCliente=nullptr;
    delete(aux)
}
#endif // FILAGRAL_H
