#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Sach {
    char maSach[20];
    char tenSach[100];
    char tacGia[50];
    float giaTien;
    char theLoai[50];
};

struct Sach sach[100];
int soSach = 0;

void nhapSach();
void hienThiSach();
void themSach(int viTri);
void xoaSach(char* maSach);
void capNhatSach(char* maSach);
void sapXepSach(int tang);
void timKiemSach(char* tenSach);

int main() {
    int luaChon;
    do {
        printf("\nMENU\n");
        printf("1. Nhap so luong va thong tin sach.\n");
        printf("2. Hien thi thong tin sach.\n");
        printf("3. Them sach vao vi tri.\n");
        printf("4. Xoa sach theo ma sach.\n");
        printf("5. Cap nhat thong tin sach theo ma sach.\n");
        printf("6. Sap xep sach theo gia (1: Tang, 0: Giam).\n");
        printf("7. Tim kiem sach theo ten sach.\n");
        printf("8. Thoat.\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);
        
        switch (luaChon) {
            case 1:
                nhapSach();
                break;
            case 2:
                hienThiSach();
                break;
            case 3: {
                int viTri;
                printf("Nhap vi tri de them sach: ");
                scanf("%d", &viTri);
                if (viTri >= 0 && viTri <= soSach) {
                    themSach(viTri);
                } else {
                    printf("Vi tri khong hop le.\n");
                }
                break;
            }
            case 4: {
                char maSach[20];
                printf("Nhap ma sach can xoa: ");
                scanf("%s", maSach);
                xoaSach(maSach);
                break;
            }
            case 5: {
                char maSach[20];
                printf("Nhap ma sach can cap nhat: ");
                scanf("%s", maSach);
                capNhatSach(maSach);
                break;
            }
            case 6: {
                int tang;
                printf("Sap xep theo gia (1: Tang, 0: Giam): ");
                scanf("%d", &tang);
                sapXepSach(tang);
                break;
            }
            case 7: {
                char tenSach[100];
                printf("Nhap ten sach can tim: ");
                getchar();
                fgets(tenSach, sizeof(tenSach), stdin);
                tenSach[strcspn(tenSach, "\n")] = 0;
                timKiemSach(tenSach);
                break;
            }
            case 8:
                printf("Thoat chuong trinh\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai\n");
        }
    }while (luaChon != 8);
    
    return 0;
}

void nhapSach() {
    if (soSach >= 100) {
        printf("Da dat gioi han so luong sach.\n");
        return;
    }
    printf("Nhap ma sach: ");
    scanf("%s", sach[soSach].maSach);
    
    printf("Nhap ten sach: ");
    getchar();
    fgets(sach[soSach].tenSach, sizeof(sach[soSach].tenSach), stdin);
    sach[soSach].tenSach[strcspn(sach[soSach].tenSach, "\n")] = 0;

    printf("Nhap tac gia: ");
    fgets(sach[soSach].tacGia, sizeof(sach[soSach].tacGia), stdin);
    sach[soSach].tacGia[strcspn(sach[soSach].tacGia, "\n")] = 0;

    printf("Nhap gia tien: ");
    scanf("%f", &sach[soSach].giaTien);
    
    printf("Nhap the loai: ");
    getchar();
    fgets(sach[soSach].theLoai, sizeof(sach[soSach].theLoai), stdin);
    sach[soSach].theLoai[strcspn(sach[soSach].theLoai, "\n")] = 0;

    soSach++;
}

void hienThiSach() {
    printf("\nDanh sach sach:\n");
    for (int i = 0; i < soSach; i++) {
        printf("Ma sach: %s, Ten sach: %s, Tac gia: %s, Gia tien: %.2f, The loai: %s\n",
               sach[i].maSach, sach[i].tenSach, sach[i].tacGia, sach[i].giaTien, sach[i].theLoai);
    }
}

void themSach(int viTri) {
    if (soSach >= 100) {
        printf("Da dat gioi han so luong sach.\n");
        return;
    }
    for (int i = soSach; i > viTri; i--) {
        sach[i] = sach[i - 1];
    }
    nhapSach();
}

void xoaSach(char* maSach) {
    int found = 0;
    for (int i = 0; i < soSach; i++) {
        if (strcmp(sach[i].maSach, maSach) == 0) {
            found = 1;
        }
        if (found && i < soSach - 1) {
            sach[i] = sach[i + 1];
        }
    }
    if (found) {
        soSach--;
        printf("Da xoa sach co ma: %s\n", maSach);
    } else {
        printf("Khong tim thay sach voi ma: %s\n", maSach);
    }
}

void capNhatSach(char* maSach) {
    for (int i = 0; i < soSach; i++) {
        if (strcmp(sach[i].maSach, maSach) == 0) {
            printf("Cap nhat thong tin sach:\n");
            nhapSach();
            sach[i] = sach[soSach - 1];
            soSach--;
            return;
        }
    }
    printf("Khong tim thay sach voi ma: %s\n", maSach);
}

void sapXepSach(int tang) {
    for (int i = 0; i < soSach - 1; i++) {
        for (int j = i + 1; j < soSach; j++) {
            if ((tang && sach[i].giaTien > sach[j].giaTien) || (!tang && sach[i].giaTien < sach[j].giaTien)) {
                struct Sach temp = sach[i];
                sach[i] = sach[j];
                sach[j] = temp;
            }
        }
    }
    printf("Da sap xep sach.\n");
}

void timKiemSach(char* tenSach) {
    int found = 0;
    for (int i = 0; i < soSach; i++) {
        if (strstr(sach[i].tenSach, tenSach) != NULL) {
            printf("Sach tim thay: Ma sach: %s, Ten sach: %s, Tac gia: %s, Gia tien: %.2f, The loai: %s\n",
                   sach[i].maSach, sach[i].tenSach, sach[i].tacGia, sach[i].giaTien, sach[i].theLoai);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay sach voi ten: %s\n", tenSach);
    }
}

