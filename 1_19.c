#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 500

void reverse(char s[]) {
    int i, j;
    char temp;
    int len = strlen(s);

    for (i = 0, j = len - 1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

int main() {
    char line[MAX_LINE_LENGTH];

    printf("Enter the lines (Press Ctrl+D to end input):\n");

    while (fgets(line, sizeof(line), stdin)) {
        line[strcspn(line, "\n")] = '\0';

        reverse(line); 
        printf("Reversed: %s\n", line);
    }

    return 0;
}
