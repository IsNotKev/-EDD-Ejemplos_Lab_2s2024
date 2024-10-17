#include <iostream> //entrada salida
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>  // Para el comando del sistema (graphviz)

using namespace std;

// Definición de un nodo en el Árbol de Merkle
struct Node {
    string hash;
    Node* left;
    Node* right;

    Node(const string& data) : hash(data), left(nullptr), right(nullptr) {}
};

// Implementación básica del algoritmo SHA-256 (simplificado para fines didácticos)
string sha256(const string &input) {
    // Simulación de SHA-256 para hacerlo más sencillo
    string hash = "0000"; // Representa un hash simulado
    return hash + input; // Añade el input al hash simulado
}

Node* combineNodes(Node* left, Node* rigth){
    string combineHash = sha256(left->hash + rigth->hash);
    Node* parent = new Node(combineHash);
    parent->left = left;
    parent->right = rigth;
    return parent;
}

// Función recursiva para construir el Árbol de Merkle
Node* buildMerkleTree(Node** leaves, int start, int end) {
    // Si solo hay una hoja, retorna el nodo hoja
    if (start == end) {
        return leaves[start];
    }

    // Encuentra el punto medio para dividir la lista de hojas
    int mid = (start + end) / 2;

    // Construir el subárbol izquierdo y derecho de manera recursiva
    Node* leftSubTree = buildMerkleTree(leaves, start, mid);
    Node* rightSubTree = buildMerkleTree(leaves, mid + 1, end);

    // Combinar los dos subárboles en un nodo padre
    return combineNodes(leftSubTree, rightSubTree);
}

// Función para generar el archivo .dot para Graphviz
void generateDotFile(Node* node, ofstream &outFile, int& nodeCounter) {
    if (!node) return;

    int currentNode = nodeCounter++;
    outFile << "node" << currentNode << " [label=\"" << node->hash << "\"];\n";

    if (node->left) {
        int leftNode = nodeCounter;
        outFile << "node" << currentNode << " -- node" << leftNode << ";\n";
        generateDotFile(node->left, outFile, nodeCounter);
    }

    if (node->right) {
        int rightNode = nodeCounter;
        outFile << "node" << currentNode << " -- node" << rightNode << ";\n";
        generateDotFile(node->right, outFile, nodeCounter);
    }
}

// Función para generar el gráfico del Árbol de Merkle
void graphMerkleTree(Node* root) {
    ofstream outFile("merkle_tree.dot");
    outFile << "graph MerkleTree {\n";

    int nodeCounter = 0;
    generateDotFile(root, outFile, nodeCounter);

    outFile << "}\n";
    outFile.close();

    // Ejecutar el comando para generar la imagen con Graphviz
    system("dot -Tpng merkle_tree.dot -o merkle_tree.png");
    cout << "Árbol de Merkle graficado en merkle_tree.png\n";
}

int main(){

    const int numleaves = 5;
    string data[numleaves] = {"A", "B", "C", "D", "E"};

    Node* leaves[numleaves];
    for (int i = 0; i < numleaves; i++) {
        leaves[i] = new Node(sha256(data[i]));
    }

    Node* root = buildMerkleTree(leaves, 0, numleaves - 1);

    cout << "Hash del árbol de Merkle: " << root->hash << endl;

    graphMerkleTree(root);

    delete root;

    return 0;
}