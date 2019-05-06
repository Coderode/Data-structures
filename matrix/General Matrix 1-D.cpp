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


class Matrix{
	float *a;
	int m,n;
	public:
		Matrix(int m,int n){
			this -> n=n;
			this -> m=m;
			a=new float[m*n];
		}
		void read();
		void print();
		Matrix mul(Matrix b);
		Matrix add(Matrix b);
		int map(int,int);
};

int Matrix::map(int i,int j)
{
	//using row major order
	return (n*i+j);
	//using col major order
//	return (m*j+i);
}
void Matrix::read()
{
	cout<<"\nEnter the elements of "<<m<<"*"<<n<<" matrix\n";
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout<<"a["<<i<<"]["<<j<<"]=";
			cin>>a[map(i,j)];
		}
	}
}
void Matrix::print()
{
	cout<<"\nthe matrix is\n";
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{	
			cout<<a[map(i,j)]<<"\t";
		}
		cout<<"\n";
	}
}
Matrix Matrix::add(Matrix b)
{
	if(m!=b.m && n!=b.n)
		{
			throw ArrayException("Addition is not possbile!");
		}
	Matrix c(m,n);
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			c.a[map(i,j)]=a[map(i,j)]+b.a[map(i,j)];
		}
	}
	return c;
}
Matrix Matrix::mul(Matrix b)
{
	if(n!=b.m)
	throw ArrayException("Multiplication is not possible!");
	Matrix c(m,b.n);
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			c.a[map(i,j)]=0;
			for(int k=0; k<n; k++)
			{
				c.a[map(i,j)]=c.a[map(i,j)]+a[map(i,k)]*b.a[map(k,j)];
			}
		}
	}
	return c;
}


int main()
{
	Matrix a(3,3),b(3,3),c(3,3),d(3,3);
	cout<<"\nfor matrix A:\n";
	a.read();
	a.print();
	cout<<"\n for matrix B:\n";
	b.read();
	b.print();
	cout<<"\nproduct is:\n";
	c=a.mul(b);
	c.print();
	d=a.add(b);
	cout<<"\n addition is:\n";
	d.print();
	

	getch();
	return 0;
}

