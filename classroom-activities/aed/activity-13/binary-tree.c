#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../utils/show.h"

typedef struct BinaryTreeNode {
    int value;
} BinaryTreeNode;

typedef struct BinaryTreeElement {
    BinaryTreeNode node;
    struct BinaryTreeElement *right;
    struct BinaryTreeElement *left;
} BinaryTreeElement;

typedef struct BinaryTree {
    BinaryTreeElement *root;
} BinaryTree;

BinaryTree * create_binary_tree() {
    BinaryTree *new = malloc(sizeof (BinaryTree));
    new->root = NULL;
    return new;
}

BinaryTreeNode * bin_tree_create_node(int value) {
    BinaryTreeNode *new = malloc(sizeof (BinaryTreeNode));
    new->value = value;
    return new;
}

BinaryTreeElement * bin_tree_create_element(BinaryTreeNode node) {
    BinaryTreeElement *new = malloc(sizeof (BinaryTreeElement));
    new->node = node;
    new->right = NULL;
    new->left = NULL;
    return new;
}

BinaryTreeElement * tree_insert_element(BinaryTreeElement *root, BinaryTreeElement *element) {
    if (root == NULL) {
        return element;
    }

    if (root->node.value > element->node.value) {
        root->left = tree_insert_element(root->left, element);
    } else {
        root->right = tree_insert_element(root->right, element);
    }

    return root;
}

bool bin_tree_insert(BinaryTree *tree, BinaryTreeNode *node) {
    BinaryTreeElement *e = bin_tree_create_element(*node);
    tree->root = tree_insert_element(tree->root, e);

    return true;
}

typedef enum Side { Root, Left, Right } Side;

void tree_print_element(BinaryTreeElement *root, BinaryTreeElement *parent, Side side) {
    if (root != NULL) {

        if (parent != NULL) {
            printf("\n(%03d).%-5s --> %d",
                parent->node.value,
                (side == Left) ? "Left" : "Right",
                root->node.value
            );
        } else {
            printf("\n[Root] %d\n",
                root->node.value
            );
        }
        tree_print_element(root->left, root, Left);
        tree_print_element(root->right, root, Right);
    }

    if (root == NULL) {
        if (parent != NULL) {
            printf("\n(%03d).%-5s --> ",
                parent->node.value,
                (side == Left) ? "Left" : "Right"
            );
            show_text("NULL", MAGENTA);
        } else {
            printf("\nTREE IS EMPTY. \n");
        }
    }
}

void bin_tree_print(BinaryTree *tree) {
    tree_print_element(tree->root, NULL, Root);
}

BinaryTreeElement * bin_tree_search_element(BinaryTreeElement *root, int target) {
    if (root == NULL) return NULL;

    if (root->node.value == target) return root;

    if (root->node.value > target) {
        return bin_tree_search_element(root->left, target);
    } else {
        return bin_tree_search_element(root->right, target);
    }
}

BinaryTreeNode * bin_tree_search(BinaryTree *tree, int target) {
    BinaryTreeElement *e = bin_tree_search_element(tree->root, target);
    return &e->node;
}

