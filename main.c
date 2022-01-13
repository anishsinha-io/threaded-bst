#include "linkedlist/linkedlist.h"
#include "threadedtree/threadedtree.h"
#include <stdio.h>

int main() {
    List *list1 = array_to_list((double *) &(double[]) {1, 2, 3, 4, 5, 6, 7, 8}, 8);
    TNode *root = sorted_list_to_bst(list1);
    convert(root);
    print_threaded_tree(root);
    return 0;
}
