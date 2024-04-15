// problema4.cpp

#include "problema4.h"
#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

void Codificador::cargarReglas(const string& archivoReglas) {
    ifstream archivo(archivoReglas);
    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            if (linea.size() >= 3 && linea[1] == '=') {
                reglas[linea[0]] = linea[2];
            }
        }
        archivo.close();
    }
}


string Codificador::codificar(const string& mensaje) {
    string mensajeCodificado;
    for (char c : mensaje) {
        if (reglas.find(c) != reglas.end()) {
            mensajeCodificado += reglas[c];
        } else {
            mensajeCodificado += c; // Mantener caracteres que no están en las reglas
        }
    }
    return mensajeCodificado;
}

string Codificador::decodificar(const string& mensaje) {
    string mensajeDecodificado;
    for (char c : mensaje) {
        bool encontrado = false;
        for (const auto& par : reglas) {
            if (par.second == c) {
                mensajeDecodificado += par.first;
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            mensajeDecodificado += c; // Mantener caracteres que no están en las reglas
        }
    }
    return mensajeDecodificado;
}

void problema4() {
    cout << "Seleccione una opcion:" << endl;
    cout << "1. Codificacion" << endl;
    cout << "2. Decodificacion" << endl;

    int opcion;
    cin >> opcion;

    switch (opcion) {
        case 1: {
            string archivoReglas, archivoEntrada, archivoSalida;
            cout << "Ingrese la ubicacion del archivo de reglas: "<<endl;
            cout << "El archivo debe ser del formato letra=valor, de lo contrario no funcionará: ";
            cin >> archivoReglas;
            cout << "Ingrese la ubicacion del archivo de entrada: ";
            cin >> archivoEntrada;
            cout << "Ingrese la ubicacion del archivo de salida: ";
            cin >> archivoSalida;

            Codificador codificador;
            codificador.cargarReglas(archivoReglas);

            ifstream entrada(archivoEntrada);
            ofstream salida(archivoSalida);
            if (entrada.is_open() && salida.is_open()) {
                string linea;
                while (getline(entrada, linea)) {
                    salida << codificador.codificar(linea) << "\n";
                }
                entrada.close();
                salida.close();
                cout << "Codificacion completada.\n";
            } else {
                cerr << "Error al abrir los archivos.\n";
            }
            break;
        }
        case 2: {
            string archivoReglas, archivoEntrada, archivoSalida;
            cout << "Ingrese la ubicacion del archivo de reglas: "<<endl;
            cout << "El archivo debe ser del formato letra=valor (Use el mismo que uso para codificar el emsaje), de lo contrario no funcionará: ";
            cin >> archivoReglas;
            cout << "Ingrese la ubicacion del archivo de entrada: ";
            cin >> archivoEntrada;
            cout << "Ingrese la ubicacion del archivo de salida: ";
            cin >> archivoSalida;

            Codificador codificador;
            codificador.cargarReglas(archivoReglas);

            ifstream entrada(archivoEntrada);
            ofstream salida(archivoSalida);
            if (entrada.is_open() && salida.is_open()) {
                string linea;
                while (getline(entrada, linea)) {
                    salida << codificador.decodificar(linea) << endl;
                }
                entrada.close();
                salida.close();
                cout << "Decodificacion completada"<<endl;
            } else {
                cout << "Error al abrir los archivos"<<endl;
            }
            break;
        }
        default:
            cout << "Opcion invalida. Seleccione 1 o 2"<<endl;
            break;
    }
}
