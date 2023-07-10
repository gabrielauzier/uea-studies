#define MAX_SIZE 101
#define MAX_CHAR 255

typedef struct Patient_v2_v2 {
    int code;
    int age;
    char name[MAX_CHAR];
    char cpf[MAX_CHAR];
} Patient_v2;

typedef struct Element_v2 {
    Patient_v2 patient;
    struct Element_v2 *next;
} Element_v2;

typedef Element_v2 * HashTable[MAX_SIZE];

int pathash_v2_hashmap(int code);
int pathash_v2_insert(HashTable src, Patient_v2 patient);
void pathash_v2_initialize_hash(HashTable src);
void pathash_v2_print_hash(HashTable src);
Patient_v2 * pathash_v2_find_patient(HashTable src, int code);