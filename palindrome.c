// 
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

// 
int isPalindrome(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        if (tolower(str[i]) != tolower(str[length - i - 1])) {
            return 0; // Not a palindrome
        }
    }
    return 1; // It's a palindrome
}


//
int main() {
    FILE *file;
    char filename[MAX_LENGTH];
    char word[MAX_LENGTH];

    // Ask the user for the file name
    printf("Enter the file name: ");
    scanf("%s", filename);

    // Try to open the file
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return 1;
    }

    // Read words from the file and check if they are palindromes
    printf("Palindromes found in the file:\n");
    while (fscanf(file, "%s", word) != EOF) {
        if (strlen(word) >= 3 && strlen(word) <= 10 && isPalindrome(word)) {
            printf("%s\n", word);
        }
    }

    // Close the file
    fclose(file);

    return 0;
}