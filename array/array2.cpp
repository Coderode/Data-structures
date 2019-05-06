#include<iostream>
using namespace std;
class Array{
	int size;
	int arr[20]={2,4,5,7,1,8};
	int length;
	public:
		Array()
		{
			length=sizeof(arr)/sizeof(arr[0]);
			size=size_of_array();
		}
		int size_of_array()
		{
			int i;
			for(i=0; arr[i]!=0; i++);
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
//				if(size==length)
//				{
//					//providing extra memory
//					arr=new int[length+1];
//				}
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
				cout<<arr[i]<<" ";
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
    cout<<"3.insert element"<<endl;
    cout<<"4.delete element"<<endl;
    cout<<"5.display"<<endl;
    cout<<"6.exit"<<endl;
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
		case 3:
			cout<<"enter value:"<<endl;
			cin>>value;
			cout<<"enter the index no.:"<<endl;
			cin>>index;
			A.insert(value,index);
			break;
		case 4:
			cout<<"Enter index no. to delete element from array:"<<endl;
			cin>>index;
			cout<<"deleted value is:"<<A.del(index)<<endl;
			break;
		case 5:
			cout<<"The existing array is:"<<endl;
			A.display();
			break;
		case 6:
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



