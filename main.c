#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validate_recursion(const char *expr, const char *prev);
int validate_expression(const char *expr);

float get_nums(const char *expr);
int is_operator(char expr);
int calculate(const char* expr, float *result);

int main() {
    char expr[201];
    float result = 0;
    printf("Podaj wyrazenie:\n");
    if (fgets(expr, 200, stdin) == NULL) {
        return 1;
    }
    int _len = strlen(expr);
    if (*(expr + _len - 1) == '\n') *(expr + _len - 1) = '\0';
    if (validate_expression(expr) <= 0) {
        printf("Incorrect input\n");
        return 1;
    }
    int _exit = calculate(expr, &result);
    if (_exit <= 0) {
        printf("Incorrect input\n");
        return 1;
    }
    printf("%.2f\n", result);

    return 0;
}

int calculate(const char* expr, float *result) {
    if (expr == NULL || result == NULL) return 0;
    if (*expr == '\0') return 1;
    if (!is_operator(*expr) && *expr >= '0' && *expr <= '9') {
        *result = get_nums(expr);
        int n = strspn(expr, "0123456789");
        return calculate(expr + n, result);
    }
    if (is_operator(*expr) && !*(expr - 1)) {
        return 0;
    }
    char op = *expr;
    if (is_operator(*(expr - 1)) || *(expr + 1) == '\0' || *(expr + 1) == '\n' || !*(expr + 1)) {
        return 0;
    }
    expr++;
    float nums = get_nums(expr);
    int n = strspn(expr, "0123456789");
    if (op == '+') {
        *result += nums;
        return calculate(expr + n, result);
    }
    if (op == '-') {
        *result -= nums;
        return calculate(expr + n, result);
    }
    if (op == '*') {
        *result *= nums;
        return calculate(expr + n, result);
    }
    if (op == '/') {
        if (nums == 0) {
            return 0;
        }
        *result /= nums;
        return calculate(expr + n, result);
    }
    return 0;
}

float get_nums(const char *expr) {
    char* _expr = "01234567890";
    size_t len = strspn(expr, _expr);
    char *nums = (char *)malloc(len + 1);
    if (nums == NULL) {
        return 0.0f;
    }
    strncpy(nums, expr, len);
    *(nums + len) = '\0';
    float res = atof(nums);
    free(nums);
    return res;
}

int is_operator(char expr) {
    return expr == '+' || expr == '-' || expr == '*' || expr == '/';
}

int validate_expression(const char *expr) {
    return validate_recursion(expr, NULL);
}

int validate_recursion(const char *expr, const char *prev) {
    if (expr == NULL) return -1;
    if (*expr == '\0') return 1;
    if (strlen(expr) > 200) return 0;
    if (
        *expr != '+'
        && *expr != '-'
        && *expr != '/'
        && *expr != '*'
        && (*expr < '0' || *expr > '9')) {
            return 0;
        }
    if (
        (  *expr == '+'
        || *expr == '-'
        || *expr == '/'
        || *expr == '*')
        && (prev == NULL
        || *prev < '0'
        || *prev > '9'
        || *(expr + 1) == '\0')) {
            return 0;
        }
    if (*expr < '0' && *expr >'9') {
        return -1;
    }
    return validate_recursion(expr + 1, expr);
}