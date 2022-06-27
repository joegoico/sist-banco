#ifndef MESAENTRADA_H
#define MESAENTRADA_H
#include "Cliente.h"
#include"FilaGral.h"
template<typename T>
class MesaEntrada
{
    private:
        struct Nodo{
            T cliente;
            Nodo *menores;
            Nodo *Mayores;
        }; Nodo *primero;
        FilaGral<Cliente> fclientes;
    public:
        MesaEntrada(T persona);
        //~MesaEntrada();
        void agregarCliente(Nodo* primero,T persona);//agrega al cliente en el registro historico de clientes

};
template<typename T>MesaEntrada<T>::MesaEntrada(T persona){
    primero->cliente=persona;
    primero->Mayores =nullptr;
    primero->menores=nullptr;
}
template<typename T>void MesaEntrada<T>::agregarCliente(Nodo *primero,T persona){
    if(primero=nullptr){
        primero->cliente=persona;
        primero->Mayores=nullptr;
        primero->menores=nullptr;
        fclientes.atenderCliente(persona);
        //tengo q llamar al metodo de la fila q manda el cliente a la fila
    }
    else if(persona.monto>primero->cliente.monto)
        return agregarCliente(primero->Mayores,persona);
    else
        return agregarCliente(primero->menores,persona);

}
#endif // MESAENTRADA_H
