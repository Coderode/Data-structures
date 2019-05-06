#include<iostream>
#include<conio.h>
using namespace std;

int n;

int min(int i,int j)
{
	return i<j?i:j;
}
int max(int i,int j)
{
	return i>j?i:j;
}

//read upper tirangular matrix
void printmatrix(int **a)
{
	cout<<"\nmatrix=\n";
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout<<a[i][j]<<"\t";
		}
		cout<<"\n";
	}
}
int ** readmatrix()
{
	int **a=new int*[n];
	for(int i=0; i<n; i++)
	 a[i]=new int[n];
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout<<"a["<<i+1<<"]["<<j+1<<"]=";
			cin>>a[i][j];
		}
	}
	return a;	
}

//for ltm
int ** readltm()
{
	int **a=new int*[n];
	for(int i=0; i<n; i++)
	 a[i]=new int[n];
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(i<j)
			{
				a[i][j]=0;
			}
			else
			{
			cout<<"a["<<i+1<<"]["<<j+1<<"]=";
			cin>>a[i][j];
			}
		}
	}
	return a;	
}
//for utm
int ** readutm()
{
	int **a=new int*[n];
	for(int i=0; i<n; i++)
	 a[i]=new int[n];
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(i>j)
			{
				a[i][j]=0;
			}
			else
			{
			cout<<"a["<<i+1<<"]["<<j+1<<"]=";
			cin>>a[i][j];
			}
		}
	}
	return a;	
}

//multiply ltm*utm
int ** mul_ltm_utm(int **a,int **b)
{
//	if(a.n!=b.n)
////	return 0;
//	 throw ArrayException("Multiplication is not possible!");
	int **c=new int*[n];
	for(int i=0; i<n; i++)
	 c[i]=new int[n];	
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n;  j++)
		{
			c[i][j]=0;
		
				for(int k=0; k<=min(i,j); k++)
				{
					c[i][j]=c[i][j]+a[i][k]*b[k][j];
				}
		
		}
	}
	return c;
	
}

//multiply utm*ltm
int ** mul_utm_ltm(int **b,int **a)
{
//	if(a.n!=b.n)
////	return 0;
//	 throw ArrayException("Multiplication is not possible!");
	int **c=new int*[n];
	for(int i=0; i<n; i++)
	 c[i]=new int[n];	
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n;  j++)
		{
			c[i][j]=0;
		
				for(int k=max(i,j); k<n; k++)
				{
					c[i][j]=c[i][j]+b[i][k]*a[k][j];
				}
		
		}
	}
	return c;
	
}
int main()
{
	cout<<"enter the size of matrix(n*n)=";
	cin>>n;	
	int **a,**b,**c;
	cout<<"\nLower tiangular matirx A:\n";
	a=readltm();
	printmatrix(a);
	cout<<"\nUpper tiangular matirx B:\n";
	b=readutm();
	printmatrix(b);
	cout<<"\nA*B=\n";
	c=mul_ltm_utm(a,b);
	printmatrix(c);
    cout<<"\nB*A=\n";
	c=mul_utm_ltm(b,a);
	printmatrix(c);
	getch();
	return 0;
	
	
}
