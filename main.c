#include <stdio.h>
#include <string.h>
#define MAX 5

char names[MAX + 1][35], start[MAX + 1][10], end[MAX + 1][10];
char sentences[MAX + 1][201];

char* create_sentence(const char *name,  int year_begin, int year_end, char *output, unsigned int size);
int min(size_t a, size_t b);
int s_comp(char const*s1, char const*s2);
void s_copy(char* s1, char* s2);
int sort(char input[][201], int size);

int main() {
    int count = 0;
    printf("Podaj imiona:\n");
    for (int i = 0; i <= MAX; i++) {
        if (fgets(*(names + i), 34, stdin) == NULL) {
            return -1;
        }
        if (*(*(names + i)) == '\n') {
            if (i == 0) {
                printf("Not enough data available\n");
                return 3;
            }
            break;
        }
        char *l = *(names + i);
        int new_line = 0;
        while (*l != '\0') {
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
    for (int i = 0; i <= count; i++) {
        if (fgets(*(start + i), 9, stdin) == NULL) {
            return - 1;
        }
        if (*(*(start + i)) == '\n') {
            if (i < count) {
                printf("Incorrect input\n");
                return 1;
            }
            break;
        }
        if (i == count && *(*start + i) != '\n') {
            printf("Incorrect input\n");
            return 1;
        }
        char *l = *(start + i);
        int new_line = 0;
        while (*l != '\0') {
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
    for (int i = 0; i <= count; i++) {
        if (fgets(*(end + i), 9, stdin) == NULL) {
            return - 1;
        }
        if (*(*(end + i)) == '\n') {
            if (i < count) {
                printf("Incorrect input\n");
                return 1;
            }
            break;
        }
        if (i == count && *(*start + i) != '\n') {
            printf("Incorrect input\n");
            return 1;
        }
        char *l = *(end + i);
        int new_line = 0;
        while (*l != '\0') {
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
        // printf("\n%s %s %s\n", *(names + i), *(start + i), *(end + i));
        int year_begin, year_end;
        sscanf(*(start + i), "%d", &year_begin);
        sscanf(*(end + i), "%d", &year_end);
        char* _outpt = create_sentence(*(names + i), year_begin, year_end, *(sentences + i), 400);
        if (_outpt == NULL) {
            printf("Incorrect input\n");
            return 1;
        }
        printf("%s\n", _outpt);
    }
    int x = sort(sentences, count);
    if (x == 1) {
        return 1;
    }
    for (int i = 0; i < count; i++) {
        printf("%s\n", *(sentences + i));
    }
    return 0;
}

char* create_sentence(const char *name,  int year_begin, int year_end, char *output, unsigned int size) {
    if (year_begin > year_end || !name || size <= 0 || year_begin * year_end < 0 || strlen(name) >= size || !output) {
        return NULL;
    }
    sprintf(output, "%s ruled in years %d - %d", name, year_begin, year_end);
    if (strlen(output) >= size) {
        return NULL;
    }
    return output;
}

int sort(char input[][201], int size) {
    if (size <= 0 || !input) return 1;
    if (size < 2) return 0;

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (*(input +j) == NULL || *(input + j + 1) == NULL) {
                return 1;
            }
            char name1[11], name2[11], surname1[21], surname2[21];
            int begin1, begin2, end1, end2;
            int T1 = sscanf(*(input + j), "%s %s ruled in years %d - %d", name1, surname1, &begin1, &end1);
            int T2 = sscanf(*(input + j + 1), "%s %s ruled in years %d - %d", name2, surname2, &begin2, &end2);
            // printf("\nT1 = %s %s %d %d\nT2 = %s %s %d %d\n", name1, surname1, begin1, end1, name2, surname2, begin2, end2);
            if (T1 + T2 != 8 || strlen(name1) > 10 || strlen(surname1) > 20 || strlen(name2) > 10 || strlen(surname2) > 20) {
                return 2;
            }
            // printf("Begin\n");
            if (begin1 > begin2) {
                // printf("Swapped Begin 1\n");
                char temp[201];
                s_copy(temp, *(input + j));
                s_copy(*(input + j), *(input + j + 1));
                s_copy(*(input + j + 1), temp);
                continue;
            }
            if (begin1 != begin2) { continue; }
            // printf("End\n");
            if (end1 > end2) {
                // printf("Swapped End 1\n");
                char temp[201];
                s_copy(temp, *(input + j));
                s_copy(*(input + j), *(input + j + 1));
                s_copy(*(input + j + 1), temp);
                continue;
            }
            if (end1 != end2) { continue; }
            // printf("Surname\n");
            int _comp_surname = s_comp(surname1, surname2);
            if (_comp_surname == 2) {
                // printf("Swapped Surname\n");
                char temp[201];
                s_copy(temp, *(input + j));
                s_copy(*(input + j), *(input + j + 1));
                s_copy(*(input + j + 1), temp);
                continue;
            }
            if (_comp_surname != 0) { continue; }
            // printf("Name\n");
            int _comp_name = s_comp(name1, name2);
            if (_comp_name == 2) {
                // printf("Swapped Name\n");
                char temp[201];
                s_copy(temp, *(input + j));
                s_copy(*(input + j), *(input + j + 1));
                s_copy(*(input + j + 1), temp);
                continue;
            }
            // printf("NOT Swapped\n");
        }
    }
    return 0;
}

int s_comp(char const*s1, char const*s2) {
    // printf("S_comp %s %s\n", s1, s2);
    int i = 0;
    while ((*(s1 + i) != '\n' || *(s1 + i) != '\0') && (*(s2 + i) != '\n' || *(s2 + i) != '\0') && (i < min(strlen(s1), strlen(s2)))) {
        if (*(s1 + i) != *(s2 + i)) {
            // printf("%d %c %c %d\n", i, *(s1 + i), *(s2 + i), (*(s1 + i) > *(s2 + i)) + 1);
            return (*(s1 + i) > *(s2 + i)) + 1;
        }
        i++;
    }
    return strlen(s1) > strlen(s2) ? 2 : strlen(s1) < strlen(s2) ? 1 : 0;
}

int min(size_t a, size_t b) {
    return (a > b) ? a : b;
}

void s_copy(char* s1, char* s2) {
    while (*s2 != '\0') {
        *s1 = *s2;
        s2++;
        s1++;
    }
    *s1 = '\0';
}