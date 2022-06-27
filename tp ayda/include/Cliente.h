#ifndef CLIENTE_H
#define CLIENTE_H
#include<iostream>
using namespace std;
class Cliente
{
    public:
        string nombre, operacion, destinatario;
        int edad;
        int monto;
        bool esCliente;
        Cliente(string nombre, int edad, int monto, string operacion, string destinatario, bool esCliente);
        //~Cliente();
};
#endif // CLIENTE_H
