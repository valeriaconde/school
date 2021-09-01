#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <fstream>
using namespace std;

struct Info {
    int accesos;
    string ip;
    long ipLong;
    
    Info() {
        accesos = 0;
        ip = "";
        ipLong = 0;
    }
    
    Info(int accesos, string ip, long ipLong) {
        this->accesos = accesos;
        this->ip = ip;
        this->ipLong = ipLong;
    }
};

long ipToLong(string ip){
    int idx = 0;
    long datoFinal= 0, dato = 0;
    while (idx < ip.size()){
        if (ip[idx]!= '.' && ip[idx]!=':'){
            dato = dato*10 + ip[idx]-'0';
        }
        else{
            datoFinal = datoFinal*1000 + dato;
            dato = 0;
        }
        idx++;
    }
    datoFinal = datoFinal*10000 + dato;
    return datoFinal;
}

#include "BST.h"

int main(){
    ifstream archivo;
    archivo.open("bitacoraOrdenada.txt");
    
    string mes;
    int dia;
    string hora;
    string direccionIP;
    string razon;
    string ipSinPuerto, ipSinPuertoAnterior = "";
    long ipAnterior = -1, ipLong = 0;
    int contador = 0;
    
    BST arbol;
    
    // lee el archivo, crea objetos y crea la linked list
    while (archivo >> mes >> dia >> hora >> direccionIP) {
        getline(archivo, razon);
        
        ipSinPuerto = direccionIP.substr(0, direccionIP.find(":", 0));
        ipLong = ipToLong(ipSinPuerto);
        
        if(ipLong != ipAnterior) {
            Info tmp(contador, ipSinPuertoAnterior, ipAnterior);
            arbol.add(tmp);
            
            contador = 0;
            ipAnterior = ipLong;
            ipSinPuertoAnterior = ipSinPuerto;
        }
        contador++;
        
    }
    
    if(contador > 0) {
        Info tmp(contador, ipSinPuerto, ipLong);
        arbol.add(tmp);
    }
    
    arbol.topNodes();

	return 0;
}
