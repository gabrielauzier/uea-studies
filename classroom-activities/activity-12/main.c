#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <unistd.h>

#define STUDENTS 10
#define TEAMS 2
#define MAX_CHAR 255

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

typedef char STRING_MATRIX[TEAMS][STUDENTS][MAX_CHAR];
typedef float FLOAT_MATRIX[TEAMS][STUDENTS];

void insert_name(STRING_MATRIX dest, int row, int col, char *name) {

    if (col >= STUDENTS) return;
    if (row >= TEAMS) return;

    strcpy(dest[row][col], name);
}

void insert_gender(STRING_MATRIX dest, int row, int col, char *gender) {

    if (col >= STUDENTS) return;
    if (row >= TEAMS) return;

    strcpy(dest[row][col], gender);
}

void insert_grade(FLOAT_MATRIX dest, int row, int col, float grade) {
    if (col >= STUDENTS) return;
    if (row >= TEAMS) return;

    dest[row][col] = grade;
}

float generate_random_grande() {
    const int num = rand() % 100 + 1;

    float grade = (num * 1.0) / 10.0;

    return grade;
}

char generate_random_gender() {
    const int num = rand() % 100 + 1;

    return num % 2 == 0 ? 'F' : 'M';
}

void show(STRING_MATRIX src_names, STRING_MATRIX src_genders, FLOAT_MATRIX src_grades ) {
    for (int i = 0; i < TEAMS; i++) {
        printf("\n\nTEAM %d:", i + 1);
        for (int j = 0; j < STUDENTS; j++) {
            printf("\n{ %s, %s, %.1f }", src_names[i][j], src_genders[i][j], src_grades[i][j]);
        }
    }
}

/* female with grade greater than 8 */
void verify_qualification(STRING_MATRIX src_names, STRING_MATRIX src_genders, FLOAT_MATRIX src_grades) {
    char qualified[STUDENTS * TEAMS][MAX_CHAR];
    int count = 0;

    puts("\n\nChecking students qualification...");

    for (int i = 0; i < TEAMS; i++) {
        for (int j = 0; j < STUDENTS; j++) {
            if (strcmp(src_genders[i][j], "Female") == 0 && src_grades[i][j] > 8.0) {
                printf("\nQualified! %s", src_names[i][j]);
                strcpy(qualified[count], src_names[i][j]);
                count++;
            }
        }
    }

    if (count == 0)
        printf("No one was qualified.");
}

void verify_females_per_group(STRING_MATRIX src_names, STRING_MATRIX src_genders) {
    int count[TEAMS];

    puts("\n\nChecking females per team...");

    for (int i = 0; i < TEAMS; i++) {
        count[i] = 0;

        for (int j = 0; j < STUDENTS; j++) {
            if (strcmp(src_genders[i][j], "Female") == 0) {
                count[i]++;
            }
        }
    }

    int greater = 0, index = 0;
    for (int i = 0; i < TEAMS; i++) {
        printf("\nFemales in team [%d] = %d", i + 1, count[i]);
    }
}

void exercise() {
    STRING_MATRIX team_names;
    STRING_MATRIX team_genders;
    FLOAT_MATRIX team_grades;

    int k = 0;
    for (int i = 0; i < TEAMS; i++) {
        for (int j = 0; j < STUDENTS; j++, k++) {
            insert_name(team_names, i, j, NAMES[k]);

            generate_random_gender() == 'F' ?
                insert_gender(team_genders, i, j, "Female") :
                insert_gender(team_genders, i, j, "Male");

            insert_grade(team_grades, i, j, generate_random_grande());
        }
    }

    show(team_names, team_genders, team_grades);

    verify_qualification(team_names, team_genders, team_grades);

    verify_females_per_group(team_names, team_genders);

}

int main() {
    srand(time(NULL));

    exercise();
    return 0;
}