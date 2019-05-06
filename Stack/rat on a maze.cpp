#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
class Point{
	public:
	int row ,col;
		Point(int r=0,int c=0)
		{
			row=r;
			col=c;
		}
};
template <class T>
class stack{
	T *a;
	int length,tos;
	public:
		stack(int n)
		{
			length=n;
			a=new T[n];
			tos=-1;
		}
		bool isEmpty();
		int getSize();
		void push(T x);
		T pop();
		void display();
//		friend class Point;
};
template <class T>
bool stack<T>::isEmpty()
{
	if(tos==-1)
		return true;
	else
		return false;
}
template <class T>
int stack<T>::getSize()
{
	return tos+1;
}
template <class T>
void stack<T>::push(T x)
{
	a[++tos]=x;
}
template <class T>
T stack<T>::pop()
{
	return a[tos--];
}
template <class T>
void  stack<T>::display()
{
	cout<<"start point:->";
	cout<<"[";
	for(int i=0; i<=tos; i++)
	{
		cout<<"("<<a[i].row+1<<","<<a[i].col+1<<")->";
	}
	cout<<"\b\b]";
	cout<<"<-exit point\n";
}

int m,n;
int ** createMaze()
{
	cout<<"\nEnter size of maze:\n";
	cout<<"no. of rows(m)=";
	cin>>m;
	cout<<"no. of cols(n)=";
	cin>>n;
	int **maze= new int*[m];
	for(int i=0; i<m; i++)
	 maze[i]=new int[n];
	 
	for(int i=0; i<m; i++)
	for(int j=0; j<n; j++)
	maze[i][j]=0;
	
	cout<<"the formed maze is(without blocked area):\n";
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout<<maze[i][j]<<"\t";
		}
		cout<<endl;
	}
	
	cout<<"\n\n";
	
	 
	int r,c;
	char ans;
	do
	{
		cout<<"Enter row and col to create blocked area:\n";
		cout<<"row=";
		cin>>r;
		cout<<"col=";
		cin>>c;
		maze[r-1][c-1]=1;
		cout<<"\ncreated!\n";
		cout<<"\ntype y to create another blocked area:\n";
		cin>>ans;
	}while(ans=='y');
	cout<<"the formed maze is:\n";
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout<<maze[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<"\n\n";
	return maze;
}
bool getPath()
{
	int **maze=createMaze();
	int row=0,col=0;
	maze[row][col]=1;
	stack<Point> s(m*n-1);
	while(row!=m-1 or col!=n-1)
	{
		if(col<n-1 and maze[row][col+1]==0)//right move 
		{
			Point p1(row,col);
			s.push(p1);
			col=col+1;
			maze[row][col]=1;
		}
		else if(row<m-1 and maze[row+1][col]==0)//down
		{
			Point p2(row,col);
			s.push(p2);
			row=row+1;
			maze[row][col]=1;
		}
		else if(col>0 and maze[row][col-1]==0)//left
		{
			Point p3(row,col);
			s.push(p3);
			col=col-1;
			maze[row][col]=1;
		}
		else if(row>0 and maze[row-1][col]==0)//up
		{
			Point p4(row,col);
			s.push(p4);
			row=row-1;
			maze[row][col]=1;
		}
		else
		{
			if(s.isEmpty()==true)
			{
				return false;  //for no path
			}
			else
			{
				Point p=s.pop();
				row=p.row;
				col=p.col;	
			}
		}
	}
	Point p(row,col);
	s.push(p);
	cout<<"\nDisplaying the way:\n";
	s.display();
	return true;  //path exist
}
int main()
{
	cout<<"\nRat on maze problem\n";
	if(getPath())
	cout<<"\nPath exist";
	else
	cout<<"\nPath does not exist";
	getch();
	return 0;
}

