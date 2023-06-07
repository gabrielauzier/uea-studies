typedef struct StudentsList StudentsList;

typedef struct Student Student;

StudentsList * create_students_list();

void free_sl(StudentsList *sl);

void init_sl(StudentsList *sl);

int get_valid_elements_on_sl(StudentsList *sl);

int is_empty_sl(StudentsList *sl);

void show_sl(StudentsList *sl);

void insert_element_sl(StudentsList *sl);

void delete_element_sl(StudentsList *sl, int value);

void update_element_sl(StudentsList *sl, int value);





