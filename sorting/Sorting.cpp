#include<iostream>
#include<conio.h>
using namespace std;
class Sorting{
	int *a;
	int n;
	public:
		Sorting(int s)
		{
			n=s;
			a=new int[n];
		}
		void display()
		{
			cout<<"\n[ ";
			for(int i=0; i<n; i++)
			{
				cout<<a[i]<<", ";
			}
			cout<<"\b\b]";
		}
		//selection sort
		//ascending order
		void selectionSort()
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
		//bubble sort
		//ascending order
		void BubbleSort()
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
		//insertion sorting
		//ascending order
		void insertionSort()
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
		void getArray()
		{
			cout<<"\nEnter the values: "<<endl;
			for(int i=0; i<n; i++)
			{
				cout<<"\nValue "<<i+1<<": ";
				cin>>a[i];
			}
		}
};
int main()
{
	int n;
	int option;
	cout<<"\nEnter the No. of elements to sort : ";
	cin>>n;
	Sorting S(n);
	while(1)
	{
		cout<<"\n1.getArray\t2.display\t3.selection sort\t4.bubble sort\t5.insertion sort\t6.exit\nselect option:";
		cin>>option;
		switch(option)
		{
			case 1:
				S.getArray();
				break;
			case 2:
				S.display();
				break;
			case 3:
				S.selectionSort();
				break;
			case 4:
				S.BubbleSort();
				break;
			case 5:
				S.insertionSort();
				break;
			case 6:
				exit(0);
				break;
			default:
				cout<<"\nwrong option enter again\n";
		}
	}
	getch();
	return 0;
}
