#include<iostream>
#include<conio.h>
#include<string.h>
#include<math.h>
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

int getMax(int *a,int n)
{
	int max=a[0];
	for(int i=1; i<n; i++)
	{
		if(a[i]>max)
		{
			max=a[i];
		}
	}
	return max;
}
int power(int base,int pow)
{
 	int res=1;
 	if(pow==0)
 	 return 1;
 	
 	for(int i=1; i<=pow; i++)
 	{
 		res=res*base;
	 }
	return res;
}
void Binsort(int *a,int n)
{
	int max=getMax(a,n);
	LinkedList L[max+1];
	for(int i=0; i<=n-1; i++)
	{
		L[a[i]].insert(a[i],0);
	}
	int k=0;
	for(int i=0; i<=max; i++)
	{
		while(L[i].isEmpty()==false)
		{
			a[k]=L[i].del(L[i].getSize()-1);
			k++;
		}
	}	
}
void radix_sort(int *a,int n)
{
	int max=getMax(a,n);
	int d=floor(log10(max)+1)+1;
	LinkedList L[10];
	for(int i=1; i<=d; i++)
	{
		for(int j=0; j<=n-1; j++)
		{
			L[int(a[j]/power(10,i-1)) % 10].insert(a[j],0);
		}
		int k=0;
		for(int j=0; j<10; j++)
		{
			while(L[j].isEmpty()==false)
			{
				a[k]=L[j].del(L[j].getSize()-1);
				k++;
			}
		}
	}
}

int main()
{	
	int a[5]={7893,5,56,1,63};
	Binsort(a,5);
	cout<<endl;
	for(int i=0; i<5; i++)
		{
			cout<<a[i]<<", ";
		}
	
	cout<<"\b\b";
	
	getch();
	return 0;	
}
