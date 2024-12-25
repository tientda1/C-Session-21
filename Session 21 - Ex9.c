#include <stdio.h>
typedef struct {
    int id;
    char name[100];
    char author[100];
    float price;
    char category[50];
} Book;

void inputBooks(Book books[], int *numBooks) {
    printf("Nhap so luong sach: ");
    scanf("%d", numBooks);
    getchar();

    for (int i = 0; i < *numBooks; i++) {
        printf("Nhap thong tin sach %d:\n", i + 1);
        printf("Ma sach: ");
        scanf("%d", &books[i].id);
        getchar();
        printf("Ten sach: ");
        fgets(books[i].name, sizeof(books[i].name), stdin);
        books[i].name[strcspn(books[i].name, "\n")] = '\0';
        printf("Tac gia: ");
        fgets(books[i].author, sizeof(books[i].author), stdin);
        books[i].author[strcspn(books[i].author, "\n")] = '\0';
        printf("Gia tien: ");
        scanf("%f", &books[i].price);
        getchar();
        printf("The loai: ");
        fgets(books[i].category, sizeof(books[i].category), stdin);
        books[i].category[strcspn(books[i].category, "\n")] = '\0';
    }
}

void saveBooksToFile(Book books[], int numBooks) {
    FILE *file = fopen("books.bin", "wb");
    if (file == NULL) {
        printf("Khong the mo file.\n");
        return;
    }

    fwrite(&numBooks, sizeof(int), 1, file);
    fwrite(books, sizeof(Book), numBooks, file);
    fclose(file);
    printf("Ða luu thong tin vao file.\n");
}

void loadBooksFromFile(Book books[], int *numBooks) {
    FILE *file = fopen("books.bin", "rb");
    if (file == NULL) {
        printf("Khong the mo file.\n");
        return;
    }

    fread(numBooks, sizeof(int), 1, file);
    fread(books, sizeof(Book), *numBooks, file);
    fclose(file);
    printf("Ða lay thong tin tu file.\n");
}

void displayBooks(Book books[], int numBooks) {
    printf("Thong tin sach:\n");
    for (int i = 0; i < numBooks; i++) {
        printf("Ma sach: %d\n", books[i].id);
        printf("Ten sach: %s\n", books[i].name);
        printf("Tac gia: %s\n", books[i].author);
        printf("Gia tien: %.2f\n", books[i].price);
        printf("The loai: %s\n", books[i].category);
        printf("\n");
    }
}

int main() {
    Book books[100];
    int numBooks = 0;
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap so luong va thong tin sach\n");
        printf("2. Luu thong tin sach vao file\n");
        printf("3. Lay thong tin sach tu file\n");
        printf("4. Hien thi thong tin sach\n");
        printf("5. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                inputBooks(books, &numBooks);
                break;
            case 2:
                saveBooksToFile(books, numBooks);
                break;
            case 3:
                loadBooksFromFile(books, &numBooks);
                break;
            case 4:
                displayBooks(books, numBooks);
                break;
            case 5:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le vui long chon lai.\n");
        }
    } while (choice != 5);

    return 0;
}

