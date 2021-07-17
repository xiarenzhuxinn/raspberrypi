#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#define MAX_ARRAY_SIZE 5000

int num[MAX_ARRAY_SIZE];
int total = 0;
void* myfunc1(void* args){
	if (args != NULL)
	{
		char* specialstr = args;
		printf("Pthread special string: %s\n",specialstr);
	}
	pthread_t pid = pthread_self();
	int i;
	int sum = 0;
	for (i = 0;i < 2500; ++i)
	{
		sum += num[i];
	}
	printf("Child[%ld]: the sum of num[%d] to num[%d] is: %d\n",pid,0,2499,sum);
	total+=sum;
}

void* myfunc2(void* args){
	if (args != NULL)
	{
		char* specialstr = args;
		printf("Pthread special string: %s\n",specialstr);
	}
	pthread_t pid = pthread_self();
	int i;
	int sum = 0;
	for (i = 2500;i < 5000; ++i)
	{
		sum += num[i];
	}
	printf("Child[%ld]: the sum of num[%d] to num[%d] is: %d\n",pid,2500,4999,sum);
	total+=sum;
}

int main(int argc, char const *argv[])
{
	int i;
	srand(time(0));
	for (i = 0;i < MAX_ARRAY_SIZE; ++i){
		num[i] = rand() % 1000;
	}
	int sum = 0;
	pthread_t th1,th2;
	pthread_create(&th1,NULL,myfunc1,"First");
	pthread_create(&th2,NULL,myfunc2,"Second");
	pthread_join(th1,NULL);
	pthread_join(th2,NULL);
	for(i = 0; i < 5000; ++i){
		sum += num[i];
	}
	pthread_t pid = pthread_self();
	printf("Main[%ld]: the sum of num[%d] to num[%d] is: %d\n",pid,0,4999,sum);
	printf("Total is %d\n",total );
	return 0;
}
