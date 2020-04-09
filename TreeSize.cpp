#include<iostream>
using namespace std;

class Node {
public:  
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;

    return node;
}

int size(Node* node) {
    if (node == nullptr) {
        return 0;
    } else {
        return size(node->left) + 1 + size(node->right);
    }
}

int main() {
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);w
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout << "Size of the tree is " << size(root);

    return 0;
}
