#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "class.h"

#include "../utils/show.h"
#include "../utils/random.h"
#include "../utils/constants.h"

Class * create_class(int studentsQtd) {
    Class *result = malloc(sizeof (Class));

    result->students = malloc(sizeof (Student) * studentsQtd);

    result->studentsMaxQtd = studentsQtd;
    result->studentsQtd = 0;
    result->id = 0;

    return result;
}

void insert_student(Class *class, Student *student) {
    if (class->studentsQtd == class->studentsMaxQtd) {
        return show_warning("Class is full ");
    }

    int len = class->studentsQtd;

    strcpy(class->students[len].name, student->name);
    class->students[len].registration = student->registration;

    class->studentsQtd++;
}

void fill_class_random() {

    printf("%s", EXAMPLE_NAMES[0]);
}