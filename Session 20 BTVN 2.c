#include <stdio.h>
#include <string.h>

struct SanPham {
    char ma[20];
    char ten[50];
    float giaNhap;
    float giaBan;
    int soLuong;
};

struct SanPham dsSanPham[100];
int soLuongSanPham = 0;
float doanhThu = 0;

void nhapSanPham() {
    struct SanPham sp;
    int i;
    printf("Nhap ma san pham: ");
    scanf("%s", sp.ma);
    printf("Nhap ten san pham: ");
    scanf("%s", sp.ten);
    printf("Nhap gia nhap: ");
    scanf("%f", &sp.giaNhap);
    printf("Nhap gia ban: ");
    scanf("%f", &sp.giaBan);
    printf("Nhap so luong: ");
    scanf("%d", &sp.soLuong);


    for (i = 0; i < soLuongSanPham; i++) {
        if (strcmp(dsSanPham[i].ma, sp.ma) == 0) {
            dsSanPham[i].soLuong += sp.soLuong;
            printf("San pham da ton tai, da cap nhat so luong.\n");
            return;
        }
    }

    dsSanPham[soLuongSanPham] = sp;
    soLuongSanPham++;
    doanhThu -= sp.giaNhap * sp.soLuong;
}

void hienThiDanhSach() {
    int i;
    printf("Danh sach san pham:\n");
    for (i = 0; i < soLuongSanPham; i++) {
        printf("Ma: %s, Ten: %s, Gia nhap: %.2f, Gia ban: %.2f, So luong: %d\n",
               dsSanPham[i].ma, dsSanPham[i].ten, dsSanPham[i].giaNhap,
               dsSanPham[i].giaBan, dsSanPham[i].soLuong);
    }
}

void banSanPham() {
    char ma[20];
    int soLuongBan, i;
    printf("Nhap ma san pham muon ban: ");
    scanf("%s", ma);
    printf("Nhap so luong muon ban: ");
    scanf("%d", &soLuongBan);

    for (i = 0; i < soLuongSanPham; i++) {
        if (strcmp(dsSanPham[i].ma, ma) == 0) {
            if (dsSanPham[i].soLuong <= 0) {
                printf("San pham da het hang.\n");
                return;
            }
            if (soLuongBan > dsSanPham[i].soLuong) {
                printf("Khong con du hang.\n");
                return;
            }
            dsSanPham[i].soLuong -= soLuongBan;
            doanhThu += dsSanPham[i].giaBan * soLuongBan;
            printf("Ban thanh cong %d san pham %s.\n", soLuongBan, dsSanPham[i].ten);
            return;
        }
    }
    printf("San pham khong ton tai.\n");
}

void capNhatSanPham() {
    char ma[20];
    printf("Nhap ma san pham can cap nhat: ");
    scanf("%s", ma);
    int i;
    for (i = 0; i < soLuongSanPham; i++) {
        if (strcmp(dsSanPham[i].ma, ma) == 0) {
            printf("Nhap ten moi: ");
            scanf("%s", dsSanPham[i].ten);
            printf("Nhap gia nhap moi: ");
            scanf("%f", &dsSanPham[i].giaNhap);
            printf("Nhap gia ban moi: ");
            scanf("%f", &dsSanPham[i].giaBan);
            printf("Nhap so luong moi: ");
            scanf("%d", &dsSanPham[i].soLuong);
            printf("Cap nhat thanh cong.\n");
            return;
        }
    }
    printf("San pham khong ton tai.\n");
}

int main() {
    int luaChon;
    do {
        printf("\nMENU\n");
        printf("1. Nhap so luong va thong tin san pham\n");
        printf("2. Hien thi danh sach san pham\n");
        printf("3. Ban san pham\n");
        printf("4. Cap nhat thong tin san pham\n");
        printf("5. Thoat\n");
        
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);

        switch(luaChon){
            case 1:
                nhapSanPham();
                break;
            case 2:
                hienThiDanhSach();
                break;
            case 3:
                banSanPham();
                break;
            case 4:
                capNhatSanPham();
                break;
            case 5:
                printf("Thoat chuong trinh\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai\n");
        }
    } while (luaChon != 5);

    return 0;
}

