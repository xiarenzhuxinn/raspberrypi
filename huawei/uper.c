#include "stdio.h"
#include "string.h"
char *s,*us; 
 
void uppers(char *s,int num)
{
int i;
for(i=0;i < num + 1; i++){
if(s[i]>='a' && s[i]<='z')
s[i] = s[i]-32;
}
}
int main()
{
int num;
char ss[20];
printf("Please input a string: ");
scanf("%s",ss);
num = strlen(ss);
s = ss;
uppers(s,num);
printf("The result is: %s\n",s);
}
