#include <stdio.h>
#include <stdlib.h>

#include "dynamic-linked-list.h"
#include "class.h"

#include "../utils/show.h"

void init_main_() {
    init_show();
}

void exercise01() {
    show_header("Exercise 01 - Class (Dynamic Linked List)", MAGENTA);

    Class *class = class_create_linked_list();

    Student *a = class_create_student(1003, "Gabriel", 19);
    Student *b = class_create_student(1002, "Rafael", 3);
    Student *c = class_create_student(1005, "Miguel", 12);

    class_insert_student(class, a);
    class_insert_student(class, b);
    class_insert_student(class, c);

    class_print_list(class);

    int len = class_get_valid_elements(class);

    show_separator(30, MAGENTA);
    show_attr_int("Valid elements on class", len);
}

int main() {
    init_main_();

    exercise01();
    return 0;
}