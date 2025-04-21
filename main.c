#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 255

typedef void (*strTransform) (char* dst, char* src);

void
printList(int size, char** lst)
{
    int i;
    for (i = 0; i < size; i++)
    { 
        printf("%d: %s\n", i, lst[i]); 
    }
}

void
uppercase(char* dst, char* src)
{
    size_t i;
    for (i = 0; src[i] != '\0'; i++)
    {
        dst[i] = src[i] >= 'a' && src[i] <= 'z' ? src[i]-32 : src[i];
    }
    dst[strlen(src)] = '\0';
}

void
reverse(char* dst, char* src)
{
    size_t i, len;
    len = strlen(src);
    for (i = 0; src[i] != '\0'; i++)
    {
        dst[i] = src[len-i-1];
    }
    dst[len] = '\0';
}

void
concatenate(char* dst, char* src)
{
    size_t dlen, slen;
    dlen = strlen(dst); 
    slen = strlen(src);
    strcpy(dst+dlen,src);
    dst[dlen+slen] = '\0';
}

void
concatenateList(int argc, char** argv, char* dst)
{
    int i;
    if (argc < 0 || sizeof(dst) < sizeof(argv)) { exit(1); }
    for (i = 0; i < argc; i++)
    {
        concatenate(dst, argv[i]);
    }
}

void
mapStrTransform(int argc, char** argv, char** dst, strTransform fn)
{
    int i;
    for (i = 0; i < argc; i++) 
    { 
        fn(dst[i], argv[i]);
    }
}

int
main(int argc, char** argv)
{
    int i;
    char **du, **dr, *dc;

    du = malloc(sizeof(char*) * BUF_SIZE);
    dr = malloc(sizeof(char*) * BUF_SIZE);
    dc = malloc(sizeof(char) * BUF_SIZE);
    if (du == NULL || dr == NULL || dc == NULL)
    {
        fprintf(stderr, "%s:%d ERROR: malloc failed\n", __FILE__, __LINE__);
        exit(1);
    }
    for (i = 0; i < argc; i++) 
    {
        du[i] = malloc(sizeof(char) * BUF_SIZE);
        dr[i] = malloc(sizeof(char) * BUF_SIZE);
    }
    mapStrTransform(argc, argv, du, uppercase);
    mapStrTransform(argc, argv, dr, reverse);
    concatenateList(argc, argv, dc);
    
    printList(argc, du);
    printList(argc, dr);
    printf("dc: %s\n", dc);
     
    return 0;
}
