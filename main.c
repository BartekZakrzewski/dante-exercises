// Imports
#include <stdio.h>

// Constants
#define N_BOOKS 50
#define L_BOOK 90

// Books table definition
char const *books[N_BOOKS + 1];
char _books[N_BOOKS + 1][L_BOOK + 1];

// Helper functions' prototypes
int read_table();
void print_books(int n_books);
int s_comparator(char const*s1, char const*s2);

// Problem function's prototype
int sort(char const*ptrs[], int size);

int main() {
    // Variables declarations
    const int n_books = read_table();

    // Code
    if (n_books == -1) return 1;
    if (!n_books) {
        printf("Not enough data available\n");
        return 3;
    }
    int res = sort(books, n_books);
    if (res) return 1;
    print_books(n_books);

    return 0;
}

// Problem function
int sort(char const*ptrs[], int size) {
    if (size <= 0 || !ptrs) return 1;
    if (size < 2) return 0;

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (s_comparator(*(ptrs + j), *(ptrs + j + 1)) > 0) {
                char const *tmp = *(ptrs + j);
                *(ptrs + j) = *(ptrs + j + 1);
                *(ptrs + j + 1) = tmp;
            }
        }
    }

    return 0;
}

// Helper functions
int read_table() {
    int n_books = 0;
    printf("Please enter your books:\n");
    for (int i = 0; i < N_BOOKS; i++) {
        if (fgets(*(_books + i), L_BOOK + 1, stdin) == NULL) {
            return -1;
        }
        if (*(*(_books + i)) == '\n') {
            break;
        }
        char *l = *(_books + i);
        int new_line = 0;
        while (*l != '\0') {
            if (*l == '\n') {
                new_line = 1;
                *l = '\0';
            }
            l++;
        }
        if (!new_line) {
            int _char;
            while ((_char = getchar()) != '\n' && _char != EOF);
        }

        *(books + i) = *(_books + i);
        n_books++;
    }
    return n_books > 10 ? 10 : n_books;
}

void print_books(int n_books) {
    for (int i = 0; i < n_books; i++) {
        printf("%s\n", *(books + i));
    }
}

int s_comparator(char const*s1, char const*s2) {
    int i = 0;
    while ((*(s1 + i) != '\n' || *(s1 + i) != '\0') && (*(s2 + i) != '\n' || *(s2 + i) != '\0') && (i < L_BOOK)) {
        if (*(s1 + i) != *(s2 + i))
            return *(s1 + i) > *(s2 + i);
        i++;
    }

    return 0;
}