#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libgeometry/counter.h"
#include "libgeometry/macr.h"
#include "libgeometry/parser.h"

int main()
{
    char* string = (char*)malloc(N * sizeof(char));
    double ** val = (double**)malloc(sizeof(double*));
    val[0] = (double*)malloc(COL*sizeof(double)); 
    FILE* check;
    check = fopen("shapes.txt", "r");
    if (check == NULL) {
        printf("Error of opening file!\n");
        return 1;
    }
    for (char count = 1; fgets(string, N, check) != NULL; count++) {
        if (!is_circle(string, count)) {
            printf("\tarea = %f\n", count_area(string));
            printf("\tperimeter = %f\n", count_perimeter(string));

        }
    }
    free(string);
    return 0;
}
