#include "libgeometry/counter.h"
#include "libgeometry/parser.h"

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
        if (is_circle(string, count) == 0) {
            printf("\tarea = %f\n", count_area(string));
            printf("\tperimeter = %f\n", count_perimeter(string));
        }
    }
    return 0;
}
