#include "linkedlist/linkedlist.h"
#include "threadedtree/threadedtree.h"

int main() {
    List *list1 = array_to_list((double *) &(double[]) {15}, 1);
    TNode *root = sorted_list_to_bst(list1);
    convert(root);
    insert(root, 4);
    insert(root, 20);
    insert(root, 17);
    insert(root, 19);
    print_threaded_tree(root);
    return 0;
}
