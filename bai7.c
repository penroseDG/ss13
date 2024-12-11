#include <stdio.h>
#include <stdlib.h>

int** taoMaTran(int soHang, int soCot) {
    int** maTran = (int**)malloc(soHang * sizeof(int*));
    for (int i = 0; i < soHang; i++) {
        maTran[i] = (int*)malloc(soCot * sizeof(int));
    }

    for (int i = 0; i < soHang; i++) {
        for (int j = 0; j < soCot; j++) {
            printf("Nhap gia tri cho phan tu [%d][%d]: ", i, j);
            scanf("%d", &maTran[i][j]);
        }
    }

    return maTran;
}

void inMaTran(int** maTran, int soHang, int soCot) {
    for (int i = 0; i < soHang; i++) {
        for (int j = 0; j < soCot; j++) {
            printf("%d ", maTran[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int soHang, soCot;
    printf("Nhap so hang: ");
    scanf("%d", &soHang);
    printf("Nhap so cot: ");
    scanf("%d", &soCot);

    int** maTran = taoMaTran(soHang, soCot);
    printf("Ma tran vua nhap:\n");
    inMaTran(maTran, soHang, soCot);

    for (int i = 0; i < soHang; i++) {
        free(maTran[i]);
    }
    free(maTran);

    return 0;
}
