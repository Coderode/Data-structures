//queue using linkedlist
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

class Node
{
	public:
		int data;
		Node *link;
		
};
class LinkedList{
	Node *first;
	public:
		LinkedList(){first=NULL;}
		bool isEmpty();
		int getSize();
		void insert(int x,int index);
		int del(int index);
		int get(int index);
		void display();
		
};
bool LinkedList::isEmpty()
{
	if(first==NULL)
		return true;
	else 
		return false;
}
int LinkedList::getSize()
{
	int sz=0;
	Node *cur=first;
	while(cur!=NULL)
	{
		sz=sz+1;
		cur=cur->link;
	}
	return sz;
}
void LinkedList::insert(int x,int index)
{
	Node *prev;
	if(index<0 or index>getSize()){
		throw Exception("Invalid index");
	}
	Node *cur=new Node;
	cur->data=x;
	if(index==0)
	{
		cur->link=first;
		first=cur;
	}
	else
	{
		prev=first;
		for(int i=1; i<=index-1; i++)
		{
			prev=prev->link;
		}
		cur->link=prev->link;
		prev->link=cur;		
	}
	
}
int LinkedList::del(int index)
{
	Node *del,*prev;
	int x;
	if(index<0 or index>=getSize())
	{
		throw Exception("Invalid index");
	}
	if(index==0)
	{
		del=first;
		first=del->link;
		x=del->data;
		del->link=NULL;
		delete del;	
	}
	else
	{
		prev=first;
		for(int i=1; i<=index-1; i++)
		{
			prev=prev->link;
		}
	del=prev->link;
	prev->link=del->link;
	x=del->data;
	del->link=NULL;
	delete del;
	}
	return x;

}
int LinkedList::get(int index)
{
	Node *cur;
	if(index<0 or index>=getSize())
	{
		throw Exception("Invalid index");
	}
	cur=first;
	for(int i=1; i<=index; i++)
	{
		cur=cur->link;
	}	
	return cur->data;	
}

void LinkedList::display()
{
	Node *cur=first;
	cout<<"[";
	while(cur!=NULL)
	{
		cout<<cur->data<<", ";
		cur=cur->link;
	}
	cout<<"\b\b]";
}

class Queue{
	LinkedList s;
//	int r,f,length;  //rear and front
	public:
//		Queue(int n)
//		{
//			a=new T[n];
//			r=-1;
//			f=-1;
//			length=n;
//		}
		bool isEmpty();
		int getSize();
		void insert(int x);
		void display();
		int del();
		int getrear();
		int getfront();
};
bool Queue::isEmpty()
{
	return s.isEmpty();
}
int Queue::getSize()
{
	return s.getSize();
}
void Queue::insert(int x)
{
	s.insert(x,s.getSize());
}
int Queue::del()
{
	return s.del(0);
}
void Queue::display()
{
	s.display();
}
int Queue::getrear()
{
	return s.get(s.getSize()-1);
}
int Queue::getfront()
{
	return s.get(0);
} 

int main()
{
	int n=10;
	Queue s;
	for(int i=1; i<=10; i++)
	{
		s.insert(i);	
	}
	s.display();
	s.del();
	cout<<endl;
	s.display();
	cout<<"\nsize of queue:"<<s.getSize();
	cout<<"\ngetfront:"<<s.getfront();
	cout<<"\ngetrear:"<<s.getrear();
	getch();
	return 0;
}

