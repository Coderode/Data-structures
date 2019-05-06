#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
class Node
{
	public:
		int data;
		Node *link;
};
Node * create(int n)
{
	Node *first,*cur;
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
	return first;
}
void display(Node *first)
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
int main()
{
	int n;
	cout<<"How many elements?\n";
	cin>>n;
	Node *first=create(n);
	display(first);
	getch();
	return 0;
}
