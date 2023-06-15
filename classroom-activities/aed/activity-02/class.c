#include <stdlib.h>
#include <string.h>

#include "class.h"

#include "../utils/constants.h"
#include "../utils/random.h"
#include "../utils/show.h"

Class * create_class(int studentsQtd) {
    Class *class = malloc(sizeof (Class));

    class->students = malloc(sizeof (int) * studentsQtd);
    class->studentsMaxQtd = studentsQtd;
    class->studentsQtd = 0;

    return class;
}

Student * create_student(
    int id,
    string name,
    int age,
    float coefficient
) {
    Student *student = malloc(sizeof (Student));

    student->id = id;
    strcpy(student->name, name);
    student->age = age;
    student->coefficient = coefficient;

    return student;
}

Student * empty_student() {
    Student *student = malloc(sizeof (Student));

    student->id = -1;
    strcpy(student->name, "");
    student->age = -1;
    student->coefficient = -1;

    return student;
}

void insert_student(Class *class, Student *student) {
    if (class->studentsQtd == class->studentsMaxQtd) {
        return show_warning("Class is full ");
    }

    int len = class->studentsQtd;

    strcpy(class->students[len].name, student->name);
    class->students[len].id = student->id;
    class->students[len].age = student->age;
    class->students[len].coefficient = student->coefficient;

    class->studentsQtd++;
}

void free_class(Class *class) {
    free(class->students);
    free(class);
}

void show_student(Student *student) {
    if (student->id == -1) {
        show_warning("Empty student ");
        free(student);
        return;
    }

    show_subtitle("Student ");

    show_attr_str("Name", student->name);
    show_attr_int("Id", student->id);
    show_attr_int("Age", student->age);
    show_attr_dob("Coefficient", student->coefficient);
}


/** sequential search */
Student * find_student_by_id_v1(Class *class, int id) {
    Student *result = empty_student();

    for (int i = 0; i < class->studentsQtd; i++) {
        if (class->students[i].id == id) {
            return &(class->students[i]);
        }
    }

    return result;
}

/** binary search */
Student * find_student_by_id_v2(Class *class, int id) {

}

void show_class(Class *class) {
    show_title("Class");
    show_attr_int("Students", class->studentsQtd);
    show_attr_int("Students Max", class->studentsMaxQtd);

    for (int i = 0; i < class->studentsQtd; i++) {
        show_student(&class->students[i]);
    }
}

int generate_id() {
    const int a = generate_random_int(100);
    const int b = generate_random_int(200);
    const int c = a * b;

    return a + b + c;
}