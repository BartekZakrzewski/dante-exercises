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
    printf("Podaj pierwszy wektor: ");
    int size1 = read_vector(vector1, MAX_VECTOR_SIZE, STOP_VALUE);
    if (size1 == 0) {
        printf("Not enough data available\n");
        return 2;
    }
    if (size1 == -2) {
        printf("Incorrect input\n");
        return 1;
    }
    while (getchar() != '\n');
    printf("Podaj drugi wektor: ");
    int size2 = read_vector(vector2, MAX_VECTOR_SIZE, STOP_VALUE);
    if (size2 == 0) {
        printf("Not enough data available\n");
        return 2;
    }
    if (size2 == -2) {
        printf("Incorrect input\n");
        return 1;
    }
    while (getchar() != '\n');
    display_vector(vector1, size1);
    display_vector(vector2, size2);
    int size_concat_begin = concat_begin(vector1, size1, vector2, size2, vector_concat_begin, MAX_VECTOR_SIZE);
    if (size_concat_begin == -1) {
        printf("Incorrect input\n");
        return 1;
    }
    if (size_concat_begin == -2) {
        printf("Output buffer is too small\n");
        return 0;
    }
    display_vector(vector_concat_begin, size_concat_begin);
    int size_concat_end = concat_end(vector1, size1, vector2, size2, vector_concat_end, MAX_VECTOR_SIZE);
    if (size_concat_end == -1) {
        printf("Incorrect input\n");
        return 1;
    }
    if (size_concat_end == -2) {
        printf("Output buffer is too small\n");
        return 0;
    }
    display_vector(vector_concat_end, size_concat_end);
    int size_concat_zip = concat_zip(vector1, size1, vector2, size2, vector_concat_zip, MAX_VECTOR_SIZE);
    if (size_concat_zip == -1) {
        printf("Incorrect input\n");
        return 1;
    }
    if (size_concat_zip == -2) {
        printf("Output buffer is too small\n");
        return 0;
    }
    display_vector(vector_concat_zip, size_concat_zip);

    return 0;
}

int concat_zip(const int first[], int size, const int second[], int size2, int dest[], int size3) {
    if (size <= 0 || size2 <= 0 || size3 <= 0) return -1;
    if (size + size2 > size3) {
        return -2;
    }
    int i1 = 0, i2 = 0, i3 = 0;
    while (i1 < size && i2 < size2) {
        *(dest + i3++) = *(first + i1++);
        *(dest + i3++) = *(second + i2++);
    }

    while (i1 < size) {
        *(dest + i3++) = *(first + i1++);
    }

    while (i2 < size2) {
        *(dest + i3++) = *(second + i2++);
    }

    return i3;
}

int concat_end(const int first[], int size, const int second[], int size2, int dest[], int size3) {
    if (size <= 0 || size2 <= 0 || size3 <= 0) return -1;
    if (size + size2 > size3) {
        return -2;
    }
    int i1 = 0, i2 = 0, i3 = 0;
    while (i2 < size2) {
        *(dest + i3++) = *(second + i2++);
    }
    while (i1 < size) {
        *(dest + i3++) = *(first + i1++);
    }

    return i3;
}

int concat_begin(const int first[], int size, const int second[], int size2, int dest[], int size3) {
    if (size <= 0 || size2 <= 0 || size3 <= 0) return -1;
    if (size + size2 > size3) {
        return -2;
    }
    int i1 = 0, i2 = 0, i3 = 0;
    while (i1 < size) {
        *(dest + i3++) = *(first + i1++);
    }
    while (i2 < size2) {
        *(dest + i3++) = *(second + i2++);
    }
    return i3;
}

int read_vector(int vec[], int size, int stop_value) {
    if (size <= 0) return -1;
    for (int i = 0; i < size; i++) {
        int input = 0;
        int n = scanf("%d", &input);
        if (!n) return -2;
        if (input == stop_value) return i;
        *(vec + i) = input;
    }
    return size;
}

void display_vector(const int vec[], int size) {
    if (size <= 0) return;
    for (int i = 0; i < size; i++) {
        printf("%d ", *(vec + i));
    }
    printf("\n");
}

