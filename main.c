#include <stdio.h>
#define MAX 5

char names[MAX][201], start[MAX][10], end[MAX][10];
char sentences[MAX][300];

char* create_sentence(const char *name,  int year_begin, int year_end, char *output, unsigned int size);
int sort(char input[][201], int size);

int main() {
    int count = 0;
    printf("Podaj imiona:\n");
    for (int i = 0; i < MAX; i++) {
        if (fgets(*(names + i), 31, stdin) == NULL) {
            return - 1;
        }
        if (*(*(names + i)) == '\n') {
            break;
        }
        char *l = *(names + i);
        int new_line = 0;
        while (*l != '0') {
            if (*l == '\n') {
                new_line = 1;
                *l = '\0';
            }
            l++;
        }
        if (!new_line) {
            int _char;
            while ((_char = getchar()) != '\n' && _char != EOF);
        }
        count++;
    }
    count = count > MAX ? MAX : count;
    printf("Podaj daty:\n");
    for (int i = 0; i < count; i++) {
        if (fgets(*(start + i), 6, stdin) == NULL) {
            return - 1;
        }
        if (*(*(start + i)) == '\n') {
            if (i < count - 1) {
                printf("Incorrect input\n");
                return 1;
            }
            break;
        }
        char *l = *(start + i);
        int new_line = 0;
        while (*l != '0') {
            if (*l == '\n') {
                new_line = 1;
                *l = '\0';
            }
            l++;
        }
        if (!new_line) {
            int _char;
            while ((_char = getchar()) != '\n' && _char != EOF);
        }
    }
    printf("Podaj daty 2:\n");
    for (int i = 0; i < count; i++) {
        if (fgets(*(end + i), 6, stdin) == NULL) {
            return - 1;
        }
        if (*(*(end + i)) == '\n') {
            if (i < count - 1) {
                printf("Incorrect input\n");
                return 1;
            }
            break;
        }
        char *l = *(end + i);
        int new_line = 0;
        while (*l != '0') {
            if (*l == '\n') {
                new_line = 1;
                *l = '\0';
            }
            l++;
        }
        if (!new_line) {
            int _char;
            while ((_char = getchar()) != '\n' && _char != EOF);
        }
    }
    for (int i = 0; i < count; i++) {
        create_sentence(*(names + i), (int)*(start + i), (int)*(end + i), *(sentences + i), 400);
    }

    return 0;
}