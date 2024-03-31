#include <stdio.h>
#include <string.h>

void calculateGrade(int marks[])     //grading function
{
    float avg,sum = 0;
    for(int i = 0; i < 15 ; i++)    //doing (ISA1+ISA2+ESA)/2
    {
        sum += (marks[i]/2);
    }
    for(int i=15;i<20;i++)         //adding assigment marks
    { 
        sum+=(marks[i]);
    }
    avg = (float)sum/5;           
    if(avg >= 90)  printf("S grade");
    else if(avg >= 80)  printf("A grade\n");
    else if(avg >= 70)  printf("B grade\n");
    else if(avg >= 60)  printf("C grade\n");
    else if(avg >= 50)  printf("D grade\n");
    else printf("F grade\n");
}

int main() 
{
    char name[100], srn[10], sem[3]; 
for(int j=0;j<10;j++)                  //for 10 students
{
    printf("Enter name: \n");
    scanf("%s", name);
    printf("Enter SRN: \n");
    scanf("%s", srn);
    printf("Enter the cycle (P/C): \n");
    scanf("%s", sem);

    if(strcmp(sem,"P") == 0)          //phy cycle
    {
        int marks_ESA[20];
        char subjects[5][20] = {"MATH", "MECHANICAL", "PHYSICS", "ELECTRICAL", "COMPUTER SCIENCE"};

        printf("Enter marks for each subject in ISA1 (out of 40) :\n");
        for (int i = 0; i < 5; i++) 
        {
            printf("%s: ", subjects[i]);
            scanf("%d", &marks_ESA[i]);
        }
        printf("Enter marks for each subject in ISA2 (out of 40) :\n");
        for (int i = 0; i < 5; i++) 
        {
            printf("%s: ", subjects[i]);
            scanf("%d", &marks_ESA[i+5]);
        }
        printf("Enter marks for each subject in ESA (out of 100) :\n");
        for (int i = 0; i < 5; i++) 
        {
            printf("%s: ", subjects[i]);
            scanf("%d", &marks_ESA[i+10]);
        }
        printf("Enter assignment marks (out of 10): \n");
        {
            for (int i = 0; i < 5; i++)
            {
                printf("%s: ", subjects[i]);
                scanf("%d", &marks_ESA[i+15]);
            }
        }
        printf("NAME: %s\n",name);
        printf("SRN: %s\n",srn);
        printf("CYCLE: %s\n",sem);
        printf("GRADE: ");
        calculateGrade(marks_ESA);     //function is called here
    } 
    else if (strcmp(sem, "C") == 0)    //chem cycle
    {
        int marks_ESA[15];
        char subjects[5][20] = {"MATH", "MECHANICS", "CHEMISTRY", "ELECTRONICS", "COMPUTER SCIENCE"};

        printf("Enter marks for each subject in ISA1 (out of 40) :\n");
        for (int i = 0; i < 5; i++) 
        {
            printf("%s: ", subjects[i]);
            scanf("%d", &marks_ESA[i]);
        } 
        printf("Enter marks for each subject in ISA2 (out of 40) :\n");
        for (int i = 0; i < 5; i++) 
        {
            printf("%s: ", subjects[i]);
            scanf("%d", &marks_ESA[i+5]);
        }
        printf("Enter marks for each subject in ESA (out of 100) :\n");
        for (int i = 0; i < 5; i++) 
        {
            printf("%s: ", subjects[i]);
            scanf("%d", &marks_ESA[i+10]);
        }
        printf("Enter assignment marks (out of 10): \n");
        {
            for (int i = 0; i < 5; i++) 
            {
           printf("%s: ", subjects[i]);
            scanf("%d", &marks_ESA[i+15]);
            }
        }
        printf("NAME: %s\n",name);
        printf("SRN: %s\n",srn);
        printf("CYCLE: %s\n",sem);
        printf("GRADE: ");
        calculateGrade(marks_ESA);  //function is called here
        }
    else
    {
        printf("invalid input");
    }
    
}
    return 0;
}
