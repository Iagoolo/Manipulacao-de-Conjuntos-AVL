#ifndef SET_HPP
#define SET_HPP

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include "Set/Set.hpp"
#include "Node.hpp"
#include "SetIterador.hpp"

class Set {
private:

    Node* root;

    Node* _copy(Node* node);
    Node* _insert(Node* node, int value);
    int _height(Node* node) const;
    Node* _remove(Node* node, int value);
    bool _search(Node* node, int value) const;
    int _size(Node* node) const;
    int _sucessor(Node* node, int value);
    int _predecessor(Node* node, int value);
    void _clear(Node* node);
    int _minimum(Node* node);
    int _maximum(Node* node);
    void _inOrder(Node* node) const;
    void _unionSet(Node* node, Set& other);
    void _intersection(Node* node, Set& other);
    void _difference(Node* node, Set& other);

public:
    Set();
    Set(const Set& other);
    ~Set();

    SetIterador begin() const;
    SetIterador end() const;
    void clear();
    int getBalance(Node* node) const;
    Node* rightRotate(Node* y);
    Node* leftRotate(Node* x);
    void insert(int value);
    void erase(int value);
    bool contains(int value) const; 
    bool empty() const;
    int size() const;
    int successor(int value);
    int predecessor(int value);
    int minimum();
    int maximum();
    void swap(Set& other);
    void print() const;
    Set& operator=(const Set& other);
    int getHeight() const;
    bool isBalanced() const;

    // Métodos de operações com conjuntos
    Set unionSet(const Set& other) const;
    Set intersection(const Set& other) const;
    Set difference(const Set& other) const;
};

#endif
