#include <stdio.h>
#include <string.h>

// Define a structure to store marks for each subject
typedef struct 
{
    int isa1;
    int isa2;
    int esa;
    int assignment;
} SubjectMarks;

// Define a structure to store data for each student
typedef struct 
{
    char name[100];
    char srn[10];
    char sem[3];
    SubjectMarks marks[5]; // Marks for 5 subjects
} StudentData;

// Function to calculate grade based on marks
void calculateGrade(SubjectMarks marks[]) 
{
    float avg, sum = 0;
    for(int i = 0; i < 5 ; i++) 
    {
        sum += (marks[i].isa1 + marks[i].isa2 + marks[i].esa) / 2; // (ISA1 + ISA2 + ESA) / 2
        sum += marks[i].assignment; // Adding assignment marks
    }
    avg = sum / 25; // Total marks are 25 (5 subjects * 5 exams/assignments)
    if(avg >= 90)  printf("S grade\n");
    else if(avg >= 80)  printf("A grade\n");
    else if(avg >= 70)  printf("B grade\n");
    else if(avg >= 60)  printf("C grade\n");
    else if(avg >= 50)  printf("D grade\n");
    else printf("F grade\n");
}

int main() 
{
    StudentData students[10];

    for(int j = 0; j < 10; j++) 
    {
        printf("Enter name: ");
        scanf("%s", students[j].name);
        printf("Enter SRN: ");
        scanf("%s", students[j].srn);
        printf("Enter the cycle (P/C): ");
        scanf("%s", students[j].sem);

        if(strcmp(students[j].sem, "P") == 0 || strcmp(students[j].sem, "p") == 0) 
        {
            char subjects[5][20] = {"MATH", "MECHANICAL", "PHYSICS", "ELECTRICAL", "COMPUTER SCIENCE"};

            printf("Enter marks for each subject in ISA1 (out of 40):\n");
            for (int i = 0; i < 5; i++) 
            {
                printf("%s: ", subjects[i]);
                scanf("%d", &students[j].marks[i].isa1);
            }
            printf("Enter marks for each subject in ISA2 (out of 40):\n");
            for (int i = 0; i < 5; i++) 
            {
                printf("%s: ", subjects[i]);
                scanf("%d", &students[j].marks[i].isa2);
            }
            printf("Enter marks for each subject in ESA (out of 100):\n");
            for (int i = 0; i < 5; i++) 
            {
                printf("%s: ", subjects[i]);
                scanf("%d", &students[j].marks[i].esa);
            }
            printf("Enter assignment marks (out of 10):\n");
            for (int i = 0; i < 5; i++) 
            {
                printf("%s: ", subjects[i]);
                scanf("%d", &students[j].marks[i].assignment);
            }
            printf("NAME: %s\n", students[j].name);
            printf("SRN: %s\n", students[j].srn);
            printf("CYCLE: %s\n", students[j].sem);
            printf("GRADE: ");
            calculateGrade(students[j].marks);
        } 
        else if (strcmp(students[j].sem, "C") == 0 || strcmp(students[j].sem, "c") == 0) 
        {
            char subjects[5][20] = {"MATH", "MECHANICS", "CHEMISTRY", "ELECTRONICS", "COMPUTER SCIENCE"};

            printf("Enter marks for each subject in ISA1 (out of 40):\n");
            for (int i = 0; i < 5; i++) 
            {
                printf("%s: ", subjects[i]);
                scanf("%d", &students[j].marks[i].isa1);
            }
            printf("Enter marks for each subject in ISA2 (out of 40):\n");
            for (int i = 0; i < 5; i++) 
            {
                printf("%s: ", subjects[i]);
                scanf("%d", &students[j].marks[i].isa2);
            }
            printf("Enter marks for each subject in ESA (out of 100):\n");
            for (int i = 0; i < 5; i++) 
            {
                printf("%s: ", subjects[i]);
                scanf("%d", &students[j].marks[i].esa);
            }
            printf("Enter assignment marks (out of 10):\n");
            for (int i = 0; i < 5; i++) 
            {
                printf("%s: ", subjects[i]);
                scanf("%d", &students[j].marks[i].assignment);
            }
            printf("NAME: %s\n", students[j].name);
            printf("SRN: %s\n", students[j].srn);
            printf("CYCLE: %s\n", students[j].sem);
            printf("GRADE: ");
            calculateGrade(students[j].marks);
        } 
        else 
        {
            printf("Invalid input\n");
        }
    }
    return 0;
}
