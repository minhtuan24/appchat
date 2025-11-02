#include <stdio.h>

int main()
{
    // int so[] = {10, 20, 40, 28};
    int banco[8][8] = {};
    printf("\n----------------------------------------\n");
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            printf("<%d> ", banco[i][j]);
        }
        printf("\n");
    }
    printf("----------------------------------------\n");
    return 0;
}