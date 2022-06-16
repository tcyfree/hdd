#include <stdio.h>
#include "timing.h"

int main()
{
    int num = 0;
    unsigned long offset = 0;
    FILE *fp;
    struct timeval start;
    char str[] = "0123456789abcde";

    /**
     * @brief 顺序写
     */
    start = time_start();
    while (num < 1024)
    {
        fp = fopen("file.txt", "w");
        fseek(fp, offset, SEEK_SET); //移动位置指针
        // printf("%ld\n",ftell(fp));
        fwrite(str, sizeof(str), 1, fp);
        offset += sizeof(str);
        num++;
    }
    fflush(fp);
    fclose(fp);
    printf("Comsumed Time:%ld ms\n", msdiff(start));

    /**
     * @brief 随机写
     */
    start = time_start();
    num = 0;
    while (num < 1024)
    {
        fp = fopen("file2.txt", "w");
        fseek(fp, offset, SEEK_SET); //移动位置指针
        // printf("%ld\n",ftell(fp));
        fwrite(str, sizeof(str), 1, fp);
        offset += sizeof(str) + 1024;
        num++;
    }
    fflush(fp);
    fclose(fp);
    printf("Comsumed Time:%ld ms\n", msdiff(start));

    return (0);
}