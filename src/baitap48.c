#include <stdio.h>
#include <math.h>

int main()
{
    int n, x;
    printf("Nhap so n:\n");
    scanf("%d", &n);
    printf("Nhap so x:\n");
    scanf("%d", &x);
    if(n <= 0){
        printf("N phai nguyen duong");
        return 0;
    }
    double t = 1;
    for(int i = 0; i <= n; i++)
    {
        t += pow(-1, i+1)*(pow(x, 2*i+1)/(2*i+1));
    }

    printf("Ket qua: %f\n", t);

    return 0;
}
