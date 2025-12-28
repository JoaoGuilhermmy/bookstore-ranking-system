# 📚 Bookstore Management System

<div align="center">

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Data Structures](https://img.shields.io/badge/Data_Structures-BST%20%7C%20Heap-orange?style=for-the-badge)
![Platform](https://img.shields.io/badge/Platform-Cross--Platform-brightgreen?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-yellow?style=for-the-badge)

**Complete bookstore management system using Binary Search Tree (BST) and Max Heap**

[🇧🇷 Versão em Português](README.md) | [📖 About](#-about-the-project) | [🚀 Installation](#-installation) | [💡 Features](#-features)

---

</div>

## 📋 About the Project

The **Bookstore Management System** is an application developed in C that demonstrates the efficient use of advanced data structures to organize and manage book categories and their bestsellers. The system uses:

- **Binary Search Tree (BST)**: For alphabetical organization of categories
- **Max Heap**: For prioritization of best-selling books in each category

### 🎯 Objectives

- Demonstrate mastery of **Advanced Data Structures**
- Implement **balanced BST** for category management
- Use **Max Heap** for sales ranking
- Create system with **dynamic memory allocation**
- Apply **modular architecture** with separation of concerns

### ✨ Key Features

- 📂 **Category Management** - BST organization for O(log n) search
- 📊 **Sales Ranking** - Max Heap keeps bestsellers at the top
- 🔄 **CSV Loading** - Automatic data import
- 📈 **Sales Recording** - Real-time update with rebalancing
- 🔍 **Fast Queries** - Top 1, Top N best-selling books
- 💾 **Memory Management** - Proper allocation and deallocation

---

## 🏗️ Architecture

### Directory Structure

```
bookstore-system/
├── bst.c                   # BST implementation
├── bst.h                   # BST interface
├── max_heap.c              # Max Heap implementation
├── max_heap.h              # Max Heap interface
├── file_parser.c           # CSV file parser
├── file_parser.h           # Parser interface
├── models.h                # Data structures
├── main.c                  # Entry point
├── makefile                # Build script
├── categorias.csv          # Category data
├── romance.csv             # Romance books
├── tecnologia.csv          # Technology books
└── historia.csv            # History books
```

### 📊 Data Structures

#### 1. **Binary Search Tree (BST)**

```c
typedef struct CategoryNode {
    int id;
    char category_name[100];
    char books_file[100];
    struct CategoryNode *left;
    struct CategoryNode *right;
} CategoryNode;
```

**Usage**: Organizes categories alphabetically for efficient search.

**Operations**:
- Insertion: O(log n) average
- Search: O(log n) average
- In-order traversal: O(n)

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

**Usage**: Maintains books sorted by sales (highest at top).

**Operations**:
- Insertion: O(log n)
- Remove maximum: O(log n)
- Query maximum: O(1)
- Update (sale): O(n) search + O(log n) rebalance

### 🔄 Data Flow

```
┌─────────────────────┐
│  categorias.csv     │
│  id;name;file       │
└──────────┬──────────┘
           │
           ▼
┌─────────────────────────────┐
│   BST Tree (Categories)     │
│                              │
│      Technology              │
│      /         \             │
│  History     Romance         │
└──────────┬──────────────────┘
           │ Select
           ▼
┌─────────────────────────────┐
│    romance.csv              │
│  isbn;title;author;...      │
└──────────┬──────────────────┘
           │
           ▼
┌─────────────────────────────┐
│   Max Heap (Books)          │
│                              │
│       [200 sales]            │
│       /         \            │
│  [150 sales] [120 sales]    │
└─────────────────────────────┘
```

---

## 💡 Features

### 1️⃣ Load Categories

```c
root = load_categories_file("categorias.csv");
```

- Reads CSV file with categories
- Inserts into alphabetically ordered BST
- Returns pointer to tree root

**CSV Format**:
```csv
id;category_name;books_file
1;Romance;romance.csv
2;Technology;tecnologia.csv
3;History;historia.csv
```

### 2️⃣ List Categories

```c
in_ordem_traversal(root);
```

**Output**:
```
Categories:
 - History
 - Romance
 - Technology
```

### 3️⃣ Select Category

```c
CategoryNode *category = search_category(root, "Romance");
heap = load_books_file(category->books_file);
```

- Search category in BST: O(log n)
- Load category books
- Build Max Heap based on sales

### 4️⃣ Query Top 1

```c
consult_top_one(heap);
```

**Output**:
```
Top 1 Book:
Name: Pride and Prejudice, Author: Jane Austen, Sales: 200
```

### 5️⃣ List Top N

```c
list_top_n(heap, 3);
```

**Output**:
```
Top 1 Book: Pride and Prejudice, Author: Jane Austen, Sales: 200
Top 2 Book: Dom Casmurro, Author: Machado de Assis, Sales: 150
Top 3 Book: Wuthering Heights, Author: Emily Bronte, Sales: 120
```

**Implementation**:
- Creates temporary heap
- Removes maximum N times
- Does not alter original heap

### 6️⃣ Register Sale

```c
register_sale(heap, isbn, quantity);
```

**Process**:
1. Search book by ISBN: O(n)
2. Update sales and stock
3. Rebalance heap: O(log n)

```c
// Update
heap->books[i].sales += quantity;
heap->books[i].stock -= quantity;

// Rebalancing (bubble up)
while (current > 0 && sales[current] > sales[parent]) {
    swap(current, parent);
    current = parent;
}
```

---

## 🚀 Installation

### Prerequisites

- **C Compiler**: GCC, Clang or MSVC
- **Make** (optional)
- **Operating System**: Windows, Linux or macOS

### Compilation

#### Using Makefile (Recommended)

```bash
# Clone the repository
git clone https://github.com/JoaoGuilhermmy/bookstore-system-c.git
cd bookstore-system-c

# Compile
make

# Run
./livraria          # Linux/macOS
livraria.exe        # Windows
```

#### Manual Compilation

```bash
# Linux/macOS
gcc -std=c99 -o livraria main.c bst.c max_heap.c file_parser.c

# Windows with MinGW
gcc -std=c99 -o livraria.exe main.c bst.c max_heap.c file_parser.c
```

---

## 💻 How to Use

### Complete Usage Example

```
1. Load categories
2. List categories
3. Select category
4. Show top 1 best-selling book
5. List top N best-selling books
6. Register sale
0. Exit

Enter your choice: 1
File 'categorias.csv' opened successfully.
Category file reading completed.

Enter your choice: 2
Categories:
 - History
 - Romance
 - Technology

Enter your choice: 3
Categories:
 - History
 - Romance
 - Technology
Enter desired category: Romance

-------------------------------
ISBN: 123, Title: Dom Casmurro, Author: Machado de Assis
Year: 1899, Price: 39.90, Stock: 20, Sales: 150
-------------------------------
ISBN: 456, Title: Pride and Prejudice, Author: Jane Austen
Year: 1813, Price: 29.90, Stock: 15, Sales: 200
-------------------------------

Enter your choice: 4
Top 1 Book:
Name: Pride and Prejudice, Author: Jane Austen, Sales: 200

Enter your choice: 6
Enter book ISBN: 456
Enter quantity sold: 5
```

---

## 🔧 Technical Details

### Cross-Platform Compatibility

```c
// bst.c - Screen clearing
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

// Pause
#ifdef _WIN32
    Sleep(3000);
#else
    sleep(3);
#endif
```

### Dynamic Allocation

```c
// BST node creation
CategoryNode *n = (CategoryNode *)malloc(sizeof(CategoryNode));
if (!n) {
    perror("malloc");
    exit(EXIT_FAILURE);
}

// Heap creation
MaxHeap *heap = (MaxHeap *)malloc(sizeof(MaxHeap));
heap->books = (Book *)malloc(sizeof(Book) * capacity);
```

### Memory Deallocation

```c
// Free BST (post-order)
void free_tree(CategoryNode *root) {
    if (root == NULL) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

// Free Heap
void free_heap(MaxHeap *heap) {
    if (heap == NULL) return;
    free(heap->books);
    free(heap);
}
```

---

## 📊 Computational Complexity

| Operation | BST | Max Heap | Justification |
|-----------|-----|----------|---------------|
| Insert category | O(log n) | - | Balanced tree on average |
| Search category | O(log n) | - | Binary search in tree |
| Insert book | - | O(log n) | Heapify up |
| Top 1 | - | O(1) | Direct root access |
| Top N | - | O(n log n) | N removals + heapify |
| Register sale | - | O(n + log n) | Linear search + heapify |
| List categories | O(n) | - | In-order traversal |

---

## 🎓 Data Structures Concepts

### Binary Search Tree (BST)

**Properties**:
- Left subtree: smaller values
- Right subtree: larger values
- Efficient search: O(log n) average

**Advantages**:
- ✅ Fast search
- ✅ Efficient insertion and removal
- ✅ Ordered traversal

**Application in Project**:
- Organize categories alphabetically
- Allow fast category search

### Max Heap

**Properties**:
- Parent always greater than children
- Implemented with array
- Indices: parent = i/2, left_child = 2i, right_child = 2i+1

**Advantages**:
- ✅ O(1) access to maximum
- ✅ O(log n) insertion/removal
- ✅ Ideal for prioritization

**Application in Project**:
- Keep best-selling books at top
- Fast bestseller queries

---

## 🐛 Troubleshooting

### Problem: "undefined reference" compilation error

**Cause**: Files not linked correctly.

**Solution**:
```bash
gcc -o livraria main.c bst.c max_heap.c file_parser.c
```

### Problem: Special characters don't appear

**Windows**:
```bash
chcp 65001
```

**Linux/macOS**:
```bash
export LANG=en_US.UTF-8
```

### Problem: Memory leak

**Check with Valgrind (Linux)**:
```bash
valgrind --leak-check=full ./livraria
```

---

## 📈 Possible Improvements

### Short Term
- [ ] Add AVL for automatic BST balancing
- [ ] Implement cache for frequent categories
- [ ] Add input validation
- [ ] Create unit tests

### Medium Term
- [ ] GUI with ncurses
- [ ] Sales persistence to file
- [ ] Sales reports by period
- [ ] Recommendation system

### Long Term
- [ ] REST API in C
- [ ] Web dashboard
- [ ] Database integration
- [ ] Multi-user system

---

## 📄 License

This project is under the MIT license. See the [LICENSE](LICENSE) file for more details.

---

## 👨‍💻 Author

**João Guilhermmy**

- 🔗 GitHub: [https://github.com/JoaoGuilhermmy](https://github.com/JoaoGuilhermmy)
- 💼 LinkedIn: [www.linkedin.com/in/joão-guilhermmy-93661b29b](https://www.linkedin.com/in/joão-guilhermmy-93661b29b)
- 📧 Email: joaoguilhermmy2@gmail.com

---

## 🙏 Acknowledgments

- C community for excellent documentation
- Professors and colleagues who contributed with feedback
- Stack Overflow for problem solutions

---

<div align="center">

### ⭐ If this project was useful, consider giving it a star!

**Developed with ❤️ and lots of ☕**

### 💡 Educational project demonstrating BST and Max Heap in C

</div>
