# 📚 Projeto: Manipulação de Conjuntos com Árvores AVL

Este projeto é um sistema interativo em C++ para criação, manipulação e operações entre conjuntos de inteiros, utilizando **árvores AVL** para garantir eficiência nas operações. Os conjuntos possuem **nomes personalizados** e suportam **diversas operações clássicas**, como união, interseção, diferença, etc.

---

## ✅ Requisitos

* Compilador C++ com suporte ao C++11 ou superior (GCC recomendado)
* `make` instalado
* Terminal compatível com comandos POSIX (ex: `clear`)

---

## 📁 Organização do Projeto

```
📦 raiz-do-projeto
├── include/
│   └── set/
│       ├── Set.hpp
│       ├── Node.hpp
│       └── SetIterador.hpp
├── src/
│   ├── main/
│   │   └── main.cpp
│   └── set/
│       ├── Set.cpp
│       ├── Node.cpp
│       └── SetIterador.cpp
├── test/
│   └── test_set.cpp
├── Makefile
└── README.md
```

---

## ⚙️ Como compilar

1. Abra o terminal na raiz do projeto.
2. Digite:

```bash
make
```

O executável `main` será gerado.

---

## ▶️ Como executar

Após compilar, você pode executar o programa com:

```bash
make run
```

Esse comando compila (se necessário) e **executa automaticamente** o binário principal.

### ⚠️ Problemas ao rodar?

Se ocorrer algum erro (como falha de execução, conflitos de compilação ou binário desatualizado), use:

```bash
make clean
make run
```

Isso irá limpar os arquivos gerados e recompilar do zero, o que costuma resolver a maioria dos problemas.

---

## 🧠 Funcionalidades do Menu

1. Criar novo conjunto com nome personalizado
2. Inserir um ou mais elementos
3. Mostrar elementos de um conjunto
4. União de múltiplos conjuntos
5. Interseção de múltiplos conjuntos
6. Diferença entre conjuntos (ex: A - B - C)
7. Exibir o menor e maior elemento
8. Ver tamanho do conjunto
9. Buscar sucessor e predecessor de um elemento
10. Remover elemento
11. Verificar se elemento está contido
12. Trocar conteúdos de dois conjuntos
13. Apagar todos os elementos de um conjunto
14. Sair

---

## 🧪 Testes

Para testar funcionalidades automaticamente, adicione casos ao arquivo:

```
test/test_set.cpp
```

Depois, compile e execute os testes com:

```bash
make test
./test/test
```

---

## 🧹 Limpando os arquivos

Para remover os binários gerados e arquivos temporários:

```bash
make clean
```

---

## 📌 Observações

* Os nomes dos conjuntos são **case-sensitive**.
* A árvore AVL garante que operações como inserção, remoção, busca, predecessor e sucessor sejam executadas em **tempo logarítmico**.
* O projeto está modularizado com separação clara entre headers (`include/set`) e implementações (`src/set`), seguindo boas práticas de organização.
* Ao executar o programa será pedido para apertar enter, isso é para limpar o terminal.

---
