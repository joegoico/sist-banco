#ifndef MESAENTRADA_H
#define MESAENTRADA_H
#include "Cliente.h"
class MesaEntrada
{
    private:
        struct Nodo{
            Cliente cliente;
            Nodo *sig;
        };
        Nodo *cursor;
    public:
        MesaEntrada();
        //~MesaEntrada();
        //void listar(montomin,montomax);
        void agregarCliente(Cliente persona);//Agrega al cliente en el registro historico de clientes

};

#endif // MESAENTRADA_H
