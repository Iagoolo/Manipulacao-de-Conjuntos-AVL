#include "Set/SetIterador.hpp"

void SetIterador::pushLeft(Node* node) {
    while (node != nullptr) {
        stack.push(node);
        node = node->left;
    }
}

SetIterador::SetIterador(Node* root) {
    pushLeft(root);
}

int SetIterador::operator*() const {
    return stack.top()->data;
}

SetIterador& SetIterador::operator++() {
    Node* node = stack.top();
    stack.pop();
    if (node->right != nullptr) {
        pushLeft(node->right);
    }
    return *this;
}

bool SetIterador::operator!=(const SetIterador& other) const {
    return stack != other.stack;
}