#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[30];
    char major[30];
} student;

int main(int argc, char *argv[]) {

    student students[] = {
        {108, "Kamol", "Physics"},
        {103, "Madina", "Economics"},
        {105, "Zebo", "Computer Science"},
        {101, "Amina", "Computer Science"},
        {107, "Nilufar", "Biology"},
        {102, "Farid", "Mathematics"},
        {106, "Rustam", "Design"},
        {104, "Daler", "Engineering"}
    };

    if (argc != 2) {
        printf("Usage: ./lookUp id\n");
        return 1;
    }

    int id = atoi(argv[1]);
    int count = sizeof(students) / sizeof(students[0]);

    for (int i = 0; i < count - 1; i++) {
        int smallest = i;
        for (int j = i + 1; j < count; j++) {
            if (students[j].id < students[smallest].id) {
                smallest = j;
            }
        }
        if (smallest != i) {
            student temp = students[i];
            students[i] = students[smallest];
            students[smallest] = temp;
        }
    }

    printf("Sorted directory:\n");
    for (int i = 0; i < count; i++) {
        printf("  %d  %-10s %s\n", students[i].id, students[i].name, students[i].major);
    }
    printf("\n");

    int low = 0, high = count - 1;
    int found = -1;
    int comparisons = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        comparisons++;
        if (students[mid].id == id) {
            found = mid;
            break;
        } else if (students[mid].id < id) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (found != -1) {
        printf("Found: %d  %s  %s\n", students[found].id,
               students[found].name, students[found].major);
    } else {
        printf("ID %d not found.\n", id);
    }
    printf("Comparisons: %d\n", comparisons);

    return 0;
}