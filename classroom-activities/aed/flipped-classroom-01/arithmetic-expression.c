/* Arithmetic Expression (artexp) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_CHAR 255

#include "arithmetic-expression.h"
#include "arithmetic-expression-stack.h"
#include "../utils/show.h"

typedef char Expression[MAX_CHAR];

typedef struct ArithmeticExpression {
    Expression infix;
    Expression postfix;
    Expression prefix;

    ArithmeticExpressionStack *postfixStack;
    ArithmeticExpressionStack *prefixStack;

    int evaluation;
} ArithmeticExpression;

int get_precedence(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}

int is_operator(char arg) {
    return (
        arg == '+' ||
        arg == '-' ||
        arg == '*' ||
        arg == '/' ||
        arg == '^'
    );
}

ArithmeticExpression * create_arithmetic_expression(char *infix) {
    ArithmeticExpression *new = malloc(sizeof (ArithmeticExpression));

    strcpy(new->infix, infix);
    strcpy(new->prefix, artexp_infix_to_prefix(infix));
    strcpy(new->postfix, artexp_infix_to_postfix(infix));

    new->prefixStack = artexpstack_create_stack_by_exp(new->prefix);
    new->postfixStack = artexpstack_create_stack_by_exp(new->postfix);

    new->evaluation = artexp_evaluate_prefix(new->prefix);

    return new;
}

void artexp_print_expression(ArithmeticExpression *src) {
    show_text_ln("Expression", BLUE);
    show_attr_str("Infix", src->infix);
    show_attr_str("Prefix", src->prefix);
    show_attr_str("Postfix", src->postfix);
    show_attr_int("Evaluation", src->evaluation);
    endline();
};

void artexp_delete_expression(ArithmeticExpression *src) {
    free(src->prefixStack);
    free(src->postfixStack);

    free(src);
}

/** util method to prefix expression */
char * __reverse_expression(char *exp) {
    int size = (int) strlen (exp);
    char *temp = malloc(sizeof(char) * (size + 2));
    int j = size, i = 0;

    temp[j--] = '\0';
    while (exp[i] != '\0') {
        temp[j] = exp[i];
        j--;
        i++;
    }

    return temp;
}

/** util method to prefix expression */
char * __reverse_brackets(char *exp) {
    int i = 0;
    int size = (int) strlen(exp);
    char *temp = malloc(sizeof(char) * (size + 2));

    strcpy(temp, exp);
    while (temp[i] != '\0') {
        if (temp[i] == '(')
            temp[i] = ')';
        else if (temp[i] == ')')
            temp[i] = '(';
        i++;
    }

    return temp;
}

/** convert infix string to postfix string */
char * artexp_infix_to_postfix(char *infix) {
    int len = (int) strlen(infix);
    char *postfix = malloc(sizeof(char) * (len + 2));
    char stack[MAX_CHAR];
    int top = -1, j = 0;

    for (int i = 0; i < len; i++) {
        if (infix[i] == ' ' || infix[i] == '\t') continue;

        // if the scanned character is operand add it to the postfix expression
        if (isalnum(infix[i])) postfix[j++] = infix[i];

            // if the scanned character is '(' push it in the stack
        else if (infix[i] == '(') stack[++top] = infix[i];

            // if the scanned character is ')' pop the stack and add it to the output string until empty or '(' found
        else if (infix[i] == ')') {
            while (top > -1 && stack[top] != '(')
                postfix[j++] = stack[top--];
            if (top > -1 && stack[top] != '(')
                return "Invalid Expression";
            else
                top--;
        }

            // if the scanned character is an operator push it in the stack
        else if (is_operator(infix[i])) {
            while (top > -1 && get_precedence(stack[top]) >= get_precedence(infix[i]))
                postfix[j++] = stack[top--];
            stack[++top] = infix[i];
        }
    }

    // pop all remaining elements from the stack
    while (top > -1) {
        if (stack[top] == '(') {
            return "Invalid Expression";
        }
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';

    return postfix;
}

/** convert infix string to prefix string */
char * artexp_infix_to_prefix(char *infix) {
    return __reverse_expression(artexp_infix_to_postfix(__reverse_brackets(__reverse_expression(infix))));
}

/** get value from postfix expression string */
int artexp_evaluate_postfix(char *postfix) {
    ArithmeticExpressionStack *stack = artexpstack_create_stack();
    int len = (int) strlen(postfix);

    for (int i = 0; i < len; i++) {
        if (isalnum(postfix[i])) {
            artexpstack_push_node(stack, *artexpstack_create_node(postfix[i] - '0', postfix[i]));
        }

        else {
            int val1 = artexpstack_pop_node(stack).value;
            int val2 = artexpstack_pop_node(stack).value;

            switch (postfix[i]) {
                case '+':
                    artexpstack_push_node(stack, *artexpstack_create_node(val2 + val1, '#'));
                    break;
                case '-':
                    artexpstack_push_node(stack, *artexpstack_create_node(val2 - val1, '#'));
                    break;
                case '*':
                    artexpstack_push_node(stack, *artexpstack_create_node(val2 * val1, '#'));
                    break;
                case '/':
                    artexpstack_push_node(stack, *artexpstack_create_node(val2 / val1, '#'));
                    break;
                case '^':
                    artexpstack_push_node(stack, *artexpstack_create_node((int) pow(val2, val1), '#'));
                    break;
            }
        }
    }

    return artexpstack_pop_node(stack).value;
}

/** get value from prefix expression string */
int artexp_evaluate_prefix(char *prefix) {
    ArithmeticExpressionStack *stack = artexpstack_create_stack();
    int len = (int) strlen(prefix);

    for (int i = len - 1; i >= 0; i--) {
        if (isalnum(prefix[i])) {
            artexpstack_push_node(stack, *artexpstack_create_node(prefix[i] - '0', prefix[i]));
        }

        else {
            int val1 = artexpstack_pop_node(stack).value;
            int val2 = artexpstack_pop_node(stack).value;

            switch (prefix[i]) {
                case '+':
                    artexpstack_push_node(stack, *artexpstack_create_node(val1 + val2, '#'));
                    break;
                case '-':
                    artexpstack_push_node(stack, *artexpstack_create_node(val1 - val2, '#'));
                    break;
                case '*':
                    artexpstack_push_node(stack, *artexpstack_create_node(val1 * val2, '#'));
                    break;
                case '/':
                    artexpstack_push_node(stack, *artexpstack_create_node(val1 / val2, '#'));
                    break;
                case '^':
                    artexpstack_push_node(stack, *artexpstack_create_node((int) pow(val1, val2), '#'));
                    break;
            }
        }
    }

    return artexpstack_pop_node(stack).value;
}

/** create prefix stack by prefix expression string (only function internal use) */
ArithmeticExpressionStack * __artexp_prefix_to_stack(char *prefix) {
    ArithmeticExpressionStack *stack = artexpstack_create_stack();

    for (int i = 0; i < strlen(prefix); i++) {
        artexpstack_push_node(stack, *artexpstack_create_node(prefix[i] - '0', prefix[i]));
    }

    return stack;
}

/** convert infix expression string to prefix stack */
ArithmeticExpressionStack * artexp_infix_to_prefix_stack(char *infix) {
    char *prefix = artexp_infix_to_prefix(infix);
    ArithmeticExpressionStack *stack = __artexp_prefix_to_stack(prefix);
    return stack;
}

/** convert infix expression string to postfix stack */
ArithmeticExpressionStack * artexp_infix_to_postfix_stack(char *infix) {
    int len = (int) strlen(infix);

    ArithmeticExpressionStack *postfix = artexpstack_create_stack();
    ArithmeticExpressionStack *stack = artexpstack_create_stack();

    for (int i = 0; i < len; i++) {
        if (infix[i] == ' ' || infix[i] == '\t') continue;

        ArithmeticExpressionNode *newNode = artexpstack_create_node(infix[i] - '0', infix[i]);

        // if the scanned character is operand add it to the postfix expression
        if (isalnum(infix[i]))
            artexpstack_push_node(postfix, *newNode);

        else if (infix[i] == '(')
            artexpstack_push_node(stack, *newNode);

        // if the scanned character is ')' pop the stack and add it to the output string until empty or '(' found
        else if (infix[i] == ')') {
            while (artexpstack_is_empty(stack) != 1 && stack->top->node.valueChar != '(')
                artexpstack_push_node(postfix, artexpstack_pop_node(stack));
            if (artexpstack_is_empty(stack) != 1 && stack->top->node.valueChar != '(')
                return NULL;
            else
                artexpstack_pop_node(stack);
        }

        // if the scanned character is an operator push it in the stack
        else if (is_operator(infix[i])) {
            while (artexpstack_is_empty(stack) != 1 && get_precedence(stack->top->node.valueChar) >= get_precedence(infix[i]))
                artexpstack_push_node(postfix, artexpstack_pop_node(stack));

            artexpstack_push_node(stack, *newNode);
        }
    }

    // pop all remaining elements from the stack
    while (artexpstack_is_empty(stack) != 1) {
        if (artexpstack_peek_node(stack).valueChar == '(') return NULL;

        artexpstack_push_node(postfix, artexpstack_pop_node(stack));
    }

    return postfix;
}