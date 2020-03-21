#include<iostream>
#include<stdio.h>
using namespace std;

struct node {
	int info;
	struct node *prev,*next;
};
struct node* start=NULL;
struct node* createnode(int val)
{
	struct node *p;
	p=new struct node;
	p->prev=NULL;
	p->info=val;
	p->next=NULL;
	return(p);
}
void insertFirstNode()
{
	struct node* n;
	int val;
	cout<<"Enter a number: ";
	cin>>val;
	n=createnode(val);
	if(start==NULL)
	start=n;
	else
	{
		start->prev=n;
		n->next=start;
		start=n;
	}
}
void DeletefirstNode() 
{
	struct node *t;
	if(start==NULL)
	cout<<"List is Empty ";
	else
	{
		t=start;
		start=start->next;
		start->prev=NULL;
		delete t;
	}
}
void viewlist()
{
	struct node *t;
	if(start==NULL)
	cout<<"List is empty ";
	else
	{
		t=start;
		while(t!=NULL)
		{
			cout<<(t->info)<<" ";
			t=t->next;
		}
	}
}
void reverselist()
{
	struct node *p1,*p2;
	p1=start;
	p2=p1->next;
	p1->next=NULL;
	p1->prev=p2;
	while(p2!=NULL)
	{
		p2->prev=p2->next;
		p2->next=p1;
		p1=p2;
		p2=p2->prev;
	}
	start=p1;
	cout<<"List reversed "<<endl;
}
void count()
{
	struct node *p;
	p=start;
	int cnt=0;
	while(p!=NULL)
	{
		p=p->next;
		cnt++;
	}
	cout<<"Number of Elements in the list is "<<cnt<<endl;
}
int menu()
{
	int ch;
	cout<<"\n1. Insert Node at front ";
	cout<<"\n2.Delete First Node ";
	cout<<"\n3.Display List ";
	cout<<"\n4.Reverse List ";
	cout<<"\n5.Number of Elements";
	cout<<"\nEnter your choice: ";
	cin>>ch;
	return(ch);
}
int main()
{
	
	while(1){
	
	switch(menu())
	{
		case 1: insertFirstNode();
		break;
		case 2: DeletefirstNode();
		break;
		case 3: viewlist();
		break;
		case 4: reverselist();
		break;
		case 5: count();
		break;
		default:
			exit(0);
	}
}
	return 0;
}

