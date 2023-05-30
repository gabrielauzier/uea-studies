#include <stdio.h>
#include <stdlib.h>

#include <conio.h>

#include "show.h"

#define MAX_CHAR 255
typedef char string[MAX_CHAR];

void print_green(string src) {
    printf("%s%s", FR_GREEN, src);
}

void print_red(string src) {
    printf("%s%s", FR_RED, src);
}

void print_blue(string src) {
    printf("%s%s", FR_BLUE, src);
}

void print_magenta(string src) {
    printf("%s%s", FR_MAGENTA, src);
}

void _reset() {
    printf("%s", FR_NORMAL);
}

void _config() {
    system("chcp 65001");
//    system("@cls");
};

void init_show() {
    _config();
}

void show() {
    system("chcp 65001");
    system("@cls");

//    printf("%sred\n", FOREGROUND_RED);
//    printf("%syellow\n", FR_YELLOW);
//    printf("%sblue\n", FR_BLUE);
//    printf("%smagenta\n", FR_MAGENTA);
//    printf("%scyan\n", FR_CYAN);
//    printf("%swhite\n", FR_WHITE);
//    printf("%snormal\n", FR_NORMAL);

//    print_green("oi, meu nome é gabs");
}

void title(char *string) {
    print_green("\n\n\n__________________________________________________\n");
    print_green(string);
    print_green("\n--------------------------------------------------\n");

    _reset();
}

void subtitle(char *string) {
    println("");
    print_magenta(string);
    println("");
}

void warn(char *string) {
    println("");
    print_red(string);
    println("");
}

void attr_str(char *key, char *value) {
    print_blue(key);
    printf(": ");
    _reset();
    println(value);
}

void attr_int(char *key, int value) {
    print_blue(key);
    printf(": ");
    _reset();
    printf("%d\n", value);
}

void attr_dob(char *key, double value) {
    print_blue(key);
    printf(": ");
    _reset();
    printf("%.2lf\n", value);
}