#include <stdio.h>
#include <math.h>

// Hàm kiểm tra xem một số có phải là số chính phương hay không
int isPerfectSquare(int num) {
    int sqrtNum = sqrt(num);
    return (sqrtNum * sqrtNum == num);
}

// Hàm đếm và in ra các số chính phương nhỏ hơn n
void countAndPrintPerfectSquares(int n) {
    if (n <= 0) {
        printf("Khong co so chinh phuong nao nho hon %d.\n", n);
        return;
    }
    printf("Cac so chinh phuong nho hon %d la:\n", n);
    int count = 0;
    for (int i = 1; i < n; i++) {
        if (isPerfectSquare(i)) {
            printf("%d ", i);
            count++;
        }
    }
    printf("\nTong so chinh phuong: %d\n", count);
}

int main() {
    int n;
    printf("Nhap vao so nguyen duong n: ");
    scanf("%d", &n);
    countAndPrintPerfectSquares(n);
    return 0;
}
