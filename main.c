#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 255

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
    memset(dst, 0, BUF_SIZE);
    for (i = 0; src[i] != '\0'; i++)
    {
        if (src[i] >= 97 && src[i] <= 122)
        {
            dst[i] = src[i]-32;
        } else {
            dst[i] = src[i];
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
    memset(dst, 0, BUF_SIZE);
    for (i = 0; src[i] != '\0'; i++)
    {
        dst[i] = src[len-i-1];
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
    size_t dlen, slen;
    dlen = strlen(dst); 
    slen = strlen(src);
    memset(dst+dlen, 0, BUF_SIZE);
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
    uppercaseList(argc, argv, du);
    reverseList(argc, argv, dr);
    concatenateList(argc, argv, dc);
    
    printList(argc, du);
    printList(argc, dr);
    printf("dc: %s\n", dc);
     
    return 0;
}
