#include "../utils/constants.h"

typedef struct Student {
    int id;
    int age;
    float coefficient;
    string name;
} Student;

typedef struct Class {
    Student *students;
    int studentsMaxQtd;
    int studentsQtd;
} Class;

Class * create_class(int studentsQtd);
Student * create_student(
    int id,
    string name,
    int age,
    float coefficient
);

int generate_id();

void insert_student(Class *class, Student *student);
void free_class(Class *class);
void show_class(Class *class);
void show_student(Student *student);

/** sequential search */
Student * find_student_by_id_v1(Class *class, int id);

/** binary search */
Student * find_student_by_id_v2(Class *class, int id);

