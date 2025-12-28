# 📚 Sistema de Gerenciamento de Livraria

<div align="center">

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Data Structures](https://img.shields.io/badge/Data_Structures-BST%20%7C%20Heap-orange?style=for-the-badge)
![Platform](https://img.shields.io/badge/Platform-Cross--Platform-brightgreen?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-yellow?style=for-the-badge)

**Sistema completo de gerenciamento de livraria utilizando Árvore Binária de Busca (BST) e Max Heap**

[🇺🇸 English Version](README.en.md) | [📖 Sobre](#-sobre-o-projeto) | [🚀 Instalação](#-instalação) | [💡 Funcionalidades](#-funcionalidades)

---

</div>

## 📋 Sobre o Projeto

O **Sistema de Gerenciamento de Livraria** é uma aplicação desenvolvida em C que demonstra o uso eficiente de estruturas de dados avançadas para organizar e gerenciar categorias de livros e seus bestsellers. O sistema utiliza:

- **Árvore Binária de Busca (BST)**: Para organização alfabética das categorias
- **Max Heap**: Para priorização dos livros mais vendidos em cada categoria

### 🎯 Objetivos

- Demonstrar domínio de **Estruturas de Dados Avançadas**
- Implementar **BST balanceada** para gerenciamento de categorias
- Utilizar **Max Heap** para ranking de vendas
- Criar sistema com **alocação dinâmica de memória**
- Aplicar **arquitetura modular** com separação de responsabilidades

### ✨ Características Principais

- 📂 **Gestão de Categorias** - Organização em BST para busca O(log n)
- 📊 **Ranking de Vendas** - Max Heap mantém os mais vendidos no topo
- 🔄 **Carregamento de CSV** - Importação automática de dados
- 📈 **Registro de Vendas** - Atualização em tempo real com rebalanceamento
- 🔍 **Consultas Rápidas** - Top 1, Top N livros mais vendidos
- 💾 **Gestão de Memória** - Alocação e liberação adequadas

---

## 🏗️ Arquitetura

### Estrutura de Diretórios

```
sistema-livraria/
├── bst.c                   # Implementação da BST
├── bst.h                   # Interface da BST
├── max_heap.c              # Implementação do Max Heap
├── max_heap.h              # Interface do Max Heap
├── file_parser.c           # Parser de arquivos CSV
├── file_parser.h           # Interface do parser
├── models.h                # Estruturas de dados
├── main.c                  # Ponto de entrada
├── makefile                # Script de compilação
├── categorias.csv          # Dados das categorias
├── romance.csv             # Livros de romance
├── tecnologia.csv          # Livros de tecnologia
└── historia.csv            # Livros de história
```

### 📊 Estruturas de Dados

#### 1. **Árvore Binária de Busca (BST)**

```c
typedef struct CategoryNode {
    int id;
    char category_name[100];
    char books_file[100];
    struct CategoryNode *left;
    struct CategoryNode *right;
} CategoryNode;
```

**Uso**: Organiza categorias alfabeticamente para busca eficiente.

**Operações**:
- Inserção: O(log n) em média
- Busca: O(log n) em média
- Travessia em ordem: O(n)

#### 2. **Max Heap**

```c
typedef struct Book {
    int isbn;
    char title[100];
    char author[100];
    int year;
    double price;
    int stock;
    int sales;
} Book;

typedef struct MaxHeap {
    Book *books;
    int size;
    int capacity;
} MaxHeap;
```

**Uso**: Mantém livros ordenados por vendas (maior no topo).

**Operações**:
- Inserção: O(log n)
- Remoção do máximo: O(log n)
- Consulta do máximo: O(1)
- Atualização (venda): O(n) busca + O(log n) rebalanceamento

### 🔄 Fluxo de Dados

```
┌─────────────────────┐
│  categorias.csv     │
│  id;nome;arquivo    │
└──────────┬──────────┘
           │
           ▼
┌─────────────────────────────┐
│   Árvore BST (Categorias)   │
│                              │
│      Tecnologia              │
│      /         \             │
│  História    Romance         │
└──────────┬──────────────────┘
           │ Selecionar
           ▼
┌─────────────────────────────┐
│    romance.csv              │
│  isbn;titulo;autor;...      │
└──────────┬──────────────────┘
           │
           ▼
┌─────────────────────────────┐
│   Max Heap (Livros)         │
│                              │
│       [200 vendas]           │
│       /         \            │
│  [150 vendas] [120 vendas]  │
└─────────────────────────────┘
```

---

## 💡 Funcionalidades

### 1️⃣ Carregar Categorias

```c
root = load_categories_file("categorias.csv");
```

- Lê arquivo CSV com categorias
- Insere em BST ordenada alfabeticamente
- Retorna ponteiro para raiz da árvore

**Formato CSV**:
```csv
id;nome_categoria;arquivo_livros
1;Romance;romance.csv
2;Tecnologia;tecnologia.csv
3;História;historia.csv
```

### 2️⃣ Listar Categorias

```c
in_ordem_traversal(root);
```

**Saída**:
```
Categorias:
 - História
 - Romance
 - Tecnologia
```

### 3️⃣ Selecionar Categoria

```c
CategoryNode *category = search_category(root, "Romance");
heap = load_books_file(category->books_file);
```

- Busca categoria na BST: O(log n)
- Carrega livros da categoria
- Constrói Max Heap baseado em vendas

### 4️⃣ Consultar Top 1

```c
consult_top_one(heap);
```

**Saída**:
```
Livro top 1:
Nome: Orgulho e Preconceito, Autor: Jane Austen, Vendas: 200
```

### 5️⃣ Listar Top N

```c
list_top_n(heap, 3);
```

**Saída**:
```
Top 1 Livro: Orgulho e Preconceito, Autor: Jane Austen, Vendas: 200
Top 2 Livro: Dom Casmurro, Autor: Machado de Assis, Vendas: 150
Top 3 Livro: O Morro dos Ventos Uivantes, Autor: Emily Bronte, Vendas: 120
```

**Implementação**:
- Cria heap temporária
- Remove máximo N vezes
- Não altera heap original

### 6️⃣ Registrar Venda

```c
register_sale(heap, isbn, quantity);
```

**Processo**:
1. Busca livro por ISBN: O(n)
2. Atualiza vendas e estoque
3. Rebalanceia heap: O(log n)

```c
// Atualização
heap->books[i].sales += quantity;
heap->books[i].stock -= quantity;

// Rebalanceamento (bubble up)
while (current > 0 && sales[current] > sales[parent]) {
    swap(current, parent);
    current = parent;
}
```

---

## 🚀 Instalação

### Pré-requisitos

- **Compilador C**: GCC, Clang ou MSVC
- **Make** (opcional)
- **Sistema Operacional**: Windows, Linux ou macOS

### Compilação

#### Usando Makefile (Recomendado)

```bash
# Clone o repositório
git clone https://github.com/JoaoGuilhermmy/sistema-livraria-c.git
cd sistema-livraria-c

# Compile
make

# Execute
./livraria          # Linux/macOS
livraria.exe        # Windows
```

#### Compilação Manual

```bash
# Linux/macOS
gcc -std=c99 -o livraria main.c bst.c max_heap.c file_parser.c

# Windows com MinGW
gcc -std=c99 -o livraria.exe main.c bst.c max_heap.c file_parser.c
```

---

## 💻 Como Usar

### Exemplo Completo de Uso

```
1. Carregar categorias
2. Listar categorias
3. Selecionar categoria
4. Mostrar top 1 livros mais vendido
5. Listar top N livros mais vendidos
6. Registrar venda
0. Sair

Digite sua escolha: 1
Arquivo 'categorias.csv' aberto com sucesso.
Leitura do arquivo de categorias concluída.

Digite sua escolha: 2
Categorias:
 - História
 - Romance
 - Tecnologia

Digite sua escolha: 3
Categorias:
 - História
 - Romance
 - Tecnologia
Digite a categoria desejada: Romance

-------------------------------
ISBN: 123, Titulo: Dom Casmurro, Autor: Machado de Assis
Ano: 1899, Preco: 39.90, Estoque: 20, Vendas: 150
-------------------------------
ISBN: 456, Titulo: Orgulho e Preconceito, Autor: Jane Austen
Ano: 1813, Preco: 29.90, Estoque: 15, Vendas: 200
-------------------------------

Digite sua escolha: 4
Livro top 1:
Nome: Orgulho e Preconceito, Autor: Jane Austen, Vendas: 200

Digite sua escolha: 6
Digite o ISBN do livro: 456
Digite a quantidade vendida: 5
```

---

## 🔧 Detalhes Técnicos

### Compatibilidade Multiplataforma

```c
// bst.c - Limpeza de tela
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

// Pausa
#ifdef _WIN32
    Sleep(3000);
#else
    sleep(3);
#endif
```

### Alocação Dinâmica

```c
// Criação de nó BST
CategoryNode *n = (CategoryNode *)malloc(sizeof(CategoryNode));
if (!n) {
    perror("malloc");
    exit(EXIT_FAILURE);
}

// Criação de heap
MaxHeap *heap = (MaxHeap *)malloc(sizeof(MaxHeap));
heap->books = (Book *)malloc(sizeof(Book) * capacity);
```

### Liberação de Memória

```c
// Liberar BST (pós-ordem)
void free_tree(CategoryNode *root) {
    if (root == NULL) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

// Liberar Heap
void free_heap(MaxHeap *heap) {
    if (heap == NULL) return;
    free(heap->books);
    free(heap);
}
```

---

## 📊 Complexidade Computacional

| Operação | BST | Max Heap | Justificativa |
|----------|-----|----------|---------------|
| Inserir categoria | O(log n) | - | Árvore balanceada em média |
| Buscar categoria | O(log n) | - | Busca binária na árvore |
| Inserir livro | - | O(log n) | Heapify up |
| Top 1 | - | O(1) | Acesso direto à raiz |
| Top N | - | O(n log n) | N remoções + heapify |
| Registrar venda | - | O(n + log n) | Busca linear + heapify |
| Listar categorias | O(n) | - | Travessia em ordem |

---

## 🎓 Conceitos de Estruturas de Dados

### Árvore Binária de Busca (BST)

**Propriedades**:
- Subárvore esquerda: valores menores
- Subárvore direita: valores maiores
- Busca eficiente: O(log n) em média

**Vantagens**:
- ✅ Busca rápida
- ✅ Inserção e remoção eficientes
- ✅ Travessia ordenada

**Aplicação no Projeto**:
- Organizar categorias alfabeticamente
- Permitir busca rápida de categorias

### Max Heap

**Propriedades**:
- Pai sempre maior que filhos
- Implementado com array
- Índices: pai = i/2, filho_esq = 2i, filho_dir = 2i+1

**Vantagens**:
- ✅ Acesso O(1) ao máximo
- ✅ Inserção/remoção O(log n)
- ✅ Ideal para priorização

**Aplicação no Projeto**:
- Manter livros mais vendidos no topo
- Consultas rápidas de bestsellers

---

## 🐛 Solução de Problemas

### Problema: Erro de compilação "undefined reference"

**Causa**: Arquivos não linkados corretamente.

**Solução**:
```bash
gcc -o livraria main.c bst.c max_heap.c file_parser.c
```

### Problema: Caracteres especiais não aparecem

**Windows**:
```bash
chcp 65001
```

**Linux/macOS**:
```bash
export LANG=pt_BR.UTF-8
```

### Problema: Vazamento de memória

**Verificação com Valgrind (Linux)**:
```bash
valgrind --leak-check=full ./livraria
```

---

## 📈 Possíveis Melhorias

### Curto Prazo
- [ ] Adicionar AVL para balanceamento automático da BST
- [ ] Implementar cache para categorias frequentes
- [ ] Adicionar validação de entrada
- [ ] Criar testes unitários

### Médio Prazo
- [ ] Interface gráfica com ncurses
- [ ] Persistência de vendas em arquivo
- [ ] Relatórios de vendas por período
- [ ] Sistema de recomendação

### Longo Prazo
- [ ] API REST em C
- [ ] Dashboard web
- [ ] Integração com banco de dados
- [ ] Sistema de múltiplos usuários

---

## 📄 Licença

Este projeto está sob a licença MIT. Consulte o arquivo [LICENSE](LICENSE) para mais detalhes.

---

## 👨‍💻 Autor

**João Guilhermmy**

- 🔗 GitHub: [https://github.com/JoaoGuilhermmy](https://github.com/JoaoGuilhermmy)
- 💼 LinkedIn: [www.linkedin.com/in/joão-guilhermmy-93661b29b](https://www.linkedin.com/in/joão-guilhermmy-93661b29b)
- 📧 Email: joaoguilhermmy2@gmail.com

---

## 🙏 Agradecimentos

- Comunidade C pela documentação excelente
- Professores e colegas que contribuíram com feedback
- Stack Overflow pelas soluções de problemas

---

<div align="center">

### ⭐ Se este projeto foi útil, considere dar uma estrela!

**Desenvolvido com ❤️ e muito ☕**

### 💡 Projeto educacional demonstrando BST e Max Heap em C

</div>
