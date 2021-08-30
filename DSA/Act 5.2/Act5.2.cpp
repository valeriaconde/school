//
//  main.cpp
//  Act 5.2
//
//  Created by Valeria Conde on 28/11/20.
//  Copyright © 2020 Valeria Conde. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map>
using namespace std;

// struct para guardar resumen de los datos
struct Datos {
    string mes;
    int dia;
    string hora;
    string razon;
    
    Datos() {
    }
    
    Datos(string mes, int dia, string hora, string razon) {
        this->mes = mes;
        this-> dia = dia;
        this->hora = hora;
        this->razon = razon;
    }
    
};

// empty hash table
unordered_map<string, vector<Datos>> hasht;

// metodo para desplegar la informacion dado un ip
void show(string ip) {
    vector<Datos> tmp = hasht[ip];
    for(int i = 0; i < tmp.size(); i++) {
        cout << "Fecha: " << tmp[i].dia << "/" << tmp[i].mes << " " << tmp[i].hora << endl;
        cout << "Falla: " << tmp[i].razon << endl;
        cout << endl;
    }
}

int main() {
    // Abre archivo de entrada
     ifstream bitacora;
     bitacora.open("bitacoraACT5_2.txt");
     
     string ipSinPuerto;
     string mes;
     int dia;
     string hora;
     string direccionIP;
     string razon;
     
    
     // lee el archivo
     while (bitacora >> mes >> dia >> hora >> direccionIP) {
         getline(bitacora, razon);
         ipSinPuerto = direccionIP.substr(0, direccionIP.find(":", 0));
         Datos tmp(mes, dia, hora, razon);
         
         // hash table ip - datos
         hasht[ipSinPuerto].push_back(tmp);
     }
    
    
    
    // LLAMAR FUNCION SHOW SEGUN IP DESEADO //
    
    
    
     // Cierra archivo de entrada
     bitacora.close();
    
    
    return 0;
}
