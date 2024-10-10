#include <iostream>
#include <memory>
#include <fstream>
#include <string>

using namespace std;

class SubNode
{
public:
    int value;
    shared_ptr<SubNode> next = nullptr;

    SubNode(int value) : value(value) {}
};

class Node
{
public:
    int index;
    shared_ptr<Node> next = nullptr;
    shared_ptr<Node> prev = nullptr;
    shared_ptr<SubNode> list = nullptr;

    void append(int value)
    {
        shared_ptr<SubNode> newNode = make_shared<SubNode>(value);

        if (!list)
        {
            list = newNode;
        }
        else
        {
            shared_ptr<SubNode> temp = list;
            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void print()
    {
        shared_ptr<SubNode> temp = list;
        while (temp)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

class ListOfList
{
public:
    shared_ptr<Node> head = nullptr;
    shared_ptr<Node> tail = nullptr;

    void insert(int index, int value)
    {
        shared_ptr<Node> new_node = make_shared<Node>();
        new_node->index = index;

        if (!head)
        {
            head = new_node;
            tail = new_node;
            new_node->append(value);
        }
        else
        {
            if (index < head->index)
            {
                head->prev = new_node;
                new_node->next = head;
                head = new_node;
                new_node->append(value);
            }
            else
            {
                shared_ptr<Node> aux = head;
                while (aux->next && index > aux->next->index)
                {
                    aux = aux->next;
                }
                if (index == aux->index)
                {
                    aux->append(value);
                }
                else
                {
                    new_node->next = aux->next;
                    new_node->prev = aux;
                    if (aux->next)
                    {
                        aux->next->prev = new_node;
                    }
                    else
                    {
                        tail = new_node;
                    }
                    aux->next = new_node;
                    new_node->append(value);
                }
            }
        }
    }

    void print()
    {
        shared_ptr<Node> temp = head;
        while (temp)
        {
            cout << temp->index << ": ";
            temp->print();
            temp = temp->next;
        }
    }

    void graph(){
        ofstream file("graph.dot");

        file << "digraph G{" << endl;

        shared_ptr<Node> temp = head;
        while(temp){
           file << temp->index << "[label=\"" << temp->index << "\"];" << endl;

            shared_ptr<SubNode> temp2 = temp->list;
            while(temp2){
                file << temp->index << " -> " << temp2->value << "[dir=none];" << endl;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }

        file << "}" << endl;
        file.close();

        string command = "dot -Tpng graph.dot -o graph.png";
        if (system(command.c_str()) == 0)
        {
            cout << "Graph created successfully" << endl;
        }
        else
        {
            cout << "Error creating graph" << endl;
        }
    }
};

int main()
{
    ListOfList list;

    list.insert(2, 1);
    list.insert(2, 3);
    list.insert(4, 1);
    list.insert(3, 1);
    list.insert(3, 4);

    list.print();

    list.graph();
    return 0;
}