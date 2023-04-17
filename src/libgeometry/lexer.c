#include <stdio.h>
#include <string.h>

extern int N;

int check_name(char* string)
{
    char temp[N], len = 0;
    for (int i = 0; (string[i] > 96) && (string[i] < 123); i++) {
        if (string[i] != '(') {
            temp[i] = string[i];
            len = i;
        } else
            break;
    }
    if (strcmp(temp, "circle") == 0)
        return len + 1;
    else {
        printf("Error at column 0: expected 'circle'\n");
        return 1;
    }
}
