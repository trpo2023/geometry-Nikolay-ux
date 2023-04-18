#include <stdio.h>
#include <string.h>

#include "libgeometry/lexer.h"

int check_args(char* string, int len)
{
    if (string[len] != '(') {
        return 2;
    }
    char arg_count = 0, arg2_count = 0, b = 0;
    for (int i = len + 1; (i < (int)strlen(string)) && (string[i] != ',');
         i++) {
        if ((string[i] != ' ') && (string[i] != '.')
            && (!((string[i] >= '0') && (string[i] <= '9')))) {
            return 3;
        } else if (
                (string[i] >= '0') && (string[i] <= '9')
                && (string[i + 1] == ' ')) {
            arg_count += 1;
        } else if ((string[i] == '.') && (string[i + 1] == ')')) {
            arg_count += 3;
        }
    }
    if ((arg_count != 1)) {
        return 4;
    }
    int v = 0;
    for (int i = 0; i < (int)strlen(string); i++) {
        if (string[i] == ',') {
            v = i + 1;
        }
    }
    for (int i = v; (string[i] != ')') && (i < (int)strlen(string)) - 1; i++) {
        if (((string[i] != ' ') && (string[i] != '.')
             && (!((string[i] >= '1') && (string[i] <= '9'))))
            || (string[i] == ',')) {
            return 5;
        } else if (
                (string[i] >= '1') && (string[i] <= '9')
                && (string[i + 1] == ' ')) {
            arg2_count += 1;
            b = i;
        } else if ((string[i] == '.') && (string[i + 1] == ' ')) {
            arg2_count += 2;
            b = i;
        }
    }
    if ((arg2_count != 1) && (b != 0)) {
        return 4;
    }
    return 0;
}

int check_str_end(char* string)
{
    int endst = 0, end = 0;
    if (string[(int)strlen(string) - 1] == '\n')
        endst = (int)strlen(string) - 2;
    else
        endst = (int)strlen(string) - 1;
    for (int i = 0; i < (int)strlen(string); i++) {
        if ((string[i] == ')') && (string[i + 1] != '\n')) {
            return 6;
        } else if (
                (string[i] == ')')
                && ((string[i + 1] == '\n') || (string[i + 1] == ' '))) {
            end = i;
            break;
        }
    }
    if (endst != end) {
        return 7;
    }
    return 0;
}

int is_circle(char* string, char count)
{
    printf("\n%d. ", count);
    printf("%s", string);
    int len;
    if ((len = check_name(string)) == 1) {
        printf("Error: expected 'circle'\n");
        return 1;
    }
    int d = 0;
    int k = check_args(string, len);
    switch (k) {
        case 0:
            d = check_str_end(string);
            break;
        case 2:
            printf("Error: expected '('\n");
            return 1;
        case 3:
            printf("Error: expected double\n");
            return 1;
        case 4:
            printf("Error: too many|less args\n");
            return 1;
        case 5:
            printf("Error: expected double\n");
            return 1;
    }
    switch (d) {
        case 0:
            return 0;
        case 6:
            printf("Error: unexpected token\n");
            return 1;
        case 7:
            printf("Error: expected ')'\n");
            return 1;
    }
    return 0;
}
