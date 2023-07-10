/*
 * Patients hash (pathash)
 * */

#define MAX_SIZE 101
#define MAX_CHAR 255

typedef struct Patient {
    int code;
    int age;
    char name[MAX_CHAR];
    char cpf[MAX_CHAR];
} Patient;


typedef Patient * HashTable[MAX_SIZE];

int pathash_hashmap(int code);
int pathash_insert(HashTable src, Patient patient);
void pathash_initialize_hash(HashTable src);
void pathash_print_hash(HashTable src);
Patient * pathash_find_patient(HashTable src, int code);