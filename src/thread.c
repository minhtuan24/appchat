#include <stdio.h> // input-ouput cở bản trên command line
#include <pthread.h>
#include <unistd.h>
#include <string.h>

// void *func_thread(void *n)
// {
//     char* input = (char *)n;
//     static int a = 0;
//     while (strcmp(input, "ket_thuc") != 0)
//     {
//         printf("Nhập lẹ đi, còn %d giây....", a++);
//         sleep(1);
//     }

//     return NULL;
// }

void *func_thread(void *n)
{
    char *input = (char *)n;
    printf("Đang bắt đầu thực thi...\n")

    pthread_exit(NULL);
}

void *func_thread2(void *n)
{
    char *input = (char *)n;
    static int a = 0;
    while (strcmp(input, "ket_thuc") == 0)
    {
        printf("Chạy ở luồng 2, còn %d giây....", a++);
        sleep(1);
    }

    pthread_exit(NULL);
}

int main(int cg, char **vg)
{
    char *input = "chua_ket_thuc";
    pthread_t thread1, thread2;
    int ret = pthread_create(
        &thread1,
        NULL,
        func_thread,
        input);

    if (ret)
    {
        fprintf(stderr, "Lỗi tạo Thread 1: %d\n", ret);
        return 1;
    }

    ret = pthread_create(
        &thread2,
        NULL,
        func_thread2,
        input);

    if (ret)
    {
        fprintf(stderr, "Lỗi tạo Thread 2: %d\n", ret);
        return 1;
    }

    // printf("Nhập số:");
    // scanf("%d", &a);
    // printf("\n");

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}