#include <iostream>   // Para la entrada y salida estándar
#include <fstream>    // Para manejar archivos

#include "json.hpp"   // Incluir la biblioteca JSON for Modern C++
#include "ListaEnlazada.h"  // Incluir la definición de la clase ListaEnlazada

using json = nlohmann::json;  // Alias para simplificar el uso de la clase json de la biblioteca nlohmann
using namespace std;  // Para evitar escribir std:: antes de cout, cin, etc.

int main() {
    ListaEnlazada lista;  // Crear una instancia de la lista simplemente enlazada
    
    ifstream archivo("usuarios.json");  // Abrir el archivo JSON
    if (archivo.is_open()) {  // Verificar si el archivo se abrió correctamente
        json j;  // Crear un objeto json para almacenar los datos del archivo
        archivo >> j;  // Leer el contenido del archivo JSON en el objeto j

        // Recorrer cada elemento (usuario) del archivo JSON
        for (const auto& item : j) {
            // Extraer el nombre y la edad de cada usuario
            string nombre = item["nombre"];
            int edad = item["edad"];

            // Crear un nuevo objeto Usuario con los datos extraídos
            Usuario* usuario = new Usuario(nombre, edad);

            // Insertar el objeto Usuario en la lista simplemente enlazada
            lista.insertar(usuario);
        }

        archivo.close();  // Cerrar el archivo JSON
    } else {
        // Si el archivo no se pudo abrir, mostrar un mensaje de error
        cerr << "No se pudo abrir el archivo JSON." << endl;
        return 1;  // Salir del programa con un código de error
    }

    // Mostrar los elementos de la lista
    lista.mostrar();

    return 0;  // Salir del programa con un código de éxito
}
