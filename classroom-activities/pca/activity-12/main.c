#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_STUDENTS 14
#define MAX_CHAR 255

#define STUDENTS 6
#define TEAMS 2

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

typedef char STRING_MATRIX[TEAMS][MAX_STUDENTS][MAX_CHAR];
typedef float FLOAT_MATRIX[TEAMS][MAX_STUDENTS];

void insert_prop(STRING_MATRIX dest, int row, int col, char *prop) {
    if (col >= MAX_STUDENTS) return;
    if (row >= TEAMS) return;

    strcpy(dest[row][col], prop);
}

void insert_grade(FLOAT_MATRIX dest, int row, int col, float grade) {
    if (col >= MAX_STUDENTS) return;
    if (row >= TEAMS) return;

    dest[row][col] = grade;
}

float generate_random_num(int lim) {
    const int num = rand() % (lim * 10) + 1;

    float grade = (num * 1.0) / 10.0;

    return grade;
}

char * generate_random_gender() {
    const int num = rand() % 100 + 1;

    return num % 2 == 0 ? "Female" : "Male";
}   

void show(STRING_MATRIX src_names, STRING_MATRIX src_genders, FLOAT_MATRIX src_grades, int *std_qtd) {
    for (int i = 0; i < TEAMS; i++) {
        printf("\n\nTEAM %d:", i + 1);
        printf("\n students = %d", std_qtd[i]);
        for (int j = 0; j < std_qtd[i]; j++) {
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

    int greater = count[0], index = 0;

    for (int i = 0; i < TEAMS; i++) {
        if (count[i] > greater) {
            greater = count[i];
            index = i;
        }

        printf("\nFemales in team [%d] = %d", i + 1, count[i]);
    }

    printf("\nTeam [%d] has most female students. ", index + 1);
}

void increase_note(FLOAT_MATRIX dest, int row, int col, float increment) {
    if (col >= STUDENTS) return;
    if (row >= TEAMS) return;

    if (dest[row][col] + increment > 10.0) {
        dest[row][col] = 10.0;
        return;
    }

    dest[row][col] += increment;
}

void increase_female_grades(STRING_MATRIX src_genders, FLOAT_MATRIX src_grades) {

    const int target_team = 1;
    const int i = target_team;

    printf("\n\nIncrease female students grades (+1) from team [%d]...\n", target_team + 1);

    for (int j = 0; j < STUDENTS; j++) {
        if (strcmp(src_genders[i][j], "Female") == 0) {
            increase_note(src_grades, i, j, 1.0);
        }
    }
}

void add_student(
    STRING_MATRIX dest_names,
    STRING_MATRIX dest_genders,
    FLOAT_MATRIX dest_grades,
    int target_team,
    char *name,
    char *gender,
    float grade,
    int *std_qtd
) {
    const int i = target_team;

    insert_prop(dest_names, i, *std_qtd, name);

    insert_prop(dest_genders, i, *std_qtd, gender);

    insert_grade(dest_grades, i, *std_qtd, grade);
    (std_qtd[i])++;
}

/* note: the new students will not participate in selection */
void start_student_creation(
    STRING_MATRIX src_names,
    STRING_MATRIX src_genders,
    FLOAT_MATRIX src_grades,
    int *std_qtd
) {
    char option;

    do {
        char name[MAX_CHAR], gender[MAX_CHAR], gender_opt;
        int target_team;
        float grade;

        puts("\n\nCreating new student...");

        puts("Team:");
        do {
            scanf("%d", &target_team);
        } while (target_team <= 0 || target_team > TEAMS);

        puts("Name: ");
        scanf("%s", name);

        puts("Gender 'F' or 'M': ");
        do {
            scanf("%c", &gender_opt);
        } while(gender_opt != 'F' && gender_opt != 'M');

        gender_opt == 'F' ?
            strcpy(gender, "Female") :
            strcpy(gender, "Male");

        puts("Grade: ");
        do {
            scanf("%f", &grade);
        } while (grade < 0 || grade > 10.0);

        add_student(
            src_names,
            src_genders,
            src_grades,
            --target_team,
            name,
            gender,
            grade,
            std_qtd
        );

        puts("Want to add another student? 'y' or 'n'");

        do {
            option = tolower(getchar());
        } while(option != 'y' && option != 'n');

    } while (option == 'y');
}

void exercise() {
    STRING_MATRIX team_names;
    STRING_MATRIX team_genders;
    FLOAT_MATRIX team_grades;

    int students[TEAMS];

    for (int i = 0; i < TEAMS; i++)
        students[i] = 0;

    int k = 0;
    for (int i = 0; i < TEAMS; i++) {
        for (int j = 0; j < STUDENTS; j++, k++) {
            insert_prop(team_names, i, j, NAMES[k]);
            insert_prop(team_genders, i, j, generate_random_gender());
            insert_grade(team_grades, i, j, generate_random_num(10));

            students[i]++;
        }
    }

    show(team_names, team_genders, team_grades, students);

    verify_qualification(team_names, team_genders, team_grades);

    verify_females_per_group(team_names, team_genders);

    increase_female_grades(team_genders, team_grades);

    start_student_creation(team_names, team_genders, team_grades, students);

    show(team_names, team_genders, team_grades, students);
}

int main() {
    srand(time(NULL));

    exercise();
    return 0;
}