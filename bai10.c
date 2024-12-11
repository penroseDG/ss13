#include <stdio.h>

int mang[100];
int n;

void nhapMang() {
    printf("Nhap so phan tu can nhap (1-100): ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Nhap gia tri phan tu thu %d: ", i + 1);
        scanf("%d", &mang[i]);
    }
}

void inMang() {
    printf("Gia tri cac phan tu dang quan ly:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", mang[i]);
    }
    printf("\n");
}

void themPhanTu() {
    int vt;
    printf("Nhap vi tri can them (1-%d): ", n + 1);
    scanf("%d", &vt);
    if (vt < 1 || vt > n + 1) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    for (int i = n; i >= vt - 1; i--) {
        mang[i + 1] = mang[i];
    }
    printf("Nhap gia tri phan tu can them: ");
    scanf("%d", &mang[vt - 1]);
    n++;
}

void suaPhanTu() {
    int vt;
    printf("Nhap vi tri can sua (1-%d): ", n);
    scanf("%d", &vt);
    if (vt < 1 || vt > n) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    printf("Nhap gia tri moi: ");
    scanf("%d", &mang[vt - 1]);
}

void xoaPhanTu() {
    int vt;
    printf("Nhap vi tri can xoa (1-%d): ", n);
    scanf("%d", &vt);
    if (vt < 1 || vt > n) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    for (int i = vt - 1; i < n - 1; i++) {
        mang[i] = mang[i + 1];
    }
    n--;
}

void sapXepTang() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (mang[i] > mang[j]) {
                int temp = mang[i];
                mang[i] = mang[j];
                mang[j] = temp;
            }
        }
    }
}

void sapXepGiam() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (mang[i] < mang[j]) {
                int temp = mang[i];
                mang[i] = mang[j];
                mang[j] = temp;
            }
        }
    }
}

int timKiemTuyenTinh(int x) {
    for (int i = 0; i < n; i++) {
        if (mang[i] == x) {
            return i + 1;
        }	
    }
    return -1;
}

int timKiemNhiPhan(int x) {
    int batDau = 0;
    int ketThuc = n - 1;
    while (batDau <= ketThuc) {
        int trungBinh = (batDau + ketThuc) / 2;
        if (mang[trungBinh] == x) {
            return trungBinh + 1;
        } else if (mang[trungBinh] < x) {
            batDau = trungBinh + 1;
        } else {
            ketThuc = trungBinh - 1;
        }
    }
    return -1;
}

int main() {
    int chon;
    do {
        printf("MENU\n");
        printf("1. Nhap so phan tu can nhap va gia tri cac phan tu\n");
        printf("2. In ra gia tri cac phan tu dang quan ly\n");
        printf("3. Them mot phan tu vao vi tri chi dinh\n");
        printf("4. Sua mot phan tu o vi tri chi dinh\n");
        printf("5. Xoa mot phan tu o vi tri chi dinh\n");
        printf("6. Sap xep cac phan tu\n");
        printf("7. Tim kiem phan tu\n");
        printf("8. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &chon);
        switch (chon) {
            case 1:
                nhapMang();
                break;
            case 2:
                inMang();
                break;
            case 3:
                themPhanTu();
                break;
            case 4:
                suaPhanTu();
                break;
            case 5:
                xoaPhanTu();
                break;
            case 6:
                printf("6. Sap xep cac phan tu\n");
                printf("a. Tang dan\n");
                printf("b. Giam dan\n");
          
                char luaChon;
                printf("Nhap lua chon cua ban: ");
                scanf(" %c", &luaChon);
                if (luaChon == 'a') {
                    sapXepTang();
                    inMang();
                } else if (luaChon == 'b') {
                    sapXepGiam();
                    inMang();
                } else {
                    printf("Lua chon khong hop le!\n");
                }
                break;
            case 7:
                printf("7. Tim kiem phan tu\n");
                printf("a. Tim kiem tuyen tinh\n");
                printf("b. Tim kiem nhi phan\n");
                char luaChonTim;
                printf("Nhap lua chon cua ban: ");
                scanf(" %c", &luaChonTim);
                int x;
                printf("Nhap gia tri can tim: ");
                scanf("%d", &x);
                if (luaChonTim == 'a') {
                    int vt = timKiemTuyenTinh(x);
                    if (vt != -1) {
                        printf("Phan tu %d o vi tri %d\n", x, vt);
                    } else {
                        printf("Khong tim thay phan tu %d\n", x);
                    }
                } else if (luaChonTim == 'b') {
                    int vt = timKiemNhiPhan(x);
                    if (vt != -1) {
                        printf("Phan tu %d o vi tri %d\n", x, vt);
                    } else {
                        printf("Khong tim thay phan tu %d\n", x);
                    }
                } else {
                    printf("Lua chon khong hop le!\n");
                }
                break;
            case 8:
                printf("Tam biet!\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (chon != 8);
    return 0;
}
