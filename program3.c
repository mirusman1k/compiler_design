//Wap to check if the entered string is a valid identifier or not. (rules to be given)
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// List of C keywords
const char *keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if",
    "inline", "int", "long", "register", "restrict", "return", "short",
    "signed", "sizeof", "static", "struct", "switch", "typedef", "union",
    "unsigned", "void", "volatile", "while", "_Alignas", "_Alignof", "_Atomic",
    "_Bool", "_Complex", "_Generic", "_Imaginary", "_Noreturn", "_Static_assert",
    "_Thread_local"
};

// Function to check if a string is a C keyword
int isKeyword(const char *word) {
    int total_keywords = sizeof(keywords) / sizeof(keywords[0]);
    for (int i = 0; i < total_keywords; i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return 1; // It's a keyword
        }
    }
    return 0; // Not a keyword
}

// Function to check if a string is a valid identifier
int isValidIdentifier(const char *str) {
    int len = strlen(str);

    if (len == 0) return 0;  // Empty string is not valid

    // First character must be a letter or underscore
    if (!(isalpha(str[0]) || str[0] == '_')) {
        return 0;
    }

    // Check remaining characters
    for (int i = 1; i < len; i++) {
        if (!(isalnum(str[i]) || str[i] == '_')) {
            return 0;  // Invalid character found
        }
    }

    // Check if it's a keyword
    if (isKeyword(str)) {
        return 0;  // Keywords are not valid identifiers
    }

    return 1;  // It's a valid identifier
}

int main() {
    char input[50];  // Buffer to store user input

    printf("Enter a string: ");
    scanf("%s", input);

    if (isValidIdentifier(input)) {
        printf("\"%s\" is a valid identifier.\n", input);
    } else {
        printf("\"%s\" is NOT a valid identifier.\n", input);
    }

    return 0;
}
