#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;

    Node(int value){
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList{
private:
    Node* head;
    Node* tail;
public:
    DoublyLinkedList(){
        head = nullptr;
        tail = nullptr;
    }

    void append(int value){
        Node* newNode = new Node(value);
        if(head == nullptr){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void push(int value){
        Node* newNode = new Node(value);
        if(head == nullptr){
            head = newNode;
            tail = newNode;
        }else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void print(){
        Node* current = head;
        while(current != nullptr){
            cout << current->data << " <-> ";
            current = current->next;
        }
        cout << "fin" <<endl;
    }

    void printBackward(){
        Node* current = tail;
        while(current != nullptr){
            cout << current->data << " <-> ";
            current = current->prev;
        }
        cout << "inicio" <<endl;
    }

    void remove(int value){
        Node* current = head;

        while (current != nullptr && current->data != value){
            current = current->next;
        }

        if(current == nullptr){
            cout << "No se encontro el valor a eliminar" << endl;
            return;
        }

        if(current->prev != nullptr){
            current->prev->next = current->next;
        } else {
            head = current->next;
        }

        if(current->next != nullptr){
            current->next->prev = current->prev;
        } else {
            tail = current->prev;
        }

        delete current;
    }

    bool search(int value){
        Node* current = head;
        while(current != nullptr){
            if(current->data == value){
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void graph(){
        ofstream file("graph.dot");
        file << "digraph G {" << endl;
        file << "rankdir=LR;" << endl;
        file << "node [shape=record];" << endl;

        Node* current = head;
        int id = 0;
        while (current != nullptr) {
            file << "node" << id << " [label=\"{" << current->data << "}\"];" << endl;
            if (current->next != nullptr) {
                file << "node" << id << " -> node" << (id + 1) << " ;" << endl;
                file << "node" << (id + 1) << " -> node" << id << " ;" << endl;
            }
            current = current->next;
            id++;
        }

        file << "}" << endl;
        file.close();

        string command = "dot -Tpng graph.dot -o graph.png";
        system(command.c_str());
    }

    ~DoublyLinkedList(){
        Node* current = head;
        while(current != nullptr){
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main(){
    DoublyLinkedList list;

    list.append(10);
    list.append(20);
    list.append(30);
    list.push(5);

    cout << "Lista normal" << endl;
    list.print();

    cout << "Lista al reves" << endl;
    list.printBackward();

    list.remove(20);
    cout << "Lista normal despues de eliminar el 20" << endl;
    list.print();

    cout << "Lista al reves despues de eliminar el 20" << endl;
    list.printBackward();

    cout << "Buscando el 10: " << list.search(10) << endl;
    cout << "Buscando el 20: " << list.search(20) << endl;

    list.graph();
    cout << "Grafico generado" << endl;
    return 0;
};