#include <stdio.h>
#include <string.h>

int main() {
    char input[200];  // Buffer to store user input
    const char delimiters[] = " ,.;:()[]{}\"'\n\t"; // Delimiters for tokenization

    // Get input string from user
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin); // Read input including spaces

    // Tokenizing the string
    char *token = strtok(input, delimiters);
    
    printf("Tokens:\n");
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, delimiters); // Get next token
    }

    return 0;
}
