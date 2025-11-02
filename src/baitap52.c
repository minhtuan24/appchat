#include <stdio.h>
#include <math.h>

int main(void) {
    double a, b, c, D, e, f;
    const double EPS = 1e-12;

    printf("Nhap he so a b c D e f (cach nhau boi dau cach hay newline):\n");
    if (scanf("%lf %lf %lf %lf %lf %lf", &a, &b, &c, &D, &e, &f) != 6) {
        printf("Nhap khong hop le.\n");
        return 0;
    }

    // Tính định thức
    double det = a * e - b * D;

    if (fabs(det) > EPS) {
        // Nghiệm duy nhất
        double x = (c * e - b * f) / det;
        double y = (a * f - c * D) / det;
        printf("He co mot nghiem duy nhat:\n");
        printf("x = %.12g\n", x);
        printf("y = %.12g\n", y);
    } else {
        // det == 0: kiểm tra tính tương thích
        double det1 = c * e - b * f; // det thay cot 1 bằng c,f
        double det2 = a * f - c * D; // det thay cot 2 bằng c,f (hoặc các biểu thức tương đương)

        if (fabs(det1) < EPS && fabs(det2) < EPS) {
            printf("He co vo so nghiem (cac phuong trinh tuong duong hoac phu thuoc nhau).\n");
            // Tùy nhu cầu, có thể in một biểu diễn tham số, ví dụ:
            // Nếu a và b không đồng thời 0, ta có y là tham số t:
            if (fabs(a) > EPS || fabs(b) > EPS) {
                if (fabs(b) > EPS) {
                    printf("Vi du mot tap nghiem: y = t, x = (c - b*t)/a  (neu a != 0)\n");
                } else {
                    printf("Neu b == 0 va a != 0: x = c/a, y la tham so tu do.\n");
                }
            } else if (fabs(D) > EPS || fabs(e) > EPS) {
                printf("Cac phuong trinh co dang D x + e y = f (tu tuong tuong phu hop)\n");
            } else {
                printf("Cac phuong trinh la 0 = 0 (bat ky x,y nao cung duoc).\n");
            }
        } else {
            printf("He vo nghiem (mau thuan).\n");
        }
    }

    return 0;
}
