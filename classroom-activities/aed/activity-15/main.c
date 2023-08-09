#include "balanced-tree.h"
#include "../utils/show.h"

#define array_len(x) (sizeof(x) / sizeof((x)[0]))

void patients_balanced_tree() {
    show_header("Example - Patients Balanced Tree", GREEN);

    BalancedTree *tree = btree_create_tree();

    int numArray1[] = { 10, 100, 20, 80, 40, 70 };
    int numArray2[] = { 5, 10, 20, 30, 40, 50, 60 };
    int numArray[]  = { 1, 2, 3, 4, 5, 6, 7, 15, 14, 13, 12, 11, 10, 9, 8 };

    bool added;

    for (int i = 0; i < array_len(numArray); i++) {
        added = bal_tree_push(tree, &numArray[i], numArray[i]);
        show_attr_int("added", added);
    }

    bal_tree_print(tree);
}

int main() {
    init_show();
    patients_balanced_tree();
    return 0;
}