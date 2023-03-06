#include <stdio.h>
#include <string.h>

#define N 50

int check_name(char *string) {
    char temp[strlen(string)], len = 0;
    for(int i = 0; i < strlen(string); i++) {
        if(string[i] != '(') {
            temp[i] = string[i];
            len = i;
        }
        else break;
    }
    if(strcmp(temp, "circle") == 0) return len + 1;
    else return 1;
}

int main()
{
    char string[N];
    FILE* check;
    check = fopen("shapes.txt", "r");
    for (char count = 1; fgets(string, N, check) != NULL; count++) {
        if(check_name(string) == 1) {
            printf("%s\n", string);
            printf("error at column 1: expected 'circle'\n\n");
        }
        else printf("%s\n", string);
    }
    return 0;
}
