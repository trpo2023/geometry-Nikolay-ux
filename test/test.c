#include <ctest.h>
#include <stdlib.h>
#include <ctest.h>
// #include "libgeometry/counter.h"

#include "libgeometry/lexer.h"
// #include "libgeometry/macr.h"
// #include "libgeometry/parser.h"

CTEST(check_figure_name, t1)
{
    char* str = "circle(1.0 1.0, 0)";
    const int expected = strlen("circle");
    const int real = check_name(str);
    ASSERT_EQUAL(expected, real);
}
