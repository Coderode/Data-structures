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
class Queue{
	T *a;
	int r,f,length;  //rear and front
	public:
		Queue(int n)
		{
			a=new T[n];
			r=-1;
			f=-1;
			length=n;
		}
		bool isEmpty();
		int getSize();
		void insertrear(T x);
		void insertfront(T x);
		
		void display();
		T delrear();
		T delfront();
};
template <class T>
bool Queue<T>::isEmpty()
{
	if(r==-1)
	return true;
	else 
	return false;
}
template <class T>
int Queue<T>::getSize()
{
	if(r==-1 )
	return 0;
			
	return (length-f+r)%length+1;
}
template <class T>
void Queue<T>::insertfront(T x)
{
	if((r+1)%length==f)
	{
		throw Exception("Queue is full");
	}
	if(f==-1)
	{
		f=r=0;
	}
	else if(f==0)
	{
		f=length-1;
	}
	else
	{
		f=f-1;
	}
	a[f]=x;
}
template <class T>
void Queue<T>::insertrear(T x)
{
	if((f-1)%length==r)
	{
		throw Exception("Queue is full");
	}
	if(r==-1)
	{
		f=r=0;
	}
	else
	{
		r=(r+1)%length;
	}
	a[r]=x;
}
template <class T>
T Queue<T>::delrear()
{
	if(r==-1)
	{
		throw Exception("Queue is empty");
	}
	T x=a[r];
	if(r==f)
	{
		r=f=-1;
	}
	else if(r==0)
	{
		r=length-1;
	}
	else
	{
		r=r-1;
	}
	return x;
}
template <class T>
T Queue<T>::delfront()
{
	if(f==-1)
	{
		throw Exception("Queue is empty");
	}
	T x=a[f];
	if(r==f)
	{
		r=f=-1;
	}
//	else if(r==0)
//	{
//		r=length-1;
//	}
	else
	{
		f=(f+1)%length;
	}
	return x;
}
template <class T>
void Queue<T>::display()
{
	if(r==-1)
	throw Exception("queue is empty");
	cout<<"[ ";
	if(f<=r)
	for(int i=f; i<=r; i++)
		cout<<a[i]<<", ";
	
		
	if(f>r)
	{
		int i=f;
		while(i!=r)	
		{
			cout<<a[i]<<", ";
			i=(i+1)%length;
		}
		cout<<a[r]<<" ,";
	}
	cout<<"\b\b ]";
	
}
int main()
{
	Queue<int> q(10);
	q.insertfront(1);
	q.insertrear(10);
	q.insertfront(2);
	q.insertrear(20);
	q.insertfront(3);
	q.insertrear(30);
	q.display();
	cout<<"\nsize="<<q.getSize();
	q.delfront();
	q.display();
	q.delrear();
	q.display();
	getch();
	return 0;
}
