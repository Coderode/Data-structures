#include<iostream>
#include<conio.h>
#include<math.h>
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

//gcd using stack
int gcd(int m,int n)
{
	stack<int> s1(1),s2(1);
	s1.push(m);
	s2.push(n);
	while(s1.isEmpty()==false)
	{
		m=s1.pop();
		n=s2.pop();
		if(m%n!=0)
		{
			s1.push(n);
			s2.push(m%n);
		}
	}
	return n;
}
//tower of hanoi using stack
void move(int n)
{
	stack<int> s1(n*n);
	stack<char> s2(n*n),s3(n*n),s4(n*n);
	s1.push(n);
	s2.push('A');
	s3.push('B');
	s4.push('C');
	while(s1.isEmpty()==false)
	{
		n=s1.pop();
		char s=s2.pop();
		char i=s3.pop();
		char d=s4.pop();
		if(n>1)
		{
			s1.push(n-1); s2.push(i); s3.push(s); s4.push(d);
			
			s1.push(1); s2.push(s); s3.push(i); s4.push(d);
			
			s1.push(n-1); s2.push(s); s3.push(d); s4.push(i);
		}
		else{
			cout<<"\nmove "<<s<<"->"<<d;
		}
		
	}
}
//factorial using stack 
int fact(int n)
{
	stack<int> s(n-1);
	while(n>1)
	{
		s.push(n);  //s.push(n--)
		n--;
	}
	int f=1;
	while(s.isEmpty()==false)
	{
		f=f*s.pop();
	}
	return f;
}
//sum of digits of a positive number using stack
int sum_digits_of(int n)
{
	int d=floor(log10(n))+1;
	stack<int> s(d);
	int sum=0;
	while(n)
	{
		s.push(n%10);
		n=n/10;
	}
	while(s.isEmpty()==false)
	{
		sum=sum+s.pop();
	}
	return sum;
}
//decimal to binary using stack
int dec_bin(int n)
{
	int d=floor(log2(n))+1,p=1;
	stack<int> s(d);
	while(n)
	{
		s.push(n%2);
		n=floor(n/2);
		p=10*p;
	}
	p=p/10;
	int b=0;
	while(s.isEmpty()==false)
	{
		b=b+p*s.pop();
		p=p/10;
	}
	return b;
}
//dec to octal using stack

int dec_oct(int n)
{
	int d=floor(((log2(n))/3))+1;
	stack<int> s(d);
	int oct,p=1;
	while(n)
	{
		s.push(n%8);
		n=n/8;
		p=p*10;
	}
	p=p/10;
	while(s.isEmpty()==false)
	{
		oct=oct+s.pop()*p;
		p=p/10;
	}
	return oct;
}
//reverse of a number using stack;
int reverse(int n)
{
	int d=floor(log10(n))+1,p=1;
	stack<int> s(d);
	while(n)
	{
		s.push(n%10);
		n=n/10;
	}
	int rev=0;
	while(s.isEmpty()==false)
	{
		rev=rev+s.pop()*p;
		p=p*10;
	}
	return rev;
}
//to get nth fibonacci number 1 1 2 3 5 8 13 ....
int fibonacci(int n)
{
	stack<int> s(n/2+1);
	s.push(n);
	int f=0;
	while(s.isEmpty()==false)
	{
		int n=s.pop();
		if(n>2)
		{
			s.push(n-1);
			s.push(n-2);
		}
		else
		{
			f=f+1;
		}
	}
	return f;
}
int main()
{
	int a=12,b=18;
	
	cout<<"gcd of 12 and 18 is:"<<gcd(a,b)<<endl;
	cout<<"\ntower of hanoi for 3 disks:\n";
	move(3);
	cout<<"\nfact of 5 is:"<<fact(5);
	cout<<"\nsum of digits of 876 is:"<<sum_digits_of(876);
	cout<<"\ndec to bin of 16 is:"<<dec_bin(16);
	cout<<"\ndec to oct of 70 is:"<<dec_oct(70);
	cout<<"\nreverse of 1234 is: "<<reverse(1234);
	cout<<"\nfibonacci 6th is:"<<fibonacci(6);
	getch();
	return 0;
}

