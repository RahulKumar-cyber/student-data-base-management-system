#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Variable to keep track of number of students
int i = 0;

// Structure to store the student
struct sinfo
{
    char fname[50];
    char lname[50];
    int roll;
    float cgpa;
    int cid[10];
} st[55];

// Function to add a student
void add_student()
{
    printf("Add the Student's Details\n");
    printf("-------------------------\n");
    printf("Enter the first name of the student: ");
    scanf("%s", st[i].fname);
    printf("Enter the last name of the student: ");
    scanf("%s", st[i].lname);
    printf("Enter the Roll Number: ");
    scanf("%d", &st[i].roll);
    printf("Enter the CGPA obtained: ");
    scanf("%f", &st[i].cgpa);
    printf("Enter the course ID of each course (up to 5): ");
    for (int j = 0; j < 5; j++)
    {
        scanf("%d", &st[i].cid[j]);
    }
    i = i + 1;
}

// Function to find a student by roll number
void find_rl()
{
    int x;
    printf("Enter the Roll Number of the student: ");
    scanf("%d", &x);
    int found = 0;
    for (int j = 0; j < i; j++)
    {
        if (x == st[j].roll)
        {
            printf("The Student's Details are:\n");
            printf("First Name: %s\n", st[j].fname);
            printf("Last Name: %s\n", st[j].lname);
            printf("Roll Number: %d\n", st[j].roll);
            printf("CGPA: %f\n", st[j].cgpa);
            printf("Course IDs: ");
            for (int k = 0; k < 5; k++)
            {
                printf("%d ", st[j].cid[k]);
            }
            printf("\n");
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("No student found with Roll Number %d\n", x);
    }
}

// Function to find a student by first name
void find_fn()
{
    char a[50];
    printf("Enter the First Name of the student: ");
    scanf("%s", a);
    int found = 0;
    for (int j = 0; j < i; j++)
    {
        if (!strcmp(st[j].fname, a))
        {
            printf("The Student's Details are:\n");
            printf("First Name: %s\n", st[j].fname);
            printf("Last Name: %s\n", st[j].lname);
            printf("Roll Number: %d\n", st[j].roll);
            printf("CGPA: %f\n", st[j].cgpa);
            printf("Course IDs: ");
            for (int k = 0; k < 5; k++)
            {
                printf("%d ", st[j].cid[k]);
            }
            printf("\n");
            found = 1;
        }
    }
    if (!found)
    {
        printf("No student found with First Name %s\n", a);
    }
}

// Function to find students enrolled in a particular course

void find_c() {
            int id;
            printf("Enter the course ID: ");
            scanf("%d", &id);
            int found = 0;
            for (int j = 0; j < i; j++)
            {
                for (int k = 0; k < 5; k++)
                {
                    if (st[j].cid[k] == id)
                    {
                        printf("The Student's Details are:\n");
                        printf("First Name: %s\n", st[j].fname);
                        printf("Last Name: %s\n", st[j].lname);
                        printf("Roll Number: %d\n", st[j].roll);
                        printf("CGPA: %f\n", st[j].cgpa);
                        printf("Course IDs: ");
                        for (int l = 0; l < 5; l++)
                        {
                            printf("%d ", st[j].cid[l]);
                        }
                        printf("\n");
                        found = 1;
                        break;
                    }
                }
            }
            if (!found)
            {
                printf("No student found enrolled in course with ID %d\n", id);
            }
}

// Main function
int main() {
            int choice;
            do
            {
                printf("\nStudent Management System\n");
                printf("-------------------------\n");
                printf("1. Add a student\n");
                printf("2. Find a student by Roll Number\n");
                printf("3. Find students by First Name\n");
                printf("4. Find students enrolled in a particular course\n");
                printf("5. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);
                switch (choice)
                {
                case 1:
                    add_student();
                    break;
                case 2:
                    find_rl();
                    break;
                case 3:
                    find_fn();
                    break;
                case 4:
                    find_c();
                    break;
                case 5:
                    exit(0);
                    break;
                default:
                    printf("Invalid choice\n");
                }
            } while (choice != 5);
            return 0;
}