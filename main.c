#include <stdio.h>
#include <string.h>

#define N 50

int check_name(char* string)
{
    char temp[strlen(string)], len = 0;
    for (int i = 0; (string[i] > 96) && (string[i] < 123); i++) {
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

int check_args(char* string, int len)
{
    if (string[len] != '(') {
        printf("Error at column %d: expected '('\n", len);
        return 1;
    }
    char arg_count = 0, arg2_count = 0, d = 0, b = 0;
    for (int i = len + 1; (i < strlen(string)) && (string[i] != ','); i++) {
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
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] == ',') {
            v = i + 1;
        }
    }
    for (int i = v; (string[i] != ')') && (i < strlen(string)) - 1; i++) {
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
    if (string[strlen(string) - 1] == '\n')
        endst = strlen(string) - 2;
    else
        endst = strlen(string) - 1;
    for (int i = 0; i < strlen(string); i++) {
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

int Errormsg(char* string, char count)
{
    printf("shape number: %d\n", count);
    printf("%s\n", string);
    int len;
    if ((len = check_name(string)) == 1)
        printf("Error at column 0: expected 'circle'\n");
    else if (check_args(string, len))
        return 0;
    else if (check_str_end(string))
        return 0;
    return 0;
}

int main()
{
    char string[N];
    FILE* check;
    check = fopen("shapes.txt", "r");
    for (char count = 1; fgets(string, N, check) != NULL; count++) {
        Errormsg(string, count);
    }
    return 0;
}
