#ifndef ABB_H
#define ABB_H

#include <iostream>
#include <fstream>
#include <memory>
#include <string>

using namespace std;

class Node {
public:
    int value;
    int height;
    int id;
    shared_ptr<Node> left, right;

    Node(int val, int idVal);
};

class ABB {
private:
    shared_ptr<Node> root;
    int globalNodeCount;

    void insertRec(shared_ptr<Node>& root, int val);
    shared_ptr<Node> deleteRec(shared_ptr<Node> root, int key);
    shared_ptr<Node> getMajorOfMinors(shared_ptr<Node> root);

    string preorderRec(shared_ptr<Node> root) const;
    string inorderRec(shared_ptr<Node> root) const;
    string posorderRec(shared_ptr<Node> root) const;

    void printRec(shared_ptr<Node> root, const string& name, ofstream& file, int& printNodeCount) const;

public:
    ABB();
    void insert(int val);
    void del(int val);

    string preorder() const;
    string inorder() const;
    string posorder() const;

    void graph(const string& filename) const;
};

#endif // ABB_H
