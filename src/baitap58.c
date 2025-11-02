#include <stdio.h>

int main() {
    long long n;
    printf("Nhap so tien can rut (chia het cho 10000): ");
    if (scanf("%lld", &n) != 1) return 0;

    if (n < 0 || n % 10000 != 0) {
        printf("Gia tri khong hop le. Vui long nhap so nguyen lon hon hoac bang 0 va chia het cho 10000.\n");
        return 0;
    }

    long long remaining = n;
    long long c100 = remaining / 100000; remaining %= 100000;
    long long c50  = remaining /  50000; remaining %=  50000;
    long long c20  = remaining /  20000; remaining %=  20000;
    long long c10  = remaining /  10000; remaining %=  10000;

    // remaining phải bằng 0 vì n chia hết cho 10000
    long long total = c100 + c50 + c20 + c10;

    printf("Phuong an tra tien:\n");
    printf("100000: %lld\n", c100);
    printf(" 50000: %lld\n", c50);
    printf(" 20000: %lld\n", c20);
    printf(" 10000: %lld\n", c10);
    printf("Tong so to: %lld\n", total);

    return 0;
}
