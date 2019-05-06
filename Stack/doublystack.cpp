#include<iostream>
#include<conio.h>
#include<math.h>
#include<string.h>
using namespace std;

class Exception{
	char *s;
	public:
		Exception(char *x){
		s = new char[strlen(x) + 1];
		strcpy(s, x);
	}
	friend ostream & operator<<(ostream &abc,Exception obj){
		abc << obj.s;
		return abc;
	}
};

template <class T>
class Dstack{
	int length,tos1,tos2;
	T *a;
	public:
		Dstack(int n)
		{
			length=n;
			tos2=n;
			a=new T[n];
			tos1=-1;
		}
		bool isEmpty(int);
		int getSize(int);
		void push(T x,int i);
		T pop(int);
		void display(int);
};
template <class T>
bool Dstack<T>::isEmpty(int i)
{
	if(tos1==-1 and i==1)
		return true;
	if(tos2==length and i==2)
		return true;
	return false;
}
template <class T>
int Dstack<T>::getSize(int i)
{
	if(i==1)
	{
		return tos1+1;
	}
	if(i==2)
	{
		return length-tos2;
	}
}
template <class T>
void Dstack<T>::push(T x,int i)
{
	if(tos1==tos2-1)
	{
		throw Exception("Dstack is full");
	}
	if(i==1)
	{
		tos1=tos1+1;
		a[tos1]=x;
	}
	if(i==2)
	{
		tos2=tos2-1;
		a[tos2]=x;
	}
}
template <class T>
T Dstack<T>::pop(int i)
{
	T x;
	if((i==1 and tos1==-1) or (i==2 and tos2==length))
	{
		throw Exception("Dstack is empty");
	}
	if(i==1)
	{
		x=a[tos1];
		tos1=tos1-1;
	}
	if(i==2)
	{
		x=a[tos2];
		tos2=tos2+1;
	}
	return x;
}
template <class T>
void  Dstack<T>::display(int i)
{
	if(i==1)
	{
	if(isEmpty(1)==true)
		 throw Exception("stack is empty");
	cout<<"[";
	for(int i=tos1; i>=0; i--)
	{
		cout<<a[i]<<", ";
	}
	cout<<"\b\b]";
	}
	if(i==2)
	{
	if(isEmpty(2)==true)
		 throw Exception("stack is empty");
	cout<<"[";
	for(int i=tos2; i<=length; i++)
	{
		cout<<a[i]<<", ";
	}
	cout<<"\b\b]";
		
	}
}
int main()
{
	Dstack<int> s(10);
	for(int i=1; i<=5; i++)
	{
		s.push(i,1);
	}
	s.push(10,2);
	s.display(1);
	s.display(2);
	getch();
	return 0;
	
}


