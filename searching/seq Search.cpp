//searching
//sequential search

#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
void display(int *a,int n)
{
	cout<<"\n[ ";
	for(int i=0; i<n; i++)
	{
		cout<<a[i]<<", ";
	}
	cout<<"\b\b]";
}
int sequentialSearch(int *a,int n, int x)
{
	int index=-1;
	for(int i=0; i<=n-1; i++)
	{
		if(a[i]==x)
		{
			index=i;
			break;
		}
	}
	return index;
}

int main()
{
	cout<<"\nSequential searching\n";
	int option;
	int *a=NULL;
	int n;
	int x;
	while(1)
	{
		cout<<"\n1.get Array\t2.Search element\t3.display\t4.exit\nselect option:";
		cin>>option;
		switch(option)
		{
			case 1:
				cout<<"\nSelection Sorting:\n";
				cout<<"\nEnter the No. of elements to sort : ";
				cin>>n;
				a=new int[n];
				cout<<"\nEnter the values: "<<endl;
				for(int i=0; i<n; i++)
				{
					cout<<"\nValue "<<i+1<<": ";
					cin>>a[i];
				}
				break;
			case 2:	
				fflush(stdin);
				cout<<"\nEnter the key to search: ";
				cin>>x;
				int index;
				index=sequentialSearch(a,n,x);
				if(index<0)
				{
					cout<<"\nKey is not present in the list\n";
				}
				else{
					cout<<x<<" is at position : "<<index;
				}	
				break;
			case 3:
				display(a,n);
				break;
			case 4:
				exit(0);
			default:
				cout<<"\nyou entered wrong option\n";	
		}
	}
	getch();
	return 0;	
}

