#include <stdio.h>

int main()
{
    int n;
    printf("Nhap so: ");
    if (scanf("%d", &n) != 1) return 0;

    if(n <= 0)
    {
        printf("N bat buoc la so nguyen duong");
        return 0;
    }

    int t = n;
    int r = 0;

    while(t != 0)
    {
        t /= 10;
        r++;
    }

    printf("Ket qua: %d\n", r);

    return 0;
}