#include <math.h>
#include <stdio.h>

void generate(int n);

int main() {
    int n; // Depth = n - 1
    printf("Enter a number: ");
    int r = scanf("%d", &n);
    if (!r) {
        printf("Incorrect input\n");
        return 1;
    }
    if (n < 1 || n > 6) {
        printf("Incorrect input data\n");
        return 2;
    }
    generate(n);

    return 0;
}

void generate(int n) {
    int i = 0;
    char cantor[7][300];
    // Generate first line
    for (int x = 0; x < pow(3, n - 1); x++) {
        cantor[i][x] = '_';
    }
    i++;
    // printf("Cantor: %c\n Len: %d\n", cantor[0][0], (int)pow(3, n - 1));
    while (i + 1 < n) {
        for (int x = 0; x < pow(3, n - 1); x++) {
            // printf(" %d %d %d |", (int)(x/pow(3, n - 1 - i)), (int)pow(3, n - 1 - i), (int)(x/pow(3, n - 1 - i))%(int)pow(3, n - 1 - i));
            if ((int)(x/pow(3, n - 1 - i))%(int)pow(3, n - 1 - i) == 1 && cantor[i - 1][x] == '_') {
                cantor[i][x] = ' ';
            } else {
                cantor[i][x] = cantor[i - 1][x];
            }
        }
        // printf("\n");
        i++;
    }
    int flip = 0;
    for (int x = 0; x < pow(3, n - 1); x++) {
        if (flip == 1) {
            cantor[i][x] = ' ';
            flip = 0;
        } else {
            cantor[i][x] = cantor[i - 1][x];
            flip = 1;
        }
    }
    i++;
    for (int x = 1; x < i; x++) {
        for (int y = 0; y < pow(3, n - 1)/9; y++) {
            cantor[x][(int)pow(3, n - 1)/3 - y - 1] = cantor[x][y];
        }
        for (int y = 0; y < pow(3, n - 1)/3; y++) {
            cantor[x][(int)pow(3, n - 1) - y - 1] = cantor[x][y];
        }
    }
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < pow(3, n - 1); y++) {
            printf("%c", cantor[x][y]);
        }
        printf("\n");
    }
}