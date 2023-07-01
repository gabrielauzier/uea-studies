/* Arithmetic Expression (artexp) */

typedef struct ArithmeticExpression ArithmeticExpression;

ArithmeticExpression * create_arithmetic_expression(char *expInfix);
void artexp_print_expression(ArithmeticExpression *src);
void artexp_delete_expression(ArithmeticExpression *src);

char * artexp_infix_to_postfix(char *infix);
char * artexp_infix_to_prefix(char *infix);

int artexp_evaluate_postfix(char *postfix);
int artexp_evaluate_prefix(char *prefix);