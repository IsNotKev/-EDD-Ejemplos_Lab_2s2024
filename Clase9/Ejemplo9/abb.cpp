#include "abb.h"

Node::Node(int val, int idVal) : value(val), height(1), id(idVal), left(nullptr), right(nullptr) {}

ABB::ABB() : root(nullptr), globalNodeCount(0) {}

void ABB::insertRec(shared_ptr<Node>& root, int val) {
    if (!root) {
        root = make_shared<Node>(val, ++globalNodeCount);
    } else if (val < root->value) {
        insertRec(root->left, val);
    } else if (val > root->value) {
        insertRec(root->right, val);
    }
}

shared_ptr<Node> ABB::deleteRec(shared_ptr<Node> root, int key) {
    if (!root) return root;

    if (key < root->value) {
        root->left = deleteRec(root->left, key);
    } else if (key > root->value) {
        root->right = deleteRec(root->right, key);
    } else {
        if (!root->left) return root->right;
        if (!root->right) return root->left;

        shared_ptr<Node> temp = getMajorOfMinors(root->left);
        root->value = temp->value;
        root->left = deleteRec(root->left, temp->value);
    }
    return root;
}

shared_ptr<Node> ABB::getMajorOfMinors(shared_ptr<Node> root) {
    while (root && root->right) root = root->right;
    return root;
}

string ABB::preorderRec(shared_ptr<Node> root) const {
    if (!root) return "";

    string result = to_string(root->value) + " - ";
    result += preorderRec(root->left);
    result += preorderRec(root->right);
    return result;
}

string ABB::inorderRec(shared_ptr<Node> root) const {
    if (!root) return "";

    string result = inorderRec(root->left);
    result += to_string(root->value) + " - ";
    result += inorderRec(root->right);
    return result;
}

string ABB::posorderRec(shared_ptr<Node> root) const {
    if (!root) return "";

    string result = posorderRec(root->left);
    result += posorderRec(root->right);
    result += to_string(root->value) + " - ";
    return result;
}

void ABB::printRec(shared_ptr<Node> root, const string& name, ofstream& file, int& printNodeCount) const {
    if (root) {
        string left = "Nodo" + to_string(++printNodeCount);
        string right = "Nodo" + to_string(++printNodeCount);

        file << '"' << name << '"' << "[label=\"" << root->value << "\"];\n";
        if (root->left) {
            file << '"' << name << "\"->\"" << left << "\";\n";
            printRec(root->left, left, file, printNodeCount);
        }
        if (root->right) {
            file << '"' << name << "\"->\"" << right << "\";\n";
            printRec(root->right, right, file, printNodeCount);
        }
    }
}

void ABB::insert(int val) {
    if (!root) {
        root = make_shared<Node>(val, ++globalNodeCount);
    } else {
        insertRec(root, val);
    }
}

void ABB::del(int val) {
    root = deleteRec(root, val);
}

string ABB::preorder() const {
    return preorderRec(root);
}

string ABB::inorder() const {
    return inorderRec(root);
}

string ABB::posorder() const {
    return posorderRec(root);
}

void ABB::graph(const string& filename) const {
    string dotFilename = filename + ".dot";
    string pngFilename = filename + ".png";
    string dotCommand = "dot -Tpng " + dotFilename + " -o " + pngFilename;

    ofstream file(dotFilename);
    file << "digraph G {\n";
    if (root) {
        int printNodeCount = 0;
        printRec(root, "Nodo" + to_string(++printNodeCount), file, printNodeCount);
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
