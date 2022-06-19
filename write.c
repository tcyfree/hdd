#include<stdio.h>
 
#include<sys/io.h>
 
#include<fcntl.h>
 
#include<string.h>
 
int main(void){
 
   int fd=open("./a.txt",O_RDWR+O_CREAT);
 
   if(fd==-1){
 
      printf("can not open the file\n");
 
      return 1;
 
   }
 
   char buf[1024]={"I love www.dotcpp.com very much!"},buf2[1024]={"\0"};
 
   int len=write(fd,buf,strlen(buf));
 
   lseek(fd,0,SEEK_SET);
 
   int len2=read(fd,buf2,1024);
 
   printf("%s\nlen=%d\n",buf2,len);
 
   close(fd);
 
   return 0;
 
}