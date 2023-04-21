#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libgeometry/lexer.h"
#include "macr.h"

int check_brace_1(char* string, int* len)
{
    *len += 1;
    return (string[*len - 1] != '(') ? 2 : 0;
}

int check_arg_x(char* string, int* lenght)
{
    char temp[N];
    int j = 0, len = 0, p = *lenght;
    for (int i = p; ((string[i] >= '0') && (string[i] <= '9')) || (string[i] == '.') || (string[i] == '-'); i++) {
        temp[j++] = string[i];
        *lenght += 1;
        len = i + 1;
    }
    if ((len == 0) || (string[len] != ' ')) {
        return 3;
    }
    if (string[p] != '0' && atof(temp) == 0) {
        return 3;
    }
    *lenght += 1;
    return 0;
}

int check_arg_y(char* string, int* lenght)
{
    char temp[N];
    int j = 0, len = 0, p = *lenght;
    for (int i = p; ((string[i] >= '0') && (string[i] <= '9')) || (string[i] == '.') || (string[i] == '-'); i++) {
        temp[j++] = string[i];
        *lenght += 1;
        len = i + 1;
    }
    if ((len == 0) || (string[len] != ',')) {
        return 4;
    }
    if (string[p] != '0' && atof(temp) == 0) {
        return 4;
    }
    *lenght += 1;
    return 0;
}

int check_radius(char* string, int* lenght)
{
    int len = 0, p = *lenght + 1;
    for (int i = p; ((string[i] >= '0') && (string[i] <= '9')) || (string[i] == '.'); i++) {
        *lenght += 1;
        len = i + 1;
    }
    if (len == 0) {
        return 5;
    }
    *lenght += 1;
    return 0;
}

int check_brace_2(char* string, int* lenght)
{
    if (string[*lenght] != ')') {
        return 7;
    }
    else if (*lenght + 4 < (int)strlen(string)) {
        return 8;
    }
    return 0;
}

int is_circle(char* string, char count)
{
    printf("\n%d. ", count);
    printf("%s", string);
    int len = 0;
    int name = check_name(string, &len);
    if (name == 1) {
        printf("Error: expected 'circle'\n");
        return 1;
    }
    if (check_brace_1(string, &len) == 2) {
        printf("Error: expected '('\n");
        return 1;
    }
    if (check_arg_x(string, &len) == 3) {
        printf("Error at x coordinate: expected double\n");
        return 1;
    }
    if (check_arg_y(string, &len) == 4) {
        printf("Error at y coordinate: expected double\n");
        return 1;
    }
    if (check_radius(string, &len) == 5) {
        printf("Error at radius: expected double\n");
        return 1;
    }
    if (check_brace_2(string, &len) == 7) {
        printf("Error: expected ')'\n");
        return 1;
    }
    else if (check_brace_2(string, &len) == 8) {
        printf("Error: unexpected token\n");
        return 1;
    }
    return 0;
}
