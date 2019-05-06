//searching
//ternary  search

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
//ternary search
int TernarySearch(int *a,int n, int x)
{
	int low=0;
	int  high=n-1;
	while(low<=high)
	{
		int mid1=floor((low+high)/3);
		int mid2=2*mid1;
		if(x<a[mid1])
		{
			high=mid1-1;
		}
		else if(x==a[mid1]){
			return mid1;
		}
		else if(x==a[mid2]){
			return mid2;
		}
		else{
			low=mid2+1;
		}
	}
	return -1;
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
				index=TernarySearch(a,n,x);
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

