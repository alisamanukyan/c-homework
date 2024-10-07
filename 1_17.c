#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 200

int main() {
    char line[MAX_LINE_LENGTH];

    printf("Enter the lines (Press Ctrl+D to end input):\n");

    while (fgets(line, sizeof(line), stdin)) {
        if (strlen(line) > 80) {
            printf("%s", line); 
        }
    }

    return 0;
}
