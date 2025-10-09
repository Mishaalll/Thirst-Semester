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
int minmax(int a, int b, int c, int *min, int *mid, int *max)
{
    if (a <= b && a <= c)
    {
        *min = 0;
        if (b <= c)
        {
            *mid = 1;
            *max = 2;
        }
        else
        {
            *mid = 2;
            *max = 1;
        }
    }
    else if (b <= a && b <= c)
    {
        *min = 1;
        if (a <= c)
        {
            *mid = 0;
            *max = 2;
        }
        else
        {
            *mid = 2;
            *max = 0;
        }
    }
    else
    {
        *min = 2;
        if (a <= b)
        {
            *mid = 0;
            *max = 1;
        }
        else
        {
            *mid = 1;
            *max = 0;
        }
    }
}
