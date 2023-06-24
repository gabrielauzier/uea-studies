#include <stdio.h>
#include <stdlib.h>

typedef struct Student Student;

typedef struct ClassElement ClassElement;

typedef struct Class Class;

Class * class_create_linked_list();
Student * class_create_student(int registration, char *name, int age);

void class_init_list(Class *src);
int class_get_valid_elements(Class *src);

void class_print_list(Class *src);
void class_print_element(ClassElement *src);

ClassElement * class_find_one(Class *src, int valueTarget);
ClassElement * class_find_element_and_previous(Class *src, int newRegistration, ClassElement **previous);

int class_insert_student(Class *src, Student *newStudent);
int class_delete_student(Class *src, int valueTarget);
