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
class UTM{
	float *a;
	int n;
	public:
		UTM(int n){
			this -> n=n;
			a=new float[n*(n+1)/2];
		}
		void read();
		void print();
		float det();
		UTM mul(UTM b);
		UTM add(UTM b);
		UTM inverse();
		int map(int,int);
};

int UTM::map(int i,int j)
{
	//using col major order
//	return ((j*(j+1)/2)+i);
	//using row major order
	return (n*i-(i*(i+1)/2)+j);
	
}
void UTM::read()
{
	cout<<"\nEnter the non -zero elements of "<<n<<"*"<<n<<" upper triangular matrix\n";
	for(int i=0; i<n; i++)
	{
		for(int j=i; j<n; j++)
		{
			cout<<"a["<<i<<"]["<<j<<"]=";
			cin>>a[map(i,j)];
		}
	}
}
void UTM::print()
{
	cout<<"\nthe upper tiangular matrix is\n";
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(i<=j)
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
UTM UTM::add(UTM b)
{
	UTM c(n);
	for(int i=0; i<n; i++)
	{
		for(int j=i; j<n; j++)
		{
			c.a[map(i,j)]=a[map(i,j)]+b.a[map(i,j)];
		}
	}
	return c;
}
UTM UTM::mul(UTM b)
{
	if(n!=b.n)
	{
		throw ArrayException("\nMultiplication not possible\n");
	}
	UTM c(n);
	for(int i=0; i<n; i++)
	{
		for(int j=i; j<n; j++)
		{
			for(int k=i; k<=j; k++)
			{
				c.a[map(i,j)]=c.a[map(i,j)]+a[map(i,k)]*b.a[map(k,j)];
			}
		}
	}
	return c;
}
UTM UTM::inverse(){
	
	UTM A(n), B(n);
	for(int i = 0; i < n; i++)
	   for(int j = i; j <= n; j++){
	   	A.a[map(i, j)] = a[map(i, j)];
	   	if(i == j)
	   	   B.a[map(i, j)] = 1;
	   	else
	   	   B.a[map(i, j)] = 0;
	   }
	   
	   
	if(A.det()==0)
	{
		throw ArrayException("\ninverse does not exist\n");
	}
	//A.print();
	//B.print();
	
	for(int i = n-1; i >=1; i--)
	{
		float x = A.a[map(i, i)];
		for(int j = 0; j <= i-1; j++)
		{
			float y = A.a[map(j, i)];
			for(int k = i; k <= n-1; k++)
			{
				A.a[map(j, k)] = A.a[map(j, k)] - A.a[map(i, k)] * y / x;
				B.a[map(j, k)] = B.a[map(j, k)] - B.a[map(i, k)] * y / x;
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
		float x = A.a[map(i,i)];
		for(int k = i; k <n; k++)
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
float UTM::det()
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
	UTM a(3),b(3),c(3),d(3),e(3);
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
	e=d.mul(a);
	e.print();
	

	getch();
	return 0;
}
