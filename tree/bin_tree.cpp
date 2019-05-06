#include<iostream>
#include<conio.h>
#include<cmath>
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
			
	return r-f+1;
}
template <class T>
void Queue<T>::insert(T x)
{
	if(r==length-1)
	{
		throw Exception("Queue is full");
	}
	if(r==-1)
	{
		f=r=0;
	}
	else
	{
		r=r+1;
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
		f++;
	}
	return x;
}
template <class T>
void Queue<T>::display()
{
	if(r==-1)
	throw Exception("queue is empty");
	cout<<"[ ";
	for(int i=f; i<=r; i++)
		cout<<a[i]<<", ";
	cout<<"\b\b]";
	
}
template <class T>
class Stack{
	T *a;
	int tos, length;
	public:
	Stack(int n){
		a = new T[n];
		tos = -1;
		length = n;
	}
	bool isEmpty(){
		if(tos == -1)
		   return true;
		else
		   return false;
	}
	void push(T x){
		if(tos == length - 1) return;
		a[++tos] = x;
	}
	T pop(){
		return a[tos--];
	}
};

int power(int base,int expo)
{
	int i=base;
	if(expo==0)
	return 1;
	for(int j=1; j<expo; j++)
	{
		i=i*base;
	}
	return i;
}

class Binarytree{
	char *a;
	int h;  //height of binary tree
	public:
		Binarytree(int height)
		{
			h=height;
			a=new char[power(2,height)-1];
			for(int i=0; i<=power(2,height); i++)
				a[i]='\0';
		}
		void build(int i)
		{
			char ans;
			if(i==0){
				cout<<"\nEnter root node:";
			}
			else if(i%2==1)
			{
				cout<<"\nEnter left child of the node "<<a[(i-1)/2]<<":";
			}
			else
			{
				cout<<"\nEnter right child of the node "<<a[(i-1)/2]<<":";
			}
			cin>>a[i];
			cout<<"\nDoes "<<a[i]<<" has left child (y/n):";
			cin>>ans;
			if(ans=='y'  and (2*(i+1)-1)< (pow(2,h)-1))
			{
				build(2*(i+1)-1);
			}
			cout<<"\nDoes "<<a[i]<<" has right child (y/n):";
			cin>>ans;
			if(ans=='y'  and (2*(i+1))<(pow(2,h)-1))
			{
				build(2*(i+1));
			}
		}
		void inOrder(int i)
		{
			if((2*(i+1)-1)<(power(2,h)-1) and a[2*(i+1)-1]!='\0')
				inOrder(2*(i+1)-1);
			if(a[i]!='\0')
				cout<<a[i]<<" ";
			if(2*(i+1)< (power(2,h)-1) and a[2*(i+1)]!='\0')
				inOrder(2*(i+1));
		}
		void preOrder(int i)
		{
			if(a[i]!='\0')
				cout<<a[i]<<" ";
			if((2*(i+1)-1)<(power(2,h)-1) and a[2*(i+1)-1]!='\0')
				preOrder(2*(i+1)-1);
			if(2*(i+1)< (power(2,h)-1) and a[2*(i+1)]!='\0')
				preOrder(2*(i+1));	
		}
		void postOrder(int i)
		{
			if((2*(i+1)-1)<(power(2,h)-1) and a[2*(i+1)-1]!='\0')
				postOrder(2*(i+1)-1);
			if(2*(i+1)< (power(2,h)-1) and a[2*(i+1)]!='\0')
				postOrder(2*(i+1));	
			if(a[i]!='\0')
				cout<<a[i]<<" ";
		}
		void levelOrder()
		{
			Queue<int> Q(power(2,h));
			if(a[0]=='\0')
				return;
			Q.insert(0);
			while(Q.isEmpty()==false)
			{
				int i=Q.del();
				cout<<a[i]<<" ";
				if((2*(i+1)-1)<(power(2,h)-1) and a[2*(i+1)-1]!='\0')
				{
					Q.insert(2*(i+1)-1);
				}
				if(2*(i+1)< (power(2,h)-1) and a[2*(i+1)]!='\0')
				{
					Q.insert(2*(i+1));
				}
			}	
		}
		int search(int i,char key);
		void insert(char key,char item);
		void del(char key);
		
};
int Binarytree::search(int i,char key)
{
//	for(int j=0; j<power(2,h); j++)
//	{
//		if(a[j]==key)
//			return j;
//	}
//	return -1;
    if(a[0] == '\0') //Tree is empty
       return -1;
    Stack <int> s(100);
    s.push(i);
    while(s.isEmpty() == false){
	   i = s.pop();
	   if(a[i]==key)
	   {
		   return i;
	   }
	   else{
	   		if((2*(i+1)-1) < (power(2,h)-1) and a[2*(i+1)-1]!='\0')
		    {
			   s.push(2*(i+1)-1);
		    }
	        if(2*(i+1) < (power(2,h)-1) and a[2*(i+1)]!='\0')
		    {
			    s.push(2*(i+1));
		    }
	   }
   }
    return -1;  //if not found
}
void Binarytree::insert(char key,char item)
{
	int i=search(0,key);
	if(i==-1)
	{
//		throw Exception("key not found");
		cout<<"\nkey not found";
		return;
	}
	if(2*(i+1)> power(2,h)-1)
	{
//		throw Exception("there is no space");
		cout<<"\nthere is no space";
		return;
	}
	if(a[2*(i+1)-1]!='\0' and a[2*(i+1)]!='\0')
	{
//		throw Exception("insertion operation failed as key has two children");
		cout<<"\ninsertion operation failed as key has two children already!";
		return;
	}
	else if(a[2*(i+1)-1]=='\0' and a[2*(i+1)]=='\0')
	{
		cout<<"\nDo you want new item as left child (y/n):";
		char ans;
		cin>>ans;
		if(ans=='y')
		{
			a[2*(i+1)-1]=item;
		}
		else{
			a[2*(i+1)]=item;
		}
	}
	else if(a[2*(i+1)-1]=='\0'){
		a[2*(i+1)-1]=item;
	}
	else{
		a[2*(i+1)]=item;
	}
}
void Binarytree::del(char key)
{
	int i=search(0,key);
	if(i==-1)
	{
//		throw Exception("key does not exist");
		cout<<"\nkey does not exist";
		return;
	}
	if(2*(i+1)<(power(2,h)-1) and (a[2*(i+1)-1]!='\0' or a[2*(i+1)]!='\0'))
	{
//		throw Exception("it is not a leaf node");
		cout<<"\nit is not a leaf node";
		return;
	}
	else{
		a[i]='\0';
	}
}

int main()
{
	int h;
	char ans;
	int option;
	do{
	cout<<"\nEnter the height of binary tree:";
	cin>>h;
	Binarytree b(h);
	cout<<"\nbuilding binary tree\n";
	b.build(0);
	cout<<"\ninorder traversing:\n";
	b.inOrder(0);
	cout<<"\npreOrder traversing:\n";
	b.preOrder(0);
	cout<<"\npost order traversing:\n";
	b.postOrder(0);
	cout<<"\nlevel order traversing:\n";
	b.levelOrder();
	
	int flag=1;
	while(flag)
	{
		
		cout<<"\n\n1.search(i,key)\t2.insert(key,item)\t3.del\t4.exit\t5.traversing\nselect option:";
		cin>>option;
		switch(option)
		{
			case 1:
				char key;
				cout<<"\nEnter key to search in the binary tree:";
				cin>>key;
				int index;
				index=b.search(0,key);
				if(index!=-1)
				cout<<key<<" is at index="<<index;
				else
				cout<<"\nkey is not present in tree\n";
				break;
			case 2:
				char item;
				cout<<"\nEnter key and item to insert in the binary tree:";
				cout<<"\nkey=";
				cin>>key;
				cout<<"\nitem=";
				cin>>item;
				b.insert(key,item);
				break;
			case 3:
//				char key;
				cout<<"\nEnter key to delete from binary tree:";
				cin>>key;
				b.del(key);
				break;
			case 5:
				cout<<"\ninorder traversing:\n";
				b.inOrder(0);
				cout<<"\npreOrder traversing:\n";
				b.preOrder(0);
				cout<<"\npost order traversing:\n";
				b.postOrder(0);
				cout<<"\nlevel order traversing:\n";
				b.levelOrder();
				break;
			case 4:
				flag=0;
				break;
			default :
				cout<<"\n wrong choice enter again !\n";
				break;
		}
	}
	cout<<"\nDo you want to continue(y or n):";
	cin>>ans;
	}while(ans=='y');
	getch();
	return 0;	
}
