/*
 * Patients hash (pathash)
 *
 * Implemented using simple hash with trivial hash function
 *
 * */

#include <stdlib.h>

#include "../utils/show.h"
#include "patients-hash.h"

void pathash_initialize_hash(HashTable src) {
    for (int i = 0; i < MAX_SIZE; i++) {
        src[i] = NULL;
    }
}

int pathash_hashmap(int code) {
    return code % MAX_SIZE;
}

int pathash_insert(HashTable src, Patient patient) {
    int key = pathash_hashmap(patient.code);

    while (src[key] != NULL) {
        if (src[key]->code == patient.code) {
            return 0;
        }

        key = (key + 1) % MAX_SIZE;
    }

    if (src[key] == NULL) {
        src[key] = malloc(sizeof(Patient));
        *(src[key]) = patient;
    } else {
        key++;
        while (src[key] != NULL) {
            key++;
        }

        src[key] = malloc(sizeof (Patient));
        *(src[key]) = patient;
    }

    return 1;
}

Patient * pathash_find_patient(HashTable src, int code) {
    int key = pathash_hashmap(code);

    while (src[key] != NULL) {
        if (src[key]->code == code) {
            return src[key];
        }

        key = (key + 1) % MAX_SIZE;
    }
    return NULL;
}

void pathash_print_hash(HashTable src) {
    for (int i = 0; i < MAX_SIZE; i++) {
        if (src[i] != NULL) {
            show_attr_str("Patient", src[i]->name);
        } else {
            show_attr_str("Patient", "NULL");
        }
    }
}
