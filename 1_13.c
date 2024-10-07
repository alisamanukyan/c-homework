#include <stdio.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 25  

int main() {
    int c, length = 0;
    int word_lengths[MAX_WORD_LENGTH + 1] = {0};  

    printf("Enter some text (Press Ctrl+D to end input):\n");

    while ((c = getchar()) != EOF) {
        if (isalpha(c)) {
            length++;  
        } else if (length > 0) {
            if (length <= MAX_WORD_LENGTH) {
                word_lengths[length]++;
            } else {
                word_lengths[MAX_WORD_LENGTH]++;  
            }
            length = 0;
        }
    }

    printf("\nHistogram of word lengths:\n");
    for (int i = 1; i <= MAX_WORD_LENGTH; i++) {
        if (word_lengths[i] > 0) {
            printf("%2d: ", i);
            for (int j = 0; j < word_lengths[i]; j++) {
                printf("*");
            }
            printf("\n");
        }
    }

    return 0;
}