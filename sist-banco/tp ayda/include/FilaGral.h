#ifndef FILAGRAL_H
#define FILAGRAL_H
#include"Cliente.h"
class FilaGral
{
    public:
        FilaGral();
        //~FilaGral();
        void agregarCliente(Cliente persona);//agrega al cliente en la fila
        void abrirFilaEspecial(bool x);
        void atenderCliente();
        bool existeCliente(Cliente persona);
        int cantfilas;
        bool filaVacia();
        bool getFilaAbierta();
    private:
        struct nodoCliente{
            Cliente cliente;
            nodoCliente *sigCliente;
        }; nodoCliente *primero,*ultimo;
        bool esEspecial=false, estaAbierta = false;
};
#endif // FILAGRAL_H
