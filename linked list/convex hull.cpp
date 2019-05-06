#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
class Point{
	public:
	int x,y;
		Point(){}
		Point(int x,int y)
		{
			this->x=x;
			this->y=y;
		}
		bool isAngleLE180(Point p1,Point p2)
		{
			if(((p1.x-x)*(p2.y-p1.y)-(p2.x-p1.x)*(p1.y-y)) <=0)
				return true;
			else 
				return false;
		}
		int compare(Point p1,Point p2)
		{
			return (p2.x-x)*(p1.y-y)-(p1.x-x)*(p2.y-y);
		}
		double distance(Point p)
		{
			return sqrt((p.x-x)*(p.x-x)+(p.y-y)*(p.y-y));
		}
		friend ostream &operator <<(ostream &out,Point p)
		{
			out<<"("<<p.x<<", "<<p.y<<")";
			return out;
		}
};
class Node{
	public:
		Point p;
		Node *prev,*next;
		Node(Point p){
			this->p=p; prev=next=NULL;
		}
};
class DCLinkedList{
	Node *first;
	public:
		DCLinkedList(){first=NULL;
		}
		void traverse()
		{
			Node *cur=first;
			while(cur->next !=first)
			{
				cout<<cur->p;
				cur=cur->next;
			}
			cout<<cur->p;
		}
		int size()
		{
			if(first==NULL)
				return 0;
			int size=1;
			Node *cur=first;
			while(cur->next!=first)
			{
				size++;
				cur=cur->next;
			}
			return size;
		}
		void create(int n)
		{
			Node *cur=NULL,*next;
//			randomize();
			for(int i=1; i<=n; i++)
			{
				int x=0,y=0;
				x=rand()%40;
				y=rand()%30;
//				cout<<"Test1=x="<<x<<"y="<<y;
				Point p(x,y);
//				cout<<"Test=p="<<p;
				if(i==1)
				{
					first=cur=new Node(p);
				}
				else{
					cur->next=new Node(p);
					next=cur->next;
					next->prev=cur;
					cur=next;
				}
			}
			first->prev=cur;
			cur->next=first;
		}
		void del(Node *del)
		{
			Node *prev,*next;
			prev=del->prev;
			next=del->next;
			prev->next=next;
			next->prev=prev;
			if(first!=next)
			{
				first=next;
			}
			else
			{
				first=NULL;
			}
			del->prev=del->next=NULL;
			delete del;
		}
		Node * get(int index)
		{
			Node *cur=first;
			for(int i=1; i<=index; i++)
			{
				cur=cur->next;
			}
			return cur;
		}
		void set(int index,Point px)
		{
			Node *cur=first;
			for(int i=1; i<=index; i++)
			{
				cur=cur->next;
			}
			cur->p=px;
		}
		Node * getFirst()
		{
			return first;
		}
};

class ConvexHull{
	public:
		Node * getp0(DCLinkedList l)
		{
			int x,y;
			Node *cur=l.getFirst();
			if(cur==NULL)
			return NULL;
			Node *p0=cur;
			x=cur->p.x;
			y=cur->p.y;
			for(int i=2; i<=l.size(); i++)
			{
				cur=cur->next;
				Point p=cur->p;
				if((p.y<y)||(p.y==y && p.x<x))
				{
					p0=cur;
					y=p.y;
					x=p.x;
				}
			}
			return p0;
		}
		void sort(DCLinkedList l,Node *p0)
		{
			Point p=p0->p;
			//sorting the point in ascending order of their angle with p0 using bubble sort
			for(int i=1; i<l.size(); i++)
			{
			bool flag=true;
			for(int j=0; j<l.size()-i; j++)
			{
				Point pj=l.get(j)->p;
				Point pjj=l.get(j+1)->p;
				if(p.compare(pj,pjj)>0 || (p.compare(pj,pjj) == 0 && p.distance(pj)>p.distance(pjj)))
				{
					flag=false;
					l.set(j,pjj);
					l.set(j+1,pj);
				}
			}
			if(flag)
			break;
			}
		}
		void getConvexHull()
		{
			int n=0;
			cout<<"How many Points? ";
			cin>>n;
			DCLinkedList l;
			l.create(n);
			l.traverse();
			Node *p0=getp0(l);
			cout<<"\np0="<<p0->p;
			sort(l,p0);
			cout<<"\nThe points after sorting\n";
			l.traverse();
			cout<<"\nComputing convex hull\n";
			for(Node *x=p0, *rx=x->next,*rrx=rx->next; rrx!=p0 || rx != rrx;)
			{
				rrx=rx->next;
				if((x->p).isAngleLE180(rx->p,rrx->p))
				{
					l.del(rx);
					rx=x;
					x=rx->prev;
				}
				else
				{
					x=rx; rx=rrx;
				}
			}
			cout<<"\nThe points of the convex hull \n";
			l.traverse();
		}
		
};
int  main()
{
	ConvexHull c;
	c.getConvexHull();
////	randomize();
//	for(int i=0; i<10; i++)
//	{
//		cout<<"\n("<<random(100)<<", ";
//		cout<<random(100)<<")";
//	}
	getchar();
	return 0;
}





