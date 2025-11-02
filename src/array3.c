// bubble sort
#include <stdio.h>

void sapXepTangDan(int a[], int n)
{
    for(int i = 0; i < n -1; i++) {
        for(int j = i+1; j < n; j++) {
            if(a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main()
{
    int n;
    printf("Nhập số phần tử: \n");
    scanf("%d", &n);

    int a[1000];
    printf("Nhập %d số nguyên:\n", n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }


    sapXepTangDan(a, n);

    printf("Day so sau khi sap xep tang dan: \n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    
    return 0;
}