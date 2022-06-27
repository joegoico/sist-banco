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
        void crearFila();
        void atenderCliente();

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
    ultimo->sigCliente=aux->sigCliente;
    delete(aux)
}
template <typename T> void FilaGral<T>::crearFila(){
    string op, ec;
    cout<<"a continuacion ingrese el tipo de operacion";
    cin>>op;
    cout<<"ingres t si es cliente, y f si no es cliente";
    cin>>ec;


}
#endif // FILAGRAL_H
