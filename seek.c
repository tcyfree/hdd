#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 测试ab+ 的seek 的功能
void wa(unsigned char * mode,int addr,char val )
{
    FILE* fp = fopen("info",mode);
    if(fp== 0)
    {
        printf("wa ERROR  mode=%s\r\n",mode);
        return ;
    }
    
    int f_ret=fseek(fp,addr,SEEK_SET);
    if(f_ret!=0)
    {
        printf("fseek ERROR  mode=%s\r\n",mode);
        return ;
    }

    f_ret=fwrite(&val,sizeof(val),1,fp);
    if(f_ret!=1)
    {
        printf("wa write File Error mode=%s \r\n",mode);
        return;
    }
    fclose(fp);
    printf("write File  mode=%s,@%d,=%c\r\n",mode,addr,val);
    printf("hexdump -C info\r\n");
    system("hexdump -C info");
    
}


void Init()
{
    FILE* fp = fopen("info","w+");
    if(fp!= 0)
    {
        char initBuf[]="0123456789";
        int f_ret=fwrite(initBuf,sizeof(initBuf),1,fp);
        if(f_ret!=1)
        {
            printf("Init File Error\r\n");
            return ;
        }
        fclose(fp);
    }
    printf("Init File Success\r\n");
    printf("hexdump -C info\r\n");
    system("hexdump -C info");
}

int main ()
{
    printf("\r\n\r\n\r\n\r\n\r\n#############Test fopen###########\r\n\r\n\r\n");
    Init();
    printf("// ab+ 即使fssek 到中间位置,也是在尾巴写入\r\n");
    wa("ab+",2,'A');
    Init();
     printf("// ab+ 即使fssek 抄出文件尾巴,也是在尾巴写入,不会留空\r\n");
    wa("ab+",100,'A');
    Init();
     printf("// rb+ fssek 到中间,是走文字替换\r\n");
    wa("rb+",2,'A');
    Init();
     printf("// rb+ fssek 超出文件,会留空追加\r\n");
    wa("rb+",100,'A');
    Init();
     printf("// wb+ fssek 超出文件,会留空追加, 提前都会清空文件\r\n");
    wa("wb+",100,'A');
     printf("// wb fssek 超出文件,会留空追加, 提前都会清空文件\r\n");
    Init();
    // wb 是不能读的
    //wa("wb",100,'A');
    return(0);
}