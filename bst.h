#ifndef BST_H
#define BST_H
#include "models.h"

CategoryNode *new_node(int id, char category_name[], char books_file[]);
CategoryNode *insert_category_node(CategoryNode *root, int id, char category_name[], char books_file[]);
void in_ordem_traversal(CategoryNode *root);
CategoryNode *search_category(CategoryNode *root, char category_name[]);
void free_tree(CategoryNode *root);
void clear_scream();
void pause();
#endif
