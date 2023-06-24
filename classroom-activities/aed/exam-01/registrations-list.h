/*
 *
 * Registrations List (reg)
 *
 * Implemented using Static Linked List (stll)
 *
 * */

#define MAX_STUDENTS 100

typedef struct Student Student;

typedef struct RegistrationsElement RegistrationsElement;

typedef struct Registrations Registrations;

Registrations * reg_create_list();
Student * reg_create_student(int registration, char *name, int age, int childrenQtd);

float reg_get_class_average_age(Registrations *src);

void reg_init_list(Registrations *src);
int reg_get_len(Registrations *src);
void reg_print_list(Registrations *src);
void reg_print_list_beauty(Registrations *src);
int reg_find_one(Registrations *src, int registrationTarget);
int reg_get_available_index(Registrations *src);
int reg_insert_student(Registrations *src, Student *newStudent);
int reg_alloc_node(Registrations *src, int i);
int reg_delete_student(Registrations *src, int registrationTarget);
