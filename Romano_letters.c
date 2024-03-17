#include <stdio.h>
#include <string.h>
#include <ctype.h>


// main function for transform the roman number into a decimal 
int romanToDecimal(char *roman) {
    int decimal = 0;
    int length = strlen(roman);

    // Switch function 
    for (int i = 0; i < length; i++) {
        char c = toupper(roman[i]);
        switch (c) {
            case 'I':
                decimal += 1;
                break;
            case 'V':
                decimal += 5;
                break;
            case 'X':
                decimal += 10;
                break;
            case 'L':
                decimal += 50;
                break;
            case 'C':
                decimal += 100;
                break;
            case 'D':
                decimal += 500;
                break;
            case 'M':
                decimal += 1000;
                break;
            default:
                return -1; // Retorn -1 if was fonded some letter its no allowed 
        }
    }

    // Check if the romanic number its correct.
    for (int i = 0; i < length; i++) {
        char c = toupper(roman[i]);
        if (c == 'I' || c == 'X' || c == 'C' || c == 'M') {
            if (i < length - 1) {
                char next_c = toupper(roman[i + 1]);
                if ((c == 'I' && (next_c == 'V' || next_c == 'X')) ||
                    (c == 'X' && (next_c == 'L' || next_c == 'C')) ||
                    (c == 'C' && (next_c == 'D' || next_c == 'M'))) {
                    decimal -= 2 * c; // Subtracts the value of the letter twice if the rule is not followed
                }
            }
        }
    }

    return decimal;
}

// Function for the user 
int main() {
    char roman[20];

    printf("Insert a Roman numeral: ");
    scanf("%s", roman);

    int decimal = romanToDecimal(roman);

    if (decimal != -1) {
        printf("The Roman numeral %s is %d in decimal notation.\n", roman, decimal);
    } else {
        printf("Error: The Roman numeral entered contains disallowed letters.\n");
    }

    return 0;
