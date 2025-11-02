#include <stdio.h>
#include <math.h>
#include <stdint.h>

int main(void) {
    unsigned long long n;
    if (scanf("%llu", &n) != 1) return 0;

    if (n <= 1) {
        // Không tồn tại k nguyên dương sao cho S(k) < n
        printf("0\n");
        return 0;
    }

    // Tính nghiệm thực r = (-1 + sqrt(1+8n)) / 2
    long double disc = 1.0L + 8.0L * (long double)n;
    long double r = (sqrtl(disc) - 1.0L) / 2.0L;

    // Lấy floor ban đầu
    unsigned long long k = (unsigned long long) floor(r);

    // Điều chỉnh an toàn nếu bằng hoặc vượt (do làm tròn)
    // while (k > 0 && ( (__uint128_t)k * (k + 1) / 2 ) >= n) --k;
    // tiếp tục tăng nếu chưa đủ (thường không xảy ra)
    // while ( ( (__uint128_t)(k + 1) * (k + 2) / 2 ) < n ) ++k;

    printf("%llu\n", k);
    return 0;
}
