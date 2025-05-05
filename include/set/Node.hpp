#ifndef NODE_HPP
#define NODE_HPP

struct Node {
    int data; // Valor do nó
    int height; // Altura do nó
    Node* left;  // Ponteiro para o filho esquerdo
    Node* right; // Ponteiro para o filho direito

    // Construtor padrão
    Node(int value, Node* left = nullptr, Node* right = nullptr, int height = 1);
};

#endif