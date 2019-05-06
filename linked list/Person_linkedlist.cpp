#include<iostream>
#include<string.h>
#include<conio.h>
using namespace std;

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
class Node;
class Person;

class Person{
	char *name;
	int height;
	float weight;
	Node *first;
	public:
		Person(){first=NULL;}
		float getBMI();
		friend istream &operator>>(istream &abc,Person &x);
		friend ostream &operator<<(ostream &abc, Person x);
		
		int getSize();
		void insert(Person,int);
		Person del(int);
		Person get(int);
		void getdiet(int);
		void display();
		void sort();
		
};
class Node{
	public:
	Person data;
	Node *link;
};
float Person::getBMI(){
	return ((weight/(height*height))*10000);
}
istream &operator>>(istream &abc, Person &x)
{
	char nm[100];
	cout<<endl;
	cout<<"Enter name:";
	fflush(stdin);
	gets(nm);
	fflush(stdin);
	x.name=new char[strlen(nm)+1];
	strcpy(x.name,nm);
	cout<<"Enter height(in cm):";
	abc>>x.height;
	cout<<"Enter weight(in kg):";
	abc>>x.weight;
	return abc;
}
ostream &operator<<(ostream &abc,Person x)
{
	float bmi=x.getBMI();
//	cout<<"\n[Name  	weight    height      BMI ]\n";
	if(bmi<18.5)
	abc<<"\t"<<x.name<<"\t "<<x.weight<<",    "<<x.height<<",    "<<bmi<<" : Under weight";
	if(bmi>=18.5 and bmi<24.9)
	abc<<"\t"<<x.name<<"\t "<<x.weight<<",     "<<x.height<<",    "<<bmi<<" : Normal";
	if(bmi>=25 and bmi<29.9)
	abc<<"\t"<<x.name<<"\t "<<x.weight<<",     "<<x.height<<",    "<<bmi<<" : Over weight";
	if(bmi>30)
	abc<<"\t"<<x.name<<"\t "<<x.weight<<",     "<<x.height<<",    "<<bmi<<" : Obese";
	return abc;
}



int Person::getSize()
{
	int sz=0;
	Node *cur=first;
	while(cur!=NULL)
	{
		sz=sz+1;
		cur=cur->link;
	}
	return sz;
}
void Person::insert(Person x,int index)
{
	Node *prev;
	if(index<0 or index>getSize()){
		throw Exception("Invalid index");
	}
	Node *cur=new Node;
	cur->data=x;
	if(index==0)
	{
		cur->link=first;
		first=cur;
	}
	else
	{
		prev=first;
		for(int i=1; i<=index-1; i++)
		{
			prev=prev->link;
		}
		cur->link=prev->link;
		prev->link=cur;		
	}
	
}
Person Person::del(int index)
{
	Node *del,*prev;
	Person x;
	if(index<0 or index>=getSize())
	{
		throw Exception("Invalid index");
	}
	if(index==0)
	{
		del=first;
		first=del->link;
		x=del->data;
		del->link=NULL;
		delete del;	
	}
	else
	{
		prev=first;
		for(int i=1; i<=index-1; i++)
		{
			prev=prev->link;
		}
	del=prev->link;
	prev->link=del->link;
	x=del->data;
	del->link=NULL;
	delete del;
	}
	return x;

}


void Person::display()
{
	Node *cur=first;
	int i=1;
//	cout<<"[";
	while(cur!=NULL)
	{
		cout<<i<<".";
		cout<<cur->data<<"\n";
		cur=cur->link;
		i=i+1;
	}
//	cout<<"\b\b]";
}
Person Person::get(int index)
{
	Node *cur;
	if(index<0 or index>=getSize())
	{
		throw Exception("Invalid index");
	}
	cur=first;
	for(int i=1; i<=index; i++)
	{
		cur=cur->link;
	}	
	return cur->data;	
}
void Person::getdiet(int index)
{
	Person p1=get(index);
	cout<<"\n[Name     weight     height       BMI ]\n";
	cout<<p1;
	float bmi=p1.getBMI();
	cout<<"\nYour bmi is:"<<bmi<<" and ";
	if(bmi<18.5)
	{
		cout<<" you are Underweight\n";
		cout<<"\n--------------------------------------Diet-suggestions for you-------------------------------------\n";
			cout<<"\nHigh-energy diet for the underweight\nHere is an example of a diet that will provide you with sufficient energy to assist with weight gain:\nFoods that should be included every day:";

			cout<<"\nFull-cream milk: 750 - 1000 ml (3 to 4 cups)\nMeat, fish, eggs and other protein foods: 3-5 servings (90 to 150 g)\nBread and cereals: 8-12 servings (e.g. up to 6 cups of starch a day)";
			cout<<"\nFruit and vegetables: 3-5 servings\nFats and oils: 90 g (6 tablespoons)\nHealthy desserts: 1-2 servings\n";
	}
	if(bmi<=24.9 and bmi>=18.5)
	{
		cout<<" you are Normal Good!\n";
		cout<<"\n--------------------------------------Diet-suggestions for you-------------------------------------\n";
	}
	if(bmi<=29.5 and bmi>=25)
	{
		cout<<" you are Overweight\n";
		cout<<"\n--------------------------------------Diet-suggestions for you-------------------------------------\n";
	}
	if(bmi>30)
	{
		cout<<" you are Obese\n";
		cout<<"\n--------------------------------------Diet-suggestions for you-------------------------------------\n";
	}
}

void bubble_sort(Person *L,int n)
{
	Person temp;
	int i,round,flag;
	for(round=1; round<=n-1; round++)
	{
      flag=0;
	 for(i=0; i<=n-1-round; i++)
	 {
	 	if(L[i].getBMI()>L[i+1].getBMI())
	     {
		 	 temp=L[i];
	     	 L[i]=L[i+1];
	    	 L[i+1]=temp;
	    	 flag=1;
	     }	
	 }
	 if(flag==0)
	 break;
    }
}
void Person::sort()
{
	Person temp[getSize()];
	Node *cur=first;
	for(int k=0; k<getSize(); k++)
	{
	temp[k].insert(cur->data,0);
	cur=cur->link;
	}
	bubble_sort(temp,getSize());
	for(int k=0; k<getSize(); k++)
		temp[k].display();
}
int main()
{
	Person P,temp;
	int option,pno;
	while(1)
	{
		cout<<"\n------------------------------Person data with BMI (main menu)-----------------------------\n";
		cout<<"\n1.Insert data for Person\n";              //index=size-1
		cout<<"2.display for all persons\n";
		cout<<"3.delete data of person\n";
		cout<<"4.to check how many data is present\n";
		cout<<"5.Diet plan for person\n";
		cout<<"6.Sorting on the basis of BMI\n";
		cout<<"7.exit\n";
		cout<<"select option:";
		cin>>option;
		switch(option)
		{
			case 1:
				cin>>temp;
				P.insert(temp,P.getSize());
				cout<<"\ndata has been inserted\n";
				break;
			case 2:
				cout<<"\n[S.no.\tName   	weight(kg)     height(cm)      BMI ]\n";
				P.display();
				break;
			case 3:
				cout<<"\nEnter S.no from list to delete data of person :";
				cin>>pno;
				P.del(pno-1);
				cout<<"\ndeleted succesfully\n";
				break;
			case 4:
				cout<<"Total people are: "<<P.getSize()<<endl;
				break;
			case 5:
				cout<<"Enter S.no. from list to get diet plan according to your BMI:";
				cin>>pno;
				P.getdiet(pno-1);
				break;
			case 6:
				P.sort();
			case 7:
				exit(0);
			default:
				cout<<"invalid choice re-enter please!"<<endl;
				
		}
		
	}

	getch();
	return 0;
}





























/*
//for first time only
Node * create(int n)
{
	Node *first,*cur;
	for(int i=1; i<=n; i++)
	{
		if(i==1)
		{
			first=cur=new Node;  //new returns address//pointers are there to keep address only//
			//first and cur contains the address of present /first node
		}
		else
		{
			cur->link=new Node;  //returns address of next node     linkof current contains add of new node
			cur=cur->link;				//current now contains the add of new node
		}
		cout<<"Enter data"<<i<<":";
		cin>>cur->data;
	}
	cur->link=NULL;
	return first;
}
void display(Node *first)
{
	Node *cur=first;
//	cout<<"\n";
	while(cur!=NULL)
	{
		cout<<cur->data<<"\n ";
		cur=cur->link;
	}
//	cout<<"";
}

int n;
	cout<<"Entries for How many Persons?\n";
	cin>>n;
//	Node *first=create(n);
//	display(first);
*/
