#include <stdio.h>

int
main(int argc, char** argv)
{
    printf("count: %d\n", argc);
    while (*argv != NULL)
    {
        printf("string: %s\n", *argv);
        argv++;
    }
    return 0;
}
