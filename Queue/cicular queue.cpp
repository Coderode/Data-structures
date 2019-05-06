//queue

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
		void insert(T x);
		void display();
		T del();
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
	if(r==-1)
	return 0;
	else if(f<=r)
	return r-f+1;
	else
	return length-f+r+1;
}
template <class T>
void Queue<T>::insert(T x)
{
	if((r+1)%length==f)
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
T Queue<T>::del()
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
	
	int i=f;	
	if(f>r)
	{
	
		do
		{
			cout<<a[i]<<", ";
			i=(i+1)%length;
		}while(i!=r+1);
	}
	cout<<"\b\b]";
	
}

int main()
{
	Queue<int> q(5);
	q.insert(9);  //always insert at rear position (last point of the queue ......)
	q.insert(5);
	q.insert(4);
	q.insert(7);
	cout<<"is Emtpy (Queue):";
	if(q.isEmpty())
	cout<<"true\n";
	else 
	cout<<"false\n";
	
	q.display();
	cout<<"\nsize of queue is:"<<q.getSize()<<endl;
	q.del();  //always delete from front of the queue (first value)
	q.del();
	q.insert(8);
	q.insert(3);
	q.insert(1);
	q.display();
	getch();
	return 0;
	
}
