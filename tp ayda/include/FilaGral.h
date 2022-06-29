#ifndef FILAGRAL_H
#define FILAGRAL_H
#include"Cliente.h"
class FilaGral
{
    public:
        FilaGral();
        //~FilaGral();
        void agregarCliente(Cliente persona);//agrega al cliente en la fila
        void abrirFilaEspecial();
        void atenderCliente();
        int cantfilas;
        bool filaVacia();
        bool getFilaAbierta();
    private:
        struct nodoCliente{
            Cliente cliente;
            nodoCliente *sigCliente;
        }; nodoCliente *primero,*ultimo;
        bool esEspecial=false, estaAbierta = true;
};
#endif // FILAGRAL_H
