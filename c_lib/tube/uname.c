#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    pid_t pid;
    int temp;
    int pipedes[2];
    char s[14] = "test message!";
    char d[14];

    if (pipe(pipedes) == -1) // 创建管道
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    if (pid == fork() == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)      // 子进程
    {
        printf("now,write data to pipe\n");
        if (write(pipedes[1], s, 14) == -1)   // 写数据到管道
        {
            perror("write");
            exit(EXIT_FAILURE);
        }
        else
        {
            printf("the written data is:%s\n",s);
            exit(EXIT_SUCESS);
        }
    }
    else if (pid > 0)     // 父进程
    {
        slepp(2);
        printf("now, read from pipe\n");
        if ((read(pipedes[0], d, 14)) == -1)
        {
            perror("read");
            exit(EXIT_FAILURE);
        }
        printf("the data from pipe is:%s\n",d);
    }
    return 0;
}
