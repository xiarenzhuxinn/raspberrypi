#include <stdio.h>
int main()
{
/*	char c1=97,c2=98; //对应26题printf("%d %c\r\n",c1,c2);*/
/*	int x;int y=10;x=y++; //对应27题printf("%d %d\r\n",x,y);*/
//	int j;j=3;printf("%d,",++j);printf("%d\r\n",j++);对应30题
//	int a=12;a+=a-=a*=a;printf("%d\r\n",a);运算结果为0,对应31题
//	int a=9;a+=a-=a+a;printf("%d\n",a);运算为-18,对应37题
//	int a=011;printf("%d\n",++a);运算结果为10,对应40题
//	printf("%d\n",null);编译未通过，对应41题
//	int k=-1;printf("%d,%u\n",k,k);对应42题
//	int k=-8567;printf("|%06d|\n",k);对应44题
//	char ch='a';int k=12;printf("%x,%o,",ch,ch,k);printf("k=%%%d\n",k);三个%%%才为%12;对应45题
//	float a=6.17;unsigned b=323;scanf("%f%o",&a,&b);第47题
//	char a='a'; a--;printf("%d,%c\n",a+'2'-'0',a+'3'-'0');第48题
//	int i,j,k,a=3,b=2;i=(--a==b++)?--a:++b;j=a++;k=b;printf("i=%d,j=%d,k=%d\n",i,j,k);对应51题
//	int a=4,b=2;int c=(a/b*b+a%b);printf("%d\r\n",c);对应53题
//	int i=1,sum=0;while(i<10) {sum=sum+1;i++;printf("i=%d,sum=%d\r\n",i,sum);}对应63题
//	int n;for(n=1;n<=10;n++){if(n%3==0)continue;printf("%d",n);}对应64题
//	int k1=1,k2=2,k3=3,x=15;if (!k1) x--;else if(k2) x=4;else x=3;printf("%d\r\n",x);67题
/*	int num['10'];*///#define size 10 char str1[size],str2[size+2];76题
//	static int a[][]={{1,2,3},{4,5,6}};printf("%d\r\n",a);//77ti
//	static char a[2]={1,2};printf("%s\r\n",a);78ti
//	static char a[3];scanf("%s",a);printf("%c,%c\r\n",a[1],a[2]);79ti
//	char a[10],*p,p=a="china";printf("%s\r\n",p);//	char a[10],*p=a;p="china";printf("%s\r\n",p);
//	int x=2,y=1;if(x>y&&x!=y);
//	int func(int x,int y){return(x+y);}int a=1,b=2,c=3,d=4,e=5;printf("%d\n",func((a+b,b+c,c+a),(d+e)));//94ti
//#define PI 3.1415//	#define S 345//	static char c;//	int max(int x,int y);{ }
//	char a[]="ljx_nb";printf("%3s\r\n",a);//255ti
//	int y[5]={1,2,3,4,5,6};printf("%d\r\n",*(y+4));//268ti
//	int a[3][4]={0},b[4]={1};printf("%d,%d\r\n",b[3],a[1][1]);//283ti
//	int n=5,a[n];printf("%d\r\n",sizeof(a));//285ti
//	int *p1,*p2,m=5,n=4;p1=&m;p2=&n;*p1=*p2;printf("%d\r\n",m);//338ti
//	char *s="beijing";char c[]="Beijing";printf("%s,%s\r\n",c,s);//两者等价342题
//	int aa[8]={0,1,2,3,4,5,6,7};printf("%d,%d,%d\r\n",0[aa],*(0+aa),*(&aa[0]));//对应345题
//	int a,b;scanf("a=%d,b=%d",&a,&b);printf("a=%d,b=%d\r\n",a,b);//397ti
//	void fun(int a,int b,int c){a=456;b=567;c=678;}{int x=10,y=20,z=30;fun(x,y,z);printf("%d,%d,%d\n",z,y,x);}423ti
//	int x=2,y=3;printf("%d\r\n",x||y);424ti
	
//	{int x=1,a=0,b=0;switch(x){case 0:b++;case 1:a++;case 2:a++;b++;}printf("a=%d,b=%d\r\n",a,b);}436ti
//	double a=5.5,b=2.5;printf("%f\r\n",(int)a+b/b);439题
//	double a=5.5,b=2.5;printf("%f\r\n",b);
//	int i,j,k;scanf("%2d%2d%2d",&i,&j,&k);printf("i=%d,j=%d,k=%d\r\n",i,j,k);//440ti


//	/*____EXAMPLE____
//	char a[]={"1235"};
//	char b[10]={'1','2','3','5'};
//	char c[10]={"1235"};
//	char d[]={'1','2','3','5'};
//	char *aa[2]={"abcd","ABCD"};printf("%s\r\n",aa[0]);
//	char *aa[]={"a","b","c","d"};printf("%s\r\n",aa[2]);/*等价//	char ab[]={'a','b','c','d'};printf("%c\r\n",ab[2]);
//	printf("%d %d\r\n",sizeof(a),sizeof(b),sizeof(c),sizeof(d));
//	printf("%d %d\r\n",sizeof(&a),sizeof(&b));
//	printf("%d %d\r\n",sizeof(a),sizeof(b));
//	printf("%c %c\r\n",*(a+1),*(b+2));
//	int k,k=2*4,k*4;//	int a=j=1;printf("%d",a);
//char a,b;	while(a != 6){printf("%c %c\r\n",a,b);}
//	printf("%c %c\r\n",a[1],b[1]);
//	printf("%d %d\r\n",a[1],b[1]);
//
	return 0;
}
