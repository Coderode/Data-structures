//binary search tree using linked list
#include<iostream>
#include<conio.h>
#include<cmath>
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

class Node{
	public:
		int data;
		Node *left,*right;
		Node()
		{
			left=NULL;
			right=NULL;
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

class Binarysearchtree{
	Node *root;
	public:
		Binarysearchtree(){
			root=NULL;
		}
		void insert(int x);
		void inorder(Node *r);
		void preorder(Node *r);
		void postorder(Node *r);
		int getHeight(Node *cur);
		void levelorder();
		Node * getRoot();
		void del(int x);
		void search(int x);
};
void Binarysearchtree::insert(int x)
{
	if(root==NULL)
	{
		root=new Node;
		root->data=x;
		root->left=root->right=NULL;
	}
	else
	{
		Node *p=NULL;
		Node *cur=root;
		while(cur!=NULL)
		{
			if(x<cur->data)
			{
				p=cur;
				cur=cur->left;
			}
			else if(x==cur->data)
			{
//				throw Exception(x,"already exist");	
				cout<<x<<" already exist!";
				return;
			}
			else
			{
				p=cur;
				cur=cur->right;
			}
		}
		Node *nNode=new Node;
		nNode->left=nNode->right=NULL;
		nNode->data=x;
		if(x<p->data)
		{
			p->left=nNode;
		}
		else
		{
			p->right=nNode;
		}
	}
}
void Binarysearchtree::inorder(Node *r)
{
	if(r->left!=NULL)
	inorder(r->left);
	
	if(r!=NULL)
	cout<<r->data<<"  ";
	
	if(r->right!=NULL)
	inorder(r->right);
}
void Binarysearchtree::postorder(Node *r)
{
	if(r->left!=NULL)
	postorder(r->left);
	
	if(r->right!=NULL)
	postorder(r->right);
	
	if(r!=NULL)
	cout<<r->data<<"  ";
}
void Binarysearchtree::preorder(Node *r)
{
	if(r!=NULL)
	cout<<r->data<<"  ";
	
	if(r->left!=NULL)
	preorder(r->left);
	
	if(r->right!=NULL)
	preorder(r->right);
}
void Binarysearchtree::levelorder()
{
	Node *r;
	Queue<Node*> Q(pow(2,getHeight(root)));
	if(root==NULL)
		return;
	Q.insert(root);
	while(Q.isEmpty()==false)
	{
		r=Q.del();
		cout<<r->data<<"  ";
		if(r->left!=NULL)
		{
			Q.insert(r->left);
		}
		if(r->right!=NULL)
		{
			Q.insert(r->right);
		}
	}
}
int Binarysearchtree::getHeight(Node *r)
{
	if(r==NULL)
		return 0;
	if(getHeight(r->left) > getHeight(r->right))
		return getHeight(r->left)+1;
	else
	{
		return getHeight(r->right)+1;
	}
}
Node * Binarysearchtree::getRoot()
{
	return root;
}
void Binarysearchtree::del(int x)
{
	if(root==NULL)
	{
		cout<<"tree is empty!";   //throw Exception("BStree is empty")
		return;
	}
	Node *r=root,*p=NULL;   //p-add of parent node r-add of the node to be deleted
	
	while(r!=NULL and r->data !=x)
	{
		if(x>r->data)
		{
			p=r;
			r=r->right;
		}
		else
		{
			p=r;
			r=r->left;
		}
	}
	if(r==NULL)
	{
		cout<<"\n"<<x<<" does not exist in this BST\n";
		return;
	}
	if(p==NULL and r->left==NULL and r->right==NULL)
	{
		root=NULL;
		delete r;
	}
	else{
		//case 1 : if r it is leaf node
		if(p!=NULL and r->left==NULL and r->right==NULL){
			if(p->left==r)
				p->left=NULL;
			else
				p->right=NULL;
			delete r;
		}
		//case 2: if r has exactly one child
		else if(p!=NULL and ((r->left==NULL and r->right !=NULL ) or (r->left!=NULL and r->right ==NULL))){
			if(p->left==r)
			{
				if(r->left!=NULL)
					p->left=r->left;
				else
					p->left=r->right;
			}
			else{
				if(r->left!=NULL)
					p->right=r->left;
				else
					p->right=r->right;
			}
		}
		//case3: if r has two childs
		else{
			Node *IP=r->left;   //IP-inorder predecessor
			Node *pIP=r;   //pIP-parent of inorder predecessor
			while(IP->right!=NULL)
			{
				pIP=IP;
				IP=IP->right;
			}
			r->data=IP->data;
			if(IP==pIP->left)
				pIP->left=IP->left;
			else
				pIP->right=IP->left;
			delete IP;
		}
	}
}
void Binarysearchtree::search(int x)
{
	Node *r=root;
	while(r !=NULL and r->data!=x)
	{
		if(x<r->data)
			r=r->left;
		else
			r=r->right;
	}	
	if(r!=NULL)
	{
		cout<<"\n"<<x<<" found in the tree node address= "<<r<<" left="<<r->left<<" right="<<r->right<<" data="<<r->data;
	}
	else
		cout<<"\n"<<x<<" does not exist in the tree\n";
}


int main()
{
	Binarysearchtree b;
	char ans;
	int option;
	do{
	int flag=1;
	while(flag)
	{
		Node *root=b.getRoot();	
		cout<<"\n\n1.search(i,key)\t2.insert(key)\t3.del\t4.getroot\n5.getHeight\t6.traversal\t7.exit\nselect option:";
		cin>>option;
		switch(option)
		{
			case 1:
				int key;
				cout<<"\nEnter key to search in the binary tree:";
				fflush(stdin);
				cin>>key;
				b.search(key);
				break;
			case 2:
				cout<<"\nEnter key to insert in the binary tree:";
				cout<<"\nkey=";
				cin>>key;
				b.insert(key);
				break;
			case 3:
				cout<<"\nEnter key to delete from binary tree:";
				cin>>key;
				b.del(key);
				break;
			case 4:
				
				cout<<"\nThe root node of the tree is: "<<root->data;
				break;
			case 5:
				cout<<"\nThe Height of the tree is: "<<b.getHeight(b.getRoot());
				break;
			case 6:
				cout<<"\ninorder traversing:\n";
				b.inorder(b.getRoot());
				cout<<"\npreOrder traversing:\n";
				b.preorder(b.getRoot());
				cout<<"\npost order traversing:\n";
				b.postorder(b.getRoot());
				cout<<"\nlevel order traversing:\n";
				b.levelorder();
				break;
			case 7:
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
