// Verifica si USUARIO_H no está definido para prevenir inclusión múltiple
#ifndef USUARIO_H

// Define USUARIO_H para indicar que el archivo ha sido incluido
#define USUARIO_H

// Incluye la biblioteca estándar de C++ para manejo de cadenas
#include <string>

// Usa el espacio de nombres estándar para evitar tener que anteponer 'std::' a cada nombre
using namespace std;

// Define la clase Usuario
class Usuario {
public:
    // Miembros públicos de la clase
    string nombre; // Almacena el nombre del usuario
    int edad;      // Almacena la edad del usuario

    // Constructor de la clase
    Usuario(string nombre, int edad) {
        // Inicializa los miembros de la clase con los valores proporcionados
        this->nombre = nombre;
        this->edad = edad;
    }
};

// Fin de la protección contra inclusión múltiple
#endif
