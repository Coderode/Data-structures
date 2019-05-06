//binary treee using linked list
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
		char data;
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

class Binarytree{
	Node *root;
	public:
		Binarytree(){
			root=NULL;
		}
		void build(Node *cur,Node *p);
		void inorder(Node *r);
		void preorder(Node *r);
		void postorder(Node *r);
		int getHeight(Node *cur);
		void levelorder();
		Node * getRoot();
		Node * search(Node *r,char key);
		void insert(char key,char item);
		void del(char key);
};
void Binarytree::build(Node *cur,Node *p)
{
	if(cur==NULL){
		root=new Node;
		cout<<"\nEnter the root node :";
		cur=root;
	}
	else if(cur==p->left){
		cout<<"\nEnter left child of "<<p->data<<" : ";
	}
	else{
		cout<<"\nEnter right child of "<<p->data<<" : ";
	}
	char ans;
	cin>>cur->data;
	cout<<"\nDoes "<<cur->data<<" has left child (y/n) :";
	cin>>ans;
	if(ans=='y')
	{
		cur->left=new Node;
//		p=cur;
//		p=cur->left;
		build(cur->left,cur);
	}
	cout<<"\nDoes "<<cur->data<<" has right child (y/n) :";
	cin>>ans;
	if(ans=='y')
	{
		cur->right=new Node;
//		p=cur;
//		p=cur->right;
		build(cur->right,cur);
	}
}
void Binarytree::inorder(Node *r)
{
	if(r->left!=NULL)
	inorder(r->left);
	
	if(r!=NULL)
	cout<<"[r=" << r <<", r->Left=" <<r->left <<", data="<<r->data<< ", r->right=" << r->right <<"]  ";
	
	if(r->right!=NULL)
	inorder(r->right);
}
void Binarytree::postorder(Node *r)
{
	if(r->left!=NULL)
	postorder(r->left);
	
	if(r->right!=NULL)
	postorder(r->right);
	
	if(r!=NULL)
	cout<<r->data<<"  ";
}
void Binarytree::preorder(Node *r)
{
	if(r!=NULL)
	cout<<r->data<<"  ";
	
	if(r->left!=NULL)
	preorder(r->left);
	
	if(r->right!=NULL)
	preorder(r->right);
}
void Binarytree::levelorder()
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
int Binarytree::getHeight(Node *r)
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
Node * Binarytree::search(Node *r,char key)
{
	cout<<"r.address="<<r<<"  "<<"r.data="<<r->data<<endl;
	if(r == NULL) return NULL;
	Stack <Node *>s(100);
	s.push(r);
	while(s.isEmpty() == false){
		r = s.pop();
		if(r->data==key){
	   	    return r;
	    }
	    else{
		   if(r->left!=NULL)
		     s.push(r->left);
		   if(r->right!=NULL)
		     s.push(r->right);
	    }
   }
    return NULL;
}

Node * Binarytree::getRoot()
{
	return root;
}
void Binarytree::insert(char key,char item)
{
	Node *i=search(NULL,key);
	if(i==NULL)
		throw Exception("key not found");
	if(i->left!=NULL and i->right!=NULL)
		throw Exception("insertion operation failed as key has two children");
	else if(i->left==NULL and i->right==NULL)
	{
		cout<<"\nDo you want new item as left child (y/n) : ";
		char ans;
		cin>>ans;
		if(ans=='y')
			i->left->data=item;
		else
			i->right->data=item;
	}
	else if(i->left==NULL)
		i->left->data=item;
	else
		i->right->data=item;
}
void Binarytree::del(char key)
{
	Node *i=search(NULL,key);
	if(i==NULL)
		throw Exception("key does not exist");
	if(i->left!=NULL or i->right!=NULL)
		throw Exception("it is not a leaf node");
	else
		i=NULL;
}
int main()
{
	Binarytree b;
	char ans;
	int option;
	do{
	cout<<"\nbuilding binary tree\n";
	b.build(NULL,NULL);
	cout<<"\ninorder traversing:\n";
	b.inorder(b.getRoot());
	cout<<"\npreOrder traversing:\n";
	b.preorder(b.getRoot());
	cout<<"\npost order traversing:\n";
	b.postorder(b.getRoot());
	cout<<"\nlevel order traversing:\n";
	b.levelorder();
	Node *root=b.getRoot();	
	int flag=1;
	while(flag)
	{
		
		cout<<"\n\n1.search(i,key)\t2.insert(key,item)\t3.del\t4.getroot\n5.getHeight\t6.exit\nselect option:";
		cin>>option;
		switch(option)
		{
			case 1:
				char key;
				cout<<"\nEnter key to search in the binary tree:";
				fflush(stdin);
				cin>>key;
				Node *index;
				index=b.search(root,key);
//				cout<<"testing index="<<index;
				if(index==NULL)
				cout<<"\nkey is not present in tree\n";
				else
				cout<<key<<" is present at index="<<index;
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
			case 4:
				cout<<"\nThe root node of the tree is: "<<root->data;
				break;
			case 5:
				cout<<"\nThe Height of the tree is: "<<b.getHeight(b.getRoot());
				break;
			case 6:
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
