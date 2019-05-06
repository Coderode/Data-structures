#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;

class ArrayException{
	char *s;
	public:
		ArrayException(char *x){
			s = new char[strlen(x) + 1];
			strcpy(s, x);
		}
		friend ostream &operator<<(ostream &abc, ArrayException a){
			abc << a.s;
			return abc;
		}
};

class DiagonalMatrix
{
	float *a;
	int n;
	public:
		DiagonalMatrix(int n);
		void read();
		void print();	
		DiagonalMatrix inverse();
//		DiagonalMatrix mul(DiagonalMatrix b);
//		DiagonalMatrix add(DiagonalMatrix b);
		float det();
		
		DiagonalMatrix add(DiagonalMatrix B)
		{
		if(B.n!=n)
		{
			throw ArrayException("addition is not possible");
		}
	
		DiagonalMatrix C(n);
		for(int i=0; i<n; i++)
		{
			C.a[i]=a[i]+B.a[i];
		}
		return C;
		}
		
		DiagonalMatrix mul(DiagonalMatrix B)
			{
				if(B.n!=n)
				{
					throw ArrayException("multiplication is not possible!");
				}
			DiagonalMatrix C(n);
			for(int i=0; i<n; i++)
			{
				C.a[i]=a[i]*B.a[i];
			}
			return C;
			}
		
};
DiagonalMatrix::DiagonalMatrix(int n)
{
	this -> n=n;
	a=new float[n];
}

void DiagonalMatrix::read()
{
	cout<<"Enter "<<n<<" diagonal elements of matrix:"<<endl;
	for(int i=0; i<n; i++)
	{
		cout<<"element("<<i+1<<","<<i+1<<"):";
		cin>>a[i];
	}	
}

void DiagonalMatrix::print()
{
	cout<<"the diagonal matrix is:"<<endl;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(i==j)
			{
				cout<<a[i]<<"\t\t";
			}
			else
			{
				cout<<"0\t\t";
			}
		}
		cout<<endl;
	}
}
float DiagonalMatrix::det()
{
	float d=1;
	for(int i=0; i<n; i++)
	{
		d=d*a[i];
	}
	return d;
}
DiagonalMatrix DiagonalMatrix::inverse()
{
	if(det()==0){
		throw ArrayException("Inverse does not exist");
	}
	DiagonalMatrix B(n);
	for(int i=0; i<n; i++){
		B.a[i]=1.0/a[i];
	}
	return B;
}



int main()
{
	int n=3,option;
	cout<<"\n------------------------------Working with diagonal MATRICES-------------------------------"<<endl;
	cout<<"Enter order for Matrixes:"<<endl;
	cin>>n;
	DiagonalMatrix X(n),Y(n),S(n),P(n);
	while(1)
	{	
		cout<<"\n1.Entry for Matrix X\t";
		cout<<"2.Entry for Matrix Y\t";
		cout<<"3.inverse of X\t";
		cout<<"4.inverse of Y\t";
		cout<<"5.det of X\t";
		cout<<"6.det of Y\t";
		cout<<"7.find X+Y\t";
		cout<<"8.find X*Y\t";
		cout<<"9.exit"<<endl;
		cout<<"select option:";
		cin>>option;
		switch(option)
		{	
			case 1:
				cout<<"for diagonal matrix X:"<<endl;
				X.read();			
				cout<<"\nMatrix X:"<<endl;
				X.print();
				break;
			case 2:				
				cout<<"for diagonal matrix Y:"<<endl;
				Y.read();
				cout<<"\nMatrix Y:"<<endl;
				Y.print();
				
				break;
			case 3:
				cout<<"Inverse X:"<<endl;
				X.inverse().print();
				break;
			case 4:
				cout<<"Inverse Y:"<<endl;
				Y.inverse().print();
				break;
			case 5:	cout<<"detX="<<X.det()<<endl;
				break;
			case 6:cout<<"detY="<<Y.det()<<endl;
				break;
			case 7:
				cout<<"Matrix X+Matrix Y="<<endl;
				//	X.add(Y).print();
				S=Y.add(X);
				S.print();
				break;
			case 8:
				cout<<"Matrix X*Matrix Y="<<endl;
				//	X.mul(Y).print();
				P=Y.mul(X); 
				P.print();
				break;
			case 9:
				exit(0);
			default:cout<<"you entered wrong option please re-enter!"<<endl;
		
		}	
	}
	getch();
	return 0;
}
