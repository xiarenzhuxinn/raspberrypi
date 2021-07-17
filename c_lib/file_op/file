#include <stdio.h>
#include <string.h>
 
int main()
{
   FILE *fp;
   int ch,cr,len;
   char c[] = "This is runoob";
   char buffer[20];
 
   /* 打开文件用于读写 */
   fp = fopen("file.txt", "w+");
 
   /* 写入字符串数据到文件 */
   fwrite(c, strlen(c) + 1, 1, fp);
 
   /* 查找文件的开头 */
   fseek(fp, 0, SEEK_SET);
 
   /* 读取字符串并显示数据 */
   fread(buffer, strlen(c)+1, 1, fp);
   printf("%s\n", buffer);
 
   /* 查找文件结尾 */
   fseek(fp, 0, 2);
 
   /*读取文件总字节数*/
   len = ftell(fp);
   printf("文件的总大小: %d\n",len);
 
   /*写入字符数据到文件*/
   for( ch = 33 ; ch <= 100; ch++ )
   {
      fputc(ch, fp);
   }
 
   /*将文件指针调整到开头*/
   rewind(fp);
 
   /* 读字符数据 */
   while(1)
   {
      cr = fgetc(fp);
      if( feof(fp) )
      {
          break ;
      }
      printf("%c", cr);
   }
   fclose(fp);
   return(0);
}
