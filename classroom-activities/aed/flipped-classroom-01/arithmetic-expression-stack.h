/*
 * Arithmetic Expression Stack (artexpstack)
 *
 * Implemented using Simple Dynamic Stack (sds)
 *
 * Basic operations for stack: push, pop, isEmpty, isFull, peek (without removing)
 *
 * */

typedef struct ArithmeticExpressionNode {
    int value;
    char valueChar;
} ArithmeticExpressionNode;

typedef struct ArithmeticExpressionElement {
    ArithmeticExpressionNode node;
    struct ArithmeticExpressionElement *next;
} ArithmeticExpressionElement;

typedef struct ArithmeticExpressionStack {
    ArithmeticExpressionElement *top;
} ArithmeticExpressionStack;

ArithmeticExpressionStack * artexpstack_create_stack();
ArithmeticExpressionStack * artexpstack_create_stack_by_exp(char *exp);
ArithmeticExpressionNode * artexpstack_create_node(int value, char valueChar);

void artexpstack_push_node(ArithmeticExpressionStack *src, ArithmeticExpressionNode newNode);
ArithmeticExpressionNode artexpstack_pop_node(ArithmeticExpressionStack *src);
ArithmeticExpressionNode artexpstack_peek_node(ArithmeticExpressionStack *src);

int artexpstack_is_empty(ArithmeticExpressionStack *src);

void artexpstack_delete_stack(ArithmeticExpressionNode *src);
void artexpstack_print_stack(ArithmeticExpressionStack *src);
void artexpstack_print_node(ArithmeticExpressionNode node);

ArithmeticExpressionStack * artexp_prefix_to_stack(char *prefix);
ArithmeticExpressionStack * artexp_infix_to_prefix_stack(char *infix);
ArithmeticExpressionStack * artexp_infix_to_postfix_stack(char *infix);
