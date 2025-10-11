#include <stdlib.h>
#include <stdio.h>
#include "bst.h"
#include "file_parser.h"
#include "max_heap.h"

int main()
{
    CategoryNode *root = NULL;
    MaxHeap *heap = NULL;
    int choice;

    while (1)
    {
        clear_scream();
        printf("1. Carregar categorias \n");
        printf("2. Listar categorias\n");
        printf("3. Selecionar categoria\n");
        printf("4. Mostrar top 1 livros mais vendido\n");
        printf("5. Listar top N livros mais vendidos\n");
        printf("6. Registrar venda\n");
        printf("0. Sair\n");
        printf("Digite sua escolha: ");
        scanf("%d", &choice);

        if (choice == 0)
        {
            printf("Saindo...\n");
            free_heap(heap);
            free_tree(root);
            exit(0);
        }

        switch (choice)
        {
        case 1:
            root = load_categories_file("categorias.csv");
            break;
        case 2:
            clear_scream();
            printf("Categorias:\n");
            in_ordem_traversal(root);
            pause();
            break;
        case 3:
        {
            clear_scream();
            char category_name[100];
            free_heap(heap);
            heap = NULL;
            printf("Categorias:\n");
            in_ordem_traversal(root);

            printf("Digite a categoria desejada: ");
            scanf("%s", category_name);
            CategoryNode *category = search_category(root, category_name);

            if (category != NULL)
            {
                heap = load_books_file(category->books_file);
                print_heap(heap);
            }
            else
            {
                printf("Categoria nao encontrada\n");
            }
        }
        break;
        case 4:

            if (heap != NULL)
            {
                clear_scream();
                consult_top_one(heap);
                pause();
            }
            else
            {
                printf("Nenhum heap carregado. Selecione uma categoria primeiro.\n");
            }
            break;
        case 5:
            clear_scream();
            if (heap != NULL)
            {
                int n;
                printf("Digite o valor de N: ");
                scanf("%d", &n);
                list_top_n(heap, n);
                pause();
            }
            else
            {
                printf("Nenhum heap carregado. Selecione uma categoria primeiro.\n");
            }
            break;
        case 6:
            clear_scream();
            if (heap != NULL)
            {
                int isbn, quantity;
                print_heap(heap);
                printf("Digite o ISBN do livro: ");
                scanf("%d", &isbn);
                printf("Digite a quantidade vendida: ");
                scanf("%d", &quantity);
                register_sale(heap, isbn, quantity);
            }
            else
            {
                printf("Nenhum heap carregado. Selecione uma categoria primeiro.\n");
            }
            break;
        default:
            break;
        }
    }

    return 0;
}