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
class CLC{
	Node *first;
	public:
		CLC(){first=NULL;}
		bool isEmpty();
		int getSize();
		void insert(int x,int index);
		int del(int index);
		int get(int index);
		int indexof(int x);
		void display();
		void create(int);
		void reverse();
		void circularleftshift(int);
		void circularrightshift(int);
		friend void merge(CLC&,CLC&);
		friend void merge2(CLC&,CLC&);
};
bool CLC::isEmpty()
{
	if(first==NULL)
		return true;
	else 
		return false;
}
int CLC::getSize()
{
	if(first==NULL)
		return 0;
	int sz=1;
	Node *cur=first;
	while(cur->link!=first)
	{
		cur=cur->link;
		sz++;
	}
	return sz;
}
void CLC::insert(int x,int index)
{
	Node *prev,*last;
	if(index<0 or index>getSize()){
		throw Exception("Invalid index");
	}
	Node *nNode=new Node;
	nNode->data=x;
	if(index==0)
	{
		while(last->link!=first)
		{
			last=last->link;
		}
		nNode->link=first;
		first=last->link=nNode;
	}
	prev=first;
	for(int i=1; i<=index-1; i++)
	{
		prev=prev->link;
	}
	nNode->link=prev->link;
	prev->link=nNode;
	
}
int CLC::del(int index)
{
	Node *del,*prev,*last;
	int x;
	if(index<0 or index>=getSize())
	{
		throw Exception("Invalid index");
	}
	if(index==0)
	{
		last=first;
		while(last->link!=first)
		{
			last=last->link;
		}
		del=first;
		x=del->data;
		if(last==first)
		{
			first=NULL;
		}
		else
		{
			first=last->link=del->link;
		}
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
	x=del->data;
	prev->link=del->link;
	del->link=NULL;
	delete del;
	}
	return x;

}
int CLC::get(int index)
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

int CLC::indexof(int x)
{
	int index=-1;
	if(first==NULL)
	{
		return index;
	}
	int i=0; 
	Node *cur=first;
	while(cur->data!=x and cur!=first)
	{
		cur=cur->link;
		i++;
	}
	if(cur->data==x)
		index=i;
	return index;
}
void CLC::display()
{
	Node *cur=first;
	if(first==NULL)
	{
		return;
	}
	cout<<"[";
	while(cur->link!=first)
	{
		cout<<cur->data<<", ";
		cur=cur->link;
	}
	cout<<cur->data<<", ";
	cout<<"\b\b]";
}

void  CLC::create(int n)
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
	cur->link=first;
//	return first;
}
//not ordered merging
void merge(CLC &L1,CLC &L2)
{
	Node *temp=L1.first->link;
	L1.first->link=L2.first->link;
	L2.first->link=temp;
}
//merging at last of L1;
void merge2(CLC &L1,CLC &L2)
{
	Node *cur=L1.first;
	while(cur->link!=L1.first)
	{
		cur=cur->link;
	}
	cur->link=L2.first;
	cur=L2.first;
	while(cur->link!=L2.first)
	{
		cur=cur->link;
	}
	cur->link=L1.first;
}

void CLC::reverse()
{
	Node *prev,*cur,*next;
	if(getSize()<=1)
		return;
	prev=first;                                                                         
    cur=prev->link;	 
	next=cur->link;
	while(cur->link!=first)
	{
		cur->link=prev;
		prev=cur;
		cur=next;
		next=next->link;
	}
	cur->link=prev;
	first->link=cur;
	first=cur;
}
void CLC::circularleftshift(int i)
{
	int n=getSize();
	if(i%n==0)
	{
		return;
	}
	for(int j=1; j<=i%n; j++)
		first=first->link;
}
void CLC::circularrightshift(int i)
{
	int n=getSize();
	if(i%n==0)
	{
		return;
	}
	Node *cur;
	for(int j=1; j<=i%n; j++)
	{
		cur=first;
		while(cur->link!=first)
			cur=cur->link;
		first=cur;	
	}
}
int main()
{
	CLC L1,L2;
	cout<<"for list first:\n";
	L1.create(5);
	L1.display();
	cout<<"\nfor list second:\n";
	L2.create(4);
	L2.display();
	cout<<"\nafter merging the list 1 is:"<<endl;
	merge2(L1,L2);
	L1.display();
	cout<<"\nsize of first link now after merging:"<<L1.getSize()<<endl;
	L1.del(0);
	cout<<"\nafter deleting at index 0:"<<endl;
	L1.display();
	cout<<"\ninsert 100 at index 2 :"<<endl;
	L1.insert(100,2);
	L1.display();
	cout<<"\nreversing the L1:\n";
	L1.reverse();
	L1.display();
	cout<<"\nright circular shift:\n";
	L1.circularrightshift(6);
	L1.display();
	cout<<"\nleft circular shift:\n";
	L1.circularleftshift(6);
	L1.display();
	
	
	getch();
	return 0;	
}
