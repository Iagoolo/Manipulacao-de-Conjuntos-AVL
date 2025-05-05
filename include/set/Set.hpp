#ifndef SET_HPP
#define SET_HPP

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include "set/Set.hpp"
#include "Node.hpp"
#include "SetIterador.hpp"

class Set {
private:

    Node* root;

    Node* _copy(Node* node); // Copia a árvore
    Node* _insert(Node* node, int value); // Insere um valor na árvore
    int _height(Node* node) const; // Retorna a altura da árvore
    Node* _remove(Node* node, int value); // Remove um valor da árvore
    bool _search(Node* node, int value) const; // Busca um valor na árvore
    int _size(Node* node) const; // Retorna o tamanho da árvore
    int _sucessor(Node* node, int value); // Encontra o sucessor de um valor
    int _predecessor(Node* node, int value); // Encontra o predecessor de um valor
    void _clear(Node* node); // Limpa a árvore
    int _minimum(Node* node); // Encontra o mínimo da árvore
    int _maximum(Node* node); // Encontra o máximo da árvore
    void _inOrder(Node* node) const; // Imprime a árvore em ordem
    void _unionSet(Node* node, Set& other); // Faz a união de dois conjuntos
    void _intersection(Node* node, Set& other); // Faz a interseção de dois conjuntos
    void _difference(Node* node, Set& other); // Faz a diferença de dois conjuntos

public:
    Set(); // Construtor padrão
    Set(const Set& other); // Construtor de cópia
    ~Set();   // Destrutor

    SetIterador begin() const; // Retorna o iterador para o início do conjunto
    SetIterador end() const; // Retorna o iterador para o final do conjunto
    void clear(); // Função pública clear que chama a função privada _clear
    int getBalance(Node* node) const; // Retorna o fator de balanceamento de um nó
    Node* rightRotate(Node* y);  // Rotação à direita
    Node* leftRotate(Node* x); // Rotação à esquerda
    void insert(int value); // Função pública insert que chama a função privada _insert
    void erase(int value); // Remove um valor da árvore
    bool contains(int value) const;  // Função pública contains que chama a função privada _search
    bool empty() const; // Verifica se a árvore está vazia
    int size() const; // Função pública size que chama a função privada _size
    int successor(int value); //Função pública successor que chama a função privada _sucessor
    int predecessor(int value); // Função pública predecessor que chama a função privada _predecessor
    int minimum(); // Função pública minimum que chama a função privada _minimum
    int maximum();  // Função pública maximum que chama a função privada _maximum
    void swap(Set& other); // Troca as duas árvores
    void print() const; // Imprime a árvore em ordem
    Set& operator=(const Set& other); // Sobrecarga do operador de atribuição
    int getHeight() const; // Retorna a altura da árvore
    bool isBalanced() const; // Verifica se a árvore está balanceada

    // Métodos de operações com conjuntos
    Set unionSet(const Set& other) const; // Faz a união de dois conjuntos
    Set intersection(const Set& other) const; // Faz a interseção de dois conjuntos
    Set difference(const Set& other) const; // Faz a diferença de dois conjuntos
};

#endif
