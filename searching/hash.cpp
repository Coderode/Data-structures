//searching
//hash  search

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

class HashTable{
	int *a,h,n;
	public:
		HashTable(int n,int p)
		{
			a=new int[n];
			this->n=n;
			for(int i=0; i<n; i++)
			{
				a[i]=-1;
			}
			h=p;
		}
		void insert(int key);
		int search(int key);
		void del(int key);
		void display()
		{
			cout<<"\n[ ";
			for(int i=0; i<n; i++)
			{
				cout<<a[i]<<", ";
			}
			cout<<"\b\b]";
		}
};
void HashTable::insert(int key)
{
	int index=key%h;
	do{
		if(a[index]==-1){
			a[index]=key;
			return; 
		}
		else if(a[index]==key){
			return;
		}
		else{
			index=(index+1)%h;
		}
	}while(index!=key%h);
	throw Exception("Hash table is full");
}
int HashTable::search(int key)
{
	int index=key%h;
	do{
		if(a[index]==-1){
			return -1;
		}
		else if(a[index]==key){
			return index;
		}
		else {
			index=(index+1)%h;
		}	
	}while(index!=key%h);
	return -1;
}
void HashTable::del(int key)
{
	int i=search(key);
	if(i==-1){
		throw Exception("key does not exist");
	}
	int j=(i+1)%h;
	int k=i; 
	while(j!=k and a[j]!=-1)
	{
		if(a[j]%h<=i){
			a[i]=a[j];
		}
		j=(j+1)%h;
	}
	a[i]=-1;
}
int main()
{
		char ans;
	do{
		try{
	cout<<"\nhash searching\n";
	int option;
	int p=7;
	int n;
	cout<<"\nEnter size of the list : ";
	cin>>n;
	
	HashTable h(n,p);

	int flag=1;
	while(flag==1)
	{
		cout<<"\n1.Search element\t2.del\t3.insert\t4.display\t5.exit\nselect option:";
		cin>>option;
		switch(option)
		{
			case 1:
				int key;
				cout<<"\nEnter the key to search : ";
				cin>>key;
				int index;
				index=h.search(key);
				if(index<0)
				{
					cout<<key<<" is  not present in the list \n";
				}
				else
				{
					cout<<key<<" is present in  the list at position : "<<index;
				}
				break;
			case 2:	
				cout<<"\nEnter the key to del : ";
				cin>>key;
				h.del(key);
				break;
			case 3:
				cout<<"\nEnter the key to insert in the list : ";
				cin>>key;
				h.insert(key);
				break;
			case 4:
				h.display();
				break;
			case 5:
				flag=0;
				break;
			default:
				cout<<"\nyou entered wrong option\n";	
		}
	}
	
	}
	catch(Exception x)
	{
		cout<<x;
	}
	fflush(stdin);
	cout<<"\nDo you want to continue? y or n:";
	cin>>ans;
	
	}while(ans=='y');
	
	getch();
	return 0;	
}

