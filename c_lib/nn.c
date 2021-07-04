#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n = 0;
    int i = 0;
    int ret = 1;
    long sum = 0;
    printf("input n: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        ret *= i;//ret=ret*i
        sum += ret;
    }
    printf("n的阶乘和为sum=%ld\n", sum);
    return 0;
}
