#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;

class ArrayException{
	char *s;
	public:
	ArrayException(char *x){
		s = new char[strlen(x) + 1];
		strcpy(s, x);
	}
	friend ostream & operator<<(ostream &abc, ArrayException obj){
		abc << obj.s;
		return abc;
	}
};


class LTM{
	float *a;
	int n;
	public:
		LTM(int n){
			this -> n=n;
			a=new float[n*(n+1)/2];
		}
		void read();
		void print();
		float det();
		LTM mul(LTM b);
		LTM add(LTM b);
		LTM inverse();
		int map(int,int);
};

int LTM::map(int i,int j)
{
	//using row major order
//	return ((i*(i+1)/2)+j);
	//using col major order
//	return (n*j-(j*(j+1)/2)+i);
	//using last row to first row and within row from left to right
	return (n*(n-i-1)-((n-i-2)*(n-i-1)/2)+j);
}
void LTM::read()
{
	cout<<"\nEnter the non -zero elements of "<<n<<"*"<<n<<"lower triangular matrix\n";
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<=i; j++)
		{
			cout<<"a["<<i<<"]["<<j<<"]=";
			cin>>a[map(i,j)];
		}
	}
}
void LTM::print()
{
	cout<<"\nthe lower tiangular matrix is\n";
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(i>=j)
			{
				cout<<a[map(i,j)]<<"\t";
			}
			else
			{
				cout<<"0\t";
			}
		}
		cout<<"\n";
	}
}
LTM LTM::add(LTM b)
{
	LTM c(n);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<=i; j++)
		{
			c.a[map(i,j)]=a[map(i,j)]+b.a[map(i,j)];
		}
	}
	return c;
}
LTM LTM::mul(LTM b)
{
	LTM c(n);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<=i; j++)
		{
			for(int k=j; k<=i; k++)
			{
				c.a[map(i,j)]=c.a[map(i,j)]+a[map(i,k)]*b.a[map(k,j)];
			}
		}
	}
	return c;
}
LTM LTM::inverse(){
	LTM A(n), B(n);
	for(int i = 0; i < n; i++)
	   for(int j = 0; j <= i; j++){
	   	A.a[map(i, j)] = a[map(i, j)];
	   	if(i == j)
	   	   B.a[map(i, j)] = 1;
	   	else
	   	   B.a[map(i, j)] = 0;
	   }
	//A.print();
	//B.print();
	
	for(int i = 0; i < n-1; i++)
	{
		float x = A.a[map(i, i)];
		for(int j = i + 1; j < n; j++)
		{
			float y = A.a[map(j, i)];
			for(int k = 0; k <= i; k++)
			{
				A.a[map(j, k)] = A.a[map(j, k)] - A.a[map(i, k)] * y / x;
				B.a[map(j, k)] = B.a[map(j, k)] - B.a[map(i, k)] * y / x;
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
		float x = A.a[map(i,i)];
		for(int k = 0; k <= i; k++)
		{
			A.a[map(i, k)] = A.a[map(i, k)] / x;
			B.a[map(i, k)] = B.a[map(i, k)] / x;
		}
	}
//	cout <<"Matrix A\n";
//	A.print();
//       cout <<"Inverse Matrix\n";
//       B.print();
   return B;
}
float LTM::det()
{
	float d=1;
	for(int i=0; i<n; i++)
	{
		d=d*a[map(i,i)];
	}
	return d;
}

int main()
{
	LTM a(3),b(3),c(3),d(3);
	cout<<"\nfor matrix A:\n";
	a.read();
	a.print();
	cout<<"\ndeterminant of matrix A is:"<<a.det()<<endl;
	cout<<"\n for matrix B:\n";
	b.read();
	b.print();
	cout<<"\ndeterminant of matrix B is:"<<b.det()<<endl;
	cout<<"\nproduct is:\n";
	c=a.mul(b);
	c.print();
	c=a.add(b);
	cout<<"\n addition is:\n";
	c.print();
	cout<<"\n for inverse of matrix A:\n";
	d=a.inverse();
	d.print();
	

	getch();
	return 0;
}
