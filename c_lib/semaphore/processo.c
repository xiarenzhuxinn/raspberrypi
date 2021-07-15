#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    sem_t *sem_test;

    sem_test = sem_open("sem_test_01", O_CREAT, 0644, 0); 
    if(sem_test < 0)
    {   
          printf("create sem error errno=%d\n",errno);
          exit(-1);
    }   

    printf("process TMAC set to waiting……\n");
    printf("This is 1\n");
    sem_wait(sem_test);
    printf("This is 3\n");
    sem_post(sem_test);
    printf("process TMAC GO OVER \n");
    sem_close(sem_test);
    sem_unlink("sem_test_01");

    return 0;
}
