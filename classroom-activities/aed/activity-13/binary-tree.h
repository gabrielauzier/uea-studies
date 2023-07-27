#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct BinaryTreeNode BinaryTreeNode;
typedef struct BinaryTreeElement BinaryTreeElement;
typedef struct BinaryTree BinaryTree;

BinaryTree * create_binary_tree();

BinaryTreeNode * bin_tree_create_node(int value);
BinaryTreeElement * bin_tree_create_element(BinaryTreeNode node);

bool bin_tree_insert(BinaryTree *tree, BinaryTreeNode *node);
void bin_tree_print(BinaryTree *tree);
