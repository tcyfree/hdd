#include <stdio.h>
#include "timing.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/io.h>

int main()
{
    unsigned long offset;
    int fp,num;
    struct timeval start;
    char str[] = "0123456789abcde";

    /**
     * @brief 顺序写
     */
    start = time_start();
    num = 0;
    offset = 0;
    while (num < 1024)
    {
        fp = open("file.txt", O_RDWR + O_CREAT);
        if (fp == -1)
        {

            printf("00can not open the file\n");

            return 1;
        }
        // printf("fp:%d\n", fp);
        lseek(fp, offset, SEEK_SET);
        // printf("%d\n",tell(fp));
        write(fp, str, sizeof(str));
        offset += sizeof(str);
        num++;
    }
    // flush(fp);
    close(fp);
    printf("Comsumed Time:%ld ms\n", msdiff(start));

    /**
     * @brief 随机写
     */
    start = time_start();
    num = 0;
    offset = 0;
    while (num < 1024)
    {
        fp = open("file2.txt", O_RDWR + O_CREAT);
        if (fp == -1)
        {

            printf("11can not open the file2\n");

            return 1;
        }
        // printf("fp:%d\n", fp);
        lseek(fp, offset, SEEK_SET);
        // printf("%d\n",tell(fp));
        write(fp, str, sizeof(str));
        offset += sizeof(str)+8;
        num++;
    }
    // flush(fp);
    close(fp);
    printf("Comsumed Time:%ld ms\n", msdiff(start));

    return (0);
}