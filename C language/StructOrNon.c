//struct record
#include <stdio.h>

struct Student
{
    char name[20];
    int age;
    float gpa;
    char grade[20];
};

typedef struct Student Record;

int main()
{
    Record r[10] = {
        {"James",18,3.80,"freshman"},
        {"Andy",18,3.80,"freshman"},
        {"Brandon",18,3.80,"freshman"},
        {"Heria",18,3.80,"freshman"},
        {"Addison",18,3.80,"freshman"},
        {"Keila",18,3.80,"freshman"},
        {"Sunny",18,3.80,"freshman"},
        {"Stark",18,3.80,"freshman"},
        {"Hork",18,3.80,"freshman"},
        {"Hugo",18,3.80,"freshman"}
    };

    for(int i = 0; i < 10 ; i++)
    {
        printf("Name: %s, Age: %d, Gpa %.2f, Grade: %s \n",r[i].name, r[i].age, r[i].gpa, r[i].grade);
    }

    return 0;
}

//non-struct record
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *name[10];
    int age[10];
    float gpa[10];
    char *grade[10];

    name[0]=(char*)malloc(20); name[0]="James"; age[0]=18; gpa[0]=3.7; grade[0]=(char*)malloc(20); grade[0]="First year";
    name[1]=(char*)malloc(20); name[1]="Andy"; age[1]=18; gpa[1]=3.3; grade[1]=(char*)malloc(20); grade[1]="First year";
    name[2]=(char*)malloc(20); name[2]="Brandon"; age[2]=18; gpa[2]=3.4; grade[2]=(char*)malloc(20); grade[2]="First year";
    name[3]=(char*)malloc(20); name[3]="Heria"; age[3]=18; gpa[3]=3.2; grade[3]=(char*)malloc(20); grade[3]="First year";
    name[4]=(char*)malloc(20); name[4]="Addison"; age[4]=18; gpa[4]=3.7; grade[4]=(char*)malloc(20); grade[4]="First year";
    name[5]=(char*)malloc(20); name[5]="Keila"; age[5]=18; gpa[5]=3.8; grade[5]=(char*)malloc(20); grade[5]="First year";
    name[6]=(char*)malloc(20); name[6]="Sunny"; age[6]=18; gpa[6]=3.9; grade[6]=(char*)malloc(20); grade[6]="First year";
    name[7]=(char*)malloc(20); name[7]="Stark"; age[7]=18; gpa[7]=3.4; grade[7]=(char*)malloc(20); grade[7]="First year";
    name[8]=(char*)malloc(20); name[8]="Hork"; age[8]=18; gpa[8]=3.6; grade[8]=(char*)malloc(20); grade[8]="First year";
    name[9]=(char*)malloc(20); name[9]="Hugo"; age[9]=18; gpa[9]=3.3; grade[9]=(char*)malloc(20); grade[9]="First year";

    int i = 0;

    for(i = 0; i < 10 ; i++)
    {
        printf("Name: %s, Age: %d, Gpa %.2f, Grade: %s \n", name[i], age[i], gpa[i], grade[i]);
    }

    return 0;
}
