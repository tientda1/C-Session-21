#include <stdio.h>

int main() {
    char ch;
    if (freopen("bt01.txt", "r", stdin) == NULL) {
        printf("Khong the mo file bt01.txt d? d?c\n");
    }
    if (freopen("bt06.txt", "w", stdout) == NULL) {
        printf("Khong the mo file bt06.txt\n");
        fclose(stdin);
    }
    while ((ch = getchar()) != EOF) {
        putchar(ch);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

