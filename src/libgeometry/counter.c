#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>

#include "macr.h"
#include "parser.h"
#include "lexer.h"

double count_area(char* string)
{
    int len = check_name(string);
    if(check_args(string, len) != 0)
    {
        return -1;
    }
    int i = 0;
    char* temp = (char*)malloc(sizeof(char));
    int count = 0;
    for (i = 0; string[i] != ','; i++) {
    }
    i++;
    for (; string[i] != ')'; i++) {
        temp[count++] = string[i];
        temp = (char*)realloc(temp, (count + 1) * sizeof(char));
    }
    double k = M_PI * atof(temp) * atof(temp);
    free(temp);
    return k;
}

double count_perimeter(char* string)
{
    int len = check_name(string);
    if (check_args(string, len) != 0) {
        return -1;
    }
    int i = 0;
    char* temp = (char*)malloc(sizeof(char));
    int count = 0;
    for (i = 0; string[i] != ','; i++) {
    }
    i++;
    for (int p = i; string[p] != ')'; p++) {
        temp[count++] = string[p];
        temp = (char*)realloc(temp, (count + 1) * sizeof(char));
    }
    double k = 2 * M_PI * atof(temp);
    free(temp);
    return k;
}
