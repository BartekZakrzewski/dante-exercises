#include <stdio.h>

int matrix[15][15];

int main() {
    printf("Podaj liczby:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int n = scanf("%d", &matrix[i][j]);
            if (!n) {
                printf("Incorrect input\n");
                return 1;
            }
        }
    }

    return 0;
}