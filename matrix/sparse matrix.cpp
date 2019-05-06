//sparse matrix
//no. of zero elements > no. of non-zero elements
#include<iostream>
using namespace std;
#include<conio.h>
#include<string.h>

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


class sparseMatrix{
	int *row;
	int *col;
	int *val;
	int nnz;  //no. of non zeros
	int rows;
	int cols;
	
	public:
		sparseMatrix(){
		}
		sparseMatrix(int nz,int r,int c)
		{
			nnz=nz;
			rows=r;
			cols=c;
			row=new int[nz];
			col=new int[nz];
			val=new int[nz];
		}
		void read();
		void print();
		friend sparseMatrix add(sparseMatrix &A,sparseMatrix &B);
		void transpose();
};
void sparseMatrix::read()
{
	cout<<"\nEnter the information of the non-zero elements\n";
	for(int i=0; i<=nnz-1; i++)
	{
		cout<<"row=";
		cin>>row[i];
		cout<<"col=";
		cin>>col[i];
		cout<<"value=";
		cin>>val[i];
		fflush(stdin);
	}
}
void sparseMatrix::print()
{
	int k=0,found;
	cout<<"\nThe sparse Matrix is:\n";
	for(int i=1; i<=rows; i++)
	{
		for(int j=1; j<=cols; j++)
		{
			k=0;
			found=0;
			while(k<=nnz-1)
			{
				if(row[k]==i and col[k]==j)
				{
					found=1;
					break;
				}
				k=k+1;
			}
			if(found==1)
			{
				cout<<val[k]<<"\t";
			}
			else
			{
				cout<<"0\t";
			}
			
		}
		cout<<"\n";
	}
}
sparseMatrix add(sparseMatrix &A,sparseMatrix &B)
{
	if(A.rows!= B.rows or A.cols!=B.cols)
	{
		throw Exception("addition not possible!");
	}
	int nnzc=0;
	for(int i=0; i<=A.nnz-1; i++)
	{
		for(int j=0; j<=B.nnz-1; j++)
		{
			if(A.row[i]==B.row[j] and A.col[i]==B.col[j])
			{
				nnzc=nnzc+1;  //for common elements
				break;
			}
		}
	}
	sparseMatrix C(A.nnz+B.nnz-nnzc,A.rows,A.cols);
	int k=0,j,i;
	for(i=0; i<=A.nnz-1; i++)
	{
		for(j=0; j<=B.nnz-1; j++)
		{
			if(A.row[i]==B.row[j] and A.col[i]==B.col[j])
			{
				C.row[k]=A.row[i];
				C.col[k]=A.col[i];
				C.val[k]=A.val[i]+B.val[j];
				k++;
				break;
			}
		}
		if(B.nnz==j)
		{
			C.row[k]=A.row[i];
			C.col[k]=A.col[i];
			C.val[k]=A.val[i];
			k++;
		}
	}
	for(i=0; i<=B.nnz-1; i++)
	{
		for(j=0; j<=A.nnz-1; j++)
		{
			if(B.row[i]==A.row[j] and B.col[i]==A.col[j])
			{
				break;
			}
		}
		if(j==A.nnz)
		{
			C.row[k]=B.row[i];
			C.col[k]=B.col[i];
			C.val[k]=B.val[i];
			k++;
		}
	}
	return C;
}
void sparseMatrix::transpose()
{
	int temp;
	for(int i=0; i<=nnz-1; i++)
	{
		row[i]=temp;
		row[i]=col[i];
		col[i]=temp;
	}
}

int main()
{
	//sparsematrix A(no. of non-zero elements,rows,cols)
	sparseMatrix A(2,4,4),B(3,4,4),C;
	cout<<"\nFor matrix A:\n";
	A.read();
	A.print();
	cout<<"\nFor matrix B:\n";
	B.read();
	B.print();
	cout<<"\naddition of A and B:\n";
	C=add(A,B);
	C.print();
	cout<<"\ntranspose of addition:\n";
	C.transpose();
	C.print();
	getch();
	return 0;
}
