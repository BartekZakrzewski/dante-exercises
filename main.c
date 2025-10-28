#include <stdio.h>

int matrix[10][10];
int hor[10][10];
int ver[10][10];

int max(int a, int b);

int main() {
    int _max = -(int)1e9, count = 0;
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

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 8; j++) {
            hor[i][j] = matrix[i][j] + matrix[i][j + 1] + matrix[i][j + 2];
            ver[j][i] = matrix[j][i] + matrix[j + 1][i] + matrix[j + 2][i];
            _max = max(_max, max(hor[i][j], ver[j][i]));
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 8; j++) {
            count += (ver[j][i] == _max) + (hor[i][j] == _max);
        }
    }

    printf("%d\n%d\n", _max, count);

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 8; j++) {
            if (hor[i][j] == _max) {
                printf("2 %d %d\n", i, j);
            }
            if (ver[j][i] == _max) {
                printf("1 %d %d\n", j, i);
            }
        }
    }

    return 0;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}