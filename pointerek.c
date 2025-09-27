#include <stdio.h>
#include <stdlib.h>

//szumma
int sumArray(int* arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += *(arr + i);
    }
    return sum;
}

// Két szám cseréje pointerrel
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Pointer to pointer: legnagyobb szám mutatója
void findMax(int* arr, int size, int** maxPtr) {
    *maxPtr = &arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > **maxPtr) {
            *maxPtr = &arr[i];
        }
    }
}

// Dinamikus tömb
int* inputArray(int size) {
    int* arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memória hiba!\n");
        exit(1);
    }
    for (int i = 0; i < size; i++) {
        printf("%d. szam: ", i + 1);
        scanf_s("%d", &arr[i]);
    }
    return arr;
}

int main() {
    int n;
    printf("Hany szamot adsz meg? ");
    scanf_s("%d", &n);

    int* numbers = inputArray(n);

    // Összegzés függvény pointerrel
    int (*sumFunc)(int*, int) = sumArray;
    int total = sumFunc(numbers, n);
    printf("\nA szamok osszege: %d\n", total);

    // Maximum keresés pointer to pointer-rel
    int* maxNum;
    findMax(numbers, n, &maxNum);
    printf("A legnagyobb szam: %d\n", *maxNum);

    // Két szám cseréje: első és utolsó
    printf("\nCsere az elso és utolso szam kozott: %d <-> %d\n", numbers[0], numbers[n - 1]);
    swap(&numbers[0], &numbers[n - 1]);
    printf("A tomb csere utan:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    free(numbers);
    return 0;
}
