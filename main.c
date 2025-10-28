#include <stdio.h>

int matrix[15][15];
int count[31];

int main() {
    printf("Podaj liczby:\n");
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            int n = scanf("%d", &matrix[i][j]);
            if (!n) {
                printf("incorrect input\n");
                return 1;
            }
            if (matrix[i][j] < 0 || matrix[i][j] >= 30) {
                printf("value out of range\n");
                return 2;
            }
            count[matrix[i][j]]++;
        }
    }

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            printf("%d ", count[matrix[i][j]]);
        }
        printf("\n");
    }

    return 0;
}