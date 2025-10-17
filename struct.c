#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"

struct myData
{
    int age;
    char *name;
    int year;
    char course[10];
    struct birthdate
    {
        int day;
        int month;
        int year;
    } bdate;
};

int main()
{
    int total = 3;

    static struct myData student[3];
    student[0].age = 17;
    student[0].name = "Misha";
    student[0].year = 2024;
    mystrcpy(student[0].course, "PX-24");
    student[0].bdate.day = 18;
    student[0].bdate.month = 8;
    student[0].bdate.year = 2008;

    student[1].age = 18;
    student[1].name = "Zhytomer";
    student[1].year = 2024;
    mystrcpy(student[1].course, "PX-24");
    student[1].bdate.day = 20;
    student[1].bdate.month = 9;
    student[1].bdate.year = 2007;

    student[2].age = 19;
    student[2].name = "Gosha";
    student[2].year = 2024;
    mystrcpy(student[2].course, "PX-24");
    student[2].bdate.day = 25;
    student[2].bdate.month = 12;
    student[2].bdate.year = 2002;


    int ind[3] = {0, 1, 2};
    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {
            struct birthdate a = student[ind[i]].bdate;
            struct birthdate b = student[ind[j]].bdate;

            if (a.year > b.year || (a.year == b.year && a.month > b.month) ||(a.year == b.year && a.month == b.month && a.day > b.day))
            {
                int temp = ind[i];
                ind[i] = ind[j];
                ind[j] = temp;
            }
        }
    }

    printf("Students:\n");
    for (int i = 0; i < 3; i++)
        printf("Age: %d\nName: %s\nYear: %d\nCourse: %s\nBirthdate: %d/%d/%d\n\n",
                student[i].age, student[i].name, student[i].year, student[i].course,
                student[i].bdate.day, student[i].bdate.month, student[i].bdate.year);

                
    printf("Sorted students by birth date:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("Age: %d\nName: %s\nYear: %d\nCourse: %s\nBirthdate: %d/%d/%d\n\n",
                student[ind[i]].age, student[ind[i]].name, student[ind[i]].year, student[ind[i]].course,
                student[ind[i]].bdate.day, student[ind[i]].bdate.month, student[ind[i]].bdate.year);
    }    
    char decision;
    printf("Do you want to enter new students? (y/n):\n");
    scanf("%c", &decision);

    struct myData *database = NULL;

    if (decision == 'y')
    {
        int n;
        printf("Enter how many students you want to add:\n");
        scanf("%d", &n);
        total = n + 3;

        struct myData *studentnew = malloc(total * sizeof(struct myData));

        for (int i = 0; i < 3; i++)
            studentnew[i] = student[i];

        printf("Enter student data in format:\n");
        printf("age name year course day month birthyear\n");

        for (int i = 3; i < total; i++)
        {
            studentnew[i].name = malloc(50 * sizeof(char));
            scanf("%d %49s %d %9s %d %d %d",
                  &studentnew[i].age,
                  studentnew[i].name,
                  &studentnew[i].year,
                  studentnew[i].course,
                  &studentnew[i].bdate.day,
                  &studentnew[i].bdate.month,
                  &studentnew[i].bdate.year);
        }

        printf("New students structure:\n");
        for (int i = 0; i < total; i++)
            printf("Age: %d\nName: %s\nYear: %d\nCourse: %s\nBirthdate: %d/%d/%d\n\n",
                    studentnew[i].age, studentnew[i].name, studentnew[i].year, studentnew[i].course,
                    studentnew[i].bdate.day, studentnew[i].bdate.month, studentnew[i].bdate.year);


        database = studentnew;
    }
    else
    {
        database = student; 
    }

    FILE *fp = fopen("database.txt", "w");

    for (int i = 0; i < total; i++)
    {
        fprintf(fp, "Age: %d, Name: %s, Year: %d, Course: %s, Birthdate: %02d/%02d/%04d\n",
                database[i].age,
                database[i].name,
                database[i].year,
                database[i].course,
                database[i].bdate.day,
                database[i].bdate.month,
                database[i].bdate.year);
    }
    fclose(fp);
    printf("Data saved successfully!\n");

    if (decision == 'y')
    {
        for (int i = 3; i < total; i++)
            free(database[i].name);
        free(database);
    }

    return 0;
}
