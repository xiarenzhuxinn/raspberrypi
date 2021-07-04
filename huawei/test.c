#include <stdio.h>

int main(){
int arr[]={6,7,8,9,10};
int *ptr=arr;

*(ptr++)+=123;

printf("%d,%d,%d\r\n",arr[0],*(++ptr),*ptr);
return 0;
}
