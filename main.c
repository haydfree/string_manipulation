#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
printList(int size, char** lst)
{
    int i;
    for (i = 0; i < size; i++) { printf("%d: %s\n", i, lst[i]); }
}

void
uppercase(char* dst, char* src)
{
    size_t i;

    for (i = 0; src[i] != '\0'; i++)
    {
        if (src[i] >= 97 && src[i] <= 122)
        {
            memcpy(dst[i], src[i], 1);
        }
    }
}

void
uppercaseList(int argc, char** argv, char** dst)
{
    int i;
    if (argc < 0 || sizeof(dst) < sizeof(argv)) { exit(1); }
    for (i = 0; i < argc; i++) 
    { 
        uppercase(dst[i], argv[i]);
    }
}

void
reverse(char* dst, char* src)
{
    size_t i, len;
    len = strlen(src);
    for (i = 0; src[i] != '\0'; i++)
    {
        memcpy(dst[i], src[len-i], 1);
    }
}

void
reverseList(int argc, char** argv, char** dst)
{
    int i;
    if (argc < 0 || sizeof(dst) < sizeof(argv)) { exit(1); }
    for (i = 0; i < argc; i++) 
    { 
        reverse(dst[i], argv[i]); 
    } 
}

void
concatenate(char* dst, char* src)
{
    size_t dlen;
    dlen = strlen(dst); 
    strcpy(dst+dlen,src);
    dst[dlen+strlen(src)] = '\0';
}

void
concatenateList(int argc, char** argv, char* dst)
{
    int i;
    if (argc < 0) { exit(1); }
    for (i = 0; i < argc; i++)
    {
        concatenate(dst, argv[i]);
    }
}

int
main(int argc, char** argv)
{
    char* dst;
    char* arg;
    uppercase(
     
    return 0;
}
