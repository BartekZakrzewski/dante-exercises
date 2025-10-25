// Imports
#include <stdio.h>
// Constants
#define N_BOOKS 10
#define L_BOOK 90

// Books table definition
char books[11][91];

// Helper functions' definitions
void read_table();

int main() {
    // Variables declarations

    // Init table
    read_table();

    return 0;
}

// Helper functions
void read_table() {
    printf("Please enter your books:\n");
    for (int i = 0; i < 10; i++) {
        int n = scanf("%s", books[i]);
    }
    int n = scanf("%s", books);
}