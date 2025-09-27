#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR 5
#define MAX_LEN 100

void toUpperCase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

void reverseString(char str[]) {
    int len = (int)strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int contains(const char str[], const char sub[]) {
    return strstr(str, sub) != NULL;
}

int main() {
    char strings[MAX_STR][MAX_LEN];
    int n;

    printf("Hany stringet adsz meg? (max %d): ", MAX_STR);
    scanf_s("%d", &n);
    if (n < 1) n = 1;
    if (n > MAX_STR) n = MAX_STR;

    getchar(); // bufferben levo Enter eltavolitasa

    for (int i = 0; i < n; i++) {
        printf("Adj meg egy stringet (%d/%d): ", i + 1, n);
        scanf_s("%99[^\n]", strings[i], (unsigned)MAX_LEN);
        getchar(); // Enter eltavolitasa a bufferbol
    }



    char search[MAX_LEN];
    printf("\nAdj meg egy keresett stringet: ");
    scanf_s("%99[^\n]", search, (unsigned)MAX_LEN);
    getchar();

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (contains(strings[i], search)) {
            printf("A(z) \"%s\" megtalalhato a(z) %d. stringben.\n", search, i + 1);
            found = 1;
        }
    }
    if (!found) {
        printf("A(z) \"%s\" sehol nem talalhato.\n", search);
    }

    printf("\n--- Eredeti stringek ---\n");
    for (int i = 0; i < n; i++) {
        printf("%d: %s\n", i + 1, strings[i]);
    }
    for (int i = 0; i < n; i++) {
        toUpperCase(strings[i]);
        reverseString(strings[i]);
    }

    printf("\n--- Nagybetus es visszaforditott stringek ---\n");
    for (int i = 0; i < n; i++) {
        printf("%d: %s\n", i + 1, strings[i]);
    }
    return 0;
}
