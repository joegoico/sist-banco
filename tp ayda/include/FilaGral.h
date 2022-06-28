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
        void atenderCliente(Cliente persona, int nfila);
        int cantfilas;
        bool filaVacia();
    private:
        struct nodoCliente{
            Cliente cliente;
            nodoCliente *sigCliente;
        }; nodoCliente *primero,*ultimo;
};
#endif // FILAGRAL_H
