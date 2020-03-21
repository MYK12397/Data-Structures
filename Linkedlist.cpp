 #include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
	int info;
 node *link;
};
struct node *START=NULL;
struct node* createnode(int value)
{
	struct node *n;
	n=new (struct node);
	n->info=value;
	n->link=NULL;
	return (n);
}
void insert_beg()
{
	struct node *temp,*t;
	int v;
	cout<<"Enter a Number: ";
	cin>>v;
	temp=createnode(v);
	temp->link=NULL;
	if(START==NULL)
	{
		START=temp;
	}
	else
	{
		t=START;
		while(t->link!=NULL)
		{
		t=t->link;}
		
	t->link=temp;
	}
}
void deletenode()
{
	struct node* r;
	if(START==NULL)
	cout<<"List is Empty";
	else
	{
		r=START;
		START=START->link;
		free(r);
	}
}
void viewlist()
{
	struct node *t;
	if(START==NULL)
	{
	cout<<"List is empty";
	}
	else
	{
		
		t=START;
		while(t!=NULL)
		{
		cout<<(t->info)<<" ";
		t=t->link;
		}
	}
}
	void reverselist()
	{
		struct node *ptr1,*ptr2,*ptr3;
		if(START==NULL)
		{
			cout<<"list is empty";
		return;
		}
		if(START->link==NULL)
		{
			cout<<"list is empty";
			return;
		}
		ptr1=START;
		ptr2 =ptr1->link;
		ptr3 =ptr2->link;
		ptr1->link=NULL;
		ptr2->link=ptr1;
		while(ptr3!=NULL)
		{
			ptr1=ptr2;
			ptr2=ptr3;
			ptr3=ptr3->link;
			ptr2->link=ptr1;
		}
		START=ptr2;
}

void searchlist()
{
	int value,pos=0;
	bool flag=false;
	if(START==NULL)
	{
		cout<<"list is empty";
		return;
	}
	cout<<"Enter the value to be searched: ";
	cin>>value;
	struct node *s;
	s=START;
	while(s!=NULL)
	{
		pos++;
		if(s->info==value)
		{
			flag=true;
			cout<<"Element"<<value<<" is found at position "<<pos<<endl;
		}
		s=s->link;
		
	}
	if(!flag)
	{
		cout<<"Element "<<value<<" not found in the list "<<endl;
		
	}
}
void insert_pos()
{
	int val,pos,count=0;
	cout<<"Enter the value to be inserted: ";
	cin>>val;
	struct node *temp,*s,*ptr;
	temp=createnode(val);
	
	cout<<"Enter the position at which node to be inserted:  ";
	cin>>pos;
	int i;
	s=START;
	while(s!=NULL)
	{
		s=s->link;
		count++;
	}
	if(pos==1)
	{
		if(START==NULL)
		{
			START=temp;
			START->link=NULL;
		}
		else
		{
			ptr=START;
			START=temp;
			START->link=ptr;
		}
	}
	else if(pos>1&&pos<=count)
	{
		s=START;
		for(i=1;i<pos;i++)
		{
			ptr=s;
			s=s->link;
		}
		ptr->link=temp;
		temp->link=s;
	}
	else
	{
		cout<<"Position out of range "<<endl;
	}
}
void insert_end()
{
	int val;
	struct node *temp,*s;
	s=START;
	cout<<"Enter value to be inserted: ";
	cin>>val;
	temp=createnode(val);
	while(s->link!=NULL)
	{
		s=s->link;
	}
	temp->link=NULL;
	s->link=temp;
	cout<<"Value inserted at last position "<<endl;
	
}
void delete_pos()
{
	struct node *temp,*s;
	s=START;
	int val;
	cout<<"Enter value to be deleted: ";
	cin>>val;
	
}
int menu()
{
	int ch;
	cout<<"\n1.insertion in the begining ";
	cout<<"\n2.insertion at given position";
	cout<<"\n3. insertion at the end";
	cout<<"\n4.Delete First Value ";
	cout<<"\n5.View List";
	cout<<"\n\n6.Reverse List";
	cout<<"\n7.Search Value ";
	cout<<"\n8.Press any other key to exit ";
	cout<<"\nEnter your choice \n";
	cin>>ch;
	return (ch);
}
int main()
{
	while(1)
	{
	switch(menu())
	{
		case 1: insert_beg();
		break;
		
		case 2:insert_pos();
		break;
		case 3:insert_end();
		break;
		case 4:deletenode();
		break;
		case 5: viewlist();
		break;
		case 6: reverselist();
		break;
		case 7: searchlist();
		break;
		default:
			exit(0);
			cout<<"Invalid choice: ";
	}
}}

