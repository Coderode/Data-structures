#include<iostream>
#include<conio.h>
#include<math.h>
#include<cstring>
#include<string.h>
#include<string>
#include <fstream>
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

bool paranthesis_matching(string line)
{
	string *a=gettokens(line);
	stack<char> s(tn);
	for(int i=0; i<=tn; i++)
	{
		if(a[i][0]=='(')
		s.push(a[i][0]);
		else if(a[i][0]==')')
		{
			if(s.isEmpty()==true)
			{
				cout<<"\nUnbalanced Paranthesis!"<<endl;
				return false;
//			throw Exception("stack is empty");
			}
			s.pop();
		}
	}	
	if(s.isEmpty()==true)
	{
	cout<<"\nBalanced Paranthesis!\n";
	return true;
	}
	else
	{
	cout<<"\nUnbalanced Paranthesis!"<<endl;
	return false;	
	}
}
int main()
{
  string line;
  ifstream myfile ("expression(parn_matching).txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      cout << line << '\n';
      if(!paranthesis_matching(line))
      	break; 
    }
    myfile.close();
  }

  else cout << "Unable to open file"; 
  getch();
  return 0;
}







//// reading a text file
//#include <iostream>
//#include <fstream>
//#include <string>
//using namespace std;
//
//int main () {
//  string line;
//  ifstream myfile ("example.txt");
//  if (myfile.is_open())
//  {
//    while ( getline (myfile,line) )
//    {
//      cout << line << '\n';
//    }
//    myfile.close();
//  }
//
//  else cout << "Unable to open file"; 
//
//  return 0;
//}
//
//
//// writing on a text file
//#include <iostream>
//#include <fstream>
//using namespace std;
//
//int main () {
//  ofstream myfile ("example.txt");
//  if (myfile.is_open())
//  {
//    myfile << "This is a line.\n";
//    myfile << "This is another line.\n";
//    myfile.close();
//  }
//  else cout << "Unable to open file";
//  return 0;
//}
//
//// basic file operations
//#include <iostream>
//#include <fstream>
//using namespace std;
//
//int main () {
//  ofstream myfile;
//  myfile.open ("example.txt");
//  myfile << "Writing this to a file.\n";
//  myfile.close();
//  return 0;
//}
