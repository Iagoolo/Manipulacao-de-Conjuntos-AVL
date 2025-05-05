#include "set/SetIterador.hpp"

// Função auxiliar para adicionar todos os nós à esquerda do nó atual à pilha
void SetIterador::pushLeft(Node* node) {
    while (node != nullptr) {
        stack.push(node);
        node = node->left;
    }
}

// Construtor que inicializa o iterador com a raiz da árvore
SetIterador::SetIterador(Node* root) {
    pushLeft(root);
}

// Retorna o valor do nó atual
int SetIterador::operator*() const {
    return stack.top()->data;
}

// Avança o iterador para o próximo nó
SetIterador& SetIterador::operator++() {
    Node* node = stack.top();
    stack.pop();
    if (node->right != nullptr) {
        pushLeft(node->right);
    }
    return *this;
}

// Compara dois iteradores
bool SetIterador::operator!=(const SetIterador& other) const {
    return stack != other.stack;
}