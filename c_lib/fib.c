#include <stdio.h>
int main()
{
//NO.1
/*
int count,num,t1=0,t2=1,result=1,display=0;
printf("input num: ");
scanf("%d",&num);
printf("fib: %d %d ",t1,t2);
count =2;
while (count < num)
{
display=t1+t2;
t1=t2;
t2=display;
++count;
result+=display;
printf("%d ",display);
}
printf("result= %d\r\n",result);
return 0;
*/

//NO.1

/*
int Fibon1(int n){
    if (n == 1 || n == 2){
        return 1;
    } else{
        return Fibon1(n - 1) + Fibon1(n - 2);
    }
}
*/

//NO.2
/*
int Fibno2(int n){
    int num1 = 1;
    int num2 = 1;
    int tmp = 0;
    int i = 0;
    if (n < 3){
        return 1;
    }else{
        for (i = 0; i <= n-3; i++){
            tmp = num1 + num2;
            num1 = num2;
            num2 = tmp;
        }
        return tmp;
    }
}
*/

//NO.3
/*
    int Fibon3(int n){
    List<int> list = new List<int>();
    list.fib(1);
    list.fib(1);
    int count = list.Count;
     while (count < n){
                list.fib(list[count - 2] + list[count - 1]);
                 count = list.Count;
          }
         return list[count - 1];
     }
*/
    int n = 0;
    int ret = 0;
    scanf("%d", &n);
    ret = Fibon3(n);
    printf("ret=%d\r\n", ret);
}
