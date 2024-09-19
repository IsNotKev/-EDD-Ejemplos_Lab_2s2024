#include "avl.h"

int main(){

    AVL tree;
    tree.insert(8);
    tree.insert(6);
    tree.insert(9);
    tree.insert(4);
    tree.insert(7);
    tree.insert(10);
    tree.insert(5);

    tree.graph("avl");

    tree.remove(5);
    tree.remove(7);
    tree.remove(10);
    tree.remove(9);
    tree.graph("avl_removed");
    return 0;
}