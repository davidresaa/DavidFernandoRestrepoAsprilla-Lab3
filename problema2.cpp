#include <iostream>
#include <fstream>
#include "problema2.h"
using namespace std;

GestorArchivo::GestorArchivo() {}

//FUNCION DE LECTURA

void GestorArchivo::leerArchivo(const string& ruta) {
    ifstream archivo(ruta); // Abrir el archivo en modo de lectura

    if (!archivo.is_open()) {
        cerr << "Error: No se pudo abrir el archivo." << endl;
        return;
    }

    string linea;

    cout << "Archivo actualizado: "<< endl;
    while (getline(archivo, linea)) { // Leer cada línea del archivo
        cout << linea << endl; // Mostrar la línea en la consola
    }

    archivo.close(); // Cerrar el archivo
}

//FUNCION DE ESCRITURA

void GestorArchivo::escribirArchivo(const string& ruta) {
    ofstream archivo(ruta, std::ios::app); // Abrir el archivo en modo de escritura, agregar al final del archivo

    if (!archivo.is_open()) {
        cerr << "Error: No se pudo abrir el archivo." << endl;
        return;
    }

    string texto;
    string linea;
    char opcion;

    do {
        cout << "Ingrese el texto a guardar en el archivo: ";
        getline(cin >> ws, texto); // Leer una línea de texto del usuario
        archivo << texto << endl; // Escribir el texto en el archivo

        cout << "¿Desea escribir más texto en el archivo? (S/N): ";
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer de entrada

    } while (opcion == 'S' || opcion == 's');

    archivo.close(); // Cerrar el archivo

    leerArchivo(ruta);
}


void problema2() {
    int opcion;
    string ruta;
    GestorArchivo gestor;

    cout << "Seleccione una opción:" << endl;
    cout << "1. Escribir en archivo" << endl;
    cout << "2. Leer archivo" << endl;
    cin >> opcion;

    cout << "Ingrese la ubicación del archivo (ruta completa): ";
    cin >> ruta;

    switch (opcion) {
        case 1:
            gestor.escribirArchivo(ruta);
            break;
        case 2:
            gestor.leerArchivo(ruta);
            break;
        default:
            cerr << "Opción no válida." << endl;
            break;
    }
}
