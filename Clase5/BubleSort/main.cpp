#include <iostream>
#include <fstream>
#include <cstdlib>  // Para la función system()

using namespace std;

// Definición de la estructura para el nodo de la lista
struct Node {
    int data;          // Dato almacenado en el nodo
    Node* next;   // Puntero al siguiente nodo

    // Constructor del nodo
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Definición de la clase para la lista simplemente enlazada
class LinkedList {
private:
    Node* head;  // Puntero al primer nodo de la lista

public:
    // Constructor de la lista
    LinkedList() {
        head = nullptr;
    }

    // Método para insertar un nuevo nodo al final de la lista (append)
    void append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Método para insertar un nuevo nodo al inicio de la lista (push)
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Método para mostrar los elementos de la lista
    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }

    // Método para eliminar un nodo por valor (delete)
    void remove(int value) {
        if (head == nullptr) return;  // La lista está vacía

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        Node* previous = nullptr;

        while (current != nullptr && current->data != value) {
            previous = current;
            current = current->next;
        }

        if (current == nullptr) return;  // El valor no se encontró en la lista

        previous->next = current->next;
        delete current;
    }

    // Método para buscar un nodo por valor
    bool search(int value) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == value) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Método para ordenar la lista usando bubble sort
    void bubbleSort() {
        if (head == nullptr) return;

        Node* current;
        Node* nextNode;
        int temp;

        bool swapped;
        do {
            swapped = false;
            current = head;
            while (current->next != nullptr) {
                nextNode = current->next;
                if (current->data < nextNode->data) {
                    // Intercambiar los datos
                    temp = current->data;
                    current->data = nextNode->data;
                    nextNode->data = temp;
                    swapped = true;
                }
                current = nextNode;
            }
        } while (swapped);
    }

    // Método para generar el archivo DOT
    void generateDOT(const string& filename) {
        ofstream file(filename);
        file << "digraph G {" << endl;
        file << "node [shape=record];" << endl;

        Node* current = head;
        int id = 0;
        while (current != nullptr) {
            file << "node" << id << " [label=\"{" << current->data << "}\"];" << endl;
            if (current->next != nullptr) {
                file << "node" << id << " -> node" << (id + 1) << ";" << endl;
            }
            current = current->next;
            id++;
        }

        file << "}" << endl;
        file.close();
    }

    // Método para renderizar usando Graphviz
    void renderGraphviz(const string& dotFilename, const string& imageFilename) {
        string command = "dot -Tpng " + dotFilename + " -o " + imageFilename;
        system(command.c_str());
    }

    // Método para graficar la lista antes y después de ordenar
    void graph(const string& filename) {
        string dotFilename = filename + ".dot";
        string imageFilename = filename + ".png";
        
        // Graficar la lista original
        generateDOT(dotFilename);
        renderGraphviz(dotFilename, imageFilename);

        // Ordenar la lista
        bubbleSort();

        // Graficar la lista ordenada
        string sortedDotFilename = filename + "_sorted.dot";
        string sortedImageFilename = filename + "_sorted.png";
        generateDOT(sortedDotFilename);
        renderGraphviz(sortedDotFilename, sortedImageFilename);
    }

    // Destructor de la lista
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

// Función principal
int main() {
    LinkedList list;

    // Insertar elementos en la lista
    list.append(10);
    list.append(30);
    list.append(15);
    list.push(50);

    // Mostrar elementos de la lista
    cout << "Elements in the list: ";
    list.print();

    // Graficar la lista antes y después de ordenar
    list.graph("list");

    cout << "The linked list has been rendered and saved as list.png and list_sorted.png" << endl;

    return 0;
}
