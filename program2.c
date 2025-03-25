//Wap to check if the entered string is a valid integer constant or not (rules to be given).

#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function to check if a string is a valid integer constant
int isValidIntegerConstant(const char *str) {
    int i = 0, len = strlen(str);

    if (len == 0) return 0;  // Empty string is not a valid integer

    // Check for optional sign at the beginning
    if (str[i] == '+' || str[i] == '-') {
        i++;
        if (i == len) return 0;  // A single '+' or '-' is not a valid integer
    }

    // Check for hexadecimal constant (starts with "0x" or "0X")
    if (i + 1 < len && str[i] == '0' && (str[i + 1] == 'x' || str[i + 1] == 'X')) {
        i += 2;  // Skip '0x' or '0X'
        if (i == len) return 0;  // "0x" alone is invalid
        // Check if the remaining characters are valid hexadecimal digits
        while (i < len) {
            if (!isdigit(str[i]) && !(str[i] >= 'A' && str[i] <= 'F') && !(str[i] >= 'a' && str[i] <= 'f'))
                return 0;
            i++;
        }
        return 1; // Valid hexadecimal integer
    }

    // Check for octal (leading 0 but not "0x")
    if (i < len && str[i] == '0') {
        i++; // Skip leading zero
        while (i < len) {
            if (str[i] < '0' || str[i] > '7') return 0; // Must be within 0-7
            i++;
        }
        return 1; // Valid octal integer
    }

    // Otherwise, check for a normal decimal integer
    while (i < len) {
        if (!isdigit(str[i])) return 0; // If non-digit character found, return false
        i++;
    }

    return 1; // Valid integer constant
}

int main() {
    char input[50];  // Buffer to store user input

    printf("Enter a string: ");
    scanf("%s", input);

    if (isValidIntegerConstant(input)) {
        printf("\"%s\" is a valid integer constant.\n", input);
    } else {
        printf("\"%s\" is NOT a valid integer constant.\n", input);
    }

    return 0;
}
