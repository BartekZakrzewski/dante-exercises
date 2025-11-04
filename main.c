#include <stdio.h>

void generate(char tab[21][21], int n, int dir);

int main() {
    char tab[10][21][21];
    int r_s[10];

    int n = 1, r, i = 0;
    while (1) {
        printf("Enter a number: ");
        n = scanf("%d", &r);
        if (r == 0) {
            break;
        }
        if (n == 0) {
            return -1;
        }

        int sign = r < 0 ? -1 : 1;
        r *= sign;
        r_s[i] = r;

        for (int x = 0; x < 2*r; x++) {
            for (int y = 0; y < 2*r; y++) {
                tab[i][x][y] = ' ';
            }
        }

        generate(*(tab + i), r, sign);

        i++;
    }
    for (int y = 0; y < i; y++) {
        for (int x = 0; x < 2*r_s[y]; x++) {
            for (int j = 0; j < 2*r_s[y]; j++) {
                printf("%c", tab[y][x][j] == 'X' || tab[y][x][j] == ' ' ? ' ' : 'X');
                // printf("%c", tab[y][x][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}

void generate(char tab[21][21], int n, int dir) {
    for (int i = 0; i < n*2; i++) {
        tab[i][i] = '-';
    }
    for (int i = n*2 - 1; i >= 0; i--) {
        tab[i][n*2 - 1 - i] = '+';
    }
    // Dir left
    /* n = 3
     *   0 1 2 3 4 5
     * 0 X     X X X
     * 1 X X   X X
     * 2 X X X X
     * 3     X X X X
     * 4   X X   X X
     * 5 X X X     X
     */
    // Top
    for (int i = n - 1; i >= 0; i--) {
        // Left
        for (int j = i; j >= 0; j--) {
            if (dir > 0) {
                tab[i][j] = '0';
                // printf("%c", tab[i][j]);
            } else {
                tab[j][i] = '0';
                // printf("%c", tab[j][i]);
            }
        }
        // printf("\n");
        // Right
        for (int j = n; j < n*2 - i; j++) {
            if (dir > 0) {
                tab[i][j] = '1';
                // printf("%c", tab[i][j]);
            } else {
                tab[j][i] = '1';
                // printf("%c", tab[j][i]);
            }
        }
        // printf("\n");
    }
    // Bottom
    for (int i = n; i < n*2; i++) {
        // Left
        for (int j = n*2 - i; j < n; j++) {
            if (dir > 0) {
                tab[i][j] = '2';
                // printf("%c", tab[i][j]);
            } else {
                tab[j][i] = '2';
                // printf("%c", tab[j][i]);
            }
        }
        // printf("\n");
        // Right
        for (int j = i; j < n*2; j++) {
            if (dir > 0) {
                tab[i][j] = '3';
                // printf("%c", tab[i][j]);
            } else {
                tab[j][i] = '3';
                // printf("%c", tab[j][i]);
            }
        }
        // printf("\n");
    }
    for (int i = 0; i < n*2; i++) {
        for (int j = 0; j < n*2; j++) {
            if (tab[i][j] != '0' && tab[i][j] != '1' && tab[i][j] != '2' && tab[i][j] != '3' && tab[i][j] != '-' && tab[i][j] != '+') {
                tab[i][j] = ' ';
            }
        }
    }
}
