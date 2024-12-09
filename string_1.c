#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
    char str1[MAX_LENGTH];
    char str2[MAX_LENGTH];
    char concatenated[MAX_LENGTH * 2];
    char copied[MAX_LENGTH];

    printf("Enter the first string (max %d characters): ", MAX_LENGTH - 1);
    fgets(str1, MAX_LENGTH, stdin);
    str1[strcspn(str1, "\n")] = '\0';

    printf("Enter the second string (max %d characters): ", MAX_LENGTH - 1);
    fgets(str2, MAX_LENGTH, stdin);
    str2[strcspn(str2, "\n")] = '\0'; 

    strcpy(concatenated, str1);
    strcat(concatenated, str2);
    printf("\nConcatenated string: %s\n", concatenated);

    if (strcmp(str1, str2) == 0) {
        printf("The strings are the same.\n");
    } else {
        printf("The strings are different.\n");
    }

    printf("Length of the first string: %lu\n", strlen(str1));
    printf("Length of the second string: %lu\n", strlen(str2));

    strcpy(copied, str1);
    printf("Copied string: %s\n", copied);

    return 0;
}
