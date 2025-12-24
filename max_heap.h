#ifndef MAX_HEAP_H
#define MAX_HEAP_H
#include "models.h"

// Correção: Padronizar o nome da struct para MaxHeap (igual ao .c)
typedef struct MaxHeap
{
    Book *books;
    int size;
    int capacity;
} MaxHeap;

// Correção: Nomes das funções iguais ao max_heap.c
MaxHeap *create_heap(int capacity);
void insert_heap(MaxHeap *heap, Book book);
void print_heap(MaxHeap *heap);
void consult_top_one(MaxHeap *heap);
void heapify_down(MaxHeap *heap, int index);
void list_top_n(MaxHeap *heap, int n);
void register_sale(MaxHeap *heap, int isbn, int quantity);
void free_heap(MaxHeap *heap); // Faltava esta declaração

#endif