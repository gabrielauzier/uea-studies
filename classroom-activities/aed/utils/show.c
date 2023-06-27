#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void __change_foreground(PROMPT_COLORS color) {
    switch (color) {
        case NORMAL:
            printf("%s", FR_NORMAL);
            break;
        case BLUE:
            printf("%s", FR_BLUE);
            break;
        case CYAN:
            printf("%s", FR_CYAN);
            break;
        case GREEN:
            printf("%s", FR_GREEN);
            break;
        case MAGENTA:
            printf("%s", FR_MAGENTA);
            break;
        case RED:
            printf("%s", FR_RED);
            break;
        case WHITE:
            printf("%s", FR_WHITE);
            break;
        case YELLOW:
            printf("%s", FR_YELLOW);
            break;
        case BLACK:
            printf("%s", FR_BLACK);
            break;
        default:
            printf("%s", FR_NORMAL);
    }
}

void __change_background(PROMPT_COLORS color) {
    switch (color) {
        case NORMAL:
            printf("%s", BG_NORMAL);
            break;
        case BLUE:
            printf("%s", BG_BLUE);
            break;
        case CYAN:
            printf("%s", BG_CYAN);
            break;
        case GREEN:
            printf("%s", BG_GREEN);
            break;
        case MAGENTA:
            printf("%s", BG_MAGENTA);
            break;
        case RED:
            printf("%s", BG_RED);
            break;
        case WHITE:
            printf("%s", BG_WHITE);
            break;
        case YELLOW:
            printf("%s", BG_YELLOW);
            break;
        default:
            printf("%s", BG_NORMAL);
    }
}

void show_text(char *string, PROMPT_COLORS color) {
    __change_foreground(color);
    printf("%s%s", string, FR_NORMAL);
}

void show_text_ln(char *string, PROMPT_COLORS color) {
    __change_foreground(color);
    printf("%s%s", string, FR_NORMAL);
    endline();
}

void print_corner_up_left() {
    printf("%c", 1);
}

void print_corner_up_right() {
    printf("%c", 2);
}

void print_corner_down_left() {
    printf("%c", 3);
}

void print_corner_down_right() {
    printf("%c", 4);
}

void print_vertical_line(int n) {
    for (int i = 0; i < n; i++)
        printf("%c", 5);
}

void print_horizontal_line(int n) {
    for (int i = 0; i < n; i++)
        printf("%c", 6);
}

void print_blank_spaces(int n) {
    for (int i = 0; i < n; i++)
        printf(" ");
}

void show_text_align_center(char *string, int lineSize) {
    int len = strlen(string);
//    if (len % 2 != 0) len++;

    int middle = lineSize / 2;
    int index = middle - len / 2;

    print_blank_spaces(index);
    printf("%s", string);
    print_blank_spaces(lineSize - index - len);
}

void show_header(char *string, PROMPT_COLORS color) {
    __change_foreground(color);
    int len = strlen(string);
    int lineSize = 70;
    int middle = lineSize / 2;

    int index = middle - len / 2;

    print_corner_up_left();
    print_horizontal_line(lineSize);
    print_corner_up_right();
    endline();

    print_vertical_line(1);
    print_blank_spaces(lineSize);
    print_vertical_line(1);
    endline();

    print_vertical_line(1);
    print_blank_spaces(index);
    printf("%s", string);
    print_blank_spaces(lineSize - index - len);
    print_vertical_line(1);
    endline();

    print_vertical_line(1);
    print_blank_spaces(lineSize);
    print_vertical_line(1);
    endline();

    print_corner_down_left();
    print_horizontal_line(lineSize);
    print_corner_down_right();
    endline();
}

void show_highlight(char *string, PROMPT_COLORS bgColor, PROMPT_COLORS textColor) {
    __change_background(bgColor);
    __change_foreground(textColor);
    printf("%s", string);
    __change_background(NORMAL);
    __change_foreground(NORMAL);
}

void show_highlight_ln(char *string, PROMPT_COLORS bgColor, PROMPT_COLORS textColor) {
    __change_background(bgColor);
    __change_foreground(textColor);
    printf("%s", string);
    __change_background(NORMAL);
    __change_foreground(NORMAL);
    endline();
}

void show_separator(int n, PROMPT_COLORS color) {
    endline();
    __change_foreground(color);
    for (int i = 0; i < n; i++) {
        printf("_");
    }
    __change_foreground(NORMAL);
    endline();
};

void show_start(PROMPT_COLORS bgColor, PROMPT_COLORS textColor) {
    __change_background(bgColor);
    __change_foreground(textColor);
}

void show_close() {
    __change_background(NORMAL);
    __change_foreground(NORMAL);
}

void show_subtitle(char *string) {
    endline();
    print_magenta(string);
    endline();
}

void show_title(char *string) {
    endline();
    show_highlight(string, BLUE, BLACK);
    endline();
    endline();
}

void show_warning(char *string) {
    print_red(string);
    endline();
}

void show_attr_str(char *key, char *value) {
    print_blue(key);
    printf(": ");
    _reset();
    println(value);
}

void show_attr_int(char *key, int value) {
    print_blue(key);
    printf(": ");
    _reset();
    printf("%d\n", value);
}

void show_attr_dob(char *key, double value) {
    print_blue(key);
    printf(": ");
    _reset();
    printf("%.2lf\n", value);
}