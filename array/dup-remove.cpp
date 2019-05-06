#include<iostream>
using namespace std;
class Array{
	int size,*arr,n;
	public:
		Array() :n(0),size(0)
		{
			cout<<"Enter the value of n for array 1223334444....nnnnnn..ntimes:"<<endl;
    		cin>>n;
			int index=0;
			arr=new int[(n*(n+1))/2];
			for(int i=1; i<=n; i++)
			for(int j=1; j<=i; j++)
			{
				*(arr+index)=i;
				index++;
			}
			size=index;	
			cout<<"array is ready!"<<endl;
		}
		
		int size_of_array()
		{
			int i;
			for( i=0; *(arr+i)!=0; i++);
			size=i;
			return i;	
		}
		bool isEmpty()
		{
			
			if(size==0)
			{
				return true;
			}
			else
			return false;	
		}
		void insert(int value,int index)
		{
			if(index<0 or index>size)
			{
				cout<<"Invalid index";
				return;
			}
			else
			{
				for(int i=size-1; i>=index; i--)
				{
					arr[i+1]=arr[i];
				}
				arr[index]=value;
				cout<<"Inserted successfully!"<<endl;
				size=size+1;
			}
		}
		int del(int index)
		{
			if(index<0 or index>=size)
			{
				cout<<"invalid index!"<<endl;
				return 0;
			}
			else
			{
				int x=arr[index];
				for(int i=index+1; i<=size-1; i++)
				{
					arr[i-1]=arr[i];
				}	
				size=size-1;
				arr[size]=0;
				return x;
			}	
		}
		void display()
		{
			for(int i=0; i<=size-1; i++)
			{
				cout<<*(arr+i)<<" ";
			}
		}
		//with minimum movements
		void delete_dup1()
		{
			for(int i=1; i<=n-1; i++)
			for(int j=1; j<=n-i; j++)
			{
				del(size-i);
			}
		}
		//with maximum movements
		void delete_dup2()
		{
			for(int i=1;i<=n-1; i++)
			for(int j=1;j<=i;j++)
			{
				del(i);
			}
			
		}		
};


int main()
{
	int ans,value,index;
	Array A;
	while(1)
	{
    cout<<"\n1.Size of array"<<endl;
    cout<<"2.Isempty array"<<endl;
    cout<<"3.delete duplicates"<<endl;
    cout<<"4.display"<<endl;
    cout<<"5.exit"<<endl;
    cout<<"Select array operation:"<<endl;
    cin>>ans;
    switch(ans)
    {		
    	case 1:cout<<"Size of the array is:"<<A.size_of_array()<<endl; break;
    	case 2:
    		cout<<"Array is empty:";
			if(A.isEmpty())
			cout<<"True"<<endl;
			else
			cout<<"False"<<endl;
			break;
//		case 0:
//			cout<<"enter value:"<<endl;
//			cin>>value;
//			cout<<"enter the index no.:"<<endl;
//			cin>>index;
//			A.insert(value,index);
//			break;
		case 3:
//			A.delete_dup1();
			A.delete_dup2();
			cout<<"duplication removed successfully!"<<endl;
			break;
		case 4:
			cout<<"The existing array is:"<<endl;
			A.display();
			break;
		case 5:
			exit(0);
			break;
		default:
			cout<<"Invalid choice!"<<endl;
			cout<<"please re-enter:"<<endl;		
	}
	}
    getchar();
    return 0;
}


