#include<iostream>
#include<conio.h>
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

class stack{
	LinkedList s;
	public:
		bool isEmpty();
		int getSize();
		void push(int x);
		int pop();
		int peep(int index);
		void display();
};
bool stack::isEmpty()
{
	return s.isEmpty();
}
int stack::getSize()
{
	return s.getSize();
}
void stack::push(int x)
{
	s.insert(x,0);
}
int stack::pop()
{
	return s.del(0);
}
void  stack::display()
{
	s.display();
}
int stack::peep(int index)
{
	return s.get(index);
}

//factorial using stack 
int fact(int n)
{
	stack s;
	while(n>1)
	{
		s.push(n);  //s.push(n--)
		n--;
	}
	int f=1;
	while(s.isEmpty()==false)
	{
		f=f*s.pop();
	}
	return f;
}
int main()
{
	cout<<"\nfact of 5 is:"<<fact(5);
	getch();
	return 0;	
}


