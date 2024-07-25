#include <iostream>

using namespace std;

int main() {

    int num1;
    int num2;
    int suma;

    cout << "Ingrese el primer numero" << endl;
    cin >> num1;

    cout << "Ingrese el segundo numero" << endl;
    cin >> num2;


    suma = num1 + num2;

    cout << " La suma de: " << num1 << " + " << num2 << " = " << suma << endl;
    
    if (suma > 0) {
        cout << "La suma es positiva" << endl;
    } else if (suma < 0) {
        cout << "La suma es negativa" << endl;
    } else {
        cout << "La suma es cero" << endl;
    }

    for (int i = 0; i < 5; i++){
        cout << i << " ";
    }
    
    

    return 0;
}