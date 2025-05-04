#ifndef NODE_HPP
#define NODE_HPP

struct Node {
    int data;
    int height;
    Node* left;
    Node* right;

    Node(int value, Node* left = nullptr, Node* right = nullptr, int height = 1);
};

#endif