#include <stdio.h>
#include <stdlib.h>

#include "students.h"
#include "../utils/constants.h"
#include "../utils/show.h"

#define SL_MAX_TAM 100

typedef struct Student {
    int age;
    int code;
    int next_code;
    string name;
} Student;

typedef struct StudentsList {
    Student class[SL_MAX_TAM];
    int head_code;
    int available;
} StudentsList;


StudentsList * create_students_list() {
    StudentsList *result = malloc(sizeof (StudentsList));

    init_sl(result);

    return result;
};

void init_sl(StudentsList *sl) {
    for (int i = 0; i < SL_MAX_TAM - 1; i++) {
        sl->class[SL_MAX_TAM].next_code = -1;
    }

    sl->class[SL_MAX_TAM - 1].next_code = -1;
    sl->head_code = -1;
    sl->available = 0;
};

void free_sl(StudentsList *sl) {
    free(sl->class);
    free(sl);
};

int get_valid_elements_on_sl(StudentsList *sl) {
    return sl->available;
};

int is_empty_sl(StudentsList *sl) {
    return sl->available == 0 ? 1 : 0;
};

void show_sl(StudentsList *sl);

void insert_element_sl(StudentsList *sl) {

};

void delete_element_sl(StudentsList *sl, int value);

void update_element_sl(StudentsList *sl, int value);





