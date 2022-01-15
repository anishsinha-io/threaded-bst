#include "linkedlist/linkedlist.h"
#include <stdbool.h>

#ifndef THREADEDBINARYSEARCHTREE_BST_H
#define THREADEDBINARYSEARCHTREE_BST_H

typedef struct TNode TNode;

void inorder_traversal(TNode *);
TNode *sorted_list_to_bst(List *);
TNode *leftmost_node(TNode *);
void convert(TNode *);
void print_threaded_tree(TNode *);
void insert(TNode *, double);

#endif //THREADEDBINARYSEARCHTREE_BST_H
