#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>

#include "macr.h"

float count_area(char* string)
{
    int i = 0;
    float pi = 3.141592;
    char* temp = (char*)malloc(sizeof(char));
    int count = 0;
    for (i = 0; string[i] != ','; i++) {
    }
    i++;
    for (; string[i] != ')'; i++) {
        temp[count++] = string[i];
        temp = (char*)realloc(temp, (count + 1) * sizeof(char));
    }
    float k = M_PI * atof(temp) * atof(temp);
    free(temp);
    return k;
}

float count_perimeter(char* string)
{
    int i = 0;
    float pi = 3.141592;
    char* temp = (char*)malloc(sizeof(char));
    int count = 0;
    for (i = 0; string[i] != ','; i++) {
    }
    i++;
    for (int p = i; string[p] != ')'; p++) {
        temp[count++] = string[p];
        temp = (char*)realloc(temp, (count + 1) * sizeof(char));
    }
    float k = 2 * M_PI * atof(temp);
    free(temp);
    return k;
}
