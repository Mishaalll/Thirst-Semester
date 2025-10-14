#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"

int mystrcmp(const char* s1, const char* s2)
{
    while (*s1 && *s2)
    {
        if (*s1 != *s2)
            return *s1 - *s2;
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

void mystrcpy(char* dest, const char* src)
{
    while (*src)
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

int myatoi(const char* a) 
{
    return atoi(a);
}



char *mystrcat(char *a, const char *b)
{
    int i = 0;
    int j = 0;

    while (a[i] != '\0')
        i++;

    while (b[j] != '\0')
    {
        a[i] = b[j];
        i++;
        j++;
    }

    a[i] = '\0';

    return a;
}
