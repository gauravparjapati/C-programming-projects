#include <stdio.h>
struct Student
{
    char name[50];
    int roll;
    float marks;
};
int main ()
{
    struct Student s;
    int choice;
    do {
    printf("=========================================\n");
    printf("     STUDENT MANAGEMENT SYSTEM\n");
    printf("=========================================\n\n");

    printf("Developed by: Gaurav Kumar Parjapati\n\n");

    printf("1. Add Student\n");
    printf("2. View Student\n");
    printf("3. Search Student\n");
    printf("4. Update Student\n");
    printf("5. Delete Student\n");
    printf("6. Exit\n");
    printf("\nEnter your choice:");
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("\nEnter student name:");
        scanf("%49s", s.name);
        printf("Enter roll number: ");
        scanf("%d", &s.roll);
        printf("Enter marks: ");
        scanf("%f", &s.marks);
        FILE *file = fopen("students.txt","a");
        if (file == NULL)
        {
            printf("File could not be opened!\n");
        }
        else
        {
        fprintf(file,"%s %d %.2f\n",s.name,s.roll,s.marks);
        fclose(file);
        printf("\nStudent Added Successfully!\n");
        }
    }
    else if (choice == 2)
    {
        FILE *file = fopen("students.txt","r");
        if(file == NULL)
        {
            printf("\nNo student records found!\n");
        }
        else{
            int found = 0;
        printf("\n-----Student Details -----\n");
        while(fscanf(file,"%49s %d %f",s.name, &s.roll,&s.marks) == 3)
        {
        printf("Name: %s\n",s.name);
        printf("Roll Number: %d\n",s.roll);
        printf("Marks: %.2f\n", s.marks);
        printf("---------------------------\n");
        found = 1;
        }
        fclose(file);
        if (found == 0)
        {
            printf("No student records found!\n");
        }
        }
    }
    else if (choice == 3)
    {
        int searchRoll;
        int found = 0;
        printf("\nEnter roll number to search: ");
        scanf("%d", &searchRoll);
        FILE *file = fopen("students.txt","r");
        if(file == NULL)
        {
            printf("\nNo student records found!\n");
        }
        else
        {
        while(fscanf(file,"%49s %d %f", s.name, &s.roll, &s.marks) == 3)
        {
            if(s.roll == searchRoll)
            {
                printf("\n----- Student Found -----\n");
                printf("Name: %s\n",s.name);
                printf("Roll Number: %d\n", s.roll);
                printf("Marks: %.2f\n", s.marks);
                found = 1;
                break;
            }
        }
        fclose(file);
        if (found == 0)
        {
            printf("\nStudent not found!\n");
        }
        }
    }
    else if (choice == 4)
    {
        int updateRoll;
        int found = 0;
        printf("\nEnter roll number to update: ");
        scanf("%d", &updateRoll);
        FILE *file = fopen("students.txt","r");
        FILE *temp = fopen("temp.txt","w");
        if (file == NULL || temp == NULL)
        {
            printf("\nFile could not be opened!\n");
            if(file != NULL)
            fclose(file);
            if(temp !=NULL)
            fclose(temp);
        }
        else
        {
        while (fscanf(file,"%49s %d %f", s.name, &s.roll, &s.marks)==3)
        {
            if(s.roll == updateRoll)
            {
                printf("\nEnter new name: ");
                scanf("%49s", s.name);
                printf("Enter new marks:");
                scanf("%f",&s.marks);
                found = 1;
            }
            fprintf(temp, "%s %d %.2f\n",s.name, s.roll,s.marks);
        }
        fclose(file);
        fclose(temp);
        remove("students.txt");
        rename("temp.txt","students.txt");
        if(found == 1)
        {
            printf("\nStudent Updated Successfully!\n");
        }
        else
        {
            printf("\nStudent not found!\n");
        }
        }
    }
    else if (choice == 5)
    {
        int deleteRoll;
        int found = 0;
        printf("\nEnter roll number to delete: ");
        scanf("%d", &deleteRoll);
        FILE *file = fopen("students.txt","r");
        FILE *temp = fopen("temp.txt","w");
        if(file == NULL || temp == NULL)
        {
            printf("\nFile could not be opened!\n");
            if(file !=NULL)
            fclose(file);
            if(temp != NULL)
            fclose(temp);
        }
        else
        {
        while (fscanf(file,"%49s %d %f", s.name,&s.roll,&s.marks) == 3)
        {
            if(s.roll == deleteRoll)
            {
                found == 1;
            }
            else
            {
            fprintf(temp, "%s %d %.2f\n",s.name, s.roll, s.marks);
            }
        }
        fclose(file);
        fclose(temp);
        remove("students.txt");
        rename("temp.txt","students.txt");
        if(found == 1)
        {
            printf("\nStudent Deleted Successfully!\n");
        }
        else 
        {
            printf("\nStudent Deleted Successfully!\n");
        }
        }
    }
    else if (choice == 6)
    {
        printf("\nThank you for using Student Management System!\n");
    }
    else
    {
        printf("\nInvalid choice!\n");
    }
    } while (choice != 6);
    return 0;
}