#include <stdio.h>
#include <string.h>

#define TEAMS 5
#define STUDENTS 4

typedef struct student {
    char name[50];
    char lastname[50];
} Student;

typedef struct team {
    Student students[STUDENTS];
} Team;

const char names[20][255] = {
    "Liam",
    "Olivia",
    "Noah",
    "Oliver",
    "Charlotte",
    "Elijah",
    "Amelia",
    "James",
    "Ava",
    "William",
    "Sophia",
    "Benjamin ",
    "Isabella",
    "Lucas",
    "Mia",
    "Henry",
    "Evelyn",
    "Theodore",
    "Harper",
    "Chris",
};

const char lastnames[20][255] = {
    "Brown",
    "Rodrigo",
    "Smith",
    "Tremblay",
    "Martin",
    "Roy",
    "Gagnon",
    "Lee",
    "Wilson",
    "Johnson",
    "MacDonald",
    "Gagnon",
    "Watson",
    "Bouchard",
    "Mora",
    "Anderson",
    "Thomas",
    "Hernandez",
    "Moore",
    "Hill"
};

void exercise01 () {
    Team teams[TEAMS];

    int k = 0;

    for (int i = 0; i < TEAMS; i++) {
        for (int j = 0; j < STUDENTS; j++, k++) {
            strcpy(teams[i].students[j].name, names[k]);
            strcpy(teams[i].students[j].lastname, lastnames[k]);
        }
    }

    /* find team by student name and lastname */

    const char name[50] = "Olivia";

    for (int i = 0; i < TEAMS; i++) {
        for (int j = 0; j < STUDENTS; j++, k++) {

            if (strcmp(teams[i].students[j].name, name) == 0) {
                printf("\n Team %d \n", i);
                for (k = 0; k < STUDENTS; k++) {
                    printf("[%d] %s ", k, teams[i].students[k].name);
                    printf("%s\n", teams[i].students[k].lastname);
                }
                return;
            }
        }
    }

    printf("None student found.");
}

#define NAMES 20
#define NAME_CHAR_MAX 120

void deleteName(char list[NAMES][NAME_CHAR_MAX], char *string) {
    for (int i = 0; i < NAMES; i++) {
        if (strcmp(list[i], string) == 0) {
            printf("Name found in [%d]. Deleting: %s\n", i, list[i]);

            int j;
            for (j = i; j < NAMES - 1; j++) {
                strcpy(list[j], list[j + 1]);
            }
            strcpy(list[j], "");
            return;
        }
    }
}

void printNames(char list[][NAME_CHAR_MAX]) {
    printf("\n Names: \n");

    int i = 0;

    while(i < NAMES) {
        if (strlen(list[i]) > 0)
            printf("[%d] %s\n", i, list[i]);
        i++;
    }

    puts("");
}

void sortNames(char list[][NAME_CHAR_MAX]) {
    char tmp[NAME_CHAR_MAX];

    puts("Sorting names...");

    for (int i = 0; i < NAMES; i++) {
        for (int j = i + 1; j < NAMES - 1; j++) {
            if(strcmp(list[i], list[j]) > 0) {
                strcpy(tmp, list[i]);
                strcpy(list[i], list[j]);
                strcpy(list[j], tmp);
            }
        }
    }
}

void exercise02() {
    char names_p[NAMES][NAME_CHAR_MAX];

    for (int i = 0; i < NAMES; i++) {
        strcpy(names_p[i], names[i]);
    }

    printNames(names_p);
    deleteName(names_p, "Mia");
    deleteName(names_p, "Sophia");
    deleteName(names_p, "Ava");
    deleteName(names_p, "William");

    printNames(names_p);

    sortNames(names_p);
    printNames(names_p);
}

int main() {

    exercise01();
    exercise02();

    return 0;
}