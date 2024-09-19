#ifndef AVL_H
#define AVL_H

#include <iostream>
#include <fstream>
#include <memory>
#include <algorithm>
#include <cstdlib>

using namespace std;

struct Node {
    int value;
    int height = 1;
    Node* left = nullptr;
    Node* right = nullptr;

    Node(int val) : value(val) {}
};

class AVL{
private:
    Node* root = nullptr;

    // Inserción recursiva
    Node* insertRec(Node* node, int val) {
        if (!node) {
            return new Node(val);
        }

        if (val < node->value) {
            node->left = insertRec(node->left, val);
        } else if (val > node->value) {
            node->right = insertRec(node->right, val);
        }

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        // Verificar balance y aplicar rotaciones
        int balance = getBalance(node);
        
        if (balance < -1) {
            if (getBalance(node->left) > 0) {
                node->right = rightRotation(node->right);
            }
            return leftRotation(node);
        }

        if (balance > 1) {
            if (getBalance(node->right) < 0) {
                node->left = leftRotation(node->left);
            }
            return rightRotation(node);
        }

        return node;
    }

    // Rotación hacia la izquierda
    Node* leftRotation(Node* node) {
        Node* newRoot = node->right;
        Node* temp = newRoot->left;

        newRoot->left = node;
        node->right = temp;

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        newRoot->height = 1 + max(getHeight(newRoot->left), getHeight(newRoot->right));

        return newRoot;
    }

    // Rotación hacia la derecha
    Node* rightRotation(Node* node) {
        Node* newRoot = node->left;
        Node* temp = newRoot->right;

        newRoot->right = node;
        node->left = temp;

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        newRoot->height = 1 + max(getHeight(newRoot->left), getHeight(newRoot->right));

        return newRoot;
    }

    int getHeight(Node* node) const {
        return node ? node->height : 0;
    }

    int getBalance(Node* node) const {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    Node* deleteRec(Node* root, int val){
        if (!root) return root;

        if (val< root->value){
            root->left = deleteRec(root->left, val);
        } else if (val > root->value){
            root->right = deleteRec(root->right, val);
        } else {
            if (!root->left) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            if (!root->right) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            Node* temp = getMajorOfMinors(root->left);
            root->value = temp->value;
            root->left = deleteRec(root->left, temp->value);
        }

        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        int balance = getBalance(root);

        if (balance < -1) {
            if (getBalance(root->left) > 0) {
                root->right = rightRotation(root->right);
            }
            return leftRotation(root);
        }

        if (balance > 1) {
            if (getBalance(root->right) < 0) {
                root->left = leftRotation(root->left);
            }
            return rightRotation(root);
        }

        return root;
    }

    Node* getMajorOfMinors(Node* root){
        while(root && root->right) root = root->right;
        return root;
    }

    // Método para imprimir el árbol en formato .dot
    void printRec(Node* node, const string& nodeName, ofstream& file, int& nodeCount) const {
        if (!node) return;

        string leftChild = "Nodo" + to_string(++nodeCount);
        string rightChild = "Nodo" + to_string(++nodeCount);

        file << "\"" << nodeName << "\" [label=\"" << node->value << "\"];\n";

        if (node->left) {
            file << "\"" << nodeName << "\" -> \"" << leftChild << "\";\n";
            printRec(node->left, leftChild, file, nodeCount);
        }

        if (node->right) {
            file << "\"" << nodeName << "\" -> \"" << rightChild << "\";\n";
            printRec(node->right, rightChild, file, nodeCount);
        }
    }

public:
    void insert(int val) {
        root = insertRec(root, val);
    }

    void remove(int val) {
        root = deleteRec(root, val);
    }

    // Método para graficar el árbol AVL
    void graph(const string& filename) const {
        string dotFilename = filename + ".dot";
        string pngFilename = filename + ".png";
        string dotCommand = "dot -Tpng " + dotFilename + " -o " + pngFilename;

        ofstream file(dotFilename);
        file << "digraph G {\n";

        if (root) {
            int nodeCount = 0;
            printRec(root, "Nodo" + to_string(++nodeCount), file, nodeCount);
        }

        file << "}\n";
        file.close();

        int result = system(dotCommand.c_str());
        if (result != 0) {
            cerr << "Error generating image\n";
        } else {
            cout << "Image generated successfully\n";
        }
    }
};

#endif // AVL_TREE_H