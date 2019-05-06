#include<stdio.h>
#include<math.h>
int main()
{
	int n;
	printf("Enter a number:");
	scanf("%d",&n);
	printf("sum of its digits is(fun1): %d\n",sum_digits1(n));
	printf("sum of its digits is(fun2): %d\n",sum_digits2(n));
	printf("sum of its digits is(fun3): %d\n",sum_digits3(n));
//	printf("do you want to continue? (y or n)\n");
//	scanf("%c",)
	getch();
}
int sum_digits1(int n)
{
	int sum=0;
	while(n)
	{
		sum=sum+n%10;
		n=n/10;
	}
	return sum;
}
int sum_digits2(int n)
{
	int m,sum=0,p=1,i;
	m=floor(log10(n))+1;
	
	for(i=1; i<=m; i++)
	{
		sum=sum+(n/p)%10;
		p=10*p;
	}
	return sum;
}
int sum_digits3(int n)
{
	if(n==0)
	return 0;
	else
	return n%10+sum_digits3(n/10);
}
