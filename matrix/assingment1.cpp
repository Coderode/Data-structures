#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
#include "file1.cpp"
UTM multiply1(DiagonalMatrix a,UTM b)
{
	UTM c(b.n);
	for(int i=0; i<b.n; i++)
	{
		for(int j=i; j<b.n; j++)
		{
			c.a[c.map(i,j)]=a.a[i]*b.a[b.map(i,j)];
		}
	}
	return c;
}
UTM multiply2(UTM b,DiagonalMatrix a)
{
	UTM c(b.n);
	for(int i=0; i<b.n; i++)
	{
		for(int j=i; j<b.n; j++)
		{
			c.a[c.map(i,j)]=b.a[b.map(i,j)]*a.a[j];
		}
	}
	return c;
}

//question number 5 one part lower triangular matrix*upper triangular matrix
Matrix multiply3(LTM a,UTM b)
{
	Matrix c(a.n,a.n);
	for(int i=0; i<a.n; i++)
	{
		for(int j=0; j<a.n; j++)
		{
			c.a[c.map(i,j)]=0;
			if(j>i)
			{
				for(int k=0; k<=i; k++)
				{
					c.a[c.map(i,j)]=c.a[c.map(i,j)]+a.a[a.map(i,k)]*b.a[b.map(k,j)];
				}
			}
			else
			{
				for(int k=0; k<=j; k++)
				{
					c.a[c.map(i,j)]=c.a[c.map(i,j)]+a.a[a.map(i,k)]*b.a[b.map(k,j)];
				}
			}
		}
	}
	return c;
}
//upper * lower triangular matrix
Matrix multiply4(UTM b,LTM a)
{
	Matrix c(a.n,a.n);
	for(int i=0; i<a.n; i++)
	{
		for(int j=0; j<a.n; j++)
		{
			c.a[c.map(i,j)]=0;
			if(j<i)
			{
				for(int k=i; k<a.n; k++)
				{
					c.a[c.map(i,j)]=c.a[c.map(i,j)]+b.a[b.map(i,k)]*a.a[a.map(k,j)];
				}
			}
			else
			{
				for(int k=j; k<a.n; k++)
				{
					c.a[c.map(i,j)]=c.a[c.map(i,j)]+b.a[b.map(i,k)]*a.a[a.map(k,j)];
				}
			}
		}
	}
	return c;
}

int min(int i,int j)
{
	return i<j?i:j;
}
int max(int i,int j)
{
	return i>j?i:j;
}

//for  ltm * utm
Matrix multiply5(LTM a,UTM b)
{
	if(a.n!=b.n)
	 throw ArrayException("Multiplication is not possible!");
		
	Matrix c(a.n,a.n);
	for(int i=0; i<a.n; i++)
	{
		for(int j=0; j<a.n;  j++)
		{
			c.a[c.map(i,j)]=0;
			{
				for(int k=0; k<=min(i,j); k++)
				{
					c.a[c.map(i,j)]=c.a[c.map(i,j)]+a.a[a.map(i,k)]*b.a[b.map(k,j)];
				}
			}
		}
	}
	return c;
}
//for  utm*ltm
Matrix multiply6(UTM b,LTM a)
{
	if(a.n!=b.n)
	 throw ArrayException("Multiplication is not possible!");
	
	Matrix c(a.n,a.n);
	for(int i=0; i<a.n; i++)
	{
		for(int j=0; j<a.n;  j++)
		{
			c.a[c.map(i,j)]=0;
			{
				for(int k=max(i,j); k<a.n; k++)
				{
					c.a[c.map(i,j)]=c.a[c.map(i,j)]+b.a[b.map(i,k)]*a.a[a.map(k,j)];
				}
			}
		}
	}
	return c;
}
int main()
{
	Matrix a(3,3);
	DiagonalMatrix b(3);
	LTM c(3),e(3);
	UTM d(3),f(3);
	//for diagonal and upper matrix multiplication
	b.read();
	b.print();
	d.read();
	d.print();
	cout<<"\nA*B=\n";
	f=multiply1(b,d);
	f.print();
	cout<<"\nB*A=\n";
	f=multiply2(d,b);
	f.print();
	
	
	
 //for upper and lower matrix multiplication	
	c.read();
	c.print();
	d.read();
	d.print();
	cout<<"\nA*B=\n";
	a=multiply5(c,d);     //multiply3
	a.print();
	cout<<"\nB*A=\n";
	a=multiply6(d,c);     //multiply4
	a.print();

	
	getch();
	return 0;
	
	
}


