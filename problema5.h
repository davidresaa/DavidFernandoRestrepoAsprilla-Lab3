// problema5.h
#ifndef PROBLEMA5_H
#define PROBLEMA5_H

#include <string>
#include <vector>

class Cancion {
public:
    Cancion(const std::string& nombre, const std::string& artista, int anoLanzamiento, const std::string& genero, const std::string& duracion);

    // Getters
    std::string getNombre() const;
    std::string getArtista() const;
    int getAnoLanzamiento() const;
    std::string getGenero() const;
    std::string getDuracion() const;

    // Setters
    void setNombre(const std::string& nombre);
    void setArtista(const std::string& artista);
    void setAnoLanzamiento(int anoLanzamiento);
    void setGenero(const std::string& genero);
    void setDuracion(const std::string& duracion);

private:
    std::string nombre;
    std::string artista;
    int anoLanzamiento;
    std::string genero;
    std::string duracion;
};

class GestorCanciones {
public:
    GestorCanciones();
    // Funciones para operar con las canciones
    void agregarCancion(const std::string& nombre, const std::string& artista, int anoLanzamiento, const std::string& genero, const std::string& duracion);
    void eliminarCancion(const std::string& nombre);
    void ordenarPorNombre();
    void ordenarPorArtista();
    void ordenarPorAno();
    void ordenarPorDuracion();
    void cambiarAtributo(const std::string& nombre, const std::string& atributo, const std::string& valor);
    void imprimirCanciones() const;
    void guardarEnArchivo(const std::string& nombreArchivo) const;
    void cargarDesdeArchivo(const std::string& nombreArchivo);

    // Función para ejecutar el problema 5
    void problema5();

private:
    std::vector<Cancion> canciones;
};

#endif // PROBLEMA5_H
