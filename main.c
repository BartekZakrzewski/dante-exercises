#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter a number: ");
    int e = scanf("%d", &n);
    if (!e) {
        printf("Incorrect input\n");
        return 1;
    }
    if (n < 2) {
        printf("NO\n");
        return 0;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}
