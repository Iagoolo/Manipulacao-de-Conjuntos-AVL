#ifndef AVLITERADOR_HPP
#define AVLITERADOR_HPP

#include "Node.hpp"
#include <stack>

class SetIterador {

private:
    std::stack<Node*> stack;
    void pushLeft(Node* node);

public:
    SetIterador(Node* root);
    int operator*() const;
    SetIterador& operator++();
    bool operator!=(const SetIterador& other) const;
};

#endif