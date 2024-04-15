// problema5.cpp

#include "problema5.h"
#include <fstream>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;

GestorCanciones::GestorCanciones() {
}

Cancion::Cancion(const std::string& nombre, const std::string& artista, int anoLanzamiento, const std::string& genero, const std::string& duracion)
    : nombre(nombre), artista(artista), anoLanzamiento(anoLanzamiento), genero(genero), duracion(duracion) {}

// Getters
string Cancion::getNombre() const {
    return nombre;
}

string Cancion::getArtista() const {
    return artista;
}

int Cancion::getAnoLanzamiento() const {
    return anoLanzamiento;
}

string Cancion::getGenero() const {
    return genero;
}

string Cancion::getDuracion() const {
    return duracion;
}

// Setters
void Cancion::setNombre(const string& nombre) {
    this->nombre = nombre;
}

void Cancion::setArtista(const string& artista) {
    this->artista = artista;
}

void Cancion::setAnoLanzamiento(int anoLanzamiento) {
    this->anoLanzamiento = anoLanzamiento;
}

void Cancion::setGenero(const string& genero) {
    this->genero = genero;
}

void Cancion::setDuracion(const string& duracion) {
    this->duracion = duracion;
}
// Funciones para operar con las canciones


void GestorCanciones::agregarCancion(const std::string& nombre, const std::string& artista, int anoLanzamiento, const std::string& genero, const std::string& duracion) {
    GestorCanciones::canciones.push_back(Cancion(nombre, artista, anoLanzamiento, genero, duracion));
}

void GestorCanciones::eliminarCancion(const string& nombre) {
    GestorCanciones::canciones.erase(remove_if(GestorCanciones::canciones.begin(), GestorCanciones::canciones.end(), [&nombre](const Cancion& cancion) { return cancion.getNombre() == nombre; }), GestorCanciones::canciones.end());
}

void GestorCanciones::ordenarPorNombre() {
    sort(GestorCanciones::canciones.begin(), GestorCanciones::canciones.end(), [](const Cancion& a, const Cancion& b) { return a.getNombre() < b.getNombre(); });
}

void GestorCanciones::ordenarPorArtista() {
    sort(GestorCanciones::canciones.begin(), GestorCanciones::canciones.end(), [](const Cancion& a, const Cancion& b) { return a.getArtista() < b.getArtista(); });
}

void GestorCanciones::ordenarPorAno() {
    sort(GestorCanciones::canciones.begin(), GestorCanciones::canciones.end(), [](const Cancion& a, const Cancion& b) { return a.getAnoLanzamiento() < b.getAnoLanzamiento(); });
}

void GestorCanciones::ordenarPorDuracion() {
    sort(GestorCanciones::canciones.begin(), GestorCanciones::canciones.end(), [](const Cancion& a, const Cancion& b) { return a.getDuracion() < b.getDuracion(); });
}

void GestorCanciones::cambiarAtributo(const string& nombre, const string& atributo, const string& valor) {
    for (auto& cancion : GestorCanciones::canciones) {
        if (cancion.getNombre() == nombre) {
            if (atributo == "Nombre") {
                cancion.setNombre(valor);
            } else if (atributo == "Artista") {
                cancion.setArtista(valor);
            } else if (atributo == "AnoLanzamiento") {
                cancion.setAnoLanzamiento(stoi(valor));
            } else if (atributo == "Genero") {
                cancion.setGenero(valor);
            } else if (atributo == "Duracion") {
                cancion.setDuracion(valor);
            }
            break;
        }
    }
}

void GestorCanciones::imprimirCanciones() const {
    for (const auto& cancion : GestorCanciones::canciones) {
        cout << "Nombre: " << cancion.getNombre() << endl;
        cout << "Artista: " << cancion.getArtista() << endl;
        cout << "Año de Lanzamiento: " << cancion.getAnoLanzamiento() << endl;
        cout << "Género: " << cancion.getGenero() << endl;
        cout << "Duración: " << cancion.getDuracion() << endl;
        cout << endl;
    }
}

void GestorCanciones::guardarEnArchivo(const string& nombreArchivo) const {
    ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        for (const auto& cancion : GestorCanciones::canciones) {
            archivo << cancion.getNombre() << "," << cancion.getArtista() << "," << cancion.getAnoLanzamiento() << "," << cancion.getGenero() << "," << cancion.getDuracion() << std::endl;
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo para escritura." << endl;
    }
}

void GestorCanciones::cargarDesdeArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            string nombre, artista, genero, duracion;
            int anoLanzamiento;
            istringstream ss(linea);
            getline(ss, nombre, ',');
            getline(ss, artista, ',');
            ss >> anoLanzamiento;
            ss.ignore(); // Ignorar la coma después del año de lanzamiento
            getline(ss, genero, ',');
            getline(ss, duracion, ',');
            GestorCanciones::canciones.push_back(Cancion(nombre, artista, anoLanzamiento, genero, duracion));
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo para lectura." << endl;
    }
}

// Función para ejecutar el problema 5
void problema5() {
    GestorCanciones gestor;
    int opcion;
    do {
        cout << "Seleccione una opcion:" << endl;
        cout << "1. Ingresar una nueva cancion." << endl;
        cout << "2. Eliminar una cancion." << endl;
        cout << "3. Ordenar canciones por nombre." << endl;
        cout << "4. Ordenar canciones por artista." << endl;
        cout << "5. Ordenar canciones por año de lanzamiento." << endl;
        cout << "6. Ordenar canciones por duracion." << endl;
        cout << "7. Realizar cambio en algun atributo de la cancion." << endl;
        cout << "8. Imprimir lista de canciones." << endl;
        cout << "9. Guardar informacion en un archivo de texto." << endl;
        cout << "10. Cargar informacion desde un archivo de texto." << endl;
        cout << "0. Salir." << endl;
        cout << "Ingrese su opcion: ";
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer del newline

        switch (opcion) {
            case 1: {
                string nombre, artista, genero, duracion;
                int anoLanzamiento;
                cout << "Ingrese el nombre de la cancion: ";
                getline(cin, nombre);
                cout << "Ingrese el artista: ";
                getline(cin, artista);
                cout << "Ingrese el año de lanzamiento: ";
                cin >> anoLanzamiento;
                cout << "Ingrese el genero: ";
                cin.ignore(); // Limpiar el buffer del newline
                getline(cin, genero);
                cout << "Ingrese la duracion (MM:SS): ";
                getline(cin, duracion);
                gestor.agregarCancion(nombre, artista, anoLanzamiento, genero, duracion);
                break;
            }
            case 2: {
                string nombreEliminar;
                cout << "Ingrese el nombre de la cancion a eliminar: ";
                getline(cin, nombreEliminar);
                gestor.eliminarCancion(nombreEliminar);
                break;
            }
            case 3:
                gestor.ordenarPorNombre();
                break;
            case 4:
                gestor.ordenarPorArtista();
                break;
            case 5:
                gestor.ordenarPorAno();
                break;
            case 6:
                gestor.ordenarPorDuracion();
                break;
            case 7: {
                string nombreCambio, atributo, valor;
                cout << "Ingrese el nombre de la cancion a cambiar: ";
                getline(cin, nombreCambio);
                cout << "Ingrese el atributo a cambiar (Nombre, Artista, AnoLanzamiento, Genero, Duracion): ";
                getline(cin, atributo);
                cout << "Ingrese el nuevo valor: ";
                getline(cin, valor);
                gestor.cambiarAtributo(nombreCambio, atributo, valor);
                break;
            }
            case 8:
                gestor.imprimirCanciones();
                break;
            case 9: {
                string nombreArchivoGuardar;
                cout << "Ingrese ruta del archivo para guardar: ";
                getline(cin, nombreArchivoGuardar);
                gestor.guardarEnArchivo(nombreArchivoGuardar);
                break;
            }
            case 10: {
                string nombreArchivoCargar;
                cout << "Ingrese ruta del archivo para cargar: ";
                cout << "Formato: Nombre de la Cancion,Artista,Año de Lanzamiento,Genero,Duracion";
                getline(cin, nombreArchivoCargar);
                gestor.cargarDesdeArchivo(nombreArchivoCargar);
                break;
            }
            case 0:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opcion invalida. Por favor, seleccione una opcion valida." << endl;
                break;
        }
    } while (opcion != 0);
}
