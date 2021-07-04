#include "stdio.h"
char *s,*us; 
 
void uppers(char *s,char *us)
{
for(;*s!='\0';s++,us++)
{
if(*s>='a'&&*s<='z')
*us = *s-32;
else
*us = *s;
}
*us ='\0';
}
int main()
{
char ss[20];
printf("Please input a string: ");
scanf("%s",ss);
s = ss;
uppers(s,us);
printf("The result is: %s\n",us);
}
