#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<errno.h>
#include<sys/stat.h>
#include<fcntl.h>


int main()
{
    sem_t *sem_test;

    sem_test = sem_open("sem_test_01",0);

    if(sem_test < 0)
    {
        printf("process Paul creat sem error errno=%d\n",errno);
        exit(-1);
    }

    printf("process Paul 2\n");
    sem_post(sem_test);
    printf("process Paul GO OVER！\n");
    sem_close(sem_test);
    sem_unlink("sem_test_01");
    return 0;
}
