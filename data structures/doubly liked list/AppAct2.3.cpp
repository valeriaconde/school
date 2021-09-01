//
//  main.cpp
//  Act2.3
//
//  Created by Valeria Conde on 08/10/20.
//  Copyright © 2020 Valeria Conde. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

// struct para guardar datos
struct Datos {
    string mes;
    int dia;
    string hora;
    string direccionIP;
    string razon;
    long longIP;
    
    Datos() {
    }
    
    Datos(string mes, int dia, string hora, string direccionIP, string razon) {
        this->mes = mes;
        this-> dia = dia;
        this->hora = hora;
        this->direccionIP = direccionIP;
        this->razon = razon;
        this->longIP = ipToLong(direccionIP);
    }
    
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
    
    void print() {
        cout << mes << " " << dia << " " << hora << " " << direccionIP << " " << razon << endl;
        arcSal << mes << " " << dia << " " << hora << " " << direccionIP << " " << razon << endl;
    }
};

#include "Node.h"
#include "DoubleLinkedList.h"

int main() {
    // Abre archivo de entrada
    ifstream bitacora;
    bitacora.open("bitacora.txt");
    
    LinkedList LL;
    
    string mes;
    int dia;
    string hora;
    string direccionIP;
    string razon;
    
    // lee el archivo, crea objetos y crea la linked list
    while (bitacora >> mes >> dia >> hora >> direccionIP) {
        getline(bitacora, razon);
        Datos tmp(mes, dia, hora, direccionIP, razon);
        LL.addLast(tmp);
    }
    
    LL.sort();
    LL.print();
    
    string ipIni, ipFin;
    
    // Pide al usuario IPs
    cout << "Ingrese el ip de inicio: ";
    cin >> ipIni;
    cout << "Ingrese el ip de fin: ";
    cin >> ipFin;
    LL.printRango(ipIni, ipFin);
    
    // Cierra archivo de entrada
    bitacora.close();
    
    return 0;
}
