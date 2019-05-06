//shell sort and pratt sort
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
//using insertion sort
void shellSort1(int *a,int n)
{
	int gap=floor(n/2);
	while(gap>=1)
	{
		//insertion sort
		for(int i=gap; i<=n-1; i++)
		{
			int x=a[i];
			int j=i;
			while(j>=gap and a[j-gap]>x)
			{
				a[j]=a[j-gap];
				j=j-gap;
			}
			a[j]=x;
		}
		gap=floor(gap/2);
	}
}
//using bubble sort
void shellSort2(int *a,int n)
{
	int gap=floor(n/2);
	while(gap>=1)
	{
		//bubble sort
		for(int i=gap; i<=n-1; i++)
		{
//			bool isSorted=true;
			for(int j=i; j>=gap; j=j-gap)
			{
				
				if(a[j-gap]>a[j])
				{
					int temp=a[j];
					a[j]=a[j-gap];
					a[j-gap]=temp;
//					isSorted=false;
				}
			}
//			if(isSorted==true)
//			{
//				break;
//			}
		}
		gap=floor(gap/2);
	}
}
void pratt(int *a,int n)
{
	int h=1;
	while(h<=n/3)
	{
		h=3*h+1;
		while(h>=1)
		{
			//insertion sort
			for(int i=h; i<=n-1; i++)
			{
				int x=a[i];
				int j=i;
				while(j>=h and a[j-h]>x)
				{
					a[j]=a[j-h];
					j=j-h;
				}
				a[j]=x;
			}
			h=floor((h-1)/3);
		}
	}
}

int main()
{
	cout<<"\nshell sort and pratt sorting\n";
	int option;
	int *a=NULL;
	int n;
	while(1)
	{
		cout<<"\n1.get Array\t2.shell sort\t3.pratt sort\t4.display\t5.exit\nselect option:";
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
					shellSort1(a,n);
					cout<<"\nAfter sorting array elements : \n";
					cout<<"\nAscending order\n";
					display(a,n);
					break;
			case 3:
				pratt(a,n);
				cout<<"\nAfter sorting array elements : \n";
				cout<<"\nAscending order\n";
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



