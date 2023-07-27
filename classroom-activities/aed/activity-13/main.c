#include <stdio.h>

#include "binary-tree.h"
#include "../utils/show.h"

void init_main() {
    init_show();
}

void binary_tree() {
    show_header("Data structure - binary tree", GREEN);
    show_close();
    BinaryTree *tree = create_binary_tree();
    BinaryTreeNode *root = bin_tree_create_node(13);
    BinaryTreeNode *a = bin_tree_create_node(15);
    BinaryTreeNode *b = bin_tree_create_node(9);
    BinaryTreeNode *c = bin_tree_create_node(3);

    bin_tree_insert(tree, root);
    bin_tree_insert(tree, a);
    bin_tree_insert(tree, b);
    bin_tree_insert(tree, c);

    bin_tree_print(tree);
    endline();
}

int main() {
    init_main();

    binary_tree();

    return 0;
}