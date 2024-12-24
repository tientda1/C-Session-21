#include <stdio.h>

int main() {
    FILE *file;
    char line[256];
    file = fopen("bt01.txt", "r");
    if (file == NULL) {
        printf("Khong the mo file bt01.txt\n");
    }
    if (fgets(line, sizeof(line), file) != NULL) {
        printf("Dong dau tien trong file la: %s\n", line);
    } else {
        printf("File rong hoac khong doc duoc dong dau tien\n");
    }
    fclose(file);
    return 0;
}

