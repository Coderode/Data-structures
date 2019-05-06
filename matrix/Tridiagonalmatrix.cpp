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


class TDM{
	float *a;
	int n;
	public:
		TDM(int n){
			this -> n=n;
			a=new float[3*n-2];
		}
		void read();
		void print();
		TDM add(TDM b);
		int map(int,int);
};

int TDM::map(int i,int j)
{
	//using row major order
	return (2*i+j);
	//using col major order
//	return (2*j+i);
	
}
void TDM::read()
{
	cout<<"\nEnter the non -zero elements of "<<n<<"*"<<n<<" tridiagonal matrix\n";
	for(int i=0; i<n; i++)
	{
		if(i!=0 && i!=n-1)
		for(int j=i-1; j<=i+1; j++)
		{
			cout<<"a["<<i<<"]["<<j<<"]=";
			cin>>a[map(i,j)];
		}
		else if(i==0)
		{
			for(int j=0; j<2; j++)
			{
				cout<<"a["<<i<<"]["<<j<<"]=";
				cin>>a[map(i,j)];
			}	
		}
		else if(i==n-1)
		{
			for(int j=n-2; j<=n-1; j++)
			{
				cout<<"a["<<i<<"]["<<j<<"]=";
				cin>>a[map(i,j)];
			}
		}
	}
}
void TDM::print()
{
	cout<<"\nthe tridiagonal matrix is\n";
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(i==j || i==j-1 || i==j+1)
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
TDM TDM::add(TDM b)
{
	TDM c(n);
	for(int i=0; i<n; i++)
	{
		
		if(i!=0 || i!=n-1)
		for(int j=i-1; j<=i+1; j++)
		{
		c.a[map(i,j)]=a[map(i,j)]+b.a[map(i,j)];
		}
		else if(i==0)
		{
			for(int j=0; j<2; j++)
			{
				c.a[map(i,j)]=a[map(i,j)]+b.a[map(i,j)];
			}	
		}
		else if(i==n-1)
		{
			for(int j=n-2; j<=n-1; j++)
			{
				c.a[map(i,j)]=a[map(i,j)]+b.a[map(i,j)];
			}
		}
//		for(int j=0; j<=i; j++)
//		{
//			c.a[map(i,j)]=a[map(i,j)]+b.a[map(i,j)];
//		}
	}
	return c;
}


int main()
{
	TDM a(5),b(5),c(5);
	cout<<"\nfor matrix A:\n";
	a.read();
	a.print();
	
	cout<<"\n for matrix B:\n";
	b.read();
	b.print();
	
	
	c=a.add(b);
	cout<<"\n addition is:\n";
	c.print();

	getch();
	return 0;
}
