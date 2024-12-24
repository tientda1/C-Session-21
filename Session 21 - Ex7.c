#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[50];
    int age;
} Student;

int main() {
    FILE *file;
    int numStudents;
    Student student;

    file = fopen("students.txt", "w");
    if (file == NULL) {
        printf("Khong the mo file students.txt\n");
        exit(1);
    }

    printf("Nhap so luong sinh vien: ");
    scanf("%d", &numStudents);

    for (int i = 0; i < numStudents; i++) {
        printf("Nhap thong tin sinh vien: %d\n", i + 1);
        printf("ID: ");
        scanf("%d", &student.id);
        printf("Ten: ");
        scanf(" %[^\n]", student.name);
        printf("Tuoi: ");
        scanf("%d", &student.age);

        fprintf(file, "%d,%s,%d\n", student.id, student.name, student.age);
    }
    fclose(file);
    printf("Ða luu thong tin sinh vien vao file students.txt\n");

    return 0;
}

