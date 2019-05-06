//infix to postfix 
//evaluate postfix expression

#include<iostream>
#include<conio.h>
#include<math.h>
#include<cstring>
#include<string.h>
#include<string>
//#include<bits/stdc++.h>
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
template <class T>
void  stack<T>::display()
{
	cout<<"[";
	for(int i=tos; i>=0; i--)   ////i=0 to tos i++
	{
		cout<<a[i]<<", ";
	}
	cout<<"\b\b]";
}
template <class T>
T stack<T>::peep(T index)
{
	if(index<0 or index>tos)
	{
		throw Exception("Invalid index");
	}
	return a[tos-index];
}

bool isoperator(char x)
{
	if(x=='+' or x=='-' or x=='*' or x=='%' or x=='/' or x=='^' or x=='=')
	return true;
	else 
	return false;
}


//gettokens
int tn;
string* gettokens(string exp)
{
	tn=-1;
	string *token=new string[30];
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
		else if(exp[i]==' ')
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
	return token;
}

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
	string *x=gettokens(I);   //x=tokens
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
	return p;	 //as a string
}

//just for calculation
float calculate(float x,float y,char c)
{
	switch(c)
	{
		case '-':
			return x-y;
		case '+':
			return x+y;
		case '*':
			return x*y;
		case '/':
			return x/y;
		case '%':
			return int(x)%int(y);
		case '^':
			return pow(x,y);
		default :
			return 0;
	}
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
	return result;		
}

//to evaluate postfix expressions using stack
float Eval(string p)
{	
	string *a=gettokens(p);	
	stack<float> s(tn);
	float x,y;
	for(int i=0; i<=tn; i++)
	{
		if(isoperator(a[i][0])==true)
		{
			y=s.pop();
			x=s.pop();
			s.push(calculate(x,y,a[i][0]));
		}
		else
		{
			s.push(strtofloat(a[i]));
		}
	}
	return s.pop();
}

int main()
{
	string exp;
	cout<<"enter a expression:\n";
	getline(cin,exp);
	
	string postfix=infixTopostfix(exp);
	cout<<"\npost fix form of the expression is:\n"<<postfix;
	cout<<"\nResult of this expression is:\n"<<Eval(postfix);
	
//	cout<<"\nint="<<strtoint("1254")<<endl;

	getch();
	return 0;
}


