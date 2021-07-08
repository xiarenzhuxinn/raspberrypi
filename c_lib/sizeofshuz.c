#include <stdio.h>
#include <stdlib.h>
int i=0,a[]={1,2,4,3,1};
int main()
{
while(*(a+i)!='\0')
{
	printf("%d\r\n",*(a+i));
i++;
}
printf("%d\r\n",sizeof(a)/4);
return 0;
}
