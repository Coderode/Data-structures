#include<iostream>
#include<conio.h>
#include<cstring>
#include<string.h>
#include<math.h>
#include<string>
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

class Node{
	public:
		Node *left,*right;
		string data;  //data - token may be operand or operator
		Node()
		{
			left=NULL;
			right=NULL;
		}		
};
template <class T>
class stack{
	T *a;
	int length,tos;
	public:
		stack(int n)
		{
			length=n;
			a=new T[n];
			tos=-1;
		}
		bool isEmpty();
		int getSize();
		void push(T x);
		T pop();
		T peep(T index);
		void display();
};
template <class T>
bool stack<T>::isEmpty()
{
	if(tos==-1)
		return true;
	else
		return false;
}
template <class T>
int stack<T>::getSize()
{
	return tos+1;
}
template <class T>
void stack<T>::push(T x)
{
	a[++tos]=x;
}
template <class T>
T stack<T>::pop()
{
	return a[tos--];
}
bool isoperator(char x)
{
	if(x=='+' or x=='-' or x=='*' or x=='%' or x=='/' or x=='^' or x=='=')
	return true;
	else 
	return false;
}
//string to int
int strtoint(string s)
{
	int l=s.length();
	int result;
	int p=1;
	for(int i=l-1; i>=0; i--)
	{
		result=result+p*(s[i]-48);
		p=p*10;
	}
	return result;
}
//string to float
float strtofloat(string s)
{
	int l=s.length();
//	cout<<"\ns="<<s;
	float result=0;
	int dl=0;    //length upto decimal point
	float p=1,d=1; 
	for(int i=0; i<l; i++)
	{
		if(s[i]=='.')
			break;
		else
			dl++;
		p=p*10;
	}
	p=p/10;
	for(int i=0; i<dl; i++)
	{
			result=result+p*(s[i]-48);
			p=p/10;
	}
	for(int i=dl+1; i<l; i++)
	{
			d=d/10;
			result=result+d*(s[i]-48);
	}
//	cout<<"\nresu="<<result;
	return result;		
}
int tn;
string* gettokens1(string exp)
{
	tn=-1;
	string *token=new string[50];
	int flag1=0,flag2=0;
	int n=exp.length();
	for(int i=0; i<n; i++)
	{	
		if(exp[i]!=' ' and exp[i]!='-' and exp[i]!='+' and exp[i]!='*' and exp[i]!='/' and exp[i]!='%' and exp[i]!='(' and exp[i]!=')')
		{
			if(flag1==0)
				tn++;
			token[tn]=token[tn]+exp[i];
			flag1=1;
			flag2=1;
		}
		else if(exp[i]==' ')// or exp[i]=='(' or exp[i]==')')
		{
			flag1=0;
		}	
		else
		{
			if(flag1==0 or flag2==1)
				tn++;
			token[tn]=exp[i];
			flag1=0;
		}
				
	}
	token[n]="\0";
	return token;
}
string* gettokens2(string exp)
{
	int tn=-1;
	string *token=new string[50];
	int flag1=0,flag2=0;
	int n=exp.length();
	for(int i=0; i<n; i++)
	{	
		if(exp[i]!=' ' and exp[i]!='-' and exp[i]!='+' and exp[i]!='*' and exp[i]!='/' and exp[i]!='%' and exp[i]!='(' and exp[i]!=')')
		{
			if(flag1==0)
				tn++;
			token[tn]=token[tn]+exp[i];
			flag1=1;
			flag2=1;
		}
		else if(exp[i]==' ' or exp[i]=='(' or exp[i]==')')
		{
			flag1=0;
		}	
		else
		{
			if(flag1==0 or flag2==1)
				tn++;
			token[tn]=exp[i];
			flag1=0;
		}
				
	}
	token[n]="\0";
	return token;
}

//just for calculation
string calculate(string p,string q,char opr)
{
	float x=strtofloat(p);
	float y=strtofloat(q);
//	cout<<"\nx="<<x;
//	cout<<"\ny="<<y;
	float res;
	string result="\0";
	switch(opr)
	{
		case '-':
			res=x-y;
			break;
		case '+':
			res=x+y;break;
		case '*':
			res= x*y; break;
		case '/':
			res=x/y; break;
		case '%':
			res= int(x)%int(y); break;
		case '^':
			res= pow(x,y);break;
		default :
			return result;
	}
//	cout<<"\nres="<<res;
	result=to_string(res);
//	cout<<"\nresult="<<result<<endl;
	return result;
}



class Exp_Tree{
	Node *root;
	public:
		Exp_Tree()
		{
			root=NULL;
		}
		Node * getroot()
		{
			return root;
		}
		//for post to expression tree (converting to tree only)
		void expr_tree(string *p)   //return type string
		{
			for(int i=0; p[i]!="\0"; i++)
			cout<<"\np="<<p[i];
			stack<Node*> s(20);
			for(int i=0; p[i]!="\0"; i++)
			{
				string t=p[i];
				if(isoperator(t[0]))
				{
					Node *nNode=new Node;
					nNode->data=t;
					nNode->right=s.pop();
					nNode->left=s.pop();
					s.push(nNode);
				}
				else{
					Node *nNode=new Node;
					nNode->data=t;
					nNode->left=nNode->right=NULL;
					s.push(nNode);
				}
			}
			root=s.pop();  //return address of root node at last  return s.pop()
		}
		//for evaluation of the postfix formed expression
		string expr_eval(Node *root)   //argument root
		{
			if(root!=NULL)
			{
				Node * lptr=root->left;
				Node * rptr=root->right;
				string T1,T2,val;
				if(lptr!=NULL and isoperator(lptr->data[0]))
				{
					T1=expr_eval(lptr);
				}
				else{
					T1=lptr->data;
					cout<<"\nT1="<<T1;
				}
				if(rptr!=NULL and isoperator(rptr->data[0]))
				{
					T2=expr_eval(rptr);
				}
				else{
					T2=rptr->data;
					cout<<"\nT2="<<T2;
				}
				char opr=root->data[0];  //opr-operator
				cout<<"\nopr="<<opr;
				val=calculate(T1,T2,opr);
				return val;
			}
		}
		void levelorder()
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
		int getHeight(Node *r)
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
		void inorder(Node *r)
		{
			if(r->left!=NULL)
			inorder(r->left);
			
			if(r!=NULL)
			cout<<r->data<<"  ";
			
			if(r->right!=NULL)
			inorder(r->right);
		}
		void postorder(Node *r)
		{
			if(r->left!=NULL)
			postorder(r->left);
			
			if(r->right!=NULL)
			postorder(r->right);
			
			if(r!=NULL)
			cout<<r->data<<"  ";
		}
		void preorder(Node *r)
		{
			if(r!=NULL)
			cout<<r->data<<"  ";
			
			if(r->left!=NULL)
			preorder(r->left);
			
			if(r->right!=NULL)
			preorder(r->right);
		}
				
};
int precedence(char x)
{
	if(x=='+')
	return 1;
	else if(x=='-')
	return 2;
	else if(x=='*' or x=='/')
	return 4;
	else if(x=='%')
	return 3;
	else if(x=='=')
	return 0;
	else if(x=='^')
	return 5;
	else 
	return -1;
}
//infix to postfix
string infixTopostfix(string I)
{
	stack<char> s(10);
	char y;
	int flag;
	string p;   //p==postfix expression
	I=I+')';
	s.push('(');
	string *x=gettokens1(I);   //x=tokens
//	cout<<"\ntn in itof:"<<tn<<endl;
	for(int i=0; i<=tn; i++)
	{
		if(x[i][0]=='(')
		{
			s.push(x[i][0]);
		}
		else if(x[i][0]==')')
		{
			y=s.pop();
		while(y!='(')
		{
			p=p+y+' ';
			y=s.pop();
		}
		}
		else if(isoperator(x[i][0])==true)
		{
			y=s.pop();
			flag=0;
			if(isoperator(y)==true and precedence(y)>=precedence(x[i][0]))
			{
				p=p+y+' ';
				flag=1;
			}
			if(flag==0)
			s.push(y);
			
			s.push(x[i][0]);
		}
		else
		{
			p=p+x[i]+' ';
		}
	}
	cout<<"\npostfix="<<p<<endl;
	return p;	 //as a string
}


int main()
{
	string exp,exp2;
	string result;
	Exp_Tree T;
	cout<<"\nEnter the mathematical expression: ";
	fflush(stdin);
	getline(cin,exp);
	fflush(stdin);
	exp2=infixTopostfix(exp);
	string *token=gettokens2(exp2);

	T.expr_tree(token);
	cout<<"\nlevel order tracing:="<<endl;
	T.levelorder();
	result=T.expr_eval(T.getroot());
	cout<<"\nFinal result= "<<result;
	getch();
	return 0;	
	
}
