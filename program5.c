//Wap to count the number of lines in a given program

#include <stdio.h>

int main() {
    char filename[100];  // To store the file name
    FILE *file;          // File pointer
    char line[500];      // Buffer to store each line
    int lineCount = 0;   // Line counter

    // Get the file name from the user
    printf("Enter the file name: ");
    scanf("%s", filename);

    // Open the file in read mode
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return 1; // Exit with an error
    }

    // Read the file line by line
    while (fgets(line, sizeof(line), file) != NULL) {
        lineCount++; // Increment line count for each line read
    }

    // Close the file
    fclose(file);

    // Display the total number of lines
    printf("Total number of lines: %d\n", lineCount);

    return 0;
}
