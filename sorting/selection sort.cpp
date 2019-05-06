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
void selectionSort1(int *a,int n)
{
	int i,j,temp,minindex;
	for(i=0; i<=n-2; i++)
	{
		minindex=i;
		for(j=i+1; j<=n-1; j++)
		{
			if(a[j]<a[minindex])
			{
				minindex=j;
			}
		}
		if(i!=minindex)
		{
			temp=a[i];
			a[i]=a[minindex];
			a[minindex]=temp;
		}
	}
}
//descending order
void selectionSort2(int *a,int n)
{
	int i,j,temp,maxindex;
	for(i=0; i<=n-2; i++)
	{
		maxindex=i;
		for(j=i+1; j<=n-1; j++)
		{
			if(a[j]>a[maxindex])
			{
				maxindex=j;
			}
		}
		if(i!=maxindex)
		{
			temp=a[i];
			a[i]=a[maxindex];
			a[maxindex]=temp;
		}
	}
}

int main()
{
	cout<<"\nSelection sorting\n";
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
					selectionSort1(a,n);
					cout<<"\nAfter sorting array elements : \n";
					cout<<"\nAscending order\n";
					display(a,n);
					break;
			case 3:
				cout<<"\nDescending order\n";
				selectionSort2(a,n);
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
