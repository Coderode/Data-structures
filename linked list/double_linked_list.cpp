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
		Node *next,*prev;
		
};
class DLL{
	Node *first;
	public:
		DLL(){first=NULL;}
		bool isEmpty();
		int getSize();
		void insert(int x,int index);
		int del(int index);
		int get(int index);
		int indexof(int x);
		void display();
//		void reverse();
		void create(int);
//		int indexof2(int x);
//		void circularleftshift(int);
//		void circularrightshift(int);
//		friend void merge(LinkedList&,LinkedList&);
};

bool DLL::isEmpty()
{
	if(first==NULL)
		return true;
	else 
		return false;
}
void DLL::display()
{
	Node *cur=first;
	cout<<"[";
	while(cur!=NULL)
	{
		cout<<cur->data<<", ";
		cur=cur->next;
	}
	cout<<"\b\b]";
}
int DLL::getSize()
{
	int sz=0;
	Node *cur=first;
	while(cur!=NULL)
	{
		sz=sz+1;
		cur=cur->next;
	}
	return sz;
}

void DLL::insert(int x,int index)
{
	Node *prev,*nNode,*next;
	if(index<0 or index>getSize())
	{
		throw Exception("Invalid index");
	}
	nNode=new Node;
	nNode->data=x;
	if(index==0)
	{
		nNode->next=first;
		nNode->prev=NULL;
		if(first!=NULL)
		{
			first->prev=nNode;
		}
		first=nNode;
	}
	else
	{
		prev=first;
		for(int i=1; i<=index-1; i++)
		{
			prev=prev->next;
		}
		next=prev->next;
		nNode->prev=prev;
		nNode->next=next;
		prev->next=nNode;
		if(next!=NULL)
		{
			next->prev=nNode;
		}
	}
}
void DLL::create(int n)
{
	Node *cur,*next;
	for(int i=1; i<=n; i++)
	{
		if(i==1)
		{
			first=cur=new Node;
		}
		else{
			cur->next=new Node;
			next=cur->next;
			next->prev=cur;
			cur=next;
		}
		cout<<"\nEnter data "<<i<<":";
		cin>>cur->data;
	}
	first->prev=cur->next=NULL;
//	return first;
}
int DLL::del(int index)
{
	Node *next,*del,*prev;
	int x;
	if(index<0 or index>=getSize())
		throw Exception("Invalid index");
	if(index==0)
	{
		del=first;
		x=del->data;
		first=del->next;
		if(first!=NULL)
		{
			first->prev=NULL;
		}
		del->prev=del->next=NULL;
		delete del;
	}
	else{
		prev=first;
		for(int i=1; i<=index-1; i++)
		{
			prev=prev->next;
		}
		del=prev->next;
		next=del->next;
		x=del->data;
		prev->next=next;
		if(next!=NULL)
		{
			next->prev=prev;
		}
		del->prev=del->next=NULL;
		delete del;
	}
	return x;
}
int DLL::indexof(int x)
{
	int index=-1;
	int i=0;
	Node *cur=first;
	while(cur!=NULL)
	{
		if(cur->data==x)
		{
			index=i;
			break;
		}
		i=i+1;
		cur=cur->next;
	}
	return index;
}
int DLL::get(int index)
{
	Node *cur;
	if(index<0 or index>=getSize())
	{
		throw Exception("Invalid index");
	}
	cur=first;
	for(int i=1; i<=index; i++)
	{
		cur=cur->next;
	}	
	return cur->data;	
}
int main()
{
	DLL l;
	l.create(5);
	l.display();
	l.del(0);
	l.display();
	l.insert(32,0);
	l.display();
	cout<<"index 0="<<l.get(0);
	getchar();
	return 0;
}


