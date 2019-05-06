//quick sort
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
int partition(int *a,int low , int high)
{
	int pivotelement=a[low];
	int j=low;
	for(int i=low+1; i<=high; i++)
	{
		if(a[i]<pivotelement)
		{
			j++;
			if(i!=j){
				int t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	int pivotpoint=j;
	if(j!=low)
	{
		int t=a[j];
		a[j]=a[low];
		a[low]=t;
	}
	return pivotpoint;
}
void quickSort(int *a,int low,int high)
{
	if(low<high)
	{
		int p=partition(a,low,high);
		quickSort(a,low,p-1);
		quickSort(a,p+1,high);
	}
}
int main()
{
	cout<<"\nQuick sorting\n";
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
					quickSort(a,0,n-1);
					cout<<"\nAfter sorting array elements : \n";
					cout<<"\nAscending order\n";
					display(a,n);
					break;
			case 3:
//				cout<<"\nDescending order\n";
//				BubbleSort2(a,n);
//				display(a,n);
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
