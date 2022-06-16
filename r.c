# include <stdio.h>
# include <stdlib.h>

int main(void){
   /* ftell 函数的返回值是一个long类型的值，因为文件可能会很长，
   用long类型的值存储当前的读写位置,从某种意义上来说,文件里面的位置
   是以数组的形式来存放，每一个位置有一个下标，ftell返回下标值*/
    FILE *fp;
    if((fp = fopen("hello.txt","w"))== NULL){
        printf("文件打开失败!\n");
        exit(EXIT_FAILURE);
    }
    printf("%ld\n",ftell(fp));
    // 打印当前的位置指示器的值
    fputc('F',fp);
    printf("%ld\n",ftell(fp));
    fputs("ishCq",fp);
    printf("%ld\n",ftell(fp));
    
    rewind(fp);
    fputs("Hello",fp);
    // 此时插入数据会直接覆盖里面有的部分
    fputs("Hello",fp);
    printf("%ld\n",ftell(fp));
    fclose(fp);
    return 0;
}
