#include <stdbool.h>

#define MAX_CHAR 255

typedef struct BalancedTreeNode BalancedTreeNode;

typedef struct BalancedTree BalancedTree;

BalancedTree * btree_create_tree();
BalancedTreeNode * btree_create_node(void *data);
void bal_tree_init(BalancedTree *tree);

BalancedTreeNode * rotate_right(BalancedTreeNode *node);
BalancedTreeNode * rotate_left(BalancedTreeNode *node);

BalancedTreeNode * rotate_left_right(BalancedTreeNode *node);
BalancedTreeNode * rotate_right_left(BalancedTreeNode *node);


BalancedTreeNode * bal_tree_insert(BalancedTreeNode *root, BalancedTreeNode *node);
bool bal_tree_push(BalancedTree *tree, void *data, int key);

void bal_tree_print(BalancedTree *tree);

