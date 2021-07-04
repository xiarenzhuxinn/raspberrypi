#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main() {
    char str1[30], str2[30],*sr1=str1,*sr2=str2;
    int rtn1,rtn2;
    printf("请输入目的字符串：\n");
    scanf("%s",sr1);
    printf("请输入源字符串：\n");
    scanf("%s",sr2);
    printf("输出目的字符串：%s\n",sr1);
    printf("输出源字符串：%s\n",sr2);
    //strcpy(str1, str2);
    strcat(sr1, sr2);
    //rtn=strcmp(str1,str2);
    rtn1=sizeof(str1);
    rtn2=strlen(sr1);
    //strupr(str1);
    //strlwr(str1);
    printf("调用函数后目的字符串：%s\n",sr1);
    printf("调用函数后目的结果：%d %d\n",rtn1,rtn2);
    //free(sr1);
    //free(sr2);
}
