/* Flipped classroom 26.06.23 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../utils/show.h"
#include "arithmetic-expression.h"
#include "arithmetic-expression-stack.h"

void init_main() {
    init_show();

    time_t now;
    time(&now);

    char date[200];
    sprintf(date, "Delivered at %s", ctime(&now));

    show_text(date, MAGENTA);
}

int main() {
    init_main();

    show_header("Arithmetic Expression Evaluation - Stack Example", BLUE);

    char *infix = "1+3*(4^2-3)+(4+5*6)-3";

    ArithmeticExpression *exp = create_arithmetic_expression(infix);

    artexp_print_expression(exp);
    artexp_delete_expression(exp);

    endline();
    return 0;
}