#include <stdio.h>

typedef struct {
    int id;
    char name[50];
    int age;
} Student;

int main() {
    FILE *file;
    Student students[100];
    int count = 0;
    file = fopen("students.txt", "r");
    if (file == NULL) {
        printf("Khong the mo file students.txt\n");
        exit(1);
    }
    while (fscanf(file, "%d,[^,],%d\n", &students[count].id, students[count].name, &students[count].age) != EOF) {
        count++;
        if (count >= 100) {
            break;
        }
    }
    fclose(file);
    printf("Danh sach sinh vien:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Ten: %s, Tuoi: %d\n", students[i].id, students[i].name, students[i].age);
    }

    return 0;
}

