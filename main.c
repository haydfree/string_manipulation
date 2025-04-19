#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char*
safeCopy(char* arg)
{
    char* str;
    if (arg == NULL) { return NULL; }
    str = malloc(strlen(arg) + 1);
    if (str == NULL) { return NULL; }
    strcpy(str, arg);
    return str;
}

void
printList(int size, char** lst)
{
    int i;
    for (i = 0; i < size; i++) { printf("%d: %s\n", i, lst[i]); }
}

char* 
uppercase(char* arg)
{
    int i;
    char* str;

    str = safeCopy(arg);
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

char**
uppercaseList(int argc, char** argv)
{
    int i;
    char** lst;
    if (argc < 0) { exit(1); }
    lst = malloc(sizeof(char*) * (size_t)argc);
    for (i = 0; i < argc; i++) { lst[i] = uppercase(argv[i]); } 
    return lst;
}

char*
reverse(char* arg)
{
    size_t i,len;
    char* str;
    char temp;

    str = safeCopy(arg);
    len = strlen(str);
    i = 0;
    for (i = 0; i < len / 2; i++)
    {
        temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
    return str;
}

char**
reverseList(int argc, char** argv)
{
    int i;
    char** lst;
    if (argc < 0) { exit(1); }
    lst = malloc(sizeof(char*) * (size_t)argc);
    for (i = 0; i < argc; i++) { lst[i] = reverse(argv[i]); } 
    return lst;
}

void
concatenate(char* dst, char* src)
{
    size_t dlen;
    dlen = strlen(dst); 
    strcpy(dst+dlen,src);
    *(dst+dlen+strlen(src))='\0';
}

char**
concatenateList(int argc, char** argv, char** dst)
{
    int i;
    char** lst;
    if (argc < 0) { exit(1); }
    lst = malloc(sizeof(char*) * (size_t)argc);
    for (i = 0; i < argc-1; i++) { concatenate(dst[i], argv[i]); } 
    return lst;
}

int
main(int argc, char** argv)
{
    int i;
    char** dst;

    dst = malloc(sizeof(char*) * 20);
    for (i = 0; i < argc; i++) { printf("argv[%d]: %s\n", i, argv[i] ? argv[i] : "NULL"); }

    concatenateList(argc, argv, dst); 
    printList(argc, dst);

    return 0;
}
