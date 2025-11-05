#include <stdio.h>

int main() {
    double sum = 0;
    int n = 1;
    while (n*(n + 1) <= 10000) {
        sum += (double)1/(double)(n*(n + 1)); n++;
    }
    printf("%d %.4f\n", n-1, sum);

    return 0;
}
