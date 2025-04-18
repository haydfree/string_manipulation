#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* 
uppercase(char* arg)
{
    char* str;
    int i;
    if (arg == NULL) { return NULL; }
    str = malloc(strlen(arg) + 1);
    if (str == NULL) { return NULL; }
    strcpy(str, arg);

    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 97 && str[i]<= 122)
        {
            str[i]-=32;
        }
        i++;
    }

    return str;
}

int
main(int argc, char** argv)
{
    char* str;
    printf("%d %s\n\n", argc, argv[0]);

    str = uppercase(argv[0]);
    printf("%s", str);
    return 0;
}
