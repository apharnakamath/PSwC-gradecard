#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    SubjectMarks marks[3]; // Marks for 3 subjects
} StudentData;

// Function to calculate grade based on marks
void calculateGrade(SubjectMarks marks[]) 
{
    float avg, sum = 0;
    for(int i = 0; i < 3 ; i++) 
    {
        sum += (marks[i].isa1 + marks[i].isa2 + marks[i].esa) / 2.0; // (ISA1 + ISA2 + ESA) / 2
        sum += marks[i].assignment; // Adding assignment marks
    }
    avg = sum / 3;
    if(avg >= 90)  printf("S grade\n");
    else if(avg >= 80)  printf("A grade\n");
    else if(avg >= 70)  printf("B grade\n");
    else if(avg >= 60)  printf("C grade\n");
    else if(avg >= 50)  printf("D grade\n");
    else printf("F grade\n");
}

// Function to load student data from a CSV file
int load_students(const char *filename, StudentData students[], int max_students) 
{
    FILE *file = fopen(filename, "r");
    if (!file) 
    {
        perror("Could not open file");
        return -1;
    }

    char line[1024];
    int count = 0;

    if (fgets(line, sizeof(line), file)) 
    {
        while (fgets(line, sizeof(line), file) && count < max_students) 
        {
            char *token = strtok(line, ",");
            strcpy(students[count].name, token);

            token = strtok(NULL, ",");
            strcpy(students[count].srn, token);

            token = strtok(NULL, ",");
            strcpy(students[count].sem, token);

            for (int i = 0; i < 3; i++) 
            {
                token = strtok(NULL, ",");
                students[count].marks[i].isa1 = atoi(token);

                token = strtok(NULL, ",");
                students[count].marks[i].isa2 = atoi(token);

                token = strtok(NULL, ",");
                students[count].marks[i].esa = atoi(token);

                token = strtok(NULL, ",");
                students[count].marks[i].assignment = atoi(token);
            }
            count++;
        }
    }

    fclose(file);
    return count;
}

int main() 
{
    StudentData students[10];
    int student_count = load_students("Students.csv", students, 10);

    if (student_count < 0) 
    {
        return 1; // Error occurred while reading the file
    }

    for(int j = 0; j < student_count; j++) 
    {
        printf("NAME: %s\n", students[j].name);
        printf("SRN: %s\n", students[j].srn);
        printf("CYCLE: %s\n", students[j].sem);
        printf("GRADE: ");
        calculateGrade(students[j].marks);
        printf("\n");
    }

    return 0;
}
