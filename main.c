#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int target = rand() % 101;
    int input;
    for (int i = 0; i < 10; i++) {
        printf("Zgadnij: ");
        scanf("%d", &input);
        if (input == target) {
            printf("wygrales\n");
            return 0;
        }

        if (input < target) {
            printf("za malo\n");
        } else {
            printf("za duzo\n");
        }
    }
    printf("przegrales\n");
    return 0;
}
