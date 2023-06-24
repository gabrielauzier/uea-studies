/*
 *
 * Registrations List (reg)
 *
 * Implemented using Static Linked List (stll)
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "registrations-list.h"
#include "../utils/show.h"

typedef struct Student {
    int registration;
    char name[255];
    int age;
    int childrenQtd;
} Student;

typedef struct RegistrationsElement {
    Student student;
    int next; // next registration
} RegistrationsElement;

typedef struct Registrations {
    RegistrationsElement class[MAX_STUDENTS];
    int head;
    int availableIndex;
} Registrations;

Registrations * reg_create_list() {
    Registrations *src = malloc(sizeof (Registrations));
    reg_init_list(src);
    return src;
}

Student * reg_create_student(int registration, char *name, int age, int childrenQtd) {
    Student *src = malloc(sizeof (Student));
    src->registration = registration;
    strcpy(src->name, name);
    src->age = age;
    src->childrenQtd = childrenQtd;
    return src;
}

void reg_init_list(Registrations *src) {
    for (int i = 0; i < MAX_STUDENTS - 1; i++) {
        src->class[i].next = i + 1;

    }

    src->class[MAX_STUDENTS - 1].next = -1;
    src->head = -1;
    src->availableIndex = 0;
}

int reg_get_len(Registrations *src) {
    int len = 0;
    int i = src->head;

    while (i != -1) {
        len++;
        i = src->class[i].next;
    }
    return len;
}

void reg_print_list(Registrations *src) {
    int i = src->head;
    endline();
    show_highlight_ln(" Registrations ", MAGENTA, BLACK);
    if (reg_get_len(src) == 0) show_text_ln("List is empty", RED);
    show_attr_int("Available", src->availableIndex);

    while (i != -1) {
        show_subtitle("Node");
        show_attr_int("index", i);
        show_attr_int("student.registration", src->class[i].student.registration);
        show_attr_str("student.name", src->class[i].student.name);
        show_attr_int("student.age", src->class[i].student.age);
        show_attr_int("next", src->class[i].next);
        i = src->class[i].next;
    }
    show_separator(strlen("Registrations") + 2, MAGENTA);
    endline();
}

void reg_print_list_beauty(Registrations *src) {
    int i = src->head;
    endline();
    show_text_ln("Registrations ", MAGENTA);
    if (reg_get_len(src) == 0) show_text_ln("List is empty", RED);

    while (i != -1) {
        char title[255];
        sprintf(title, " %s (%d|%d|%d) ", src->class[i].student.name, src->class[i].student.registration, src->class[i].student.age, src->class[i].student.childrenQtd);
        show_highlight(title, MAGENTA, BLACK);

        printf(" --> ");
        i = src->class[i].next;
    }

    show_highlight_ln(" END ", BLUE, BLACK);
    endline();
};

void test(Registrations src, int target) {
    RegistrationsElement *element = src.class[0].student;


    endline();
    endline();
};

int reg_find_one(Registrations *src, int registrationTarget) {
    int i = src->head;
    while (i != -1 && src->class[i].student.registration < registrationTarget) {
        i = src->class[i].next;

        return (i != -1 && src->class[i].student.registration == registrationTarget) ? i : -1;
    }
    return -1;
}

int reg_get_available_index(Registrations *src) {
    int index = src->availableIndex;
    if (src->availableIndex != -1) {
        src->availableIndex = src->class[index].next;
    }
    return index;
}

int reg_insert_student(Registrations *src, Student *newStudent) {
    if (src->availableIndex == -1) return 0;

    int i = src->head;
    int insertAt = -1;

    while (i != -1 && newStudent->registration > src->class[i].student.registration) {
        insertAt = i;
        i = src->class[i].next;
    }
    if (i != -1 && newStudent->registration == src->class[insertAt].student.registration) return 0;

    i = reg_get_available_index(src);

    src->class[i].student = *newStudent;

    if (insertAt == -1) {
        src->class[i].next = src->head;
        src->head = i;
    } else {
        src->class[i].next = src->class[insertAt].next;
        src->class[insertAt].next = i;
    }

    return 1;
}

int reg_insert_student_without_sorting(Registrations *src, Student *newStudent) {
    if (src->availableIndex == -1) return 0;

    int i = src->head;
    int insertAt = -1;

    while (i != -1) {
        insertAt = i;
        i = src->class[i].next;
    }

    i = reg_get_available_index(src);

    src->class[i].student = *newStudent;

    if (insertAt == -1) {
        src->class[i].next = src->head;
        src->head = i;
    } else {
        src->class[i].next = src->class[insertAt].next;
        src->class[insertAt].next = i;
    }

    return 1;
}

int reg_alloc_node(Registrations *src, int i) {
    src->class[i].next = src->availableIndex;
    src->availableIndex = i;
}

int reg_delete_student(Registrations *src, int registrationTarget) {
    int i = src->head;
    int previous = -1;

    while (i != -1 && src->class[i].student.registration < registrationTarget) {
        previous = i;
        i = src->class[i].next;
    }

    if (i != -1 && src->class[i].student.registration != registrationTarget) return 0;
    if (i == -1) return 0;

    if (previous == -1) {
        src->head = src->class[i].next;
    } else {
        src->class[previous].next = src->class[i].next;
        reg_alloc_node(src, i);
        return 1;
    }

    return 0;
}

float reg_get_class_average_age(Registrations *src) {
    int i = src->head;
    int sum = 0;

    while (i != -1) {
        sum += src->class[i].student.age;
        i = src->class[i].next;
    }

    return (sum * 1.0) / reg_get_len(src);
}
