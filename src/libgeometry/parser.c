#include "libgeometry/lexer.h"
#include <stdio.h>
#include <string.h>

int check_args(char* string, int len)
{
    if (string[len] != '(') {
        printf("Error at column %d: expected '('\n", len);
        return 1;
    }
    char arg_count = 0, arg2_count = 0, d = 0, b = 0;
    for (int i = len + 1; (i < (int)strlen(string)) && (string[i] != ','); i++) {
        if ((string[i] != ' ') && (string[i] != '.')
            && (!((string[i] > 47) && (string[i] < 58)))) {
            printf("Error at column %d\n", i);
            return 1;
        }
        if ((string[i] > 47) && (string[i] < 58) && (string[i + 1] == ' ')) {
            arg_count += 1;
            d = i;
        } else if ((string[i] == '.') && (string[i + 1] == ')')) {
            arg_count += 3;
            d = i;
        }
    }
    if ((arg_count != 1)) {
        printf("Error at column %d: too many|less args\n", d);
        return 1;
    }
    int v = 0;
    for (int i = 0; i < (int)strlen(string); i++) {
        if (string[i] == ',') {
            v = i + 1;
        }
    }
    for (int i = v; (string[i] != ')') && (i < (int)strlen(string)) - 1; i++) {
        if (((string[i] != ' ') && (string[i] != '.')
             && (!((string[i] > 47) && (string[i] < 58))))
            || (string[i] == ',')) {
            printf("Error at column %d: \n", i);
            return 1;
        }
        if ((string[i] > 47) && (string[i] < 58) && (string[i + 1] == ' ')) {
            arg2_count += 1;
            b = i;
        } else if ((string[i] == '.') && (string[i + 1] == ' ')) {
            arg2_count += 2;
            b = i;
        }
    }
    if ((arg2_count != 1) && (b != 0)) {
        printf("Error at column %d: too many|less args\n", b);
        return 1;
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
            printf("Error at column %d: unexpected token\n", i + 1);
            return 1;
        } else if (
                (string[i] == ')')
                && ((string[i + 1] == '\n') || (string[i + 1] == ' '))) {
            end = i;
            break;
        }
    }
    if (endst != end) {
        printf("Error at column %d: expected ')'\n", endst);
        return 1;
    }
    return 0;
}

int is_circle(char* string, char count)
{
    printf("\nshape number: %d\n", count);
    printf("%s", string);
    int len;
    if ((len = check_name(string)) == 1)
        return 1;
    else if (check_args(string, len))
        return 1;
    else if (check_str_end(string))
        return 1;
    return 0;
}
