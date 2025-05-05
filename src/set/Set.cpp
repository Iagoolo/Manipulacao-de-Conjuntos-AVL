#include "set/Set.hpp"

// Métodos privados
Node* Set::_copy(Node* node) {
    if (node == nullptr) {
        return nullptr;
    }

    Node* newNode = new Node(node->data, nullptr, nullptr, node->height);

    newNode->left = _copy(node->left);
    newNode->right = _copy(node->right);

    return newNode;
}

Node* Set::_insert(Node* node, int value) {
    if (node == nullptr) {
        return new Node(value, nullptr, nullptr, 1);
    }

    if (value < node->data) {
        node->left = _insert(node->left, value);
    } else if (value > node->data) {
        node->right = _insert(node->right, value);
    } else {
        return node;
    }

    node->height = 1 + std::max(_height(node->left), _height(node->right));
    int balance = getBalance(node);

    if (balance > 1 && value < node->left->data) {
        return rightRotate(node);
    }
    if (balance < -1 && value > node->right->data) {
        return leftRotate(node);
    }
    if (balance > 1 && value > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && value < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

int Set::_height(Node* node) const {
    if (node == nullptr) {
        return 0;
    }
    
    return node->height;
}

Node* Set::_remove(Node* node, int value) {
    if (node == nullptr) {
        return node;
    }

    if (value < node->data) {
        node->left = _remove(node->left, value);
    } else if (value > node->data) {
        node->right = _remove(node->right, value);
    } else {
        if ((node->left == nullptr) || (node->right == nullptr)) {
            Node* temp = node->left ? node->left : node->right;

            if (temp == nullptr) {
                temp = node;
                node = nullptr;
            } else {
                *node = *temp;
            }
            delete temp;
        } else {
            Node* temp = node->right;
            while (temp && temp->left != nullptr) {
                temp = temp->left;
            }
            node->data = temp->data;
            node->right = _remove(node->right, temp->data);
        }
    }

    if (node == nullptr) {
        return node;
    }

    node->height = 1 + std::max(_height(node->left), _height(node->right));
    int balance = getBalance(node);

    if (balance > 1 && getBalance(node->left) >= 0) {
        return rightRotate(node);
    }
    if (balance < -1 && getBalance(node->right) <= 0) {
        return leftRotate(node);
    }
    if (balance > 1 && getBalance(node->left) < 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && getBalance(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

bool Set::_search(Node* node, int value) const {
    if (node == nullptr) {
        return false;
    }

    if (value < node->data) {
        return _search(node->left, value);
    } else if (value > node->data) {
        return _search(node->right, value);
    } else {
        return true;
    }
}

int Set::_size(Node* node) const {
    if (node == nullptr) {
        return 0;
    }
    return 1 + _size(node->left) + _size(node->right);
}

int Set::_sucessor(Node* node, int value) {
    Node* sucessor = nullptr;
    Node* aux = node;

    while (aux != nullptr) {
        if (value < aux->data) {
            sucessor = aux;
            aux = aux->left;
        } else if (value > aux->data) {
            aux = aux->right;
        } else {
            if (aux->right) {
                Node* temp = aux->right;
                while (temp->left)
                    temp = temp->left;
                return temp->data;
            }
            break;
        }
    }

    if (sucessor != nullptr) {
        return sucessor->data;
    } else {
        throw std::runtime_error("Sucessor não encontrado.");
    }
}

int Set::_predecessor(Node* node, int value) {
    Node* predecessor = nullptr;
    Node* aux = node;

    while (aux != nullptr) {
        if (value < aux->data) {
            aux = aux->left;
        } else if (value > aux->data) {
            predecessor = aux;
            aux = aux->right;
        } else {
            if (aux->left) {
                Node* temp = aux->left;
                while (temp->right)
                    temp = temp->right;
                return temp->data;
            }
            break;
        }
    }

    if (predecessor != nullptr) {
        return predecessor->data;
    } else {
        throw std::runtime_error("Predecessor não encontrado.");
    }
}

void Set::_clear(Node* node) {
    if (node == nullptr) {
        return;
    }

    _clear(node->left);
    _clear(node->right);
    delete node;
}

int Set::_minimum(Node* node) {
    if (node == nullptr) {
        throw std::runtime_error("Árvore vazia.");
    }

    Node* aux = node;
    while (aux->left != nullptr) {
        aux = aux->left;
    }

    return aux->data;
}

int Set::_maximum(Node* node) {
    if (node == nullptr) {
        throw std::runtime_error("Árvore vazia.");
    }

    Node* aux = node;
    while (aux->right != nullptr) {
        aux = aux->right;
    }

    return aux->data;
}

void Set::_inOrder(Node* node) const {
    if (node == nullptr) {
        return;
    }

    _inOrder(node->left);
    std::cout << node->data << " ";
    _inOrder(node->right);
}

// Construtor
Set::Set() {
    root = nullptr;
}

// Construtor de cópia
Set::Set(const Set& other) {
    root = _copy(other.root);
}

// Destrutor
// Libera a memória alocada para os nós da árvore
Set::~Set() {
    _clear(root);
}

// Métodos públicos 
SetIterador Set::begin() const{
    return SetIterador(root);
}

SetIterador Set::end() const{
    return SetIterador(nullptr);
}

void Set::clear() {
    _clear(root);
    root = nullptr;
}

int Set::getBalance(Node* node) const {
    if (node == nullptr) {
        return 0;
    }
    return _height(node->left) - _height(node->right);
}

Node* Set::rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = std::max(_height(y->left), _height(y->right)) + 1;
    x->height = std::max(_height(x->left), _height(x->right)) + 1;

    return x;
}

Node* Set::leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = std::max(_height(x->left), _height(x->right)) + 1;
    y->height = std::max(_height(y->left), _height(y->right)) + 1;

    return y;
}

void Set::insert(int value) {
    root = _insert(root, value);
}

void Set::erase(int value) {
    root = _remove(root, value);
}

bool Set::contains(int value) const {
    return _search(root, value);
}

bool Set::empty() const {
    return root == nullptr;
}

int Set::size() const {
    return _size(root);
}

int Set::successor(int value) {
    return _sucessor(root, value);
}

int Set::predecessor(int value) {
    return _predecessor(root, value);
}

int Set::minimum() {
    return _minimum(root);
}

int Set::maximum() {
    return _maximum(root);
}

void Set::swap(Set& other) {
    Node* temp = root;
    root = other.root;
    other.root = temp;
}

void Set::print() const {
    std::cout << "Conjunto: { ";
    _inOrder(root);
    std::cout << "}" << std::endl;
}

Set& Set::operator=(const Set& other) {
    if (this != &other) {
        _clear(root);
        root = _copy(other.root);
    }
    return *this;
}

int Set::getHeight() const {
    return _height(root);
}

bool Set::isBalanced() const {
    return getBalance(root) >= -1 && getBalance(root) <= 1;
}

Set Set::unionSet(const Set& other) const {
    Set result = *this;
    for (auto it = other.begin(); it != other.end(); ++it) {
        result.insert(*it);
    }
    return result;
}

Set Set::intersection(const Set& other) const {
    Set result;
    for (auto it = begin(); it != end(); ++it) {
        if (other.contains(*it)) {
            result.insert(*it);
        }
    }
    return result;
}

Set Set::difference(const Set& other) const {
    Set result;
    for (auto it = begin(); it != end(); ++it) {
        if (!other.contains(*it)) {
            result.insert(*it);
        }
    }
    return result;
}
