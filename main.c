#include <stdio.h>
#include <string.h>
#define MAX_LEN 200

int add(const char* number1, const char* number2, char* result, int size);
int validate(const char * number);

void find_new_line(char *l);

int main() {
    char n1[MAX_LEN + 1], n2[MAX_LEN + 1], _add[2 * MAX_LEN];
    printf("Podaj pierwsza liczbe: ");
    if (fgets(n1, MAX_LEN, stdin) == NULL) {
        return 1;
    }
    find_new_line(n1);
    printf("Podaj druga liczbe: ");
    if (fgets(n2, MAX_LEN, stdin) == NULL) {
        return 1;
    }
    find_new_line(n2);

    int _res = add(n1, n2, _add, MAX_LEN);
    if (_res == 1) {}
    printf("Add: %s\n", _add);

    return 0;
}

int add(const char* number1, const char* number2, char* result, int size) {
    unsigned long long l1 = strlen(number1) - 1;
    unsigned long long l2 = strlen(number2) - 1;
    if (size <= 0) return 1;
    char sum[2 * MAX_LEN];
    int sgn1 = *number1 == '-' ? -1 : 1, sgn2 = *number2 == '-' ? -1 : 0;
    int carry = 0, i = 0;
    while (l1 > 0 && l2 > 0) {
        int _sum = sgn1*(int)*(number1 - 1 + l1--) + sgn2*(int)*(number2 - 1 + l2--) + carry;
        carry = _sum % 10;
        _sum /= 10;
        *(sum + i++) = (char)carry;
        *(sum + i++) = (char)_sum;
        l1--;l2--;
    }
    if (strlen(sum) > size) return 2;
    for (int j = 0; j < i; j++) {
        *(result + j) = *(sum + i - j);
    }
    return 0;
}

void find_new_line(char *l) {
    int new_line = 0;
    while (*l != '\0') {
        if (*l == '\n') {
            *l = '\0';
            new_line = 1;
            break;
        }
        l++;
    }
    if (!new_line) {
        int _char;
        while ((_char = getchar()) != '\n' || _char != '\0');
    }
}