#include <stdio.h>
#include "filewrite.h"

void writeDatabase(struct myData *students, int count, const char *filename)
{
    FILE *fp = fopen(filename, "w");
    for (int i = 0; i < count; i++)
    {
        fprintf(fp, "Age: %d, Name: %s, Year: %d, Course: %s, Birthdate: %02d/%02d/%04d\n",
                students[i].age,
                students[i].name,
                students[i].year,
                students[i].course,
                students[i].bdate.day,
                students[i].bdate.month,
                students[i].bdate.year);
    }

    fclose(fp);
    printf("\nData saved to %s successfully!\n", filename);
}
