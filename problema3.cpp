#include "problema3.h"
BuscadorTexto::BuscadorTexto() {}

void BuscadorTexto::buscarCaracter(const string& rutaArchivo, char caracter, ofstream& resultado) {
    ifstream archivo(rutaArchivo);

    if (!archivo.is_open()) {
        cerr << "Error: No se pudo abrir el archivo." << endl;
        return;
    }

    char c;
    int contador = 0;

    while (archivo.get(c)) {
        if (c == caracter) {
            contador++;
        }
    }

    archivo.close();

    cout << "El caracter '" << caracter << "' se encontró " << contador << " veces en el texto." << endl;
    resultado << "El caracter '" << caracter << "' se encontró " << contador << " veces en el texto." << endl;
}

void BuscadorTexto::buscarSecuencia(const string& rutaArchivo, const string& secuencia, ofstream& resultado) {
    ifstream archivo(rutaArchivo);

    if (!archivo.is_open()) {
        cerr << "Error: No se pudo abrir el archivo." << endl;
        return;
    }

    string linea;
    int contador = 0;

    while (getline(archivo, linea)) {
        size_t pos = 0;
        while ((pos = linea.find(secuencia, pos)) != string::npos) {
            contador++;
            pos += secuencia.length();
        }
    }

    archivo.close();

    cout << "La secuencia \"" << secuencia << "\" se encontró " << contador << " veces en el texto." << endl;
    resultado << "La secuencia \"" << secuencia << "\" se encontró " << contador << " veces en el texto." << endl;
}

void problema3() {
    string rutaArchivo, rutaResultado;
    int n;

    cout << "Ingrese la cantidad de veces que desea buscar en el texto: ";
    cin >> n;
    cin.ignore(); // Limpiar el buffer de nueva línea

    cout << "Ingrese la ruta del archivo: ";
    getline(cin, rutaArchivo);

    cout << "Ingrese la ruta y nombre del archivo de resultado: ";
    getline(cin, rutaResultado);

    ofstream resultado(rutaResultado);

    BuscadorTexto buscador;

    for (int i = 0; i < n; ++i) {
        int opcion;

        cout << "Búsqueda " << i + 1 << ":" << endl;
        cout << "Seleccione una opción:" << endl;
        cout << "1. Buscar un caracter" << endl;
        cout << "2. Buscar una secuencia de texto" << endl;
        cin >> opcion;

        if (opcion == 1) {
            char caracter;
            cout << "Ingrese el carácter a buscar: ";
            cin >> caracter;
            buscador.buscarCaracter(rutaArchivo, caracter, resultado);
        } else if (opcion == 2) {
            string secuencia;
            cout << "Ingrese la secuencia de texto a buscar: ";
            cin >> secuencia;
            buscador.buscarSecuencia(rutaArchivo, secuencia, resultado);
        } else {
            cerr << "Opción inválida." << endl;
            --i; // Restar i para que el bucle repita la búsqueda actual
        }
    }

    resultado.close();

    cout << "********************************************************************************"<<endl;
    cout << "El archivo con la información del resultado ha sido guardado con éxito en la ruta: " << rutaResultado << endl;
}
