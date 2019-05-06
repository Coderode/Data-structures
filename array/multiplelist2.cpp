#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;

class ArrayException{
	char *s;
	public:
		ArrayException(char *x){
			s = new char[strlen(x) + 1];
			strcpy(s, x);
		}
		friend ostream &operator<<(ostream &abc, ArrayException a){
			abc << a.s;
			return abc;
		}
};


class Multiplelist{
	int a[100];
	int length,size;
	int *front,*last;
	public:
		int m;
		Multiplelist(){
			length=0;
			size=0;
			cout<<"Enter No. of lists:";
			fflush(stdin);
			cin>>m;
			front=new int[m];
			last=new int[m];
			for(int j=0; j<m; j++)
			{
				front[j]=-1;
				last[j]=-1;
			}
		}
		bool isEmpty(int i);  //i=list no. 1,2,3...
		int getSize(int i);
		void insert(int x,int index,int i);
		void del(int index,int i);
		void display(int i);
		int get(int index,int i);
		int index(int x,int i);
		
};
bool Multiplelist::isEmpty(int i) 
{
	if(getSize(i)==0)
		return true;
	else
		return false;
}
int Multiplelist::getSize(int i)
{
	return (last[i-1]-front[i-1]);
}
void Multiplelist::insert(int x,int index,int i)
{
	if(index<0 or index>getSize(i))
		throw ArrayException("Invalid index!");
	int sum=0;

	for(int j=0; j<m; j++)
	{
		sum=sum+getSize(i);
	}
	if((front[i-1]+index+1)!=size)
	{
	for(int j=size-1; j>=(front[i-1]+index+1); j--)
	{
		a[j+1]=a[j];
	}
	}
	a[front[i-1]+index+1]=x;
	for(int j=i-1; j<m; j++)
	{
		last[j]=last[j]+1;
	}
	for(int j=i; j<m; j++)
	{
		front[j]=last[j-1];
	}
	size=size+1;	
}

void Multiplelist::del(int index,int i)
{
	
	for(int j=front[i-1]+index+1; j<size-1; j++)
	{
		a[j]=a[j+1];
	}
	for(int j=i-1; j<m; j++)
	{
		last[j]=last[j]-1;
	}
	for(int j=i; j<m; j++)
	  front[j]=last[j-1];
	size=size-1;	
}
void Multiplelist::display(int i)
{
	int flag=0;
	i=i-1;
	cout<<"[";
	for(int j=front[i]+1; j<=last[i]; j++)
	{
		cout<<a[j]<<",";
		flag=1;
	}
	if(flag==1)
	cout<<"\b]"<<endl;
	if(flag==0)
	cout<<"]"<<endl;
}
int Multiplelist::get(int index,int i)
{
	if(index<0 || index>=getSize(i))
	throw ArrayException("Invalid index!");
	else
	return a[front[i-1]+index+1];
}

int Multiplelist::index(int x,int i)
{
	int index=0,flag=0;
	for(int j=front[i-1]+1; j<=last[i-1]; j++)
	{
		if(a[j]==x)
		{
		return index;
		flag=1;
		}
		else
		index++;
	}
	if(flag==0)
	{
			throw ArrayException("element does not exist in this list");
	}	
}
void getarray(Multiplelist &a)
{
	int n,p=1,sum,flag;
	int *list=new int[a.m];
	cout<<"Enter total no. of elements to put in these elements:";
	cin>>n;
	do{
	flag=0;
	sum=0;
	for(int j=0; j<a.m; j++)
	{
	cout<<"Enter no. of elements to put in list "<<j+1<<":";
	cin>>list[j];
	sum=sum+list[j];
	}
	if(sum!=n)
	{
		cout<<"\nTotal no. of elements in lists is not equal to total elements entered please re-enter!\n";
		flag=1;
	}
	}while(flag==1);
	for(int j=1; j<=a.m; j++)
	{
		for(int k=1; k<=list[j-1]; k++)
		{
			a.insert(p,k-1,j);
			p++;
		}
	}
	
}
int main()
{
	int option;
	Multiplelist A;
	getarray(A);
	while(1)
	{
		cout<<"\nWelcome to Multiple list class"<<endl;
		
		cout<<"1.isEmpty(listno)\t";
		cout<<"2.display(list)\t";
		cout<<"\t3.getSize(list)\t";
		cout<<"\t4.insert(value,index,list)\n";
		cout<<"5.get(index,list)\t";
		cout<<"6.index(value,list)\t";
		cout<<"7.del(index,list)\t";
		cout<<"8.exit\t";
		cout<<"\nselect option:";
		cin>>option;
		switch(option)
		{
			case 1:
				int list;
				cout<<"Enter list no.:";
				cin>>list;
				cout<<"isEmpty list "<<list<<endl;
				if(A.isEmpty(list))
				cout<<"true"<<endl;
				else
				cout<<"false"<<endl;
				break;
			case 2:
				cout<<"Enter list no.:";
				cin>>list;
				cout<<"list "<<list<<endl;
				A.display(list);
				break;
			case 3:
				cout<<"Enter list no.:";
				cin>>list;
				cout<<"Size of list "<<list<<"is:"<<A.getSize(list)<<endl;
				break;
			case 4:
				int index,value;
				cout<<"Enter list no.:";
				cin>>list;
				cout<<"Enter index no.:";
				cin>>index;
				cout<<"Enter value to insert:";
				cin>>value;
				A.insert(value,index,list);
				cout<<"inserted succesfully"<<endl;
				break;
			case 5:
				cout<<"Enter list no.:";
				cin>>list;
				cout<<"Enter index no.:";
				cin>>index;
				cout<<"list"<<list<<"["<<index<<"]:"<<A.get(index,list)<<endl;
				break;
			case 6:
				cout<<"Enter list no.:";
				cin>>list;
				cout<<"Enter value to insert";
				cin>>value;
				cout<<"index of list"<<list<<"for value "<<value<<"is:"<<A.index(value,list)<<endl;
				break;
			case 7:
				cout<<"Enter list no.:";
				cin>>list;
				cout<<"Enter index no.:";
				cin>>index;
				A.del(index,list);
				cout<<"\ndeleted successfully\n";
				break;
			case 8:
				exit(0);
			default:cout<<"wrong choice re-enter please!"<<endl;
		}
	}
	getch();
	return 0;
	
}
