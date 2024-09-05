#ifndef ABB_H
#define ABB_H

#include <iostream>   // Para operaciones de entrada y salida
#include <fstream>    // Para manejo de archivos
#include <memory>     // Para usar shared_ptr
#include <string>     // Para manejo de cadenas de texto
#include <cstdlib>    // Para usar system() y ejecutar comandos del sistema

using namespace std;

class Node{
public:
    int value;                      // Valor almacenado en el nodo
    int id;                         // Identificador único del nodo
    shared_ptr<Node> left, right;   // Punteros a los nodos izquierdo y derecho

    // Constructor del nodo
    Node(int val, int idVal) : value(val), id(idVal), left(nullptr), right(nullptr) {}
};    

class ABB{
private:
    shared_ptr<Node> root;          // Puntero a la raíz del árbol
    int globalNodeCount;            // Contador global de nodos

    void insertRec(shared_ptr<Node>& root, int val) {
        if (!root) {  // Si el nodo actual es nulo, se inserta el nuevo nodo aquí
            root = make_shared<Node>(val, ++globalNodeCount);
        } else if (val < root->value) {  // Si el valor es menor, se inserta en el subárbol izquierdo
            insertRec(root->left, val);
        } else if (val > root->value) {  // Si el valor es mayor, se inserta en el subárbol derecho
            insertRec(root->right, val);
        }
        // Si el valor es igual, no se hace nada (no se permiten duplicados)
    }

    void preorderRec(shared_ptr<Node> root) {
        if (root) {
            cout << root->value << " ";
            preorderRec(root->left);
            preorderRec(root->right);
        }
    }

    void inorderRec(shared_ptr<Node> root) const {
        if (root) {
            inorderRec(root->left);      // Recurre en el subárbol izquierdo
            cout << root->value << " ";  // Visita el nodo actual
            inorderRec(root->right);     // Recurre en el subárbol derecho
        }
    }

    void posorderRec(shared_ptr<Node> root) const {
        if (root) {
            posorderRec(root->left);     // Recurre en el subárbol izquierdo
            posorderRec(root->right);    // Recurre en el subárbol derecho
            cout << root->value << " ";  // Visita el nodo actual
        }
    }

    // Función recursiva para generar el archivo DOT para graficar el árbol
    void printRec(shared_ptr<Node> root, const string& name, ofstream& file, int& printNodeCount) const {
        if (root) {
            // Se generan nombres únicos para los nodos hijos
            string left = "Nodo" + to_string(++printNodeCount);
            string right = "Nodo" + to_string(++printNodeCount);

            // Escribe el nodo actual en el archivo DOT
            file << '"' << name << '"' << "[label=\"" << root->value << "\"];\n";
            if (root->left) {
                // Conecta el nodo actual con su hijo izquierdo
                file << '"' << name << "\"->\"" << left << "\";\n";
                printRec(root->left, left, file, printNodeCount);  // Recurre en el hijo izquierdo
            }
            if (root->right) {
                // Conecta el nodo actual con su hijo derecho
                file << '"' << name << "\"->\"" << right << "\";\n";
                printRec(root->right, right, file, printNodeCount);  // Recurre en el hijo derecho
            }
        }
    }

    shared_ptr<Node> deleteRec(shared_ptr<Node> root, int key){
        if (!root) return root;  // Si el nodo actual es nulo, no se hace nada
    
        if (key < root->value){
            root->left = deleteRec(root->left, key);
        }else if (key > root->value){
            root->right = deleteRec(root->right, key);
        }else {
            // Si se encuentra el nodo a eliminar
            if (!root->left) return root->right;  // Si no tiene hijo izquierdo, se devuelve el hijo derecho
            if (!root->right) return root->left;  // Si no tiene hijo derecho, se devuelve el hijo izquierdo

            // Si tiene dos hijos, se reemplaza con el mayor de los menores
            shared_ptr<Node> temp = getMajorOfMinors(root->left);
            root->value = temp->value;  // Se copia el valor del nodo a eliminar
            root->left = deleteRec(root->left, temp->value);  // Se elimina el nodo copiado
        }

        return root;
    }

    shared_ptr<Node> getMajorOfMinors(shared_ptr<Node> root){
        while(root && root->right) root = root->right;
        return root;
    }

public:
    // Constructor del árbol binario de búsqueda
    ABB() : root(nullptr), globalNodeCount(0) {}

    void insert(int val){
        if(!root){
            root = make_shared<Node>(val, ++globalNodeCount);
        }else{
            insertRec(root, val);
        }
    }

    void deleteNode(int val){
        root = deleteRec(root, val);
    }

    // Recorridos en orden, preorden y postorden
    void preorder(){
        preorderRec(root);
        cout << endl;
    }

    void inorder() const {
        inorderRec(root);
        cout << endl;
    }

    void posorder() const {
        posorderRec(root);
        cout << endl;
    }

    // Función para graficar el árbol
    void graph(const string& filename) const {
        string dotFilename = filename + ".dot";   // Nombre del archivo DOT
        string pngFilename = filename + ".png";   // Nombre del archivo PNG
        string dotCommand = "dot -Tpng " + dotFilename + " -o " + pngFilename;  // Comando para generar la imagen

        ofstream file(dotFilename);
        file << "digraph G {\n";  // Inicia el archivo DOT
        if (root) {
            int printNodeCount = 0;  // Reinicia el contador de nodos para graficar
            printRec(root, "Nodo" + to_string(++printNodeCount), file, printNodeCount);
        }
        file << "}\n";  // Finaliza el archivo DOT
        file.close();

        // Ejecuta el comando para convertir el archivo DOT en una imagen PNG
        int result = system(dotCommand.c_str());
        if (result != 0) {
            cerr << "Error generating image\n";  // Si ocurre un error al generar la imagen
        } else {
            cout << "Image generated successfully\n";  // Si la imagen se genera correctamente
        }
    }
};

#endif