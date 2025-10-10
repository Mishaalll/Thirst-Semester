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

void printmyData(struct myData stud)
{
    printf("Age: %d\nName: %s\nYear: %d\nCourse: %s\nBirthdate: %d/%d/%d\n\n",
           stud.age, stud.name, stud.year, stud.course,
           stud.bdate.day, stud.bdate.month, stud.bdate.year);
}

int sortbirth(struct birthdate a, struct birthdate b)
{
    if (a.year != b.year) 
    {
        return a.year - b.year;
    }    
    if (a.month != b.month) 
    {
        return a.month - b.month;
    }
    return a.day - b.day;
}
