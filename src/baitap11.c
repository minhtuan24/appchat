#include <stdio.h>

int main() {
    int n;
    printf("Nhap so nguyen: ");
    scanf("%d", &n);

    if (n < 0) n = -n;

    int tong = 0;
    while (n > 0) {
        tong += n % 10;
        n /= 10;
    }

    printf("Tong cac chu so la: %d\n", tong);
    return 0;
}
