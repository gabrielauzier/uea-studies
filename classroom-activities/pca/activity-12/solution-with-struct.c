/*
 * This file contains another solution for the same question using structs instead just arrays
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CHAR 255
#define MAX_STUDENTS 10
#define MAX_TEAMS 4

#define STUDENTS 6
#define TEAMS 2
#define END() (printf("\n"))

typedef char string[MAX_CHAR];

typedef struct STUDENT {
    string name;
    string gender;
    float grade;
} STUDENT;

typedef struct TEAM {
    STUDENT students[MAX_STUDENTS];
    int length;
    int id;
} TEAM;

char NAMES[20][MAX_CHAR] = {
        "Liam",
        "Olivia",
        "Noah",
        "Charlotte",
        "Oliver",
        "Elijah",
        "Amelia",
        "James",
        "Ava",
        "William",
        "Sophia",
        "Benjamin",
        "Isabella",
        "Lucas",
        "Mia",
        "Henry",
        "Evelyn",
        "Theodore",
        "Harper",
        "Chris",
};


const char LASTNAMES[20][MAX_CHAR] = {
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

float generate_random_num(int lim) {
    const int _num = rand() % (lim * 10) + 1;

    float num = (_num * 1.0) / 10.0;

    return num;
}

int generate_random_int(int lim) {
    const int num = rand() % lim;

    return num;
}

char * generate_random_gender() {
    const int num = rand() % 100 + 1;

    return num % 2 == 0 ? "Female" : "Male";
}


STUDENT * create_student(string name, string gender, float grade) {
    STUDENT *student = malloc(sizeof (struct STUDENT));

    strcpy(student->name, name);
    strcpy(student->gender, gender);
    student->grade = grade;

    return student;
}

TEAM * create_team(int id) {
    TEAM *team = malloc(sizeof (struct TEAM));

    team->id = id;
    team->length = 0;

    return team;
}

TEAM * find_team_by_id(TEAM **teams, int id) {
    for (int i = 0; i < TEAMS; i++) {
        if (teams[i]->id == id)
            return teams[i];
    }

    puts("None team was found with given id. ");
    return NULL;
}

void push_student_to_team(TEAM *dest_team, string name, string gender, float grade) {
    if (dest_team->length == MAX_STUDENTS) {
        printf("\nException: Students limit exceeded.");
        END();
        return;
    }

    const STUDENT *student = create_student(name, gender, grade);

    const int i = dest_team->length;

    dest_team->students[i] = *student;
    dest_team->length = dest_team->length + 1;
}

void add_student(TEAM **teams, int team_id, string name, string gender, float grade) {
    printf("\nAdding student [%s]...", name);

    TEAM *dest_team = find_team_by_id(teams, team_id);

    push_student_to_team(dest_team, name, gender, grade);
}

void show(TEAM *team) {
    printf("\n\nTeam %d (len %d):", team->id, team->length);

    for (int i = 0; i < team->length; i++) {
        printf("\n{ %s, %s, %.1f }",
           team->students[i].name, team->students[i].gender, team->students[i].grade
        );

    }

    END();
}

void initialize_teams(TEAM **teams) {
    for (int i = 0; i < TEAMS; i++) {
        for (int j = 0; j < STUDENTS; j++) {
            string fullname, gender;
            int rand_index;

            rand_index = generate_random_int(19);
            strcpy(fullname, NAMES[rand_index]);

            rand_index = generate_random_int(19);
            strcat(fullname, " ");
            strcat(fullname, LASTNAMES[rand_index]);

            float grade = generate_random_num(10);
            strcpy(gender, generate_random_gender());

            add_student(teams, teams[i]->id, fullname, gender, grade);
        }
    }
}

void show_all(TEAM **teams) {
    for (int i = 0; i < TEAMS; i++) {
        show(teams[i]);
    }

    END();
}

void sort_by_gender_qtd(TEAM **teams, string gender) {
    int gender_qtd[TEAMS];
    int ids[TEAMS];

    printf("\n\nSorting by %ss...", gender);

    for (int i = 0; i < TEAMS; i++) {
        gender_qtd[i] = 0;
        ids[i] = teams[i]->id;

        for (int j = 0; j < teams[i]->length; j++) {
            if (strcmp(teams[i]->students[j].gender, gender) == 0) {
               gender_qtd[i]++;
            }
        }
    }

    for (int i = 0; i < TEAMS; i++) {
        for (int j = i; j < TEAMS; j++) {
            if (gender_qtd[i] < gender_qtd[j]) {
                int tmp = gender_qtd[j];
                gender_qtd[j] = gender_qtd[i];
                gender_qtd[i] = tmp;

                tmp = ids[j];
                ids[j] = ids[i];
                ids[i] = tmp;
            }
        }
    }

    for (int i = 0; i < TEAMS; i++) {
        printf("\nTeam [%d] has %d %ss", ids[i], gender_qtd[i], gender);
    }

    END();
}

TEAM * filter_by_gender_and_grade(TEAM **src_teams, string gender, float grade) {
    TEAM *filtered = create_team(1001);

    for (int i = 0; i < TEAMS; i++) {
        for (int j = 0; j < STUDENTS; j++) {
            if (strcmp(src_teams[i]->students[j].gender, gender) == 0 &&
                src_teams[i]->students[j].grade >= grade
            ) {
                push_student_to_team(
                        filtered,
                        src_teams[i]->students[j].name,
                        src_teams[i]->students[j].gender,
                        src_teams[i]->students[j].grade
                );
            }
        }
    }

    if (filtered->length == 0)
        printf("No one was selected. ");

    END();
    return filtered;
}

TEAM * filter_by_gender(TEAM **src_teams, string gender) {
    TEAM *filtered = create_team(1002);

    for (int i = 0; i < TEAMS; i++) {
        for (int j = 0; j < STUDENTS; j++) {
            if (strcmp(src_teams[i]->students[j].gender, gender) == 0) {
                push_student_to_team(
                        filtered,
                        src_teams[i]->students[j].name,
                        src_teams[i]->students[j].gender,
                        src_teams[i]->students[j].grade
                );
            }
        }
    }

    return filtered;
}

void increase_grade(TEAM *team, int i, float increment) {
    if (team->students[i].grade + increment > 10.0) {
        team->students[i].grade = 10.0;
        return;
    }

    team->students[i].grade += increment;
}

void make_increasing(TEAM** teams, int target_team_id, string gender) {
    printf("\nIncreasing grades for %s students from Team [%d]...", gender, target_team_id);

    TEAM * dest_team = find_team_by_id(teams, target_team_id);

    for (int i = 0; i < dest_team->length; i++) {
        if (strcmp(dest_team->students[i].gender, gender) == 0) {
            increase_grade(dest_team, i, 1.0);
        }
    }

    END();
}

int main() {
    srand(time(NULL));

    TEAM *teams[TEAMS];

    for (int i = 0; i < TEAMS; i++) {
        teams[i] = create_team(i + 1);
    }

    initialize_teams(teams);
    show_all(teams);

    sort_by_gender_qtd(teams, "Female");

    add_student(teams, 1, "Gabriel", "Male", 9.5);
    add_student(teams, 1, "Julia", "Female", 9.2);

    show_all(teams);

    printf("Selection...");
    TEAM *filtered = filter_by_gender_and_grade(teams, "Female", 8.0);
    show(filtered);

    make_increasing(teams, 1, generate_random_gender());
    show_all(teams);

    return 0;
}