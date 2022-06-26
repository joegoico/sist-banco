#include <iostream>
#include"MesaEntrada.h"
#include "Cliente.h"
#include"FilaGral.h"
using namespace std;

int main()
{
    Cliente persona("joe",20,60000,"deposito","puto",true);
    MesaEntrada<Cliente> Arbol(persona);
    Arbol.agregarCliente(persona);
    return 0;
}
