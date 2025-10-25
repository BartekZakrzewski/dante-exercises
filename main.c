#include <stdio.h>
#define MAX_VECTOR_SIZE 50
#define STOP_VALUE 0

int concat_begin(const int first[], int size, const int second[], int size2, int dest[], int size3);
int concat_end(const int first[], int size, const int second[], int size2, int dest[], int size3);
int concat_zip(const int first[], int size, const int second[], int size2, int dest[], int size3);
int read_vector(int vec[], int size, int stop_value);
void display_vector(const int vec[], int size);

int main() {
    int vector1[MAX_VECTOR_SIZE], vector2[MAX_VECTOR_SIZE];
    int vector_concat_begin[MAX_VECTOR_SIZE], vector_concat_end[MAX_VECTOR_SIZE], vector_concat_zip[MAX_VECTOR_SIZE];
    int size1 = read_vector(vector1, MAX_VECTOR_SIZE, STOP_VALUE);
    if (size1 == -1 || size1 == -2) {
        printf("Incorrect input\n");
        return 1;
    }
    int size2 = read_vector(vector2, MAX_VECTOR_SIZE, STOP_VALUE);
    if (size2 == -1 || size2 == -2) {
        printf("Incorrect input\n");
        return 1;
    }
    display_vector(vector1, size1);
    display_vector(vector2, size2);
    int size_concat_begin = concat_begin(vector1, size1, vector2, size2, vector_concat_begin, MAX_VECTOR_SIZE);
    if (size_concat_begin == -2) {
        printf("Output buffer is too small\n");
        return 0;
    }
    display_vector(vector_concat_begin, size_concat_begin);
    int size_concat_end = concat_end(vector1, size1, vector2, size2, vector_concat_end, MAX_VECTOR_SIZE);
    if (size_concat_end == -2) {
        printf("Output buffer is too small\n");
        return 0;
    }
    display_vector(vector_concat_end, size_concat_end);
    int size_concat_zip = concat_zip(vector1, size1, vector2, size2, vector_concat_zip, MAX_VECTOR_SIZE);
    if (size_concat_zip == -2) {
        printf("Output buffer is too small\n");
        return 0;
    }
    display_vector(vector_concat_zip, size_concat_zip);

    return 0;
}

int concat_zip(const int first[], int size, const int second[], int size2, int dest[], int size3) {
    if (size + size2 > size3) {
        return -2;
    }
    int i1 = 0, i2 = 0, i3 = 0;
    while (i1 < size && i2 < size2) {
        dest[i3++] = first[i1++];
        dest[i3++] = second[i2++];
    }

    while (i1 < size) {
        dest[i3++] = first[i1++];
    }

    while (i2 < size2) {
        dest[i3++] = second[i2++];
    }

    return i3;
}

int concat_end(const int first[], int size, const int second[], int size2, int dest[], int size3) {
    if (size + size2 > size3) {
        return -2;
    }
    int i1 = 0, i2 = 0, i3 = 0;
    while (i2 < size) {
        dest[i3++] = second[i2++];
    }
    while (i1 < size) {
        dest[i3++] = first[i1++];
    }

    return i3;
}

int concat_begin(const int first[], int size, const int second[], int size2, int dest[], int size3) {
    if (size + size2 > size3) {
        return -2;
    }
    int i1 = 0, i2 = 0, i3 = 0;
    while (i1 < size) {
        dest[i3++] = first[i1++];
    }
    while (i2 < size) {
        dest[i3++] = second[i2++];
    }
    return i3;
}

int read_vector(int vec[], int size, int stop_value) {
    int i = 0, input, n;
    do {
        n = scanf("%d", &input);
        if (n != 1) {
            while (getchar() != '\n');
            return -2;
        }
        vec[i++] = input;
    } while (input != stop_value && i <= size);
    while (getchar() != '\n');
    if (i == 1) return -1;
    return i - 1;
}

void display_vector(const int vec[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

