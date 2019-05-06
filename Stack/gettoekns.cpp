#include<iostream>
#include<conio.h>
#include<cstring>
#include<stdio.h>
using namespace std;
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

int main()
{
	string exp;
	cout<<"enter a expression:\n";
	getline(cin,exp);

	string *token=gettokens(exp);
	for(int i=0; i<=tn; i++)
	{
		cout<<"token"<<i+1<<"="<<token[i]<<endl;
	}
	getch();
	return 0;
}

