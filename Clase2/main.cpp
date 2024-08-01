#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    void append(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void push(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void print()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << " nullptr" << endl;
    }

    void remove(int value)
    {
        if (head == nullptr)
            return;

        if (head->data == value)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node *current = head;
        Node *previous = nullptr;

        while (current != nullptr && current->data != value)
        {
            previous = current;
            current = current->next;
        }

        if (current == nullptr)
            return;

        previous->next = current->next;
        delete current;
    }

    bool search(int value)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->data == value)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    };

    void generateDot(const string &filename)
    {
        ofstream file(filename);
        if (file.is_open())
        {
            file << "digraph G {" << endl;
            file << "node [shape=record];" << endl;
            file << "rankdir=LR;" << endl;

            Node *current = head;
            int id = 0;
            while (current != nullptr)
            {
                file << "node" << id << " [label=\"{" << current->data << "}\"];" << endl;
                if (current->next != nullptr)
                {
                    file << "node" << id << " -> node" << (id + 1) << ";" << endl;
                }
                current = current->next;
                id++;
            }

            file << "}" << endl;
            file.close();
        }
        else
        {
            cout << "No se pudo abrir el archivo" << endl;
        }
    }

    void renderGraphviz(const string& dotFilename, const string& imageFilename) {
        string command = "dot -Tpng " + dotFilename + " -o " + imageFilename;
        system(command.c_str());
    }
};

int main()
{
    LinkedList list;

    list.append(10);
    list.append(20);
    list.append(30);
    list.push(5);

    cout << "Los elementos de la lista son: " << endl;
    list.print();

    list.remove(20);
    cout << "Los elementos de la lista son: " << endl;
    list.print();

    // Buscar un elemento en la lista
    int valueToSearch = 30;
    if (list.search(valueToSearch)) {
        cout << valueToSearch << " si esta." << endl;
    } else {
        cout << valueToSearch << " no esta." << endl;
    }

    // Generar archivo DOT y renderizar la imagen
    string dotFilename = "list.dot";
    string imageFilename = "list.png";
    list.generateDot(dotFilename);
    list.renderGraphviz(dotFilename, imageFilename);

    return 0;
}