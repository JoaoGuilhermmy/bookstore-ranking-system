#ifndef BST_H
#define BST_H
#include "models.h"

CategoryNode *new_node(int id, char category_name[], char books_file[]);
CategoryNode *insert_category_node(CategoryNode *root, int id, char category_name[], char books_file[]);
void in_ordem_traversal(CategoryNode *root); // Correção: retorno void
CategoryNode *search_category(CategoryNode *root, char category_name[]);
void free_tree(CategoryNode *root); // Faltava esta declaração
void pause();                       // Para que outros arquivos possam usar
void clear_scream();                // Para que outros arquivos possam usar

#endif