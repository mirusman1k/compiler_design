//Wap to check if the entered string is a valid keyword or nor (rules to be given).

#include <stdio.h>
#include <string.h>


const char *keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do", 
    "double", "else", "enum", "extern", "float", "for", "goto", "if", 
    "inline", "int", "long", "register", "restrict", "return", "short, 
    "signed", "sizeof", "static", "struct", "switch", "typedef", "union", 
    "unsigned", "void", "volatile", "while", "_Alignas", "_Alignof", "_Atomic", 
    "_Bool", "_Complex", "_Generic", "_Imaginary", "_Noreturn", "_Static_assert", 
    "_Thread_local"
};


int isKeyword(const char *word) {
    int total_keywords = sizeof(keywords) / sizeof(keywords[0]);

    for (int i = 0; i < total_keywords; i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return 1;  // Found a match, return true
        }
    }
    return 0;  // Not a keyword
}

int main() {
    char input[50];  // Buffer to store user input

    printf("Enter a string: ");
    scanf("%s", input);

    if (isKeyword(input)) {
        printf("\"%s\" is a valid C keyword.\n", input);
    } else {
        printf("\"%s\" is NOT a valid C keyword.\n", input);
    }

    return 0;
}
