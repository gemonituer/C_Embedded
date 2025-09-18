#include <stdio.h>
#include <stdlib.h>

#define INITIAL_BUFFER_SIZE 100

int main() {
    char *str = malloc(INITIAL_BUFFER_SIZE);
    if (str == NULL) {
        perror("Memory allocation error");
        return 1;
    }

    size_t capacity = INITIAL_BUFFER_SIZE;
    size_t length = 0;
    int ch;
    int digit_count = 0;

    printf("Enter a string: ");

    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (length + 1 >= capacity) {
            capacity *= 2;
            char *new_str = realloc(str, capacity);
            if (new_str == NULL) {
                free(str);
                perror("Memory reallocation error");
                return 1;
            }
            str = new_str;
        }

        str[length++] = (char)ch;

        if (ch >= '0' && ch <= '9') {
            digit_count++;
        }
    }

    str[length] = '\0';

    printf("Number of digits in the string: %d\n", digit_count);

    free(str);
	
    return 0;
}
