#include "max_heap.h"
#include <stdlib.h>
#include <stdio.h>
#include "bst.h"

MaxHeap *create_heap(int capacity)
{
    MaxHeap *heap = (MaxHeap *)malloc(sizeof(MaxHeap));
    heap->books = (Book *)malloc(sizeof(Book) * capacity);
    heap->capacity = capacity;
    heap->size = 0;

    return heap;
}

void insert_heap(MaxHeap *heap, Book book)
{
    if (heap->size == heap->capacity)
    {
        printf("Heap cheio\n");
        return;
    }
    heap->books[heap->size] = book;
    heap->size++;

    int s = heap->size - 1;

    while (s > 0 && heap->books[s].sales > heap->books[(s - 1) / 2].sales)
    {
        Book temp = heap->books[s];
        heap->books[s] = heap->books[(s - 1) / 2];
        heap->books[(s - 1) / 2] = temp;
        s = (s - 1) / 2;
    }
}

void print_heap(MaxHeap *heap)
{
    printf("-------------------------------\n");
    for (int i = 0; i < heap->size; i++)
    {
        printf("ISBN: %d, Titulo: %s, Autor: %s, Ano: %d, Preco: %.2f, Estoque: %d, Vendas: %d\n",
               heap->books[i].isbn,
               heap->books[i].title,
               heap->books[i].author,
               heap->books[i].year,
               heap->books[i].price,
               heap->books[i].stock,
               heap->books[i].sales);
        printf("-------------------------------\n");
    }
    pause();
}

void consult_top_one(MaxHeap *heap)
{
    if (heap->size == 0)
    {
        printf("Heap vazio\n");
        return;
    }

    printf("Livro top 1:\n");
    printf("Nome: %s , Autor: %s , Vendas: %d", heap->books[0].title, heap->books[0].author, heap->books[0].sales);
}

void heapify_down(MaxHeap *heap, int index)
{
    int largest = index;
    int son_left = 2 * index + 1;
    int son_right = 2 * index + 2;

    if (son_left < heap->size && heap->books[son_left].sales > heap->books[largest].sales)
    {
        largest = son_left;
    }

    if (son_right < heap->size && heap->books[son_right].sales > heap->books[largest].sales)
    {
        largest = son_right;
    }

    if (largest != index)
    {
        Book temp = heap->books[index];
        heap->books[index] = heap->books[largest];
        heap->books[largest] = temp;
        heapify_down(heap, largest);
    }
}

void list_top_n(MaxHeap *heap, int n)
{
    if (n > heap->size)
    {
        printf("Você solicitou %d livros, mas só existem %d. Mostrando todos.\n", n, heap->size);
        n = heap->size;
    }

    MaxHeap *temp_heap = create_heap(heap->capacity);
    for (int i = 0; i < heap->size; i++)
    {
        temp_heap->books[i] = heap->books[i];
    }
    temp_heap->size = heap->size;

    for (int i = 0; i < n; i++)
    {
        printf("Top %d Livro: %s, Autor: %s, Ano: %d, Preco: %.2f, Estoque: %d, Vendas: %d\n", (i + 1), temp_heap->books[0].title, temp_heap->books[0].author, temp_heap->books[0].year, temp_heap->books[0].price, temp_heap->books[0].stock, temp_heap->books[0].sales);

        Book temp = temp_heap->books[0];
        temp_heap->books[0] = temp_heap->books[temp_heap->size - 1];
        temp_heap->books[temp_heap->size - 1] = temp;
        temp_heap->size--;
        heapify_down(temp_heap, 0);
    }
    free_heap(temp_heap);
}

void register_sale(MaxHeap *heap, int isbn, int quantity)
{
    int found = 0;
    for (int i = 0; i < heap->size; i++)
    {
        if (heap->books[i].isbn == isbn)
        {
            heap->books[i].sales += quantity;
            heap->books[i].stock -= quantity;

            int current_index = i;

            while (current_index > 0 && heap->books[current_index].sales > heap->books[(current_index - 1) / 2].sales)
            {
                Book temp = heap->books[current_index];
                heap->books[current_index] = heap->books[(current_index - 1) / 2];
                heap->books[(current_index - 1) / 2] = temp;
                current_index = (current_index - 1) / 2;
            }
            found = 1;
            break;
        }
    }
    if (found == 0)
    {
        printf("Livro com ISBN %d nao encontrado no heap.\n", isbn);
    }
}

void free_heap(MaxHeap *heap)
{
    if (heap == NULL)
        return;
    free(heap->books);
    free(heap);
}