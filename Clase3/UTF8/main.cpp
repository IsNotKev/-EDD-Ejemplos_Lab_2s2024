#include <iostream>
#include <locale>
#include <windows.h>  // Incluye la biblioteca de Windows para cambiar la página de códigos

using namespace std;

int main() {
    // Establecer la página de códigos a UTF-8
    SetConsoleOutputCP(CP_UTF8);

    // Ejemplo de texto con tildes y eñes
    cout << "¡Hola, mundo! ¿Cómo están? Aquí hay una ñ y tildes: áéíóú" << endl;

    return 0;
}

