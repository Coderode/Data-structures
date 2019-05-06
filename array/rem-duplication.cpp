#include<iostream>
#include<string.h>
#include<conio.h>
using namespace std;

class ArrayException{
	char *s;
	public:
		ArrayException(char *x){
			s = new char[strlen(x) + 1];
			strcpy(s, x);
		}
		friend ostream &operator<<(ostream &abc, ArrayException a){
			abc << a.s;
			return abc;
		}
};

class Array{
	int *a, length, size;
	public:
		Array(int n);
		int getSize();
		void insert(int x, int idex);
		int del(int index);
		void display();
};

Array::Array(int n){
	length = n;
	a = new int[n];
	size = 0;
}

void Array::insert(int x, int index){
	if(index < 0 || index > size){
		throw ArrayException("Invalid index in insertion operation");
	}
	for(int i = size - 1; i >= index; i--)
	   a[i+1] = a[i];
	a[index] = x;
	size++;
}

void Array::display(){
	cout <<"[";
	for(int i = 0;  i < size; i++)
	   cout <<a[i] <<", ";
	cout <<"\b\b]";
}
int Array::getSize()
{
	return size;
}
int Array::del(int index)
{
//	cout<<"index="<<index<<"size="<<size;
	if(index<0 || index>=size)
		throw ArrayException("Invalid in deletion operation");
		int x=a[index];
		for(int i=index; i<size-1; i++)
			a[i]=a[i+1];
			size--;
			return x;
}
//for 12233344444..........
//using minimum movements operations
void getPattern1(Array &a,int n)
{
//	a.display();
	for(int i=1; i<=n; i++)
	for(int j=1; j<=i; j++)
	 {
	 	a.insert(i,a.getSize());
	 }
	 a.display();
}
//using maximum movements operations
void getPattern2(Array &a,int n)
{
	for(int i=n; i>=1; i--)
	for(int j=1; j<=i; j++)
	 {
	 	a.insert(i,0);
	 }
	 a.display();
}
//remove duplicates using min remove operations
void delete_dup1(Array &a,int n)
	{
		cout<<"\nInside duplicate remove function"<<endl;
		a.display();
		cout<<endl;
		for(int i=1; i<=n-1; i++)
		for(int j=1; j<=n-i; j++)
		{
			a.del(a.getSize()-i);
		}
		cout<<"After remove of elements using minimum remove operation"<<endl;
		a.display();
		cout<<endl;
	}
//remove duplicates using max remove operations
void delete_dup2(Array &a,int n)
{
	cout<<"\nInside duplicate remove function"<<endl;
	a.display();
	cout<<endl;
	for(int i=1; i<=n-1; i++)
	for(int j=1; j<=i; j++)
	{
		a.del(i);
	}
	cout<<"After remove of elements using max remove operation"<<endl;
	a.display();
	cout<<endl;
}
//for 122223333333334444444444444444...............
//using minimum movements operations
void getPattern3(Array &a,int n)
{
	for(int i=1; i<=n; i++)
	for(int j=1; j<=i*i; j++)
	 {
	 	a.insert(i,a.getSize());
	 }
	 a.display();
}
//using maximum movements operations
void getPattern4(Array &a,int n)
{
	for(int i=n; i>=1; i--)
	for(int j=1; j<=i*i; j++)
	 {
	 	a.insert(i,0);
	 }
	 a.display();
}
//remove duplicates using min remove operations
void delete_dup3(Array &a,int n)
	{
		cout<<"\nInside duplicate remove function"<<endl;
		a.display();
		cout<<endl;
		for(int i=1; i<=n-1; i++)
		for(int j=1; j<=(n-i+1)*(n-i+1)-1; j++)
		{
			a.del(a.getSize()-i);
		}
		cout<<"After remove of elements using minimum remove operation"<<endl;
		a.display();
		cout<<endl;
	}
//remove duplicates using max remove operations
void delete_dup4(Array &a,int n)
{
	cout<<"\nInside duplicate remove function"<<endl;
	a.display();
	cout<<endl;
	for(int i=1; i<=n-1; i++)
	for(int j=1; j<=(i+1)*(i+1)-1; j++)
	{
		a.del(i);
	}
	cout<<"After remove of elements using max remove operation"<<endl;
	a.display();
	cout<<endl;
}


int main()
{
int n;
cout<<"Enter the value of n:"<<endl;
cin>>n;
Array b(n*(n+1)/2),c((n*(n+1)*(2*n+1))/6);
//for 1223334444.......
getPattern2(b,n);
delete_dup2(b,n);
//for 12222333333333....
getPattern4(c,n);
delete_dup4(c,n);
getch();
}
