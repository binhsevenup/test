#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Sinhvien {
    char ID[10];
    char Name[100];
    char PhoneNum[20];
} Sinhvien;

//Nhập ID - Tên - PhoneNum
void Addnew(int *count, Sinhvien sinhvienArray[]) {
    char choice[20];
    for (int j = 0; j < 10; ++j) {
        printf("*Vui long nhap tong tin cua sinh vien thu %d\n"
               "", *count+1);
        while (1) {
            printf("Nhap ID sinh vien: \n");
            scanf("%s", &sinhvienArray[*count].ID);
            if (strlen(&sinhvienArray[*count].ID) != 5) {
                printf("ERROR! Ma sinh vien phai dung 5 ki tu, vui long nhap lai.\n");
            } else break;
        }
        printf("Nhap ten sinh vien:\n");
        fgets(sinhvienArray[*count].Name, 100, stdin);
        getchar();
        printf("Nhap so dien thoai cua sinh vien:\n");
        fgetc(stdin);
        scanf("%[0-9]", &sinhvienArray[*count].PhoneNum);
        *count += 1;
        getchar();
        printf("Nhap exit de ket thuc nhap thong tin hoac go Enter de tiep tuc.");
        fgetc(stdin);
        fgets(choice, 10, stdin);
        if (strcmp(choice, "exit\n") == 0)break;
        if (*count == 10) {
            printf("Danh sach sinh vien khong du de nhap them");
            break;
        }
    }
}

//Hiển thị
void HienthiSinhvien(Sinhvien sinhvienArray[]) {
    int i = 0;
    printf("%-20s%-10s%-20s%-10s%-20s", "ID", "|", "Ten sinh vien", "|",
           "So dien thoai" "\n");
    for (int j = 0; j < 10; ++j) {
        printf("%-20s%-10s%-20s%-10s%-20s\n", &sinhvienArray[i].ID, "|", sinhvienArray[i].Name, "|",
               sinhvienArray[i].PhoneNum );
        i++;
    }
}

//Lưu
void save(Sinhvien sinhvienArray[]) {
    int i = 0;
    FILE *f = fopen("danhsachsinhvien.txt", "w");
    fprintf(f, "%-20s%-10s%-20s%-10s%-20s", "ID", "|", "Ten sinh vien", "|",
            "So dien thoai" "\n");
    for (int j = 0; j < 10; ++j) {
        fprintf(f, "%-20s%-10s%-20s%-10s%-20s\n", &sinhvienArray[i].ID, "|", sinhvienArray[i].Name, "|",
                sinhvienArray[i].PhoneNum);
        i++;
    }
    fclose(f);
}

//Đọc
void read() {
    FILE *f = fopen("danhsachsinhvien.txt", "r");
    printf("Đọc dữ liệu từ file\n");
    char buffer[255];
    while (fgets(buffer, 255, f) != NULL) {
        printf("%s", buffer);
    }
    fclose(f);
}

int main() {
    int Menuchoice;
    int i = 0;
    int *count;
    count = &i;
    Sinhvien sinhvienArray[10] = {};
    printf("\n------ MENU ------\n");
    printf("1. Them moi sinh vien.\n");
    printf("2. Hien thi danh sach sinh vien.\n");
    printf("3. Luu danh sach sinh vien ra file.\n");
    printf("4. Doc danh sach sinh vien tu file.\n");
    printf("5. Thoat chuong trinh.\n");

    while (1) {
        printf("\nNhap lua chon cua ban:");
        scanf("%d", &Menuchoice);
        fgetc(stdin);
        switch (Menuchoice) {
            case 1:
                if (*count == 10) {
                    printf("Danh sach sinh vien da day.");
                    break;
                }
                Addnew(count, sinhvienArray);
                break;
            case 2:
                HienthiSinhvien(sinhvienArray);
                break;
            case 3:
                save(sinhvienArray);
                break;
            case 4:
                read();
                break;
        }
        if (Menuchoice == 5) {
            printf("Ket thuc chuong trinh!\n");
            break;
        }
    }
    return 0;
}