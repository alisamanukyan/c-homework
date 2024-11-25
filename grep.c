#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void grep(const char *pattern, const char *file1) {
    FILE *file = fopen(file1, "r");

    char line[1024];
    int line_number = 0;

    while (fgets(line, 1024, file) != NULL) {
        line_number++;
        if (strstr(line, pattern) != NULL) { 
            printf("Line %d: %s", line_number, line);
        }
    }
    fclose(file);
}

int main(int argc, char *argv[]) {
    grep(argv[1], argv[2]);
    return 0;
}