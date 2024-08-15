#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <iomanip>

using namespace std;

// Clase NodeVal para manejar los valores en la matriz
class NodeVal {
public:
    bool exists = false;
    bool value = false;
};

// Clase Node para cada nodo de la matriz
class Node {
public:
    int i = -1, j = -1;
    bool value = false;
    Node* up = nullptr;
    Node* down = nullptr;
    Node* right = nullptr;
    Node* left = nullptr;

    Node(int i = -1, int j = -1, bool value = false) : i(i), j(j), value(value) {}
};

// Clase Matrix que maneja la matriz
class Matrix {
private:
    Node* root = nullptr;
    int width = 0;
    int height = 0;

public:
    // Método para insertar un nuevo nodo en la matriz
    void insert(int i, int j, bool value) {
        Node* newNode = new Node(i, j, value);

        if (!root) {
            root = new Node(-1, -1);
        }

        Node* row = searchRow(i);
        Node* column = searchColumn(j);

        if (j > width) width = j;
        if (i > height) height = i;

        if (!nodeExists(newNode)) {
            if (!column) {
                column = insertColumnHeader(j);
            }

            if (!row) {
                row = insertRowHeader(i);
            }
            insertInColumn(newNode, row);
            insertInRow(newNode, column);
        }
    }

    // Método para buscar una fila por su índice
    Node* searchRow(int i) {
        Node* current = root;

        while (current) {
            if (current->i == i) return current;
            current = current->down;
        }
        return nullptr;
    }

    // Método para buscar una columna por su índice
    Node* searchColumn(int j) {
        Node* current = root;

        while (current) {
            if (current->j == j) return current;
            current = current->right;
        }
        return nullptr;
    }

    // Método para verificar si un nodo ya existe
    bool nodeExists(Node* newNode) {
        Node* rowHeader = root;

        while (rowHeader) {
            if (rowHeader->i == newNode->i) {
                Node* column = rowHeader;
                while (column) {
                    if (column->j == newNode->j) {
                        column->value = newNode->value;
                        return true;
                    }
                    column = column->right;
                }
                return false;
            }
            rowHeader = rowHeader->down;
        }
        return false;
    }

    // Método para insertar un encabezado de fila
    Node* insertRowHeader(int i) {
        Node* newRowHeader = new Node(i, -1);
        insertInRow(newRowHeader, root);
        return newRowHeader;
    }

    // Método para insertar un encabezado de columna
    Node* insertColumnHeader(int j) {
        Node* newColumnHeader = new Node(-1, j);
        insertInColumn(newColumnHeader, root);
        return newColumnHeader;
    }

    // Método para insertar un nodo en una fila
    void insertInRow(Node* newNode, Node* rowHeader) {
        Node* current = rowHeader;

        while (current->down) {
            if (newNode->i < current->down->i && newNode->i > current->i) {
                newNode->down = current->down;
                newNode->up = current;
                current->down->up = newNode;
                current->down = newNode;
                return;
            }
            current = current->down;
        }

        current->down = newNode;
        newNode->up = current;
    }

    // Método para insertar un nodo en una columna
    void insertInColumn(Node* newNode, Node* columnHeader) {
        Node* current = columnHeader;

        while (current->right) {
            if (newNode->j < current->right->j && newNode->j > current->j) {
                newNode->right = current->right;
                newNode->left = current;
                current->right->left = newNode;
                current->right = newNode;
                return;
            }
            current = current->right;
        }

        current->right = newNode;
        newNode->left = current;
    }

    // Método para imprimir la matriz
    void print() const {
        printColumnHeaders();

        for (int i = 0; i <= height; ++i) {
            cout << "\n" << setw(3) << i;
            for (int j = 0; j <= width; ++j) {
                NodeVal val = getValue(i, j);
                if (!val.exists) {
                    cout << setw(3) << "X";
                } else {
                    cout << setw(3) << val.value;
                }
            }
        }
        cout << endl;
    }

    // Método para imprimir los encabezados de las columnas
    void printColumnHeaders() const {
        for (int j = -1; j <= width; ++j) {
            cout << setw(3) << j;
        }
    }

    // Método para obtener el valor de un nodo en la matriz
    NodeVal getValue(int i, int j) const {
        NodeVal val;
        Node* rowHeader = root;

        while (rowHeader) {
            if (rowHeader->i == i) {
                Node* column = rowHeader;
                while (column) {
                    if (column->j == j) {
                        val.value = column->value;
                        val.exists = true;
                        return val;
                    }
                    column = column->right;
                }
                return val;
            }
            rowHeader = rowHeader->down;
        }
        return val;
    }
};

#endif
