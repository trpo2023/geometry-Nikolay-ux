#include <stdlib.h>

float count_area(char* string)
{
    int i = 0;
    float pi = 3.141592;
    char* temp = (char*)malloc(sizeof(char));
    int count = 0;
    for (i = 0; string[i] != ','; i++)
        ;
    i++;
    for (; string[i] != ')'; i++) {
        temp[count++] = string[i];
        temp = (char*)realloc(temp, (count + 1) * sizeof(char));
    }
    return pi * atof(temp) * atof(temp);
}

float count_perimeter(char* string)
{
    int i = 0;
    float pi = 3.141592;
    char* temp = (char*)malloc(sizeof(char));
    int count = 0;
    for (i = 0; string[i] != ','; i++)
        ;
    i++;
    for (; string[i] != ')'; i++) {
        temp[count++] = string[i];
        temp = (char*)realloc(temp, (count + 1) * sizeof(char));
    }
    return 2 * pi * atof(temp);
}
