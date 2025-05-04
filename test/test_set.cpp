#include "../include/Set/Set.hpp"
#include <iostream>
#include <cassert>
#include <cmath> // para log2

void testConjunto() {
    Set S;
    Set R;

    // Teste inicial
    assert(S.empty());
    assert(S.size() == 0);

    // Inserir elementos e testar altura e balanceamento
    S.insert(10);
    assert(S.getHeight() == 1);  // Verificar altura após inserção
    assert(S.isBalanced());      // Verificar se está balanceada

    S.insert(20);
    assert(S.getHeight() == 2);  // Verificar altura após inserção
    assert(S.isBalanced());      // Verificar se está balanceada

    S.insert(5);
    assert(S.getHeight() == 2);  // Verificar altura após inserção
    assert(S.isBalanced());      // Verificar se está balanceada

    // Remover elementos e testar altura e balanceamento
    S.erase(10);
    assert(S.getHeight() == 2);  // Verificar altura após remoção
    assert(S.isBalanced());      // Verificar se está balanceada

    // Minimum & Maximum
    try {
        assert(S.minimum() == 5);
        assert(S.maximum() == 20);
    } catch (const std::runtime_error& e) {
        std::cout << "Erro ao obter o mínimo ou máximo: " << e.what() << '\n';
        assert(false);
    }

    // Successor & Predecessor
    try {
        assert(S.successor(5) == 20);
        assert(S.predecessor(20) == 5);
    } catch (const std::runtime_error& e) {
        std::cout << "Erro ao obter o sucessor ou predecessor: " << e.what() << '\n';
        assert(false);
    }

    // Clear
    S.clear();
    assert(S.empty());
    assert(S.size() == 0);

    // Swap
    S.insert(1);
    S.insert(2);
    R.insert(99);
    S.swap(R);
    assert(S.size() == 1);
    assert(R.size() == 2);
    assert(S.contains(99));
    assert(!S.contains(1));
    assert(R.contains(1));
    assert(!R.contains(99));

    // Union
    Set A, B, U;
    A.insert(1);
    A.insert(2);
    B.insert(2);
    B.insert(3);
    U = A.unionSet(B);
    assert(U.contains(1));
    assert(U.contains(2));
    assert(U.contains(3));
    assert(U.size() == 3);

    // Intersection
    Set I = A.intersection(B);
    assert(!I.contains(1));
    assert(I.contains(2));
    assert(!I.contains(3));
    assert(I.size() == 1);

    // Difference
    Set D = A.difference(B);
    assert(D.contains(1));
    assert(!D.contains(2));
    assert(!D.contains(3));
    assert(D.size() == 1);

    // Exceções esperadas
    S.clear();
    try {
        S.minimum();
        assert(false);
    } catch (const std::runtime_error&) {}

    try {
        S.maximum();
        assert(false);
    } catch (const std::runtime_error&) {}

    try {
        S.successor(10);
        assert(false);
    } catch (const std::runtime_error&) {}

    try {
        S.predecessor(10);
        assert(false);
    } catch (const std::runtime_error&) {}

    std::cout << "Todos os testes passaram!\n";
}

int main() {
    testConjunto();
    return 0;
}
