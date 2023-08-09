#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../utils/show.h"
#include "balanced-tree.h"
#define MAX_CHAR 255

typedef struct BalancedTreeNode {
    void *data;
    int key;
    struct BalancedTreeNode *left;
    struct BalancedTreeNode *right;
    int height; // node height
} BalancedTreeNode;

typedef struct BalancedTree {
    BalancedTreeNode *root;
} BalancedTree;

// btree

BalancedTree * btree_create_tree() {
    BalancedTree *newTree = malloc(sizeof (BalancedTree));
    bal_tree_init(newTree);
    return newTree;
}

BalancedTreeNode * btree_create_node(void *data) {
    BalancedTreeNode * newBalancedTreeNode = malloc(sizeof (BalancedTreeNode));
    newBalancedTreeNode->data = data;
    newBalancedTreeNode->height = 0;
    newBalancedTreeNode->left = NULL;
    newBalancedTreeNode->right = NULL;
    return newBalancedTreeNode;
}

void bal_tree_init(BalancedTree *tree) {
    tree->root = NULL;
}

int max(int x, int y){
    return (x > y) ? x : y;
}

int height(BalancedTreeNode *root) {
    return (root == NULL) ? -1 : root->height;
}

BalancedTreeNode * rotate_right(BalancedTreeNode *node) {
    BalancedTreeNode *tmp;
    tmp = node->left;
    node->left = tmp->right;
    tmp->right = node;

    node->height = max(height(node->right), height(node->left)) + 1;
    tmp->height = max(height(tmp->left), height(node)) + 1;

    return tmp;
}

BalancedTreeNode * rotate_left(BalancedTreeNode *node) {
    BalancedTreeNode *tmp;
    tmp = node->right;
    node->right = tmp->left;
    tmp->left = node;

    node->height = max(height(node->right), height(node->left)) + 1;
    tmp->height = max(height(tmp->right), height(node)) + 1;

    return tmp;
}

BalancedTreeNode * rotate_left_right(BalancedTreeNode *node) {
    node->left = rotate_left(node->left);
    return rotate_right(node);
}

BalancedTreeNode * rotate_right_left(BalancedTreeNode *node) {
    node->right = rotate_right(node->right);
    return rotate_left(node);
}

BalancedTreeNode * bal_tree_insert(BalancedTreeNode *root, BalancedTreeNode *node) {
    if (root == NULL) return node;

    if (root->key > node->key) {
        root->left = bal_tree_insert(root->left, node);

        if ((height(root->right) - height(root->left)) == 2) {
            if (node->key < root->left->key)
                root = rotate_right(root);
            else
                root = rotate_left_right(root);
        }
    } else if (root->key < node->key) {
        root->right = bal_tree_insert(root->right, node);

        if ((height(root->right) - height(root->left)) == 2) {
            if (node->key > root->right->key)
                root = rotate_left(root);
            else
                root = rotate_right_left(root);
        }
    }

    root->height = max(height(root->left), height(root->right)) + 1;
    return root;
}

bool bal_tree_push(BalancedTree *tree, void *data, int key) {
    BalancedTreeNode *newNode = malloc(sizeof (BalancedTreeNode));
    newNode->key = key;
    newNode->data = data;
    newNode->height = 0;
    newNode->left = NULL;
    newNode->right = NULL;
    tree->root = bal_tree_insert(tree->root, newNode);
    return true;
}

typedef enum Side { Root, Left, Right } Side;

void bal_tree_print_element(BalancedTreeNode *root, BalancedTreeNode *parent, Side side) {
    if (root != NULL) {

        if (parent != NULL) {
            printf("\n(%03d).%-5s --> %d",
                   parent->key,
                   (side == Left) ? "Left" : "Right",
                   root->key
            );
        } else {
            printf("\n[Root] %d\n",
                   root->key
            );
        }
        bal_tree_print_element(root->left, root, Left);
        bal_tree_print_element(root->right, root, Right);
    }

    if (root == NULL) {
        if (parent != NULL) {
            printf("\n(%03d).%-5s --> ",
                   parent->key,
                   (side == Left) ? "Left" : "Right"
            );
            show_text("NULL", MAGENTA);
        } else {
            printf("\nTREE IS EMPTY. \n");
        }
    }
}

void bal_tree_print(BalancedTree *tree) {
    bal_tree_print_element(tree->root, NULL, Root);
}