#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#define MAX_BUFF_SIZE (1024)

int create_big_file(const char * path, int num_gb)
{
    int ret = -1;
    int fd  = -1;
    fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if(fd < 0)
    {
        perror("open");
        return -1;
    }
    
    lseek(fd, num_gb*256LL*1024LL*1024LL-1LL, SEEK_SET);
    write(fd,"",1);

    return 0;
    
}

int main(int argc, const char* argv[])
{
	int ret = 0;
    long long num_gb = 0;
    if(argc < 2)
    {
        fprintf(stderr, "Usage %s <src_file> <num_gb>\n", argv[0]);
        return -1;
    }
    num_gb = atoi(argv[2]);
    
    ret = create_big_file(argv[1], num_gb);
	if(ret != 0)
	{
		fprintf(stderr, "create_big_file error %d\n", ret);
		return ret;
	}
   
    return 0;
}


