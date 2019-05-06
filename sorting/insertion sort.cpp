#include<iostream>
#include<conio.h>
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
//ascending order
void insertionSort1(int *a,int n)
{
	for(int i=1; i<=n-1; i++)
	{
		int x=a[i];
		int j=i-1;
		while(j>=0 and a[j]>x)
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=x;
	}
}

//descending order
void insertionSort2(int *a,int n)
{
	for(int i=1; i<=n-1; i++)
	{
		int x=a[i];
		int j=i-1;
		while(j>=0 and a[j]<x)
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=x;
	}
}

int main()
{
	cout<<"\ninsertion sorting\n";
	int option;
	int *a=NULL;
	int n;
	while(1)
	{
		cout<<"\n1.get Array\t2.ascending order\t3.descending order\t4.display\t5.exit\nselect option:";
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
					insertionSort1(a,n);
					cout<<"\nAfter sorting array elements : \n";
					cout<<"\nAscending order\n";
					display(a,n);
					break;
			case 3:
				cout<<"\nDescending order\n";
				insertionSort2(a,n);
				display(a,n);
				break;
			case 4:
				display(a,n);
				break;
			case 5:
				exit(0);
			default:
				cout<<"\nyou entered wrong option\n";	
		}
	}
	getch();
	return 0;	
}
