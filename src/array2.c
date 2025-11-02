#include <stdio.h>

int timKiem(int a[], int len, int b)
{
    for(int i = 0; i < len; i++)
    {
        if(a[i] == b)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int input[] = {10, 20, 40, 28, 60, 39, 49, 39};
    int soCanTim;
    printf("Nhap can tim so: ");
    scanf("%d", &soCanTim);
    int r = timKiem(input, sizeof(input)/sizeof(int), soCanTim);
    if( r >= 0)
    {
        printf("Chi so cua %d la %d.\n", soCanTim, r);
    }
    else
    {
        printf("Ko tim thay.\n");
    }
    return 0;
}