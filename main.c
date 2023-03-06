#include <stdio.h>
#include <string.h>

#define N 50

int check_name(char* string)
{
    char temp[strlen(string)], len = 0;
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] != '(') {
            temp[i] = string[i];
            len = i;
        } else
            break;
    }
    if (strcmp(temp, "circle") == 0)
        return len + 1;
    else
        return 1;
}

int check_args(char* string, char len)
{
    char arg_count = 0, arg2_count = 0, d = 0, b = 0;
    for (char i = len; (i < strlen(string)) && (string[i] != ','); i++) {
        if ((string[i] != ' ') && (string[i] != '.')
            && (!((string[i] > 47) && (string[i] < 58)))) {
            printf("Error at column %d", i);
            return 1;
        }
        if ((string[i] > 47) && (string[i] < 58) && (string[i + 1] == ' '))
            arg_count += 2;
        else if ((string[i] == '.') && (string[i + 1] == ')')) {
            arg_count += 3;
            d = i;
        }
    }
    if (arg_count > 2) {
        printf("Error at column %d", d);
        return 1;
    }

    for (char i = 0; i < strlen(string); i++) {
        if ((string[i] == ',') && (d == 0)) {
            d = i + 1;
        }
    }
    for (char i = d; (string[i] != ')') && (i < strlen(string)); i++) {
        if ((string[i] != ' ') && (string[i] != '.')
            && (!((string[i] > 47) && (string[i] < 58)))) {
            printf("Error at column %d", i);
            return 1;
        }
        if ((string[i] > 47) && (string[i] < 58) && (string[i + 1] == ' '))
            arg2_count += 1;
        else if ((string[i] == '.') && (string[i + 1] == ')')) {
            arg2_count += 2;
            b = i;
        }
    }
    if (arg2_count > 1) {
        printf("Error at column %d", b);
        return 1;
    }
    return 0;
}

check_str_end(char* string)
{
    char end = 0;
    if (string[strlen(string) - 1] == '\n')
        end = strlen(string) - 2;
    else
        end = strlen(string) - 1;
    if (string[end] != ')') {
        printf("Error at column %d: expected ')'", end);
        return 1;
    }
    return 0;
}

int main()
{
    char string[N];
    FILE* check;
    check = fopen("shapes.txt", "r");
    for (char count = 1; fgets(string, N, check) != NULL; count++) {
        if (check_name(string) == 1) {
            printf("%s\n", string);
            printf("error at column 0: expected 'circle'\n\n");
        } else
            printf("%s\n", string);
    }
    return 0;
}
