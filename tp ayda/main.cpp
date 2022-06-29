#include <iostream>
#include"MesaEntrada.h"
#include "Cliente.h"
#include"FilaGral.h"
using namespace std;
struct condicion{
    string operacion = "";
    bool escliente;
};
int cantfilas=1;
void ingresar(FilaGral general,FilaGral especial,FilaGral especial2,int cantfilas,condicion criterio,condicion criterio2,Cliente persona){
    if (cantfilas==1)
        general.agregarCliente(persona);
    else{
        if(criterio.operacion!=""){
            if (criterio.operacion==persona.operacion && criterio.escliente==persona.esCliente)
                especial.agregarCliente(persona);
        }
        else if(criterio2.operacion!=""){
            if (criterio2.operacion==persona.operacion && criterio2.escliente==persona.esCliente)
                especial2.agregarCliente(persona);
        }
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
void cerrarcola(condicion criterio,condicion criterio2,int nfila,FilaGral especial,FilaGral especial2){
    cout<<"Que fila desea cerrar?"<<endl;
    if(criterio.operacion!="")
        cout<<"1 para fila de"<<criterio.operacion<<"y es cliente: "<<criterio.escliente<<endl;
    if(criterio2.operacion!="")
        cout<<"2 para fila de"<<criterio2.operacion<<"y es cliente: "<<criterio2.escliente<<endl;
    cin>>nfila;
    while (nfila!=1 && nfila!=2){
        cout<<"Introduzca un numero de fila valido."<<endl;
        cin>>nfila;
    }
    if (nfila==1){
        if (especial.filaVacia())
            criterio.operacion="";
        else
            cout<<"Para poder eliminar la fila auxiliar, primero debe atender todos los clientes de la misma.";
    }
    else{
        if (especial2.filaVacia())
            criterio2.operacion="";
        else
            cout<<"Para poder eliminar la fila auxiliar, primero debe atender todos los clientes de la misma.";
    }
}
void abrircola(int cantfilas,condicion criterio,condicion criterio2,FilaGral especial,FilaGral especial2){
    if(cantfilas<3){
        if(!especial.getFilaAbierta())
            especial.abrirFilaEspecial();
        else if(!especial2.getFilaAbierta())
            especial2.abrirFilaEspecial();
        cantfilas +=1;
    }
    else
        cout<<"ya hay dos filas especiales"<<endl;
}
void atendercliente(condicion criterio,condicion criterio2,int nfila,FilaGral general,FilaGral especial,FilaGral especial2){
    cout<<"0 para fila general"<<endl;
    if(criterio.operacion!="")
        cout<<"1 para fila de"<<criterio.operacion<<"y es cliente: "<<criterio.escliente<<endl;
    if(criterio2.operacion!="")
        cout<<"2 para fila de"<<criterio2.operacion<<"y es cliente: "<<criterio2.escliente<<endl;
    cout<<"Ingrese la fila de la que quiere atender al proximo cliente:"<<endl;
    cin>>nfila;
    while (nfila<0 || nfila>2){
        cout<<"Ingrese una fila valida:"<<endl;
        cin>>nfila;
    }
    if (nfila==0)
        general.atenderCliente();
    else if (nfila==1)
        especial.atenderCliente();
    else
        especial2.atenderCliente();
}
void listaroperaciones(MesaEntrada historicos){
    int montomax,montomin;
    cout<<"Introduzca un monto minimo:"<<endl;
    cin>>montomin;
    cout<<"Introduzca un monto maximo:"<<endl;
    cin>>montomax;
}
void menu(MesaEntrada historicos,FilaGral general,FilaGral especial,FilaGral especial2,int cantfilas){
    int opcion;
/*    struct condicion{
        string operacion = "";
        bool escliente;
    };*/
    condicion criterio,criterio2;
    cout<<"-------------Menu-------------"<<endl;
    cout<<"1.Ingresar nuevo cliente."<<endl;
    cout<<"2.Atender cliente."<<endl;
    cout<<"3.Abrir cola especial."<<endl;
    cout<<"4.Cerrar cola especial."<<endl;
    cout<<"5.Listar operaciones entre dos montos."<<endl;
    cin>>opcion;
    while (opcion<1 || opcion>5){
        cout<<"Ingrese una opcion valida:"<<endl;
        cin>>opcion;
    }
    int nfila;
    if (opcion==1){
        Cliente persona=tomarDatos();
        historicos.agregarCliente(persona);
        ingresar(general,especial,especial2,cantfilas,criterio,criterio2,persona);
    }
    else if (opcion==2)
        atendercliente(criterio,criterio2,nfila,general,especial,especial2);
    else if (opcion==3)
        abrircola(cantfilas,criterio,criterio2,especial,especial2);
    else if (opcion==4)
        cerrarcola(criterio,criterio2,nfila,especial,especial2);
    else{
        /*float promedio;
        listaroperaciones(historicos,promedio);
        cout<<"El promedio de edad de los clientes es:"<<promedio<<endl;*/
    }
    cout<<"Si desea realizar otra accion ingrese s, para salir ingrese n."<<endl;
    char salida;
    cin>>salida;
    if (salida=='s'){
        cout<<"-----------------------------------------------"<<endl;
        cout<<"-----------------------------------------------"<<endl;
        menu(historicos,general,especial,especial2,cantfilas);
    }
    else{
        cout <<"Salida realizada con exito.";
    }
}

int main(){
    MesaEntrada historicos;
    FilaGral general;
    FilaGral especial;
    FilaGral especial2;
    menu(historicos,general,especial,especial2,cantfilas);
    return 0;
}
