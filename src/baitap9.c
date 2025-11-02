#include <stdio.h>

int main()
{
    int n;
    printf("Nhap so: ");
    if (scanf("%d", &n) != 1) return 0;
    
    for(int i = 2; i<n; i++)
    {
        if(n%i == 0) 
        {
            printf("Ko phai so nguyen to");
            return 0;
        }
    }

    printf("La so nguyen to\n");

    return 0;
}