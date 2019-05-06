//image processing
#include<iostream>
#include<conio.h>
#include<math.h>
#include<string.h>

using namespace std;
class Point{
	
	public:
		int x,y;
		Point(int r=0,int c=0)
		{
			x=r;
			y=c;
		}
};
class Exception{
	char *s;
	public:
		Exception(char *x){
		s = new char[strlen(x) + 1];
		strcpy(s, x);
	}
	friend ostream & operator<<(ostream &abc,Exception obj){
		abc << obj.s;
		return abc;
	}
};
template <class T>
class Queue{
	T *a;
	int r,f,length;  //rear and front
	public:
		Queue(int n)
		{
			a=new T[n];
			r=-1;
			f=-1;
			length=n;
		}
		bool isEmpty();
		int getSize();
		void insert(T x);
		void display();
		T del();
};
template <class T>
bool Queue<T>::isEmpty()
{
	if(r==-1)
	return true;
	else 
	return false;
}
template <class T>
int Queue<T>::getSize()
{
	if(r==-1)
	return 0;
			
	return r-f+1;
}
template <class T>
void Queue<T>::insert(T x)
{
	if(r==length-1)
	{
		throw Exception("Queue is full");
	}
	if(r==-1)
	{
		f=r=0;
	}
	else
	{
		r=r+1;
	}
	a[r]=x;
}
template <class T>
T Queue<T>::del()
{
	if(f==-1)
	{
		throw Exception("Queue is empty");
	}
	T x=a[f];
	if(r==f)
	{
		r=f=-1;
	}
	else
	{
		f++;
	}
	return x;
}
template <class T>
void Queue<T>::display()
{
	if(r==-1)
	throw Exception("queue is empty");
	cout<<"[ ";
	for(int i=f; i<=r; i++)
		cout<<a[i]<<", ";
	cout<<"\b\b]";
	
}

void lebelComponents(int **pixel,int m)   //m-size of image ,pixel[m][m]
{
	Queue<Point> Q(m*m);
	int id=1;
	for(int r=0; r<m; r++)
	{
		for(int c=0; c<m; c++)
		{
			if(pixel[r][c]==1)
			{
				pixel[r][c]=++id;
				Point p(r,c);
				Q.insert(p);
				while(Q.isEmpty()==false)
				{
					Point p=Q.del();
					int row=p.x,col=p.y;
					if(col<m-1 and pixel[row][col+1]==1){  //right
						pixel[row][col+1]=id;
						Point p(row,col+1);
						Q.insert(p);
					}
					if(row<m-1 and pixel[row+1][col]==1){//down
						pixel[row+1][col]=id;
						Point p(row+1,col);
						Q.insert(p);
					}
					if(col>0  and pixel[row][col-1]==1){//left
						pixel[row][col-1]=id;
						Point p(row,col-1);
						Q.insert(p);
					}
					if(row>0 and pixel[row-1][col]==1){//up
						pixel[row-1][col]=id;
						Point p(row-1,col);
						Q.insert(p);
					}
				}
			}
		}
	}
}
void generateimage(int **p,int m)
{
	cout<<"\nEnter values 0 or 1 only\n";
	for(int i=0; i<m; i++)
	{
		for (int j=0; j<m; j++)
		{
			cout<<"\nEnter pixel["<<i<<","<<j<<"]:";
			cin>>p[i][j];
		}
	}	
	cout<<"\ngenerated image is:\n";
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<m; j++)
		{
			cout<<p[i][j]<<"\t";
		}
		cout<<"\n";
	}
}
int main()
{
	int m;
	cout<<"\nEnter the size of the image:"<<endl;
	cin>>m;
	int **pixel=new int*[m];
	for(int i=0; i<m; i++)
		pixel[i]=new int[m];
	cout<<"\ngenerate image:"<<endl;
	generateimage(pixel,m);
	lebelComponents(pixel,m);
	cout<<"\nthe lablled image is:"<<endl;
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<m; j++)
		{
			cout<<pixel[i][j]<<"\t";
		}
		cout<<"\n";
	}
	getch();
	return 0;
	
	
}


