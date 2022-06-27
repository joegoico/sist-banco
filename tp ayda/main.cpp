#include <iostream>
#include"MesaEntrada.h"
#include "Cliente.h"
#include"FilaGral.h"
using namespace std;
void ingresar(FilaGral general,FilaGral especial,FilaGral especial2,int cantfilas,condicion criterio,condicion criterio2,Cliente persona){
    if (cantfilas==1)
        general.agregarCliente(persona)
    else{
        if (criterio.operacion==persona.operacion)&&(criterio.escliente==persona.esCliente)
            especial.agregarCliente(persona);
        else if (criterio2.operacion==persona.operacion)&&(criterio2.escliente==persona.esCliente)
            especial2.agregarCliente(persona);
        else
            general.agregarCliente(persona);
    }
}
Cliente tomarDatos(){
    string nombre, operacion, destinatario,esCliente;
    int edad;
    int monto;
    bool x;
    cout<<"Ingrese el nombre ";
    cin>>nombre;
    cout<<"Ingrese la edad ";
    cin>>edad;
    while(edad<18){
        cout<<"El valor que ingreso no es valido, ingrese nuevamente";
        cin>>edad;
    }
    cout<<"Ingrese el monto a operar ";
    cin>>monto;
    while(monto<=0){
        cout<<"El valor que ingreso no es valido, ingrese nuevamente";
        cin>>monto;
    }
    cout<<"Ingrese la operacion a realizar "<<endl;
    cout<<"deposito, pago, retiro o transferencia, ingrese nuevamente";
    cin>>operacion;
    while(operacion!= "deposito" || operacion!= "pago" || operacion!="retiro" || operacion!="transferencia"){
        cout<<"El valor que ingreso no es valido, ingrese nuevamente";
        cin>>operacion;
    }
    cout<<"Ingrese el destinatario: persona, banco o impuesto ";
    cin>>destinatario;
    while(destinatario!= "persona" || destinatario!="banco" || destinatario!="impuesto"){
        cout<<"El valor que ingreso no es valido, ingrese nuevamente";
        cin>>destinatario;
    }
    cout<<"Si es cliente ingrese T, de lo contrario ingrese F ";
    cin>>esCliente;
    while(esCliente!= "T" || esCliente!="F"){
        cout<<"El valor que ingreso no es valido, ingrese nuevamente";
        cin>>esCliente;
    }
    if (esCliente=="T"){
         x=true;
    }
    else{
         x=false;
    }
    Cliente aux(nombre,edad,monto,operacion,destinatario,x);
    return aux;
}
void crearFila(){
}
void menu(MesaEntrada historicos,FilaGral general,FilaGral especial,FilaGral especial2,int cantfilas){
    int opcion;
    struct condicion{
        string operacion;
        bool escliente;
    };
    condicion criterio,criterio2;
    cout<<"-------------Menu-------------"<<endl;
    cout<<"1.Ingresar nuevo cliente."<<endl;
    cout<<"2.Atender cliente."<<endl;
    cout<<"3.Abrir cola especial."<<endl;
    cout<<"4.Cerrar cola especial."<<endl;
    cout<<"5.Listar operaciones entre dos montos."<<endl;
    cin>>opcion;
    while (opcion<1) || (opcion>5){
        cout<<"Ingrese una opcion valida:"<<endl;
        cin>>opcion;
    }
    if (opcion==1){
        tomarDatos();
        Cliente persona=tomarDatos();
        historicos.agregarCliente(persona);
        ingresar(general,especial,especial2,cantfilas,criterio,criterio2,persona);
    }
    else if (opcion==2){
        int nfila;
        cout<<"0 para fila general"<<endl;
        cout<<"1 para fila de"<<criterio.operacion<<"y es cliente:"<<criterio.escliente<<endl;
        cout<<"2 para fila de"<<criterio2.operacion<<"y es cliente:"<<criterio2.escliente<<endl;
        cout<<"Ingrese la fila de la que quiere atender al proximo cliente:"<<endl;
        cin>>nfila;
        while (nfila<0) || (nfila>3){
            cout<<"Ingrese una fila valida:"<<endl;
            cin>>nfila;
        }
        if (nfila==0)
            general.atenderCliente(nfila)
        else if (nfila==1)
            especial.atenderCliente(nfila)
        else
            especial2.atenderCliente(nfila);
    }
    else if (opcion==3){

    }
    else if (opcion==4){

    }
    else{

    }
}
int main(){
    int cantfilas=1;
    MesaEntrada historicos;
    FilaGral general;
    FilaGral especial;
    FilaGral especial2;
    menu(historicos,general,especial,especial2,cantfilas);
    return 0;
}
