/*
 * Class of students
 *
 * Implemented using Dynamic Linked List
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "class.h"
#include "../utils/show.h"

typedef struct Student {
    int registration;
    char name[255];
    int age;
} Student;

typedef struct ClassElement {
    Student student;
    struct ClassElement *next;
} ClassElement;

typedef struct Class {
    ClassElement *head;
} Class;

Class * class_create_linked_list() {
    Class *src = malloc(sizeof (Class));
    class_init_list(src);
    return src;
}

Student * class_create_student(int registration, char *name, int age) {
    Student *src = malloc(sizeof (Student));
    src->registration = registration;
    strcpy(src->name, name);
    src->age = age;
    return src;
}

void class_init_list(Class *src) {
    src->head = NULL;
}

int class_get_valid_elements(Class *src) {
    int len = 0;
    ClassElement *crawler = src->head;
    while (crawler != NULL) {
        len++;
        crawler = crawler->next;
    }
    return len;
}

void class_print_list(Class *src) {
    ClassElement *crawler = src->head;

    show_highlight_ln(" Class ", MAGENTA, BLACK);
    while (crawler != NULL) {
        class_print_element(crawler);
        crawler = crawler->next;
    }
}

void class_print_element(ClassElement *src) {
    show_text_ln("Student", MAGENTA);

    show_attr_int("Registration", src->student.registration);
    show_attr_str("Name", src->student.name);
    show_attr_int("Age", src->student.age);
}

ClassElement * class_find_one(Class *src, int valueTarget) {}

ClassElement * class_find_element_and_previous(Class *src, int newRegistration, ClassElement **previous) {
    *previous = NULL;
    ClassElement *crawler = src->head;
    while (crawler != NULL && crawler->student.registration < newRegistration) {
        *previous = crawler;
        crawler = crawler->next;
    }
    if (crawler != NULL && crawler->student.registration == newRegistration) return crawler;
    return NULL;
}

int class_insert_student(Class *src, Student *newStudent) {
    int newRegistration = newStudent->registration;
    ClassElement *previous;
    ClassElement *crawler;

    crawler = class_find_element_and_previous(src, newRegistration, &previous);
    if (crawler != NULL) return 0;
    crawler = malloc(sizeof (ClassElement));
    crawler->student = *newStudent;

    if (previous == NULL) {
        crawler->next = src->head;
        src->head = crawler;
    } else {
        crawler->next = previous->next;
        previous->next = crawler;
    }

    return 1;
}

int class_delete_student(Class *src, int valueTarget) {}