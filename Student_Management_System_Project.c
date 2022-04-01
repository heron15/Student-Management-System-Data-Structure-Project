#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct studentInfo
{
    char name[50];
    int id;
    char dep[10];
    double cgpa;
    struct studentInfo *next;
};

struct studentInfo *head;

void newStudent(char *name, int id, char *dep, float cgpa)
{
    struct studentInfo *student;
    student = (struct studentInfo*)malloc(sizeof(struct studentInfo));
    strcpy(student->name, name);
    student->id=id;
    strcpy(student->dep, dep);
    student->cgpa=cgpa;

    if(head==NULL)
    {
        head = student;
    }
    else
    {
        student->next=head;
        head=student;
    }
}

void deleteStudentInfo(int id)
{
    struct studentInfo *temp1=head;
    struct studentInfo *temp2=head;

    while(temp1!=NULL)
    {
        if(temp1->id==id)
        {
            printf("\n\nStudent id %d founded!!\n\n", id);
            if(temp1==temp2)
            {
                head = head->next;
                free(temp1);
            }
            else
            {
                temp2->next=temp1->next;
                free(temp1);
            }
            printf("\nStudent information delete successfully\n\n");
            return;
        }
        temp2=temp1;
        temp1=temp1->next;
    }
    printf("\n\nStudent id %d not found!!\n\n", id);
}

void sarchStudendInfo(int id)
{
    struct studentInfo *temp = head;
    
    while(temp!=NULL)
    {
        if(temp->id==id)
        {
            printf("\n\nStudent name: %s\n", temp->name);
            printf("Student ID: %d\n", temp->id);
            printf("Student Department: %s\n", temp->dep);
            printf("Student CGPA: %.2f\n", temp->cgpa);
            return;
        }
        temp = temp->next;
    
    }
    printf("\n\nStudent id %d not found\n\n", id);
}

void display(){
    struct studentInfo *temp=head;
    while(temp!=NULL)
    {
        printf("\n\nStudent name: %s\n", temp->name);
        printf("Student ID: %d\n", temp->id);
        printf("Student Department: %s\n", temp->dep);
        printf("Student CGPA: %.2f\n", temp->cgpa);
        temp = temp->next;
    }

}

void update(int id)
{
    struct studentInfo *temp=head;
    while(temp!=NULL)
    {
        if(temp->id==id)
        {
            printf("Enter name: ");
            scanf("%s", temp->name);
            printf("Enter student id: ");
            scanf("%d", &temp->id);
            printf("enter deparment: ");
            scanf("%s", temp->dep);
            printf("Enter cgpa: ");
            scanf("%lf", &temp->cgpa);
            return;
        }
        temp=temp->next;
    }
}

int main()
{
    int n;
    char name[50];
    int id;
    char dep[10];
    float cgpa;
    printf("-------------------------------------------------------------\n");
    printf("----------Welcome to Student Management System Project-------\n");
    printf("-------------------------------------------------------------\n\n");
    do
    {
        printf("\n1. create  new student list\n");
        printf("2. delete student list\n");
        printf("3. search student information\n");
        printf("4. print all student list\n");
        printf("5. Update\n");
        printf("6. Exit\n\n");

        printf("chose your option: ");
        scanf("%d", &n);

        switch(n)
        {
        case 1:
            printf("Enter student name: ");
            scanf("%s", &name);
            printf("Enter student ID: ");
            scanf("%d", &id);
            printf("Enter Student Depaertment: ");
            scanf("%s", &dep);
            printf("Enter student CGPA: ");
            scanf("%f", &cgpa);

            newStudent(name, id, dep, cgpa);
            break;

        case 2:
            printf("Enter roll number to delete: ");
            scanf("%d", &id);
            deleteStudentInfo(id);
            break;

        case 3:
            printf("Enter Student ID: ");
            scanf("%d", &id);
            sarchStudendInfo(id);
            break;

        case 4:
            display();
            break;

        case 5:
            printf("Enter student ID: ");
            scanf("%d", &id);
            update(id);
            break;

        case 6:
            printf("\nTerminating \n");
            exit(0);
            break;

        default:
            printf("Worng option select!\n");
            break;
        }
    }
    while(n!=5);


    return 0;
}
