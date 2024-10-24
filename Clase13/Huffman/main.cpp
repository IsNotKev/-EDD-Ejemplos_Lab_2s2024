#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Definición de nodo del árbol de Huffman
struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char ch, int freq) {
        this->ch = ch;
        this->freq = freq;
        left = right = nullptr;
    }
};

// Lista enlazada para manejar la cola de prioridad manualmente
struct PriorityQueue {
    Node* data;
    PriorityQueue* next;

    PriorityQueue(Node* data) : data(data), next(nullptr) {}
};

// Insertar en la cola de prioridad (ordenado por frecuencia)
void insert(PriorityQueue*& head, Node* newNode) {
    PriorityQueue* newElement = new PriorityQueue(newNode);
    if (!head || head->data->freq > newNode->freq) {
        newElement->next = head;
        head = newElement;
    } else {
        PriorityQueue* current = head;
        while (current->next && current->next->data->freq <= newNode->freq) {
            current = current->next;
        }
        newElement->next = current->next;
        current->next = newElement;
    }
}

// Extraer el nodo con la menor frecuencia
Node* extractMin(PriorityQueue*& head) {
    if (!head) return nullptr;
    PriorityQueue* temp = head;
    Node* minNode = head->data;
    head = head->next;
    delete temp;
    return minNode;
}

// Función recursiva para generar los códigos de Huffman
void buildHuffmanCode(Node* root, string code, string codes[256]) {
    if (!root) return;

    // Nodo hoja, asignar código
    if (!root->left && !root->right) {
        codes[(unsigned char)root->ch] = code;
    }

    buildHuffmanCode(root->left, code + "0", codes);
    buildHuffmanCode(root->right, code + "1", codes);
}

// Función para comprimir una cadena de texto usando los códigos de Huffman
string compress(const string& text, string codes[256]) {
    string compressedText = "";
    for (char ch : text) {
        compressedText += codes[(unsigned char)ch];
    }
    return compressedText;
}

// Función para descomprimir el texto comprimido
string decompress(Node* root, const string& compressedText) {
    string decompressedText = "";
    Node* currentNode = root;
    for (char bit : compressedText) {
        if (bit == '0') {
            currentNode = currentNode->left;
        } else {
            currentNode = currentNode->right;
        }

        if (!currentNode->left && !currentNode->right) {
            decompressedText += currentNode->ch;
            currentNode = root;
        }
    }
    return decompressedText;
}

// Función para generar el archivo .dot con Graphviz
void generateDotFile(Node* root, ofstream& dotFile, int& nullCount) {
    if (!root) return;

    // Si es un nodo hoja, lo representamos con su carácter y frecuencia
    if (!root->left && !root->right) {
        dotFile << "    \"" << root << "\" [label=\"" << root->ch << " (" << root->freq << ")\"];\n";
    } else {
        // Nodo interno, representamos solo la frecuencia
        dotFile << "    \"" << root << "\" [label=\"Freq: " << root->freq << "\"];\n";
    }

    // Conexión al hijo izquierdo
    if (root->left) {
        dotFile << "    \"" << root << "\" -> \"" << root->left << "\" [label=\"0\"];\n";
        generateDotFile(root->left, dotFile, nullCount);
    } else {
        dotFile << "    null" << nullCount << " [shape=point];\n";
        dotFile << "    \"" << root << "\" -> null" << nullCount++ << " [label=\"0\"];\n";
    }

    // Conexión al hijo derecho
    if (root->right) {
        dotFile << "    \"" << root << "\" -> \"" << root->right << "\" [label=\"1\"];\n";
        generateDotFile(root->right, dotFile, nullCount);
    } else {
        dotFile << "    null" << nullCount << " [shape=point];\n";
        dotFile << "    \"" << root << "\" -> null" << nullCount++ << " [label=\"1\"];\n";
    }
}

// Función para crear el archivo .dot de Graphviz
void createGraph(Node* root) {
    ofstream dotFile("huffman_tree.dot");
    dotFile << "digraph G {\n";
    dotFile << "    node [fontname=\"Arial\"];\n";
    
    int nullCount = 0;
    generateDotFile(root, dotFile, nullCount);

    dotFile << "}\n";
    dotFile.close();
    cout << "Archivo 'huffman_tree.dot' generado correctamente.\n";

    // Ejecutar el comando para generar la imagen PNG
    system("dot -Tpng huffman_tree.dot -o huffman_tree.png");
    cout << "Imagen PNG generada: huffman_tree.png\n";
}

// Función principal para ejecutar la compresión y descompresión
int main() {
    string text = "edd esta muy facil";

    // Contar la frecuencia de cada carácter manualmente
    int freq[256] = {0};
    for (char ch : text) {
        freq[(unsigned char)ch]++;
    }

    // Crear una cola de prioridad manualmente
    PriorityQueue* pq = nullptr;
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            Node* newNode = new Node((char)i, freq[i]);
            insert(pq, newNode);
        }
    }

    // Construir el árbol de Huffman
    while (pq && pq->next) {
        Node* left = extractMin(pq);
        Node* right = extractMin(pq);

        int sumFreq = left->freq + right->freq;
        Node* parent = new Node('\0', sumFreq);  // Nodo intermedio
        parent->left = left;
        parent->right = right;

        insert(pq, parent);
    }

    // El nodo raíz del árbol de Huffman
    Node* root = extractMin(pq);

    // Generar los códigos de Huffman
    string codes[256];
    buildHuffmanCode(root, "", codes);

    // Mostrar los códigos de Huffman
    cout << "Códigos de Huffman:\n";
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            cout << (char)i << ": " << codes[i] << '\n';
        }
    }

    // Comprimir el texto
    string compressedText = compress(text, codes);
    cout << "\nTexto comprimido: " << compressedText << "\n";

    // Descomprimir el texto
    string decompressedText = decompress(root, compressedText);
    cout << "\nTexto descomprimido: " << decompressedText << "\n";

    // Generar el archivo .dot para graficar el árbol
    createGraph(root);

    return 0;
}
