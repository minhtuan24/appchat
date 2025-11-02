#include <stdio.h>
#include <unistd.h>

int dog(int n)
{
    printf("Tôi là con chó: %d\n", n);
    return 0;
}

int pig(int n)
{
    printf("Tôi là con heo: %d\n", n);
    return 0;
}

int chicken(int n)
{
    printf("Tôi là con gà: %d\n", n);
    return 0;
}

int in_convat(int (*func)(int), int n)
{
    func(n);
}


// n!
int giai_thua(int n)
{
    printf("n đang là: %d\n", n);
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * giai_thua(n - 1); // đệ quy
    }
}

// process gọi main
int main(int cg, char **vg)
{
    int t = 8;
    int kq;
    int* p_kq = &kq;
    kq = giai_thua(t);



    printf("Kết quả: %d\n", kq);

    // function 
    in_convat(&dog, 5);
    in_convat(&pig, 8);
    in_convat(&chicken, 95);

    
    while(1) {
        sleep(1);
    }


    return 0;
}