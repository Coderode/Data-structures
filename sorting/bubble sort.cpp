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
void BubbleSort1(int *a,int n)
{
	for(int i=1; i<=n-1; i++)
	{
		bool isSorted=true;
		for(int j=0; j<=n-i-1; j++)
		{
			if(a[j]>a[j+1])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				isSorted=false;
			}
		}
		if(isSorted==true)
		{
			break;
		}
	}
}
void BubbleSort2(int *a,int n)
{
	for(int i=1; i<=n-1; i++)
	{
		bool isSorted=true;
		for(int j=0; j<=n-i-1; j++)
		{
			if(a[j]<a[j+1])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				isSorted=false;
			}
		}
		if(isSorted==true)
		{
			break;
		}
	}
}
int main()
{
	cout<<"\nBubble sorting\n";
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
					BubbleSort1(a,n);
					cout<<"\nAfter sorting array elements : \n";
					cout<<"\nAscending order\n";
					display(a,n);
					break;
			case 3:
				cout<<"\nDescending order\n";
				BubbleSort2(a,n);
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
