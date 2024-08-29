#include "abb.h"

int main(){
    ABB tree;

    tree.insert(20);
    tree.insert(8);
    tree.insert(3);
    tree.insert(1);
    tree.insert(0);
    tree.insert(15);
    tree.insert(30);
    tree.insert(48);
    tree.insert(26);
    tree.insert(10);
    tree.insert(7);
    tree.insert(5);
    tree.insert(60);
    tree.insert(19);
    tree.insert(11);
    tree.insert(21);
    tree.insert(3);

    tree.graph("arbol");

    cout << "Escribiendo en preorden: ";
    tree.preorder();

    cout << "Escribiendo en inorden: ";
    tree.inorder();

    cout << "Escribiendo en posorden: ";
    tree.posorder();
}