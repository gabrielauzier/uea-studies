#include "../utils/constants.h"
#define MAX_STUDENTS 100

typedef struct Student {
    int registration;
    string name;
} Student;

typedef struct Class {
    int id;
    int studentsQtd;
    int studentsMaxQtd;
    Student *students;
} Class;

void fill_class_random();
