#include<iostream>
#include<string.h>
using namespace std;

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
class ArrayException2{
	string s;
	public:
		ArrayException2(string y){
			s=y;
		}
	 	friend void operator<<(ostream &abc, ArrayException2 obj)
		{
			abc<<obj.s;
		}
};

int main()
{
	ArrayException2 a("Invalid index ... Sandeep");
	cout << a;
	getchar();
	return 0;
}
