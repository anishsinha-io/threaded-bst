#include <stdlib.h>
#include <stdbool.h>
#include "linkedlist/linkedlist.h"
#include <stdio.h>

typedef struct TNode {
    double val;
    struct TNode *left;
    struct TNode *right;
    bool right_thread;
} TNode;

static TNode *new_tnode(double val) {
    TNode *new_tnode = malloc(sizeof(TNode));
    new_tnode->left = new_tnode->right = NULL;
    new_tnode->val = val;
    new_tnode->right_thread = false;
    return new_tnode;
}

double node_val(TNode *t) {
    return t->val;
}


static TNode *sorted_list_to_bst_recursive(ListNode **head_pointer, int length) {
    if (length < 1) return NULL;
    TNode *left = sorted_list_to_bst_recursive(head_pointer, length / 2);
    TNode *root = new_tnode(val((*head_pointer)));
    root->left = left;
    *head_pointer = inc_pointer((*head_pointer), 1);
    root->right = sorted_list_to_bst_recursive(head_pointer, length - length / 2 - 1);
    return root;
}

static void visit(TNode *r) {
    printf("%f\t", node_val(r));
}

TNode *sorted_list_to_bst(List *l) {
    List *clone = clone_deep(l);
    ListNode *head_pointer = get_head(clone);
    int length = (int) get_length(clone);
    TNode *root = sorted_list_to_bst_recursive(&head_pointer, length);
    clone = NULL;
    head_pointer = NULL;
    free(head_pointer);
    free(clone);
    return root;
}

void inorder_traversal(TNode *r) {
    if (r != NULL) {
        inorder_traversal(r->left);
        visit(r);
        inorder_traversal(r->right);
    }
}

TNode *leftmost_node(TNode *t) {
    if (t == NULL) return NULL;
    while (t->left != NULL) t = t->left;
    return t;
}

static void inorder(TNode *root, TNode *prev) {
    if (root == NULL) return;
    inorder(root->right, prev);
    if (root->right == NULL && prev != NULL) {
        root->right = prev;
        root->right_thread = true;
    }
    inorder(root->left, root);
}

void convert(TNode *root) {
    inorder(root, NULL);
}

void print_threaded_tree(TNode *root) {
    TNode *curr = leftmost_node(root);
    while (curr != NULL) {
        printf("%f\t", curr->val);
        if (curr->right_thread) curr = curr->right;
        else curr = leftmost_node(curr->right);
    }
    printf("\n");
}

void insert(TNode *r, double val) {
    TNode *p, *prev = NULL, *new_node;
    new_node = new_tnode(val);
    if (r == NULL) return;
    p = r;
    while (p != NULL) {
        prev = p;
        if (p->val > val) p = p->left;
        else if (p->right_thread == false) p = p->right;
        else break;
    }
    if (prev->val > val) {
        prev->left = new_node;
        new_node->right_thread = true;
        new_node->right = prev;
    } else if (prev->right_thread == true) {
        new_node->right_thread = true;
        prev->right_thread = false;
        new_node->right = prev->right;
        prev->right = new_node;
    } else prev->right = new_node;
}