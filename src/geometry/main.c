#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libgeometry/counter.h"
#include "libgeometry/macr.h"
#include "libgeometry/parser.h"

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
        int k = is_circle(string, count);
        switch (k) {
            case 0:
                printf("\tarea = %f\n", count_area(string));
                printf("\tperimeter = %f\n", count_perimeter(string));
                break;
            case 1:
                printf("Error: expected 'circle'\n");
                break;
            case 2:
                printf("Error: expected '('\n");
                break;
            case 3:
                printf("Error: expected double\n");
                break;
            case 4:
                printf("Error: too many|less args\n");
                break;
            case 5:
                printf("Error: expected double\n");
                break;
            case 6:
                printf("Error: unexpected token\n");
                break;
            case 7:
                printf("Error: expected ')'\n");
                break;
        }
    }
    free(string);
    return 0;
}
