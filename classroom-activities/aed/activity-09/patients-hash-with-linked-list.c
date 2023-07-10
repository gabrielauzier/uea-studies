/*
 * Patient_v2s hash v2 (pathash_v2)
 *
 * Implemented using simple hash with trivial hash function and linked list
 *
 * */

#include <stdlib.h>
#include <string.h>

#include "../utils/show.h"
#include "patients-hash-with-linked-list.h"

Patient_v2 * pathash_v2_create_patient(int code, int age, char *name, char *cpf) {
    Patient_v2 *new = malloc(sizeof (Patient_v2));
    new->code = code;
    new->age = age;
    strcpy(new->name, name);
    strcpy(new->cpf, cpf);
    return new;
}

void pathash_v2_initialize_hash(HashTable src) {
    for (int i = 0; i < MAX_SIZE; i++) {
        src[i] = NULL;
    }
}

int pathash_v2_hashmap(int code) {
    return code % MAX_SIZE;
}

int pathash_v2_insert(HashTable src, Patient_v2 patient) {
    int key = pathash_v2_hashmap(patient.code);

    Element_v2 *previous = NULL;
    Element_v2 *crawler = src[key];

    while (crawler != NULL) {
        if (crawler->patient.code == patient.code) return 0;

        previous = crawler;
        crawler = crawler->next;
    }

    if (crawler == NULL) {
        crawler = malloc(sizeof (Element_v2));
        crawler->patient = patient;
        crawler->next = NULL;

        if (previous == NULL) src[key] = crawler;
        else previous->next = crawler;
    }

    return 1;
}

Patient_v2 * pathash_v2_find_patient(HashTable src, int TargetCode) {
    int key = pathash_v2_hashmap(TargetCode);
    Element_v2 *crawler = src[key];

    while (crawler != NULL) {
        if (crawler->patient.code == TargetCode) {
            return &crawler->patient;
        } else {
            crawler = crawler->next;
        }
    }
    return NULL;
}

void pathash_v2_print_hash(HashTable src) {
    Element_v2 *crawler;

    for (int i = 0; i < MAX_SIZE; i++) {
        if (src[i] != NULL) {
            crawler = src[i];
            show_attr_int("Patient_v2.code: ", src[i]->patient.code);

            while (crawler != NULL) {
                show_attr_str("Patient_v2.name: ", src[i]->patient.name);
                crawler = crawler->next;
            }
        } else {
            show_attr_str("Patient_v2", "NULL");
        }
    }
}
