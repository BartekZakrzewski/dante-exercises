#include <stdio.h>
#include <stdlib.h>

int read(char input[3][70]);
void convert(char input[3][70], int width, int *n1, char *op, int *n2);
int compare(char input[4][4]);
int calculate(int n1, char op, int n2);

char numbers[10][3][3] = {
    { // 1
        "   ",
        "  |",
        "  |"
    }, { // 2
        " _ ",
        " _|",
        "|_ "
    }, { // 3
        " _ ",
        " _|",
        " _|"
    }, { // 4
        "   ",
        "|_|",
        "  |"
    }, { // 5
        " _ ",
        "|_ ",
        " _|"
    }, { // 6
        " _ ",
        "|_ ",
        "|_|"
    }, { // 7
        " _ ",
        "  |",
        "  |"
    }, { // 8
        " _ ",
        "|_|",
        "|_|"
    }, { // 9
        " _ ",
        "|_|",
        " _|"
    }, { // 0
        " _ ",
        "| |",
        "|_|"
    },
};

int main() {
    char input[3][70];
    // Read input
    printf("Please enter your input:\n");
    int width = read(input);
    int n1, n2;
    char op;

    // Convert input to 'number op number'
    convert(input, width, &n1, &op, &n2);
    // Calculate res and handle operation permission
    int res = calculate(n1, op, n2);
    if (res == -10001) {
        printf("Operation not permitted\n");
        return 4;
    }
    // Convert res to sign and string
    int sign = res < 0 ? -1 : 1;
    res *= sign;
    char output[12] = "";
    int len = 0;
    while (res != 0) {
        output[len++] = (char)('0' + (res%10));
        res /= 10;
    }
    if (sign == -1) {
        output[len++] = '-';
    }
    output[len] = '\0';
    // Create 2D char with output as 7-segment
    char ans[3][70];

    // Ans line length
    int x = 0;
    // Lines
    for (int i = 0; i < 3; i++) {
        x = 0;
        // Go through output from end to start
        for (int j = len - 1; j >= 0; j--) {
            // For every number (or operator) in output string
            if (output[j] == '-') {
                ans[i][x++] = ' ';
                ans[i][x++] = i == 1 ? '-' : ' ';
                ans[i][x++] = ' ';
            } else {
                int n = (int)(output[j] - '0') == 0 ? 9 : ((int)(output[j] - '0') - 1);
                ans[i][x++] = numbers[n][i][0];
                ans[i][x++] = numbers[n][i][1];
                ans[i][x++] = numbers[n][i][2];
            }
            // Add space
            ans[i][x++] = ' ';
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < x; j++) {
            printf("%c", ans[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void convert(char input[3][70], int width, int *n1, char *op, int *n2) {
    int num = 0;
    for (int i = 0; i < width; i += 4) {
        char temp[4][4];
        // printf("\nInput 1, i: %c\n", input[1][i]);
        for (int x = 0; x < 3; x++) {
            for (int y = i; y < i + 3; y++) {
                temp[x][y - i] = input[x][y];
                // printf("%c", temp[x][y - i]);
            }
            // printf("\n");
        }
        if (temp[1][1] == '+' || temp[1][1] == '-' || temp[1][1] == '*' || temp[1][1] == '/') {
            *op = temp[1][1];
            *n1 = num;
            num = 0;
        } else {
            num = 10*num + compare(temp);
        }
    }
    *n2 = num;
}

int compare(char input[4][4]) {
    for (int n = 0; n < 10; n++) {
        int flag = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (input[i][j] != numbers[n][i][j]) {
                    flag = 1;
                }
            }
        }
        if (!flag) {
            return (n+1)%10;
        }
    }
    return -1;
}

int calculate(const int n1, const char op, const int n2) {
    int res = 0;
    if (op == '+') {
        res = n1 + n2;
    } else if (op == '-') {
        res = n1 - n2;
    } else if (op == '*') {
        res = n1 * n2;
    } else if (op == '/') {
        if (n2 == 0) {
            return -10001;
        }
        res = n1 / n2;
    }
    return res;
}

int read(char input[3][70]) {
    char w;
    int x = 0, y = 0;
    int width = 0;
    do {
        scanf("%c", &w);
        input[x][y] = w;
        y++;
        if (w == '\n') {
            width = y;
            x++; y = 0;
        }
    } while (x != 3);
    return width - 1;
}

/*
 *      _   _       _   _   _   _   _   _ ⏎
 *   |  _|  _| |_| |_  |_    | |_| |_| | |⏎
 *   | |_   _|   |  _| |_|   | |_|  _| |_|⏎
 */
