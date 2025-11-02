#include <stdio.h>
#include <math.h>

int giaithua(int n)
{
    if(n==0) return 1;
    int r = 1;
    for(int i = 1; i <=n; i++)
    {
        r *=i;
    }
    return r;
}

double tongS(int n, int x)
{

    double S = 0;
    for(int i = 1; i <= n; i++)
    {
        S += pow(x, i)/giaithua(i);
    }
    return S;
}

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

    printf("Ket qua: %f\n", tongS(n, x));

    return 0;
}
