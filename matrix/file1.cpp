class ArrayException{
	char *s;
	public:
	ArrayException(char *x){
		s = new char[strlen(x) + 1];
		strcpy(s, x);
	}
	friend ostream & operator<<(ostream &abc, ArrayException obj){
		abc << obj.s;
		return abc;
	}
};


class Matrix{
	public:
	float *a;
	int m,n;
	
		Matrix(int m,int n){
			this -> n=n;
			this -> m=m;
			a=new float[m*n];
		}
		void read();
		void print();
		Matrix mul(Matrix b);
		Matrix add(Matrix b);
		int map(int,int);
};

int Matrix::map(int i,int j)
{
	//using row major order
	return (n*i+j);
	//using col major order
//	return (m*j+i);
}
void Matrix::read()
{
	cout<<"\nEnter the elements of "<<m<<"*"<<n<<" matrix\n";
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout<<"a["<<i<<"]["<<j<<"]=";
			cin>>a[map(i,j)];
		}
	}
}
void Matrix::print()
{
	cout<<"\nthe matrix is\n";
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{	
			cout<<a[map(i,j)]<<"\t";
		}
		cout<<"\n";
	}
}
Matrix Matrix::add(Matrix b)
{
	if(m!=b.m && n!=b.n)
		{
			throw ArrayException("Addition is not possbile!");
		}
	Matrix c(m,n);
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			c.a[map(i,j)]=a[map(i,j)]+b.a[map(i,j)];
		}
	}
	return c;
}
Matrix Matrix::mul(Matrix b)
{
	if(n!=b.m)
	throw ArrayException("Multiplication is not possible!");
	Matrix c(m,b.n);
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			c.a[map(i,j)]=0;
			for(int k=0; k<n; k++)
			{
				c.a[map(i,j)]=c.a[map(i,j)]+a[map(i,k)]*b.a[map(k,j)];
			}
		}
	}
	return c;
}

class DiagonalMatrix
{
	public:
		float *a;
		int n;
		DiagonalMatrix(int n){
			this->n=n;
			a=new float[n];
		}
		void read();
		void print();	
		
};
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

class LTM{
	public:
	float *a;
	int n;
		LTM(int n){
			this -> n=n;
			a=new float[n*(n+1)/2];
		}
		void read();
		void print();
		float det();
		LTM mul(LTM b);
		LTM add(LTM b);
		LTM inverse();
		int map(int,int);
};

int LTM::map(int i,int j)
{
	//using row major order
	return ((i*(i+1)/2)+j);
	//using col major order
//	return (n*j-(j*(j+1)/2)+i);
	//using last row to first row and within row from left to right
//	return (n*(n-i-1)-((n-i-2)*(n-i-1)/2)+j);
}
void LTM::read()
{
	cout<<"\nEnter the non -zero elements of "<<n<<"*"<<n<<"lower triangular matrix\n";
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<=i; j++)
		{
			cout<<"a["<<i<<"]["<<j<<"]=";
			cin>>a[map(i,j)];
		}
	}
}
void LTM::print()
{
	cout<<"\nthe lower tiangular matrix is\n";
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(i>=j)
			{
				cout<<a[map(i,j)]<<"\t";
			}
			else
			{
				cout<<"0\t";
			}
		}
		cout<<"\n";
	}
}
LTM LTM::add(LTM b)
{
	LTM c(n);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<=i; j++)
		{
			c.a[map(i,j)]=a[map(i,j)]+b.a[map(i,j)];
		}
	}
	return c;
}
LTM LTM::mul(LTM b)
{
	LTM c(n);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<=i; j++)
		{
			for(int k=j; k<=i; k++)
			{
				c.a[map(i,j)]=c.a[map(i,j)]+a[map(i,k)]*b.a[map(k,j)];
			}
		}
	}
	return c;
}
LTM LTM::inverse(){
	LTM A(n), B(n);
	for(int i = 0; i < n; i++)
	   for(int j = 0; j <= i; j++){
	   	A.a[map(i, j)] = a[map(i, j)];
	   	if(i == j)
	   	   B.a[map(i, j)] = 1;
	   	else
	   	   B.a[map(i, j)] = 0;
	   }
	//A.print();
	//B.print();
	
	for(int i = 0; i < n-1; i++)
	{
		float x = A.a[map(i, i)];
		for(int j = i + 1; j < n; j++)
		{
			float y = A.a[map(j, i)];
			for(int k = 0; k <= i; k++)
			{
				A.a[map(j, k)] = A.a[map(j, k)] - A.a[map(i, k)] * y / x;
				B.a[map(j, k)] = B.a[map(j, k)] - B.a[map(i, k)] * y / x;
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
		float x = A.a[map(i,i)];
		for(int k = 0; k <= i; k++)
		{
			A.a[map(i, k)] = A.a[map(i, k)] / x;
			B.a[map(i, k)] = B.a[map(i, k)] / x;
		}
	}
//	cout <<"Matrix A\n";
//	A.print();
//       cout <<"Inverse Matrix\n";
//       B.print();
   return B;
}
float LTM::det()
{
	float d=1;
	for(int i=0; i<n; i++)
	{
		d=d*a[map(i,i)];
	}
	return d;
}



class UTM{
	public:
		float *a;
		int n;
		UTM(int n){
			this -> n=n;
			a=new float[n*(n+1)/2];
		}
		void read();
		void print();
		int map(int,int);
};

int UTM::map(int i,int j)
{
	//using col major order
//	return ((j*(j+1)/2)+i);
	//using row major order
	return (n*i-(i*(i+1)/2)+j);	
}
void UTM::read()
{
	cout<<"\nEnter the non -zero elements of "<<n<<"*"<<n<<" upper triangular matrix\n";
	for(int i=0; i<n; i++)
	{
		for(int j=i; j<n; j++)
		{
			cout<<"a["<<i<<"]["<<j<<"]=";
			cin>>a[map(i,j)];
		}
	}
}
void UTM::print()
{
	cout<<"\nthe upper tiangular matrix is\n";
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(i<=j)
			{
				cout<<a[map(i,j)]<<"\t";
			}
			else
			{
				cout<<"0\t";
			}
		}
		cout<<"\n";
	}
}

