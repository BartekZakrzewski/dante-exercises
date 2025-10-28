#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// int str_cmp(char *s1, char *s2);
int cmp(const void*a, const void*b);
int sort_alphabetically(char tab[]);

int main() {
    char tab[1001];
    printf("Please enter a string:\n");
    if (fgets(tab, 1001, stdin) == NULL) {
        return -1;
    }
    if (*(tab + strlen(tab) - 1) == '\n') {
        *(tab + strlen(tab) - 1) = '\0';
    }
    int x = sort_alphabetically(tab);
    if (x == 1) {
        printf("Incorrect input data\n");
        return 2;
    }
    printf("%s", tab);

    return 0;
}

int sort_alphabetically(char tab[]) {
    if (tab == NULL) return 1;
    if (strlen(tab) <= 1) return 0;
    char words[1001][1001];
    int n_words = 0, letter = 0;
    char *__tab = (tab + strlen(tab) - 1);
    if (*(__tab + 1) == '\n') {
        return 1;
    }
    while (*__tab == ' ') {
        __tab--;
    }
    *(__tab + 1) = '\0';
    char *_tab = tab;
    while (*_tab != '\0') {
        if (!(*_tab >= 'a' && *_tab <= 'z') && !(*_tab >= 'A' && *_tab <= 'Z') && !(*_tab == ' ')) {
            return 1;
        }
        if (*_tab != ' ') {
            *(*(words + n_words) + letter) = *_tab;
            letter++;
        } else {
            if (letter > 0) {
                *(*(words + n_words) + letter) = '\0';
                if ((int)strlen(*(words + n_words)) > 0) n_words++;
                // printf("%s %d %d\n", *(words + n_words - 1), n_words, (int)strlen(*(words + n_words - 1)));
            }
            letter = 0;
        }
        _tab++;
    }
    n_words++;
    int n = sizeof(words) / sizeof(words[0]);
    qsort(words, n, sizeof(words[0]), cmp);
    // printf("%s %d\n", *(words + n_words - 1), n_words);
    // int same = 0;
    // for (int i = 0; i < n_words - 1; i++) {
    //     for (int j = 0; j < n_words - i - 1; j++) {
    //         // if (*(words + j) == *(words + j + 1)) {
    //         //     same = 1;
    //         // }
    //         if (strcmp(*(words + j), *(words + j + 1)) > 0) {
    //             char temp[1001];
    //             strcpy(temp, *(words + j));
    //             strcpy(*(words + j), *(words + j + 1));
    //             strcpy(*(words + j + 1), temp);
    //         }
    //     }
    // }

    int len = 0;
    for (int i = 0; i < n_words; i++) {
        for (int j = 0; j < (int)strlen(*(words + i)); j++) {
            *(tab + len) = *(*(words + i) + j);
            len++;
        }
        *(tab + len) = ' ';
        len++;
    }
    *(tab + len - 1) = '\0';

    return 0;
}

int cmp(const void*a, const void*b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

// int str_cmp(char *s1, char *s2) {
//     char *_s1, *_s2;
//     strcpy(_s1, s1);
//     strcpy(_s2, s2);
//     if (_s1 && _s2) {
//         return strcmp(_s1, _s2);
//     }
//     return 0;
// }