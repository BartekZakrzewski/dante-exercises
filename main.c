#include <stdio.h>
#define SIZE_A 10
#define SIZE_B 2

int A[SIZE_A][SIZE_A], B[SIZE_B][SIZE_B];
int check_matrix(int A[SIZE_A][SIZE_A], int B[SIZE_B][SIZE_B], int x, int y);

int main() {
    int _res[(SIZE_A - 1) * (SIZE_A - 1)][2];
    printf("Podaj liczby:\n");
    for (int i = 0; i < SIZE_A; i++) {
        for (int j = 0; j < SIZE_A; j++) {
            int n = scanf("%d", (*(A + i) + j));
            if (n != 1) {
                printf("Incorrect input\n");
                return 1;
            }
        }
    }
    printf("Podaj liczby:\n");
    for (int i = 0; i < SIZE_B; i++) {
        for (int j = 0; j < SIZE_B; j++) {
            int n = scanf("%d", (*(B + i) + j));
            if (n != 1) {
                printf("Incorrect input\n");
                return 1;
            }
        }
    }
    // printf("\nB:\n%d %d\n%d %d\n:B\n", *(*(B + 0) + 0), *(*(B + 0) + 1), *(*(B + 1) + 0), *(*(B + 1) + 1));
    int res = 0, _index = 0;
    for (int i = 0; i < SIZE_A - SIZE_B + 1; i++) {
        for (int j = 0; j < SIZE_A - SIZE_B + 1; j++) {
            // printf("\n%d %d", i, j);
            if (check_matrix(A, B, i, j)) {
                // printf(" TRUE\n");
                res++;
                _res[_index][0] = j;
                _res[_index][1] = i;
                _index++;
            }
        }
    }
    // printf("\nB:\n%d %d\n%d %d\n:B\n", *(*(B + 0) + 0), *(*(B + 0) + 1), *(*(B + 1) + 0), *(*(B + 1) + 1));

    printf("%d\n", res);
    for (int i = 0; i < _index; i++) {
        printf("%d %d\n", _res[i][0], _res[i][1]);
    }

    return 0;
}

int check_matrix(int A[SIZE_A][SIZE_A], int B[SIZE_B][SIZE_B], int x, int y) {
    // printf("\n%d %d\n%d %d\n%d %d\n", x, y, *(*(A + x) + y), *(*(A + x + 1) + y), *(*(A + x) + y + 1), *(*(A + x + 1) + y + 1));
    return (*(*(A + x) + y) == *(*(B + 0) + 0)
        && *(*(A + x + 1) + y) == *(*(B + 1) + 0)
        && *(*(A + x) + y + 1) == *(*(B + 0) + 1)
        && *(*(A + x + 1) + y + 1) == *(*(B + 1) + 1));
}