/*
 * Exam 16.06.2023
 * */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../utils/show.h"
#include "registrations-list.h"

void init_main_() {
    init_show();

    time_t now;
    time(&now);

    char date[200];
    sprintf(date, "Delivered at %s", ctime(&now));

    show_text(date, MAGENTA);
    show_text_ln("by Gabriel Vasconcelos Auzier", MAGENTA);
    show_header("Code 008 - Students Registrations (Static Linked List)", MAGENTA);
}


int main() {
    init_main_();

    Registrations *list = reg_create_list();

    Student *a = reg_create_student(001, "Daniel", 21, 0);
    Student *b = reg_create_student(002, "Suza", 19, 0);
    Student *c = reg_create_student(003, "Danilo", 24, 1);
    Student *d = reg_create_student(004, "Camila", 18, 0);
    Student *e = reg_create_student(005, "Carlos", 22, 1);

    Student *students[] = { a, b, c, d, e};

    for (int i = 0; i < 5; i++) {
        reg_insert_student(list, students[i]);
    }

    reg_print_list_beauty(list);

    float age_avg = reg_get_class_average_age(list);

    show_attr_dob("Average students age", age_avg);

    return 0;
}