#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char surname[MAX_NAME_LENGTH];
    int id;
    float grade;
} Student;

typedef struct {
    Student* students;
    int size;
    int capacity;
} StudentList;

void initStudentList(StudentList* list, int initialCapacity) {
    list->students = (Student*)malloc(initialCapacity * sizeof(Student));
    if (!list->students) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    list->size = 0;
    list->capacity = initialCapacity;
}

void freeStudentList(StudentList* list) {
    free(list->students);
    list->students = NULL;
    list->size = 0;
    list->capacity = 0;
}

void addStudent(StudentList* list) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->students = (Student*)realloc(list->students, list->capacity * sizeof(Student));
        if (!list->students) {
            printf("Memory allocation failed!\n");
            exit(1);
        }
    }

    Student* newStudent = &list->students[list->size];

    printf("Enter student name: ");
    scanf("%s", newStudent->name);
    printf("Enter student surname: ");
    scanf("%s", newStudent->surname);
    printf("Enter student ID: ");
    scanf("%d", &newStudent->id);
    printf("Enter student grade: ");
    scanf("%f", &newStudent->grade);

    list->size++;
}

void removeStudent(StudentList* list, int id) {
    int index = -1;
    for (int i = 0; i < list->size; i++) {
        if (list->students[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Student with ID %d not found.\n", id);
        return;
    }

    for (int i = index; i < list->size - 1; i++) {
        list->students[i] = list->students[i + 1];
    }

    list->size--;
    printf("Student with ID %d removed.\n", id);
}

Student* searchStudentById(StudentList* list, int id) {
    for (int i = 0; i < list->size; i++) {
        if (list->students[i].id == id) {
            return &list->students[i];
        }
    }
    return NULL;
}

void displayAllStudents(StudentList* list) {
    for (int i = 0; i < list->size; i++) {
        printf("ID: %d, Name: %s %s, Grade: %.2f\n", list->students[i].id, list->students[i].name, list->students[i].surname, list->students[i].grade);
    }
}

float calculateAverageGrade(StudentList* list) {
    float totalGrade = 0;
    for (int i = 0; i < list->size; i++) {
        totalGrade += list->students[i].grade;
    }

    return totalGrade / list->size;
}

void saveToFile(StudentList* list, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Unable to open file for writing.\n");
        return;
    }

    for (int i = 0; i < list->size; i++) {
        fprintf(file, "%s,%s,%d,%.2f\n", list->students[i].name, list->students[i].surname, list->students[i].id, list->students[i].grade);
    }

    fclose(file);
    printf("Student details saved to %s.\n", filename);
}

void loadFromFile(StudentList* list, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Unable to open file for reading.\n");
        return;
    }

    while (fscanf(file, "%99[^,],%99[^,],%d,%f\n", list->students[list->size].name, list->students[list->size].surname, &list->students[list->size].id, &list->students[list->size].grade) == 4) {
        list->size++;
        if (list->size == list->capacity) {
            list->capacity *= 2;
            list->students = (Student*)realloc(list->students, list->capacity * sizeof(Student));
            if (!list->students) {
                printf("Memory allocation failed!\n");
                exit(1);
            }
        }
    }

    fclose(file);
    printf("Student details loaded from %s.\n", filename);
}

void menu() {
    printf("\nMenu:\n");
    printf("1. Add a new student\n");
    printf("2. Remove a student by ID\n");
    printf("3. Search a student by ID\n");
    printf("4. Display all students\n");
    printf("5. Display average grade\n");
    printf("6. Save to file\n");
    printf("7. Load from file\n");
    printf("8. Exit\n");
}

int main() {
    StudentList list;
    initStudentList(&list, 2); 

    int choice, id;
    float avgGrade;
    Student* student;

    do {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(&list);
                break;
            case 2:
                printf("Enter student ID to remove: ");
                scanf("%d", &id);
                removeStudent(&list, id);
                break;
            case 3:
                printf("Enter student ID to search: ");
                scanf("%d", &id);
                student = searchStudentById(&list, id);
                if (student) {
                    printf("Student found: ID: %d, Name: %s %s, Grade: %.2f\n", student->id, student->name, student->surname, student->grade);
                } else {
                    printf("Student with ID %d not found.\n", id);
                }
                break;
            case 4:
                displayAllStudents(&list);
                break;
            case 5:
                avgGrade = calculateAverageGrade(&list);
                if (avgGrade > 0) {
                    printf("Average grade: %.2f\n", avgGrade);
                }
                break;
            case 6:
                saveToFile(&list, "group_details.csv");
                break;
            case 7:
                loadFromFile(&list, "group_details.csv");
                break;
            case 8:
                freeStudentList(&list);
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 8);

    return 0;
}
