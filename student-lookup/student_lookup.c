#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[30];
    char major[30];
} student;

int main(int argc, char *argv[]){

    student students[] = {
        {101, "Amina", "Computer Science"},
        {102, "Farid", "Mathematics"},
        {103, "Madina", "Economics"},
        {104, "Rustam", "Design"},
        {105, "Zebo", "Computer Science"}
    };

    if (argc != 2) {
        printf("Usage: ./lookUp id\n");
        return 1;
    }

    int id = atoi(argv[1]);
    int count = sizeof(students) / sizeof(students[0]);

    for (int i = 0; i < count; i++)
        if (students[i].id == id)
        {
            printf("found"); 
            printf("   %s ", students[i].name);
            printf("  %s  ", students[i].major);    
            return 0;
        } 
    printf("Student not found\n");
    return 1;
}                   