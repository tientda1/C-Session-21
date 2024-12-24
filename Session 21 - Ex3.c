#include <stdio.h>

int main() {
    FILE *file;
    char input[100];
    file = fopen("bt01.txt", "a");
    if (file == NULL) {
        printf("Khong the mo file bt01.txt\n");
        exit(1);
    }

    printf("Nhap chuoi can them vao file: ");
    fgets(input, sizeof(input), stdin);
    fputs(input, file);
    fclose(file);
    return 0;
}

