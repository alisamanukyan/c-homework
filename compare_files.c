#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

void compare_files(const char *file1, const char *file2) {
    FILE *fp1 = fopen(file1, "r");
    FILE *fp2 = fopen(file2, "r");

    char line1[MAX_LINE_LENGTH], line2[MAX_LINE_LENGTH];
    int line_number = 0;

    while (fgets(line1, MAX_LINE_LENGTH, fp1) != NULL && 
           fgets(line2, MAX_LINE_LENGTH, fp2) != NULL) {
        line_number++;
        if (strcmp(line1, line2) != 0) {
            printf("Files differ at line %d:\n", line_number);
            printf("File 1: %s", line1);
            printf("File 2: %s", line2);
            fclose(fp1);
            fclose(fp2);
            return;
        }
    }

    if (fgets(line1, MAX_LINE_LENGTH, fp1) != NULL) {
        printf("File 1 has extra lines starting at line %d:\n%s", line_number + 1, line1);
    } else if (fgets(line2, MAX_LINE_LENGTH, fp2) != NULL) {
        printf("File 2 has extra lines starting at line %d:\n%s", line_number + 1, line2);
    } else {
        printf("Files are identical.\n");
    }

    fclose(fp1);
    fclose(fp2);
}

int main(int argc, char *argv[]) {
    compare_files(argv[1], argv[2]);
    return 0;
}
