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
		int indexof(int x);
		void display();
		void reverse();
		void create(int);
		int indexof2(int x);
		void circularleftshift(int);
		void circularrightshift(int);
		friend void merge(LinkedList&,LinkedList&);
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
int LinkedList::indexof(int x)
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
		cur=cur->link;
	}
	return index;
}
//not good for searching index indexof2
int LinkedList::indexof2(int x)
{
	int index=-1;
	if(first==NULL)
	{
		return index;
	}
	int i=0; 
	Node *cur=first;
	while(cur!=NULL and cur->data!=x)
	{
		cur=cur->link;
		i++;
	}
	if(cur->data==x)
	index=i;
	return index;
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
void LinkedList::reverse()
{
	Node *prev,*cur,*next;
	if(getSize()<=1)
		return;
	prev=first;
    cur=prev->link;	 
	next=cur->link;
	first->link=NULL;
	while(cur!=NULL)
	{
		cur->link=prev;
		prev=cur;
		cur=next;
		if(next!=NULL)
			next=next->link;
	}
//	cur->link=prev;
	first=prev;
}
void LinkedList::create(int n)
{
	Node *cur;
	cout<<endl;
	for(int i=1; i<=n; i++)
	{
		if(i==1)
		{
			first=cur=new Node;  //new returns address//pointers are there to keep address only//
			//first and cur contains the address of present /first node
		}
		else
		{
			cur->link=new Node;  //returns address of next node     linkof current contains add of new node
			cur=cur->link;				//current now contains the add of new node
		}
		cout<<"Enter data"<<i<<":";
		cin>>cur->data;
	}
	cur->link=NULL;
//	return first;
}
void merge(LinkedList &L1,LinkedList &L2)
{
	Node *cur=L1.first;
	while(cur->link!=NULL)
	{
		cur=cur->link;
	}
	cur->link=L2.first;
}
void LinkedList::circularleftshift(int i)
{
	int n=getSize();
	Node *prev,*cur;
	if(i%n==0)
	{
		return;
	}
	for(int j=1; j<=i%n; j++)
	{
		prev=first;
		cur=first;
		while(cur->link!=NULL)
		{
			cur=cur->link;
		}
		cur->link=first;
		first=prev->link;
		prev->link=NULL;
	}	
}
void LinkedList::circularrightshift(int i)
{
	int n=getSize();
	Node *prev,*cur;
	if(i%n==0)
	{
		return;
	}
	for(int j=1; j<=i%n; j++)
	{
		prev=first;
		cur=prev->link;
		while(cur->link!=NULL)
		{
			prev=cur;
			cur=cur->link;
		}
		cur->link=first;
		first=cur;
		prev->link=NULL;
	}
}
int main()
{
	LinkedList L,L2;
	L.create(5);
	L.insert(5,0);
	L.insert(6,1);
	L.insert(9,0);
	cout<<"size="<<L.getSize()<<endl;
	L.display();
	cout<<"\ndeleting value at index 1:\n";
	L.del(1);
	L.display();
	cout<<"\nafter reversing:\n";
	L.reverse();
	L.display();
	cout<<"\nindex of40:\n"<<L.indexof(40);	
	L2.create(4);
	cout<<"\nmerging L1 and L2:\n";
	merge(L,L2);
	L.display();
	cout<<"\nright circular shift:\n";
	L.circularrightshift(2);
	L.display();
	cout<<"\nleft circular shift:\n";
    L.circularleftshift(3);
	L.display();
	
	getch();
	return 0;	
}
