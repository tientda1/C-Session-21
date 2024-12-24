#include <stdio.h>

int main() {
    FILE *file;
    int numLines;
    char buffer[256];
    file = fopen("bt05.txt", "w");
    if (file == NULL) {
        printf("Khong the mo file bt05.txt\n");
    }
    printf("Nhap so dong: ");
    scanf("%d", &numLines);
    getchar();
    for (int i = 0; i < numLines; i++) {
        printf("Nhap dong %d: ", i + 1);
        fgets(buffer, sizeof(buffer), stdin);
        fputs(buffer, file);
    }
    fclose(file);
    file = fopen("bt05.txt", "r");
    if (file == NULL) {
        printf("Khong the mo file bt05.txt\n");
        exit(1);
    }
    printf("\nNoi dung file bt05.txt:\n");
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }
    fclose(file);
    return 0;
}

