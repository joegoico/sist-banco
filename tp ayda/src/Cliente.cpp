#include "CLIENTE.h"
#include<iostream>
Cliente::Cliente(string nombre, int edad, int monto, string operacion, string destinatario, bool esCliente){
   this->nombre=nombre;
   this->edad=edad;
   this->monto=monto;
   this->operacion=operacion;
   this->destinatario=destinatario;
   this->esCliente=esCliente;
}
//CLIENTE::~CLIENTE()
//{
    //dtor
//}
