#include <stdio.h>

int main() {
    int N;
    scanf("%i ", &N);
    char sym;
    char sym_1;
    int j = 0;
    int k = 0;
    scanf("%c", &sym);
    char arr[100000];
    for (int i = 0; i < N; i++) {
        if (sym != ';') {
            arr[i] = sym;
        }
        else {
            k = j;
            for (j; j <= k + (i - k - 1) / 2; j++) {
                sym_1 = arr[i - 1 - j + k];
                arr[i - 1 - j + k] = arr[j];
                arr[j] = sym_1;
            }
            arr[i] = ';';
            j = i + 1;
        }
        scanf("%c", &sym);
    }
    for (int i = 0; i < N; i++) {
        printf("%c", arr[i]);
    }
    return 1;
}