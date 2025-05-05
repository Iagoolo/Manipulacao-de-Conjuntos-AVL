#ifndef AVLITERADOR_HPP
#define AVLITERADOR_HPP

#include "Node.hpp"
#include <stack>

class SetIterador {

private:
    std::stack<Node*> stack; // Pilha para armazenar os nós
    void pushLeft(Node* node); // Adiciona todos os nós à esquerda do nó atual à pilha, com isso conseguimos fazer a travessia em ordem

public:
    SetIterador(Node* root); // Construtor que inicializa o iterador com a raiz da árvore
    int operator*() const; // Retorna o valor do nó atual
    SetIterador& operator++(); // Avança o iterador para o próximo nó
    bool operator!=(const SetIterador& other) const; // Compara dois iteradores
};

#endif