#include "set/Node.hpp"

Node::Node(int value, Node* left, Node* right, int height) {
    this->data = value;
    this->left = left;
    this->right = right;
    this->height = height;
}