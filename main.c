#include <stdio.h>

int t[2000];
int l[2000];

int main() {
    int a, b;
    printf("Podal liczbe: ");
    scanf("%d", &a);
    printf("Podal liczbe: ");
    scanf("%d", &b);
    int _i = 0;
    while (b > 0) {
        l[_i] = b % 10;
        b /= 10;
        t[_i] = a * l[_i];
        _i++;
    }
    int indent = _i - 1;
    for (int i = 0; i < _i; i++) {
        printf("%d\n", t[i]);
    }

    return 0;
}