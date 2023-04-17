#include "src/libgeometry/lexer.h"
#include "src/libgeometry/parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N = 50;

int main()
{
    char* string = (char*)malloc(N * sizeof(char));
    FILE* check;
    check = fopen("shapes.txt", "r");
    if (check == NULL) {
        printf("Error of opening file!\n");
        return 1;
    }
    for (char count = 1; fgets(string, N, check) != NULL; count++) {
        if (is_circle(string, count) == 1) {
            return 1;
        }
    }
    return 0;
}
