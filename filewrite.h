#ifndef FILEWRITE_H
#define FILEWRITE_H

#include "mylib.h"

struct birthdate
{
    int day;
    int month;
    int year;
};

struct myData
{
    int age;
    char *name;
    int year;
    char course[10];
    struct birthdate bdate;
};

void writeDatabase(struct myData *students, int count, const char *filename);

#endif
