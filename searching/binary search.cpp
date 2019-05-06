//searching
//binary search

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
//recursive function
int BinarySearch1(int *a,int low,int high,int x)
{
	if(low<=high)
	{
		int mid=floor((low+high)/2);
		if(x<a[mid])
		{
			return BinarySearch1(a,low,mid-1,x);
		}
		else if(x==a[mid]){
			return mid;
		}
		else{
			return BinarySearch1(a,mid+1,high,x);
		}
	}
	else{
		return -1;  //if key is not present
	}
}
//iterative function
int BinarySearch2(int *a,int n,int x)
{
	int low=0;
	int high=n-1;
	while(low<=high)
	{
		int mid=floor((low+high)/2);
		if(x<a[mid])
		{
			high=mid-1;
		}
		else if(x==a[mid])
		{
			return mid;
		}
		else{
			low=mid+1;
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
				//recursive function
//				index=BinarySearch1(a,0,n-1,x);
				//iterative function
				index=BinarySearch2(a,n,x);
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

